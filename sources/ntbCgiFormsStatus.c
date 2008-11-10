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
 *            CREATE XSL SEARCH FILE                                          *
 ******************************************************************************/
	
	xsl = fopen(PATHFILE, "w");
	
	fprintf(xsl,"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
	fprintf(xsl,"<xsl:stylesheet xmlns:xsl=\"http://www.w3.org/1999/XSL/Transform\" version=\"1.0\"\r\n");
	fprintf(xsl,"				xmlns:fo=\"http://www.w3.org/1999/XSL/Format\"\r\n");
	fprintf(xsl,"				xmlns=\"http://www.w3.org/1999/xhtml\">\r\n");
	fprintf(xsl,"\r\n");
	fprintf(xsl,"<xsl:include href=\"formStatus.xsl\" />\r\n");
	fprintf(xsl,"\r\n");
	
	fprintf(xsl,"<xsl:variable name=\"uid\" select=\"string('%s')\" />\r\n", uid);
	fprintf(xsl,"<xsl:variable name=\"id\" select=\"string('%s')\" />\r\n", pid);
	fprintf(xsl,"\r\n");
	
	fprintf(xsl,"<xsl:template match=\"/\">\r\n");
	//fprintf(xsl,"\r\n");
	//fprintf(xsl,"	<html>\r\n");
	//fprintf(xsl,"	<head>\r\n");
	//fprintf(xsl,"		<link rel=\"stylesheet\" type=\"text/css\" href=\"css/menu.css\" />\r\n");
	//fprintf(xsl,"		<link rel=\"stylesheet\" type=\"text/css\" href=\"css/patientForms.css\" />\r\n");
	//fprintf(xsl,"		<script type=\"javascript\" src=\"js/funcoes.js\"></script>\r\n");
	//fprintf(xsl,"		<title>Projeto Neural TB - Formul&aacute;rios</title>\r\n");
	//fprintf(xsl,"	</head>\r\n");
	//fprintf(xsl,"\r\n");
	//fprintf(xsl,"	<body>\r\n");
	fprintf(xsl,"	<xsl:apply-templates select=\"pacientes/paciente\" />\r\n");
	//fprintf(xsl,"	</body>\r\n");
	//fprintf(xsl,"	</html>\r\n");
	//fprintf(xsl,"	\r\n");
	fprintf(xsl,"</xsl:template>\r\n");
	fprintf(xsl,"\r\n");
	fprintf(xsl,"</xsl:stylesheet>");
	fclose(xsl);
	
/******************************************************************************
 *            PRINTING RESULT                                                 *
 ******************************************************************************/
	
	cgi_init_headers();
	//printf("Content-type: text/html; charset=iso-8859-1\r\n\r\n");
	
	printf("<html>\n");
	printf("<head>\n");
	//printf("\t<meta http-equiv=\"Content-Type\" content=\"text/html; charset=ISO-8859-1\">\n");
	printf("\t<title>Formul&aacute;rios</title>\n");
	
	printf("\t<link rel=\"stylesheet\" type=\"text/css\" href=\"css/menu.css\" />\r\n");
	printf("\t<link rel=\"stylesheet\" type=\"text/css\" href=\"css/patientForms.css\" />\r\n");
	printf("\t<script type=\"javascript\" src=\"js/funcoes.js\"></script>\r\n");
	
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
	printf("<body id=\"result\" onLoad=\"displayResult()\">\n");
	
	
/*
	printf("\t<script type=\"text/javascript\">\n");

// load xml --------------------------------------------------------------------
	
	printf("\
		try //Internet Explorer\n\
		{\n\
			xml = new ActiveXObject(\"Microsoft.XMLDOM\");\n\
		}\n\
		catch(e)\n\
		{\n\
			try //Firefox, Mozilla, Opera, etc.\n\
			{\n\
				xml = document.implementation.createDocument(\"\",\"\",null);\n\
			}\n\
			catch(e) {alert(e.message)}\n\
		}\n\
		try\n\
		{\n\
			xml.async = false;\n\
			xml.load(\"/~psvaiter/neuralTB/pacientesGuadalupe2.xml\");\n\
		}\n\
		catch(e) {alert(e.message)}\n");

// load xsl --------------------------------------------------------------------

	printf("\
		try //Internet Explorer\n\
		{\n\
			xsl = new ActiveXObject(\"Microsoft.XMLDOM\");\n\
		}\n\
		catch(e)\n\
		{\n\
			try //Firefox, Mozilla, Opera, etc.\n\
			{\n\
				xsl = document.implementation.createDocument(\"\",\"\",null);\n\
			}\n\
			catch(e) {alert(e.message)}\n\
		}\n\
		try\n\
		{\n\
			xsl.async = false;\n\
			xsl.load(\"/~psvaiter/neuralTB/xsl/resultado.xsl\");\n\
		}\n\
		catch(e) {alert(e.message)}\n");

// transform XML to XHTML ------------------------------------------------------ adaptar a transformacao tb para FF, e ai fica ok

	printf("\t\tdocument.write(xml.transformNode(xsl));\n");
	printf("\t</script>\n");
*/
	
	printf("</body>\n");
	printf("</html>");
	
/******************************************************************************
 *            FREE MEMORY AND EXIT                                            *
 ******************************************************************************/
	
	cgi_end();
	
	return (ok);
}
