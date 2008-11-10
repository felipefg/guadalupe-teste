/*
	Universidade Federal do Rio de Janeiro
	Escola Politecnica
	Departamento de Engenharia Eletronica e de Computacao
	
	Laboratorio de Processamento de Sinais
	Projeto Neural TB
	
	Autor: Patrick Svaiter
	
	Descricao:
	- Incluir informacoes em um usuario ja existente no sistema.
	- A funcao faz uso da Libxml2 para manipular arquivos XML
	- "numeroGeral" e um elemento XML que esta dentro do formulario de Triagem
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xmlstring.h>
#include "cgi.h"
#include "ntbConsts.h"
#include "ntbTypes.h"
#include "ntbFunctions.h"

void usualFreeMemory (xmlDocPtr doc)
{
	cgi_end();
	if (doc)
		xmlFreeDoc(doc);
	xmlCleanupParser();
	xmlMemoryDump();
}

void printError (char *msg)
{
	cgi_init_headers();
	
	printf ("<html><head><title>Erro</title></head><body><h2>%s</h2></body></html>", msg);
}

int main (void)
{
	/* general declarations */
	char *pid, *formName;
	char xmlFilePath [FILE_NAME_MAX];
	char tempFile[] = "xml/pacientesTemp.xml";
	int rc, utf8;
	boolean found_patient, found_form;
	
	/* date and time declarations */
	/*time_t rawtime;
	struct tm *timeinfo;
	int day, month, year, hour, min;*/
	
	/* libcgi declarations */
	formvars *first_input, *input;
	
	/* libxml2 declarations */
	xmlChar *strUTF;
	xmlDocPtr doc;
	xmlNodePtr root_element, cur_node, new_form, new_node, right_patient;
	
	
	
	/*
	 * this initialize the library and check potential ABI mismatches
	 * between the version it was compiled for and the actual shared
	 * library used.
	 */
	LIBXML_TEST_VERSION
	
/******************************************************************************
 *            GET CURRENT DATE AND TIME                                       *
 ******************************************************************************/
	/*
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	
	day = timeinfo->tm_mday;
	month = timeinfo->tm_mon +1;
	year = timeinfo->tm_year +1900;
	
	hour = timeinfo->tm_hour;
	min = timeinfo->tm_min;
	*//* date and time are being entered manually */
	
	cgi_init();
	
/******************************************************************************
 *            READ CONTENT STRING FROM SERVER.                                *
 *            PROCESS DATA.                                                   *
 *            CREATE A LINKED LIST.                                           *
 ******************************************************************************/
	
	first_input = cgi_process_form();
	
	formName = cgi_param("form");
	pid = cgi_param("pid");
	
	if ((!pid) || (!formName))
	{
		printError("ID do paciente e nome do formul&aacute;rio n&atilde;o foram enviados");
		usualFreeMemory(NULL);
		exit(0);
	}
	
/******************************************************************************
 *            OPENING AND PARSING AN XML FILE TO A TREE                       *
 ******************************************************************************/
	
	//strcpy (healthCenter, "Guadalupe");
	//snprintf (xmlFilePath, FILE_NAME_MAX, "xml/pacientes%s.xml", healthCenter);
	strcpy (xmlFilePath, "xml/pacientesGuadalupe.xml");
	
	doc = xmlReadFile(xmlFilePath, NULL, 256);	/* 256 = remove blank nodes */
	if (doc == NULL)
	{
		printError("Failed to parse doc");
		usualFreeMemory(NULL);
		exit(0);
	}
	
/******************************************************************************
 *            SEARCH PATIENT                                                  *
 ******************************************************************************/
	
	root_element = xmlDocGetRootElement(doc);
	cur_node = root_element->children;	/* Get the node <paciente> if file isn't empty */
	if (!cur_node) //test!!!! printf!! pode-se tb na remocao exigir a remocao do arquivo se o paciente excluido for o unico do arquivo
		found_patient = false;
	
	else
	{
		/* looping through patients looking for the right patient */
		
		for (found_patient = false; ((!found_patient) && (cur_node)); cur_node = cur_node->next)
		{
			cur_node = cur_node->children; /* <triagem> */
			cur_node = cur_node->children; /* <numeroGeral> ? */
			
			while ((!xmlStrEqual(cur_node->name, BAD_CAST "numeroGeral")) && (cur_node))
				cur_node = cur_node->next;
			
			if (xmlStrEqual(cur_node->name, BAD_CAST "numeroGeral"))
			{
				if (xmlStrEqual(cur_node->children->content, BAD_CAST pid))
				{
					//MANDAR IMPRIMIR o CONTEUDO VAZIO DE UM NUMERO GERAL PARA TESTE!
					
					found_patient = true;
					right_patient = cur_node->parent->parent;
				}
				else
				{
					cur_node = cur_node->parent; /* <triagem> */
					cur_node = cur_node->parent; /* <paciente> */
				}
			}
			else
			{
				printError("Erro de forma&ccedil;&atilde;o do XML. Tem paciente sem n&uacute;mero geral.");
				usualFreeMemory(doc);
				exit(0);
			}
		}
	}
	
/******************************************************************************
 *            CHECK IF PATIENT WAS FOUND                                      *
 *            IF TRUE, CONVERT FORM NAME INPUT TO UTF-8 IF NECESSARY          *
 ******************************************************************************/
	
	if (found_patient)
	{	
		utf8 = xmlCheckUTF8 (BAD_CAST formName);
		if (!utf8)
		{
			rc = convertISO88591toUTF8 ((unsigned char *)formName, &strUTF);
			
			if (rc < 0)
			{
				printError("Erro convertendo valor para UTF-8");
				usualFreeMemory(doc);
				free(strUTF);
				exit(0);
			}
			
			formName = (char *)strUTF;
		}
		
/******************************************************************************
 *            CHECK IF FORM EXISTS                                            *
 ******************************************************************************/
		
		cur_node = right_patient->children;
		
		found_form = false;
		while ((cur_node) && (!found_form))
		{
			if ((xmlStrEqual(BAD_CAST formName, cur_node->name)) && (strcmp(formName, "followUp")))
				found_form = true;
			
			cur_node = cur_node->next;
		}
		
		if (found_form)
		{
			printError("O paciente j&aacute; possui este formul&aacute;rio");
			usualFreeMemory(doc);
			free(strUTF);
			exit(0);
		}
		
/******************************************************************************
 *            ADD NEW FORM                                                    *
 ******************************************************************************/
		
		new_form = xmlNewNode (NULL, BAD_CAST formName);
		free(strUTF);//frees formName
		
		for (input = first_input; input; input = input->next)
		{
			while ((!strcmp(input->name,"form")) || (!strcmp(input->name,"pid")))
				input = input->next;
			
			
			/* Validate tag name input against UTF-8 */
			utf8 = xmlCheckUTF8 (BAD_CAST input->name);
			if (!utf8)
			{
				rc = convertISO88591toUTF8 ((unsigned char *)input->name, &strUTF);
				
				/** the code above is equiv to the code below
				inlen = strlen(input->name);
				lenUTF = 2 * inlen;
				strUTF = BAD_CAST malloc ((size_t) (lenUTF + 1));
				
				rc = isolat1ToUTF8 (strUTF, &lenUTF, input->name, &inlen);
				**/
				
				if (rc < 0)
				{
					printError("Erro convertendo valor para UTF-8");
					usualFreeMemory(doc);
					free(strUTF);
					exit(0);
				}
				
				new_node = xmlNewNode (NULL, strUTF);
				free(strUTF);
			}
			else
				new_node = xmlNewNode (NULL, BAD_CAST input->name);
			
			
			/* Validate tag value input against UTF-8 */
			utf8 = xmlCheckUTF8 (BAD_CAST input->value);
			if (!utf8)
			{	
				rc = convertISO88591toUTF8 ((unsigned char *)input->value, &strUTF);
				
				if (rc < 0)
				{
					printError("Erro convertendo valor para UTF-8");
					usualFreeMemory(doc);
					free(strUTF);
					exit(0);
				}
				
				xmlNodeAddContent (new_node, strUTF);
				free(strUTF);
			}
			else
				xmlNodeAddContent (new_node, BAD_CAST input->value);
			
			
			xmlAddChild (new_form, new_node);
		}
		
		xmlAddChild (right_patient, new_form);
		
/******************************************************************************
 *            DUMPING DOCUMENT TO FILE                                        *
 ******************************************************************************/
		
		if ((xmlSaveFormatFileEnc(tempFile, doc, "ISO-8859-1", 1)) < 0)
		{
			remove(tempFile);
			printError("Erro ao salvar arquivo");
			usualFreeMemory(doc);
			exit(0);
		}
		
		remove(xmlFilePath);
		    
		if (rename(tempFile, xmlFilePath))
		{
			printError("Erro ao renomear o arquivo atualizado");
			usualFreeMemory(doc);
			exit(0);
		}
	}
	
	
	
	else
	{
		printError("O paciente n&atilde;o tem registro no sistema");
		usualFreeMemory(doc);
		exit(0);
	}
	
/******************************************************************************
 *            FREE MEMORY AND EXIT                                            *
 ******************************************************************************/
	
	usualFreeMemory(doc);
	printError("Fomul&aacute;rio adicionado com sucesso");
	
	return (0);
}
