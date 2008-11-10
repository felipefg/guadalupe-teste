/*
	Universidade Federal do Rio de Janeiro
	Escola Politecnica
	Departamento de Engenharia Eletronica e de Computacao
	
	Laboratorio de Processamento de Sinais
	Projeto Neural TB
	
	Autor: Patrick Svaiter
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xmlstring.h>

#include "cgi.h"
#include "ntbError.h"
#include "ntbConfig.h"
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

void printSuccess (char *username)
{
	cgi_init_headers();
	
	printf ("<html>\n");
	printf ("\t<head>\n");
	printf ("\t\t<title>Fomul&aacute;rio adicionado</title>\n");
	printf ("\t\t<meta http-equiv=\"refresh\" content=\"2; URL=triagem.cgi?uid=%s\" />\n",username);
	printf ("\t</head>\n");
	printf ("\t</body>\n");
	printf ("<span style=\"background-color:green; color: white; font-family: Verdana, Arial; font-size:15pt; padding: 5px\">");
	printf ("Fomul&aacute;rio adicionado com sucesso. Aguarde...</span>");
	printf ("\t</body>\n");
	printf ("</html>");
}

void printError (char *msg)
{
	cgi_init_headers();
	
	printf ("<html><head><title>Erro</title></head><body><h2>%s</h2></body></html>", msg);
}

int main (void)
{
	FILE *fp; //short for file pointer
	//unsigned long count = 0;
	char xmlFilePath[FILE_NAME_MAX];
	char tempFile[] = "xml/pacientesTemp.xml";
	char *formName, *pid, *username;
	boolean found_patient;
	
	//char username[65];
	
	/* date and time declarations */
	/*time_t rawtime;
	struct tm *timeinfo;
	int day, month, year, hour, min;*/
	
	/* libcgi declarations */
	formvars *first_input, *input;
	
	/* libxml2 declarations */
	xmlChar *strUTF = NULL;
	xmlDocPtr doc;
	xmlNodePtr root_element, cur_node, new_form, new_node, new_patient;
	
	
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
*///inclusao manual de data
	
	cgi_init();
	
/******************************************************************************
 *            READ CONTENT STRING FROM SERVER.                                *
 *            PROCESS DATA.                                                   *
 *            CREATE A LINKED LIST.                                           *
 ******************************************************************************/
	
	first_input = cgi_process_form();
	pid = cgi_param("numeroGeral");
	formName = cgi_param("form");
	username = cgi_param("cadastradoPor");
	
	if ((!pid) || (!formName))
	{
		printError("ID do paciente e nome do formul&aacute;rio n&atilde;o foram enviados");
		usualFreeMemory(NULL);
		exit(0);
	}
	
	
	//strcpy (healthCenter, "Guadalupe");
	//snprintf (xmlFilePath, FILE_NAME_MAX, "xml/pacientes%s.xml", healthCenter);
	strcpy (xmlFilePath, "xml/pacientesGuadalupe.xml");
	
	/* Trying to open patients' file */
	fp = fopen (xmlFilePath, "r");
	
/******************************************************************************
 *            CREATE A NEW XML DOCUMENT                                       *
 ******************************************************************************/
	
	if (!fp)
	{
		doc = xmlNewDoc(BAD_CAST "1.0");
		root_element = xmlNewDocNode(doc, NULL, BAD_CAST "pacientes", NULL);
		xmlDocSetRootElement(doc, root_element);
		found_patient = false;
	}
	
/******************************************************************************
 *            OPENING AND PARSING AN XML FILE TO A TREE                       *
 ******************************************************************************/
	
	else
	{
		fclose(fp);
		
		doc = xmlReadFile(xmlFilePath, NULL, XML_PARSE_NOBLANKS);
		if (doc == NULL)
		{
			printError("Failed to parse doc");
			usualFreeMemory(NULL);
			exit(0);
		}
		
		root_element = xmlDocGetRootElement(doc);
		
/******************************************************************************
 *            SEARCH THE SAME <numeroGeral>                                   *
 ******************************************************************************/
		
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
						//right_patient = cur_node->parent->parent;
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
	}
	
/******************************************************************************
 *            CHECK IF PATIENT WAS FOUND                                      *
 *            IF TRUE, EXIT                                                   *
 ******************************************************************************/
	
	if (found_patient)
	{
		printError("Esse n&uacute;mero geral j&aacute; foi registrado");
		usualFreeMemory(doc);
		exit(0);
	}
	
/******************************************************************************
 *            CREATE PATIENT ELEMENT                                          *
 ******************************************************************************/
	
	new_patient = xmlNewChild (root_element, NULL, BAD_CAST "paciente", NULL);
	
	//add attribute removido='nao' to <paciente>
	xmlNewProp (new_patient, BAD_CAST "removido", BAD_CAST "nao");
	
/******************************************************************************
 *            ADD NEW FORM                                                    *
 ******************************************************************************/
	
	strUTF = fixCgiStr(BAD_CAST formName);
	if (!strUTF)
	{
		cgi_init_headers();
		printError("Erro na convers&atilde;o de formName para UTF-8");
		usualFreeMemory(doc);
		exit(0);
	}
	
	new_form = xmlNewChild (new_patient, NULL, BAD_CAST strUTF, NULL);
	free(strUTF);//frees formName
	
	for (input = first_input; input; input = input->next)
	{
		if (!strcmp(input->name,"form"))
			input = input->next;
		
		
		/* Validate tag name input against UTF-8 */
		strUTF = fixCgiStr((xmlChar *)input->name);
		if (!strUTF)
		{
			printError("Erro na convers&atilde;o de input->name para UTF-8");
			usualFreeMemory(doc);
			exit(0);
		}
		
		new_node = xmlNewNode (NULL, strUTF);
		free(strUTF);//frees input->name
		
		
		/* Validate tag value input against UTF-8 */
		strUTF = fixCgiStr((xmlChar *)input->value);
		if (!strUTF)
		{
			printError("Erro na convers&atilde;o de input->value para UTF-8");
			usualFreeMemory(doc);
			exit(0);
		}
		
		xmlNodeAddContent (new_node, strUTF);
		free(strUTF);//frees input->value
		
		
		xmlAddChild (new_form, new_node);
	}
	
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

	
	/**
		//numero geral
		fprintf (fp, "\t\t\t<numeroGeral>1</numeroGeral>\n");
		
		//date of inclusion (automated)
		fprintf (fp, "\t\t\t<dia_inclusao>%i</dia_inclusao>\n", day);
		fprintf (fp, "\t\t\t<mes_inclusao>%02i</mes_inclusao>\n", month);
		fprintf (fp, "\t\t\t<ano_inclusao>%i</ano_inclusao>\n", year);		
		fprintf (fp, "\t\t\t<hora_inclusao>%02i:%02i</hora_inclusao>\n", hour, min);
	**/

	
/******************************************************************************
 *            HTML/XML INITIALIZATION CODE                                    *
 ******************************************************************************/
/**
	printf("Content-type: text/html\r\n\r\n");
	
	printf("	<html>\n");
	printf("			<head>\n");
	printf("				<title>NeuralTB - Dados Inseridos - Formulario Adicionar Paciente</title>\n");
	printf("				<link rel=\"stylesheet\" type=\"text/css\" href=\"css/main.css\">\n");
	printf("				<link rel=\"stylesheet\" type=\"text/css\" href=\"css/menu.css\">\n");
	printf("				<link rel=\"stylesheet\" type=\"text/css\" href=\"css/form.css\">\n");
	printf("				<script language=javascript src=\"js/funcoes.js\"></script>");
	printf("				<style>\n");
	printf("					iframe {width: 90%%; height: 360px}\n");
	printf("				</style>\n");
	printf("			</head>\n");

	printf("		<body>\n");
	printf("			<table border=\"0\" id=\"menu\">\n");
	printf("			<tr>\n");
	printf("				<td>\n");
	printf("					<table border=\"0\">\n");
	printf("					<tr>\n");
	printf("						<td class=\"fl\" onmouseover=\"showmenu('forms')\" onmouseout=\"hidemenu('forms')\">\n");
	printf("							<span class=\"active\">Formul&aacute;rios</span><br />\n");
	printf("							<!--<a class=\"active\" href=\"\">Formul&aacute;rios</a><br />-->\n");
	printf("							<ul class=\"option\" id=\"forms\">\n");
	printf("								<li><a href=\"triagem.cgi?uid=%s\">Triagem</a></li>\n",username);
	printf("								<li><a href=\"custosA.cgi?uid=%s\">Custos - Parte A</a></li>\n",username);
	printf("								<li><a href=\"consultaMedica.cgi?uid=%s\">Consulta M&eacute;dica</a></li>\n",username);
	printf("								<li><a href=\"questionarioCustosParteBeC.html\">Custos - Parte B e C</a></li>\n");
	printf("								<li><a href=\"followUp.cgi?uid=%s\">Follow up</a></li>\n",username);
	printf("							</ul>\n");
	printf("						</td>\n");
	printf("\n");						
	printf("						<td class=\"fl\"><a href=\"busca.html\">Buscar - Editar - Remover</a></td>\n");
	printf("						<td class=\"fl\"><a href=\"backup.cgi\">Backup</a></td>\n");
	printf("						<td class=\"fl\"><a style=\"cursor:help\" href=\"ajuda.html\" target=\"_blank\">Ajuda!</a></td>\n");
	printf("					</tr>\n");
	printf("					</table>\n");
	printf("				</td>\n");
	printf("				<td>\n");
	printf("					<table border=\"0\">\n");
	printf("					<tr>\n");
	printf("						<td class=\"fr\"><i>%s</i> conectado | <a href=\"logout.cgi\">Sair</a></td>\n",username);
	printf("					</tr>\n");
	printf("					</table>\n");
	printf("				</td>\n");
	printf("			</tr>\n");
	printf("			</table>\n");
	printf("\n");
	printf("			<table>\n");
	printf("			<tr>\n");
	printf("				<td>\n");
	printf("					<div align=center>\n");
	printf("						<iframe src=\"xml/lastAdded.xml\" frameborder=\"0\" name=\"resultado\" scrolling=\"auto\">\n");
	printf("						</iframe>\n");
	printf("					</div>\n");
	printf("				</td>\n");
	printf("			</tr>\n\t\t\t</table>\n");
	 **/
	/*
	printf("			<tr>\n");
	printf("				<td><iframe src=\"xml/lastAdded.xml\" frameborder=\"0\" name=\"resultado\" ></td>\n");
	printf("			</tr>\n");
	*/
	/**
	printf("		</body>\n");
	printf("	</html>\n");
	**/
	
/******************************************************************************
 *            FREE MEMORY AND EXIT                                            *
 ******************************************************************************/

	printSuccess(username);
	//printf("Content-type: application/javascript\r\n\r\n");
	//printf("alert(\"Formul&aacute;rio\")");
	usualFreeMemory(doc);
	
	return 0;
}
