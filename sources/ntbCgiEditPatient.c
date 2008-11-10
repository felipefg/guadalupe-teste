/*
	Universidade Federal do Rio de Janeiro
	Escola Politecnica
	Departamento de Engenharia Eletronica e de Computacao
	
	Laboratorio de Processamento de Sinais
	Projeto Neural TB (Guadalupe)
	Autor: Igor Cunha Braganca

	$Author$
	$Date$
	$Log$
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

#define XML_FILE_PATH "./xml/pacientesGuadalupe.xml"
#define XML_TEMP_FILE "./xml/TempPacientesGuadalupe.xml"

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
	printf ("\t\t<title>Usu&aacute;rio Editado</title>\n");
	printf ("\t\t<meta http-equiv=\"refresh\" content=\"2; URL=busca.cgi?uid=%s\" />\n",username);
	printf ("\t</head>\n");
	printf ("\t</body>\n");
	printf ("<span style=\"background-color:green; color: white; font-family: Verdana, Arial; font-size:15pt; padding: 5px\">");
	printf ("Usu&aacute;rio editado com sucesso. Aguarde...</span>");
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
	char *formName, *pid, *username;
	boolean found_patient;
	
	/* libcgi declarations */
	formvars *first_input, *input;
	
	/* libxml2 declarations */
	xmlChar *strUTF = NULL;
	xmlDocPtr doc;
	xmlNodePtr root_element, cur_node, new_form, new_node, edited_patient, old_patient;
	
	/*
	 * this initialize the library and check potential ABI mismatches
	 * between the version it was compiled for and the actual shared
	 * library used.
	 */
	LIBXML_TEST_VERSION
	
/******************************************************************************
 *            READ CONTENT STRING FROM SERVER.		*
 *            PROCESS DATA.						*
 *            CREATE A LINKED LIST.					*
 ******************************************************************************/
	
	cgi_init();
	first_input = cgi_process_form();
	pid = cgi_param("numeroGeral");
	formName = cgi_param("form");
	username = cgi_param("uid");
	
	if ((!pid) || (!formName))
	{
		printError("ID do paciente e nome do formul&aacute;rio n&atilde;o foram enviados");
		usualFreeMemory(NULL);
		exit(0);
	}

/******************************************************************************
 *            OPENING AND PARSING AN XML FILE TO A TREE                       *
 ******************************************************************************/	
 
	doc = xmlReadFile(XML_FILE_PATH, NULL, XML_PARSE_NOBLANKS);
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
					old_patient = cur_node->parent; /*old_paciente recebe o noh <triagem> do paciente que possui o numeroGeral procurado */
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
 *            CHECK IF PATIENT WAS FOUND		*
 *            IF TRUE, EXIT 					*
 ******************************************************************************/
	
	if (!found_patient)
	{
		printError("Este paciente n&atilde;o existe.");
		usualFreeMemory(doc);
		exit(0);
	}
	
/******************************************************************************
 *            CRIANDO NOVO FORMULARIO DE TRIAGEM                                        *
 ******************************************************************************/
	
	edited_patient = xmlNewNode (NULL,BAD_CAST "triagem");
	
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
	
	new_form = xmlNewChild (edited_patient, NULL, BAD_CAST strUTF, NULL);
	free(strUTF);//frees formName
	
	for (input = first_input; input; input = input->next)
	{
		if (!strcmp(input->name,"form"))
			input = input->next;
		
		
		/* Validate tag name input against UTF-8 */
		strUTF = fixCgiStr((unsigned char *)input->name);
		if (!strUTF)
		{
			printError("Erro na convers&atilde;o de input->name para UTF-8");
			usualFreeMemory(doc);
			exit(0);
		}
		
		new_node = xmlNewNode (NULL, strUTF);
		free(strUTF);//frees input->name
		
		
		/* Validate tag value input against UTF-8 */
		strUTF = fixCgiStr((unsigned char *)input->value);
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
*	Substituindo o noh antigo pelo novo		*
******************************************************************************/

	xmlReplaceNode (old_patient, edited_patient->children);
	xmlFreeNode (old_patient);
	
/******************************************************************************
 *            DUMPING DOCUMENT TO FILE		*
 ******************************************************************************/
	
	if ((xmlSaveFormatFileEnc(XML_TEMP_FILE, doc, "ISO-8859-1", 1)) < 0)
	{
		remove(XML_TEMP_FILE);
		printError("Erro ao salvar arquivo");
		usualFreeMemory(doc);
		exit(0);
	}
	
	remove(XML_FILE_PATH);
    
    if (rename(XML_TEMP_FILE, XML_FILE_PATH))
    {
        printError("Erro ao renomear o arquivo atualizado");
        usualFreeMemory(doc);
        exit(0);
    }

/******************************************************************************
 *            FREE MEMORY AND EXIT			*
 ******************************************************************************/

	printSuccess(username);
	
	usualFreeMemory(doc);
	
	xmlFreeNode(edited_patient);
	
	return 0;
}
