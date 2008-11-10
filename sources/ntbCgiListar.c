/*
	Universidade Federal do Rio de Janeiro
	Escola Politecnica
	Departamento de Engenharia Eletronica e de Computacao
	
	Laboratorio de Processamento de Sinais
	Projeto Neural TB
	Autor: Igor Bragança

	$Author$
	$Date$
	$Log$
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"
#include "cgi.h"
/*
#include "ntbConfig.h"
#include "Const.h"
#include "Types.h"
#include "Error.h"
#include "Functions.h"
*/

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

int main (int argc, char **argv)
{
	char *username;
	//CGI process
	
	cgi_init();
	cgi_process_form();
	username = cgi_param("uid");

	cgi_init_headers();
	
/************** pagina html busca ********************/

printf("<html>\n");
printf("<head>\n");
printf("	<title>Neural TB - Lista de Pacientes</title>\n");
printf("	<link rel=\"stylesheet\" type=\"text/css\" href=\"css/main.css\" />\n");
printf("	<link rel=\"stylesheet\" type=\"text/css\" href=\"css/menu.css\" />\n");
printf("	<link rel=\"stylesheet\" type=\"text/css\" href=\"css/form.css\" />\n");
printf("	<script language=javascript src=\"js/funcoes.js\"></script>\n");
printf("\n");
printf("	<style>\n");
printf("		iframe {width: 100%%; min-width: 800px; height:500px}\n");
printf("	</style>\n");
printf("</head>\n");
printf("\n");
printf("<body>\n");
printf("\n");

showMenu("listar",username);

printf("\n");
printf("<table border=\"0\">\n");
printf("<tr>\n");
printf("	<td class=\"under_menu\">\n");
printf("		<div align=\"center\">\n");
printf("		<table border=\"0\" style=\"width: 100%%\" cellspacing=\"0\" cellpadding=\"0\">	\n");
printf("\n");
printf("		<tr>\n");
printf("			<td><iframe src=\"listPatients.cgi?uid=%s\" frameborder=\"0\" name=\"resultado\" marginwidth=\"0\" marginheight=\"0\" style=\"width: 100%%\"></iframe></td>\n",username);
printf("		</tr>\n");
printf("\n");
printf("		</table>\n");
printf("		</div>\n");
printf("	</td>\n");
printf("</tr>\n");
printf("</table>\n");
printf("</body>\n");
printf("</html>\n");

/*****************************************************/

	cgi_end();
	
	return 0;
}

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/* $RCSfile$ */
