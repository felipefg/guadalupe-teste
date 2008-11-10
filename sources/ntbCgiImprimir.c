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


#define PATHFILE "xml/xsl/resultado.xsl"

int main (void)
{
	FILE *xsl;
	//size_t len;
	//char xmlSearchResultFilePath[FILE_NAME_MAX];
	//char healthCenter[HEALTH_CENTER_NAME_MAX];
	formvars *first;
	char *pid;
	
	
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
	
	pid = cgi_param("pid");
	
/******************************************************************************
 *            CREATE XSL SEARCH FILE                                          *
 ******************************************************************************/
	
	xsl = fopen(PATHFILE, "w");
	
	fprintf(xsl,"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
	fprintf(xsl,"\r\n");
	fprintf(xsl,"<xsl:stylesheet xmlns:xsl=\"http://www.w3.org/1999/XSL/Transform\" version=\"1.0\"\r\n");
	fprintf(xsl,"				xmlns:fo=\"http://www.w3.org/1999/XSL/Format\"\r\n");
	fprintf(xsl,"				xmlns=\"http://www.w3.org/1999/xhtml\">\r\n");
	fprintf(xsl,"\r\n");
	fprintf(xsl,"<xsl:include href=\"fullPatientDetails2.xsl\" />\r\n");
	fprintf(xsl,"\r\n");
	fprintf(xsl,"<xsl:template match=\"/\">\r\n");
	fprintf(xsl,"\r\n");
	fprintf(xsl,"		\r\n");
	fprintf(xsl,"		<xsl:apply-templates select=\"pacientes\" />\r\n");
	fprintf(xsl,"		\r\n");
	fprintf(xsl,"</xsl:template>\r\n");
	fprintf(xsl,"\r\n");
	fprintf(xsl,"\r\n");
	fprintf(xsl,"<xsl:template match=\"pacientes\">\r\n");
	fprintf(xsl,"	<!-- Tags' values -->\r\n");
	fprintf(xsl,"	<xsl:for-each select=\"paciente[@removido = 'nao']\">\r\n");
	fprintf(xsl,"	<xsl:sort select=\"descendant::nomeCompleto\" />\r\n");
	fprintf(xsl,"		<xsl:if test=\"triagem/numeroGeral = '%s'\">\r\n", pid);


	fprintf(xsl,"			<table>\r\n");
	fprintf(xsl,"			<tr>\r\n");
	fprintf(xsl,"				<th colspan=\"2\">Critério Inicial de Triagem para TB</th>\r\n");
	fprintf(xsl,"			</tr>\r\n");
	fprintf(xsl,"			<xsl:apply-templates select=\"triagem\" />\r\n");

/*	fprintf(xsl,"			<tr>\r\n");
	fprintf(xsl,"				<td colspan=\"2\" height=\"10\"></td>\r\n");
	fprintf(xsl,"			</tr>\r\n");
	fprintf(xsl,"			\r\n");
	fprintf(xsl,"			<tr>\r\n");
	fprintf(xsl,"				<th colspan=\"2\">Questionário de Custos - Parte A</th>\r\n");
	fprintf(xsl,"			</tr>\r\n");
	fprintf(xsl,"			<xsl:apply-templates select=\"custosA\" />\r\n");
	fprintf(xsl,"			<tr>\r\n");
	fprintf(xsl,"				<td colspan=\"2\" height=\"10\"></td>\r\n");
	fprintf(xsl,"			</tr>\r\n");
	fprintf(xsl,"			\r\n");
	fprintf(xsl,"			<tr>\r\n");
	fprintf(xsl,"				<th colspan=\"2\">Consulta Médica</th>\r\n");
	fprintf(xsl,"			</tr>\r\n");
	fprintf(xsl,"			<xsl:apply-templates select=\"consultaMedica\" />\r\n");
	fprintf(xsl,"			<tr>\r\n");	
	fprintf(xsl,"				<td class=\"title3\" colspan=\"2\" height=\"10\"></td>\r\n");
	fprintf(xsl,"			</tr>\r\n");
	fprintf(xsl,"			\r\n");
	fprintf(xsl,"			<tr>\r\n");
	fprintf(xsl,"				<th class=\"title3\" colspan=\"2\">Questionário de Custos - Partes B e C</th>\r\n");
	fprintf(xsl,"			</tr>\r\n");
	fprintf(xsl,"			<xsl:apply-templates select=\"custosBeC\" />\r\n");
	fprintf(xsl,"			<tr>\r\n");
	fprintf(xsl,"				<td class=\"title3\" colspan=\"2\" height=\"10\"></td>\r\n");
	fprintf(xsl,"			</tr>\r\n");
	fprintf(xsl,"			\r\n");
	fprintf(xsl,"			<tr>\r\n");
	fprintf(xsl,"				<th colspan=\"2\">Follow Up - 90 dias</th>\r\n");
	fprintf(xsl,"			</tr>\r\n");
	fprintf(xsl,"			<xsl:apply-templates select=\"followUp\" />\r\n");
	fprintf(xsl,"			<tr>\r\n");
	fprintf(xsl,"				<td colspan=\"2\" height=\"10\"></td>\r\n");
	fprintf(xsl,"			</tr>\r\n");
	fprintf(xsl,"			\r\n");
	fprintf(xsl,"			<tr>\r\n");
	fprintf(xsl,"				<th class=\"title3\">Gráfico de Grupo</th>\r\n");
	fprintf(xsl,"				<td><!--<a href=\"{concat(graficoGrupo, triagem/numeroGeral)}\" target=\"_blank\">Visualizar</a>--></td>\r\n");
	fprintf(xsl,"			</tr>\r\n");
*/
	fprintf(xsl,"			</table>\r\n");
	fprintf(xsl,"			<br /><br />\r\n");
	fprintf(xsl,"		</xsl:if>\r\n");
	fprintf(xsl,"	</xsl:for-each>\r\n");
	fprintf(xsl,"	\r\n");
	fprintf(xsl,"</xsl:template>\r\n");
	fprintf(xsl,"\r\n");
	fprintf(xsl,"</xsl:stylesheet>\r\n");
	fclose(xsl);
	
/******************************************************************************
 *            PRINTING RESULT                                                 *
 ******************************************************************************/
	
	cgi_init_headers();
	//printf("Content-type: text/html; charset=iso-8859-1\r\n\r\n");
	
	printf("<html>\n");
	printf("<head>\n");
	//printf("\t<meta http-equiv=\"Content-Type\" content=\"text/html; charset=ISO-8859-1\">\n");
	printf("\t<title>Vers�o de Impress�o</title>\n");
	printf("\t<link rel=\"stylesheet\" type=\"text/css\" href=\"css/imprimir.css\" />\n"); 
	printf("\
	<script>\n\
		function loadXMLDoc(fname)\n\
		{\n\
			var xmlDoc;\n\
			\n\
			// code for IE\n\
			if (window.ActiveXObject)\n\
			{\n\
				xmlDoc = new ActiveXObject(\"Microsoft.XMLDOM\");\n\
			}\n\
			\n\
			// code for Mozilla, Firefox, Opera, etc.\n\
			else if (document.implementation && document.implementation.createDocument)\n\
			{\n\
				xmlDoc = document.implementation.createDocument(\"\",\"\",null);\n\
			}\n\
			else\n\
			{\n\
				alert('O seu navegador n&atilde;o tem suporte a este script');\n\
			}\n\
			xmlDoc.async = false;\n\
			xmlDoc.load(fname);\n\
			return(xmlDoc);\n\
		}\n\
		\n\
		function displayResult()\n\
		{\n\
			xml = loadXMLDoc(\"xml/pacientesGuadalupe.xml\");\n\
			xsl = loadXMLDoc(\"xml/xsl/resultado.xsl\");\n\
			\n\
			// code for IE\n\
			if (window.ActiveXObject)\n\
			{\n\
				x = xml.transformNode(xsl);\n\
				document.getElementById(\"result\").innerHTML = x;\n\
			}\n\
			\n\
			// code for Mozilla, Firefox, Opera, etc.\n\
			else if (document.implementation && document.implementation.createDocument)\n\
			{\n\
				xsltProcessor = new XSLTProcessor();\n\
				xsltProcessor.importStylesheet(xsl);\n\
				resultDocument = xsltProcessor.transformToFragment(xml,document);\n\
				document.getElementById(\"result\").appendChild(resultDocument);\n\
			}\n\
		}\n\
	</script>\n");






	printf("</head>\n");
	printf("<body id=\"result\" onLoad=\"displayResult(), window.print()\">\n");
	printf("</body>\n");
	printf("</html>");
	
/******************************************************************************
 *            FREE MEMORY AND EXIT                                            *
 ******************************************************************************/
	
	cgi_end();
	
	return (ok);
}
