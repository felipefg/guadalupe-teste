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
printf ("<html>\n");
printf ("<head>\n");
printf ("	<title>Neural TB - Busca</title>\n");
printf ("	<link rel=\"stylesheet\" type=\"text/css\" href=\"css/main.css\" />\n");
printf ("	<link rel=\"stylesheet\" type=\"text/css\" href=\"css/menu.css\" />\n");
printf ("	<link rel=\"stylesheet\" type=\"text/css\" href=\"css/form.css\" />\n");
printf ("	<script language=javascript src=\"js/funcoes.js\"></script>\n");
printf ("	\n");
printf ("	<style>\n");
printf ("		iframe {width: 100%%; min-width: 800px; height:500px}\n");
printf ("	</style>\n");
printf ("\n");
printf ("</head>\n");
printf ("\n");
printf ("<body>\n");
printf ("\n");


showMenu("busca",username);



printf("<table border=\"0\">\n");
printf("<tr>\n");
	printf("<td class=\"under_menu\">\n");
	printf("<!--<img src=\"images/Busca.jpg\" />-->\n");
	printf("<!--<span class=\"bold\" style=\"font-size: 15pt; font-family: Arial\">\n");
		printf("Procure por um paciente e selecione a a&ccedil;&atilde;o desejada\n");
	printf("</span>-->\n");
	printf("<form action=\"searchPatient.cgi\" method=\"get\" target=\"resultado\">\n");
		printf("<div align=\"center\">\n");
		printf("<table border=\"0\" style=\"width: 100%%\" cellspacing=\"0\" cellpadding=\"0\">\n");
		printf("<tr>\n");
			printf("<td>\n");
				printf("<table border=\"0\" style=\"width: 500px\">\n");
				printf("<tr style=\"color:white;font-weight:bold\">\n");
					printf("<td style=\"font-size:10pt;\">Crit&eacute;rio:</td>\n");
					printf("<td style=\"font-size:10pt;\">Modo:</td>\n");
					printf("<td style=\"font-size:10pt;\">Valor:</td>\n");
				printf("</tr>\n");
				printf("<tr>\n");
					printf("<td>\n");
						printf("<select name=\"criterio\">\n");
							printf("<option value=\"numeroGeral\">N&uacute;mero Geral</option>\n");
							printf("<option value=\"nomeCompleto\">Nome do Paciente</option>\n");
							printf("<option value=\"nomeMae\">Nome da M&atilde;e</option>\n");
						printf("</select>\n");
					printf("</td>\n");
					printf("<td>\n");
						printf("<select name=\"filtro\">\n");
							printf("<option value=\"contendo\" selected=\"selected\">contendo</option>\n");
							printf("<option value=\"igual\">&eacute; igual a</option>\n");
						printf("</select>\n");
					printf("</td>\n");
					printf("<td><input type=\"text\" name=\"valor\" size=\"35\" /></td>\n");
				printf("</tr>\n");
				printf("<!--<tr>\n");
					printf("<td colspan=\"3\" style=\"color:blue\">Deixe o campo <b>valor</b> em branco para listar todos os pacientes</td>\n");
				printf("</tr>-->\n");
				printf("<!--<tr>\n");
					printf("<td colspan=\"3\"><input type=\"checkbox\" name=\"matchCase\" value=\"\" disabled=\"disabled\" /> Diferenciar mai&uacute;sculas e\n"); printf("min&uacute;sculas</td>\n");
				printf("</tr>-->\n");
				printf("<tr>\n");
					printf("<td></td>\n");
					printf("<td></td>\n");
					printf("<td class=\"right\">\n");
						printf("<input type=\"submit\" value=\"Buscar\" />\n");
						printf("<input type=\"submit\" name=\"modo\" value=\"Listar todos\" />\n");
						printf("</td>\n");
				printf("</tr>\n");
				printf("</table>\n");
			printf("</td>\n");
		printf("</tr>\n");
		printf("<tr>\n");
			printf("<td height=\"15\"></td>\n");
		printf("</tr>\n");
		printf("<tr>\n");
			printf("<td><iframe src=\"searchPatient.cgi?modo=listagem&uid=%s\" frameborder=\"0\" name=\"resultado\" marginwidth=\"0\" marginheight=\"0\" style=\"width:100%%\"></iframe></td>\n", username);
printf("		</tr>\n");
printf("		\n");
		printf("</table>\n");
		printf("</div>\n");
	printf("</form>\n");
	printf("</td>\n");
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
