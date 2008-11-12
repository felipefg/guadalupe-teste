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
printf ("	<title>Lista de Pacientes</title>\n");
printf ("\n");
	printf("\t<link rel=\"stylesheet\" type=\"text/css\" href=\"css/main.css\" />\n"); 
	printf("	<script type=\"text/javascript\" src=\"js/jquery.js\"></script>\n");
	printf("	<script type=\"text/javascript\" src=\"js/colors.js\"></script>\n");
printf ("\n");
printf ("	<script>\n");
printf ("		function loadXMLDoc(fname)\n");
printf ("		{\n");
printf ("			var xmlDoc;\n");
printf ("			\n");
printf ("			// code for IE\n");
printf ("			if (window.ActiveXObject)\n");
printf ("			{\n");
printf ("				xmlDoc = new ActiveXObject(\"Microsoft.XMLDOM\");\n");
printf ("			}\n");
printf ("			\n");
printf ("			// code for Mozilla, Firefox, Opera, etc.\n");
printf ("			else if (document.implementation && document.implementation.createDocument)\n");
printf ("			{\n");
printf ("				xmlDoc = document.implementation.createDocument(\"\",\"\",null);\n");
printf ("			}\n");
printf ("			else\n");
printf ("			{\n");
printf ("				alert('O seu navegador n&atilde;o tem suporte a este script');\n");
printf ("			}\n");
printf ("			xmlDoc.async = false;\n");
printf ("			xmlDoc.load(fname);\n");
printf ("			return(xmlDoc);\n");
printf ("		}\n");
printf ("		\n");
printf ("		function displayResult()\n");
printf ("		{\n");
printf ("			xml = loadXMLDoc(\"xml/pacientesGuadalupe.xml?t=\" + new Date().getTime());\n");
printf ("			xsl = loadXMLDoc(\"xml/xsl/listar.xsl\");\n");
printf ("			\n");
printf ("			// code for IE\n");
printf ("			if (window.ActiveXObject)\n");
printf ("			{\n");
printf ("				x = xml.transformNode(xsl);\n");
printf ("				document.getElementById(\"result\").innerHTML = x;\n");
printf ("			}\n");
printf ("			\n");
printf ("			// code for Mozilla, Firefox, Opera, etc.\n");
printf ("			else if (document.implementation && document.implementation.createDocument)\n");
printf ("			{\n");
printf ("				xsltProcessor = new XSLTProcessor();\n");
printf ("				xsltProcessor.importStylesheet(xsl);\n");
printf ("				resultDocument = xsltProcessor.transformToFragment(xml,document);\n");
printf ("				document.getElementById(\"result\").appendChild(resultDocument);\n");
printf ("			}\n");
printf ("		}\n");
printf ("	</script>	\n");
printf ("	</head>\n");
printf ("\n");
printf ("<body id=\"result\" onLoad=\"displayResult()\">\n");
printf ("</body>\n");
printf ("</html>\n");

/*****************************************************/

	cgi_end();
	
	return 0;
}

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/* $RCSfile$ */
