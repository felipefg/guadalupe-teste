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

void printSuccess (void)
{
	cgi_init_headers();
	
	printf ("<html>\n");
	printf ("\t<head>\n");
	printf ("\t\t<title>Usu&aacute;rio Removido</title>\n");
	printf ("\t\t<meta http-equiv=\"refresh\" content=\"2; URL=searchPatient.cgi\" />\n");
	printf ("\t</head>\n");
	printf ("\t</body>\n");
	printf ("<span style=\"background-color:green; color: white; font-family: Verdana, Arial; font-size:15pt; padding: 5px\">");
	printf ("Usu&aacute;rio removido com sucesso. Aguarde...</span>");
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
	//unsigned long count = 0;
	char xmlFilePath[FILE_NAME_MAX];
	char tempFile[] = "xml/pacientesTemp.xml";
	char *pid;
	boolean found_patient;
	
	//char username[65];
	
	/* date and time declarations */
	/*time_t rawtime;
	struct tm *timeinfo;
	int day, month, year, hour, min;*/
	
	/* libcgi declarations */
	formvars *first_input;
	
	/* libxml2 declarations */
	xmlDocPtr doc;
	xmlNodePtr root_element, cur_node;
	
	
	/*
	 * this initialize the library and check potential ABI mismatches
	 * between the version it was compiled for and the actual shared
	 * library used.
	 */
	LIBXML_TEST_VERSION
	
/******************************************************************************
 *            GET CURRENT DATE AND TIME                                       *
 *********************************************tempFile*********************************/
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
	
	if (!pid)
	{
		printError("ID do paciente n&atilde;o foi enviado");
		usualFreeMemory(NULL);
		exit(0);
	}
	
	
	//strcpy (healthCenter, "Guadalupe");
	//snprintf (xmlFilePath, FILE_NAME_MAX, "xml/pacientes%s.xml", healthCenter);
	strcpy (xmlFilePath, "xml/pacientesGuadalupe.xml");
	
	
/******************************************************************************
 *            OPENING AND PARSING AN XML FILE TO A TREE                       *
 ******************************************************************************/
	/*
	else
	{ */

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
						found_patient = true;
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
	/*}*/
	
/******************************************************************************
 *            CHECK IF PATIENT WAS NOT FOUND                                      *
 *            IF TRUE, EXIT                                                   *
 ******************************************************************************/
	

	if (!found_patient)
	{
		printError("Esse n&uacute;mero geral n&atilde;o foi encontrado");
		usualFreeMemory(doc);
		exit(0);
	}
	
/******************************************************************************
 *            EDIT PATIENT ELEMENT                                          *
 ******************************************************************************/
//Volto para o node Paciente

	cur_node = cur_node->parent;
	cur_node = cur_node->parent;

// Modifico atributo "removido" de 'nao' para 'sim' 

	xmlSetProp (cur_node, BAD_CAST "removido", BAD_CAST "sim");
	

	
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
	
	if (rename(tempFile, xmlFilePath))
	{
		printError("Erro ao renomear o arquivo atualizado");
		usualFreeMemory(doc);
		exit(0);
	}
	
	remove(tempFile);
	

	
/******************************************************************************
 *            FREE MEMORY AND EXIT                                            *
 ******************************************************************************/

	printSuccess();
	//printf("Content-type: application/javascript\r\n\r\n");
	//printf("alert(\"Formul&aacute;rio\")");
	usualFreeMemory(doc);
	
	return 0;
}
