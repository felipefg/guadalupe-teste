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

#include "cgi.h"
#include "ntbFunctions.h"

#define PATHFILE "xml/xsl/filtro.xsl"
#define PATHFILE2 "xml/xsl/resultado.xsl"

int main (void)
{
	FILE *xsl, *xsl2;
	formvars *first;
	char *criterio, *filtro, *modo, *valor, *VALOR, *username;
	
	
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

 	username = cgi_param("uid");
	
	if (!(modo = cgi_param("modo")))
	{
		criterio = cgi_param("criterio");
		filtro = cgi_param("filtro");
		valor = cgi_param("valor");
	}
	
/******************************************************************************
 *            CREATE DISPLAY XSL FILE                                          *
 ******************************************************************************/	
xsl2 = fopen(PATHFILE2, "w");
fprintf(xsl2,"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
fprintf(xsl2,"<xsl:stylesheet xmlns:xsl=\"http://www.w3.org/1999/XSL/Transform\" version=\"1.0\"\n");
fprintf(xsl2,"				xmlns=\"http://www.w3.org/1999/xhtml\">\n");
fprintf(xsl2,"\n");
fprintf(xsl2,"<xsl:include href=\"filtro.xsl\" />\n");
fprintf(xsl2,"\n");
fprintf(xsl2,"<xsl:template match=\"/\">\n");
fprintf(xsl2,"		<xsl:apply-templates select=\"pacientes\" />\n");
fprintf(xsl2,"</xsl:template>\n");
fprintf(xsl2,"\n");
fprintf(xsl2,"\n");
fprintf(xsl2,"<xsl:template match=\"pacientes\">\n");
fprintf(xsl2,"	<table>\n");
fprintf(xsl2,"		<tr>\n");
fprintf(xsl2,"			<th class=\"title3\">Nº Geral</th>\n");
fprintf(xsl2,"			<th class=\"title3\" width=\"40%%\">Paciente</th>\n");
fprintf(xsl2,"			<th class=\"title3\" width=\"30%%\">Nome da Mãe</th>\n");
fprintf(xsl2,"			<th class=\"title3\">Data de Nascimento</th>\n");
fprintf(xsl2,"			<th class=\"title3\">Incluído em</th>\n");
fprintf(xsl2,"			<th class=\"title3\">Visualizar</th>\n");
fprintf(xsl2,"			<th class=\"title3\">Remover</th>\n");
fprintf(xsl2,"			<th class=\"title3\">Editar</th>\n");
fprintf(xsl2,"		</tr>\n");
fprintf(xsl2,"		<xsl:for-each select=\"paciente[@removido = 'nao']\">\n");
fprintf(xsl2,"		<xsl:sort select=\"descendant::nomeCompleto\" />\n");
fprintf(xsl2,"			<xsl:apply-templates select=\"triagem\" />\n");
fprintf(xsl2,"		</xsl:for-each>\n");
fprintf(xsl2,"	</table>\n");
fprintf(xsl2,"</xsl:template>\n");
fprintf(xsl2,"\n");
fprintf(xsl2,"\n");
fprintf(xsl2,"<!-- Criterio inicial de triagem para TB pulmonar -->\n");
fprintf(xsl2,"<xsl:template name=\"filtro\">\n");
fprintf(xsl2,"		<tr>\n");
fprintf(xsl2,"			<td class=\"answer center\"><xsl:value-of select=\"numeroGeral\" /></td>\n");
fprintf(xsl2,"			<td class=\"answer\"><xsl:value-of select=\"nomeCompleto\" /></td>\n");
fprintf(xsl2,"			<td class=\"answer\"><xsl:value-of select=\"nomeMae\" /></td>\n");
fprintf(xsl2,"			<td class=\"answer center\"><xsl:value-of select=\"concat(dia_nascimento,'/', mes_nascimento,'/', ano_nascimento)\" /></td>\n");
fprintf(xsl2,"			<td class=\"answer center\"><xsl:value-of select=\"concat(dia_inclusao,'/', mes_inclusao,'/', ano_inclusao)\" /></td>\n");
fprintf(xsl2,"			<td class=\"answer center\"><a href=\"viewPatient.cgi?pid={numeroGeral}\"><img alt=\"Ver\" src=\"images/ver.gif\" style=\"border: 0px\" /></a></td>\n");
fprintf(xsl2,"<td class=\"answer center\"><a href=\"removePatient.cgi?numeroGeral={numeroGeral}\" onclick=\"return confirm('Deseja remover o paciente?');\"><img alt=\"Remover\" src=\"images/remove.gif\" style=\"border: 0px\" /></a></td>\n");
fprintf(xsl2,"			<td class=\"answer center\"><a href=\"\" onclick=\"window.open ('formsStatus.cgi?uid=%s&amp;pid={numeroGeral}','formularios','toolbar=no, width=300, height=280,resizable=yes'); return false;\"><img src=\"images/forms.gif\" style=\"border: 0px\" /></a></td>\n",username);
fprintf(xsl2,"</tr></xsl:template>\n");
fprintf(xsl2,"\n");
fprintf(xsl2,"</xsl:stylesheet>\n");
fclose(xsl2);
	
/******************************************************************************
 *            CREATE XSL SEARCH FILE                                          *
 ******************************************************************************/
	
	xsl = fopen(PATHFILE, "w");
	
	fprintf(xsl,"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
	fprintf(xsl,"<xsl:stylesheet version=\"1.0\" xmlns:xsl=\"http://www.w3.org/1999/XSL/Transform\">\n\n");
	
	
	fprintf(xsl,"<!-- Criterio inicial de triagem para TB pulmonar -->\n");
	fprintf(xsl,"<xsl:template match=\"triagem\">\n");
	
	if ((modo) || (!valor)){
	fprintf(xsl,"\t<xsl:call-template name=\"filtro\" />\n");
	}
	
	// é igual a
	else if (!(strcmp(filtro, "igual"))) {
	fprintf(xsl,"\t<xsl:if test=\"%s ='%s'\">\n", criterio, valor);
	fprintf(xsl,"\t\t<xsl:call-template name=\"filtro\" />\n");
	fprintf(xsl,"\t</xsl:if>\n");
	}
	
	// contendo
	else if (!(strcmp(filtro, "contendo"))) {
	VALOR = to_uppercase(valor);
	//translate() is an XPath Core Function that allows us to perform an uppercase function
	fprintf(xsl,"\t<xsl:if test=\"contains(translate(%s,'abcdefghijklmnopqrstuvwxyz','ABCDEFGHIJKLMNOPQRSTUVWXYZ'),'%s') = true()\">\n", criterio, VALOR);
	fprintf(xsl,"\t\t<xsl:call-template name=\"filtro\" />\n");
	fprintf(xsl,"\t</xsl:if>\n");
	}
	
	fprintf(xsl,"</xsl:template>\n\n");
	
	
	fprintf(xsl,"</xsl:stylesheet>\n");
	fclose(xsl);
	
/******************************************************************************
 *            PRINTING RESULT                                                 *
 ******************************************************************************/
	
	cgi_init_headers(); //printf("Content-type: text/html\r\n\r\n");
	
	printf("<html>\n");
	printf("<head>\n");
	printf("\t<title>Busca Conclu&iacute;da</title>\n");
	printf("	<script src=\"js/jquery.js\"></script>\n");
	printf("	<script src=\"js/colors.js\"></script>\n");
	printf("\t<link rel=\"stylesheet\" type=\"text/css\" href=\"css/main.css\" />\n"); 
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
			xml = loadXMLDoc(\"xml/pacientesGuadalupe.xml?t=\" + new Date().getTime());\n\
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
	printf("<body id=\"result\" onLoad=\"displayResult()\">\n");
	printf("</body>\n");
	printf("</html>");
	
/******************************************************************************
 *            FREE MEMORY AND EXIT                                            *
 ******************************************************************************/
	
	cgi_end();
	
	return 0;
}
