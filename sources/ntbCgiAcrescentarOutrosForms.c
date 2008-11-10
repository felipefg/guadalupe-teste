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

#include "cgi.h"

#include "ntbError.h"
//#include "ntbConfig.h"
//#include "ntbConsts.h"
#include "ntbFunctions.h"

//#include "ntbSearchPatient.h"

int main (void)
{
	formvars *first;
	char *pid, *uid;
	
	
	cgi_init();
	
/******************************************************************************
 *            READ CONTENT STRING FROM SERVER.                                *
 *            PROCESS DATA.                                                   *
 *            CREATE A LINKED LIST.                                           *
 ******************************************************************************/
	
	first = cgi_process_form();
	
/******************************************************************************
 *            ACQUIRE VALUES CHOSEN BY USER                                   *
 ******************************************************************************/
	
	uid = cgi_param("uid");
	pid = cgi_param("pid");
	
/******************************************************************************
 *            PRINTING HTML                                                   *
 ******************************************************************************/
	
	cgi_init_headers();
	//printf("Content-type: text/html; charset=iso-8859-1\r\n\r\n");
	
	printf ("<html>\n");
	printf ("	<head>\n");
	printf ("		<title>Neural TB - Incluir Formul&aacute;rio</title>\n");
	printf ("	</head>\n");
	printf ("	<frameset cols=\"25%%,*\">\n");
	printf ("		<frame src=\"verLado.cgi?pid=%s\" />\n", pid);
	printf ("		<frame src=\"consultaMedica.cgi?uid=%s&amp;pid=%s\" />\n",uid,pid);
	printf ("	</frameset>\n");
	printf ("</html>");
	
/******************************************************************************
 *            FREE MEMORY AND EXIT                                            *
 ******************************************************************************/
	
	cgi_end();
	
	return (ok);
}
