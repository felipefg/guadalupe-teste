/*
	Universidade Federal do Rio de Janeiro
	Escola Politecnica
	Departamento de Engenharia Eletronica e de Computacao
	
	Laboratorio de Processamento de Sinais
	Projeto Neural TB
	Autor: Igor Cunha Braganca

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
	
	char *numeroGeral;
	//char *cagePositivo;

	//CGI process
	
	cgi_init();
	cgi_process_form();
	username = cgi_param("uid");
	
	numeroGeral = cgi_param("pid");
	//cagePositivo = cgi_param("cage");

	cgi_init_headers();

	//HTML

printf ("<html>\n");
printf ("<head>\n");
printf ("	<title>Projeto TB Adapt - Preencha todos os campos do formul&aacute;rio abaixo</title>\n");
printf ("	<link rel=\"stylesheet\" type=\"text/css\" href=\"css/main.css\">\n");
printf ("	<link rel=\"stylesheet\" type=\"text/css\" href=\"css/menu.css\">\n");
printf ("	<link rel=\"stylesheet\" type=\"text/css\" href=\"css/form.css\">\n");
printf ("	<script language=javascript src=\"js/funcoes.js\"></script>\n");
printf ("	<script language=javascript src=\"js/validar.js\"></script>\n");
printf ("	<script>/* Funcao que  oculta as linhas do formulario que nao deverao se vistas em seu carregamento inicial */\n");
printf ("	\n");
printf ("	\n");
printf ("	tabFields= new Array(26);\n");
printf ("	tabFields[0] = [\"inclusao\", \"Crit&eacute;rios de inclus&atilde;o:\"];\n");
printf ("	tabFields[1] = [\"especimes_respiratorios\", \"Data da coleta dos DOIS esp&eacute;cimes respirat&oacute;rios:\"];\n");
printf ("	tabFields[2] = [\"cicatriz_bcg\", \"Cicatriz de BCG presente?(Checar delt&oacute;ide direito):\"];\n");
printf ("	tabFields[3] = [\"resultado_leitura\", \"Resultado da leitura (mil&iacute;metros de endura&ccedil;&atilde;o):\"];\n");
printf ("	tabFields[4] = [\"aplicacao_data\", \"Data da aplica&ccedil;&atilde;o da prova tubercul&iacute;nica (dia/m&ecirc;s/ano):\"];\n");
printf ("	tabFields[5] = [\"leitura_data\", \"Data da leitura (dia/m�s/ano):\"];\n");
printf ("	tabFields[6] = [\"pt_1dose\", \"PT 1&170; dose Leitor:\"];\n");
printf ("	tabFields[7] = [\"tb_anterior\", \"01 - Tratamento de TB anterior:\"];\n");
printf ("	tabFields[8] = [\"inh\", \"01.1 - NH:\"];\n");
printf ("	tabFields[9] = [\"rif\", \"01.2 - RIF:\"];\n");
printf ("	tabFields[10] = [\"esquema\", \"01.3 - Qual esquema?\"];\n");
printf ("	tabFields[11] = [\"quimio\", \"02 - Quimioprofilaxia:\"];\n");
printf ("	tabFields[12] = [\"cage_positivo\",\"03 - Cage positivo: (Verificar no questionario Triagem)\"];\n");
printf ("	tabFields[13] = [\"inh1\", \"03.1 - INH:\"];\n");
printf ("	tabFields[14] = [\"rif1\", \"03.2 - RIF\"];\n");
printf ("	tabFields[15] = [\"data_quimio\", \"03.4 - Data da Quimioprofilaxia:\"];\n");
printf ("	tabFields[16] = [\"desfecho\", \"03.5 - Desfecho:\"];\n");
printf ("	tabFields[17] = [\"hiv_teste\", \"04 - HIV teste:\"];\n");
printf ("	tabFields[18] = [\"data_antihiv\", \"05 - Data do anti-HIV:\"];\n");
printf ("	tabFields[19] = [\"exame_fisico\", \"07 - Exame f&iacute;sico normal:\"];\n");
printf ("	tabFields[20] = [\"exame_fisico_anormal\", \"07.1 - Descreva as altera&ccedil;&otilde;es:\"];\n");
printf ("	tabFields[21] = [\"prob_tb_ativa\", \"08 - Probabilidade de TB ativa:\"];\n");
printf ("	tabFields[22] = [\"prob_tb_ativa_sem_rx_baar\", \"09 - Qual a probabilidade do diagn&oacute;stico de TB pulmonar ativa sem avaliar RX de t&oacute;rax ou BAAR?\"];\n");
printf ("	tabFields[23] = [\"prob_tb_ativa_rx\", \"10 - Probabilidade de TB ativa ao avaliar o RXT:\"];\n");
printf ("	tabFields[24] = [\"cavitacao\", \"10.1 - Cavita&ccedil;&atilde;o\"];\n");
printf ("	tabFields[25] = [\"padrao_tipico\", \"10.2 - Padr&atilde;o t&oacute;pico (infiltrado em lobo(s) superior(es) e/ou segmento apical de lobo inferior):\"];\n");
printf ("	tabFields[26] = [\"compativel\", \"10.3 - Compat&iacute;vel (alargamento mediastinal ou linf.  hilar , padr&atilde;o miliar,ou derrame pleural):\"];\n");
printf ("	tabFields[27] = [\"atipico\", \"10.4 - At&iacute;pico (qualquer outro padr&atilde;o):\"];\n");
printf ("	tabFields[28] = [\"nsa\", \"\"];\n");
printf ("	tabFields[29] = [\"baixa_prioridade\", \"10.1 - Em caso de baixa probabilidade de TB ativa responda:\"];\n");
printf ("	tabFields[30] = [\"data_rx\", \"11 - Data do RX:\"];\n");
printf ("	tabFields[31] = [\"prob_rx_sem_bacterio\", \"12 - Diagn&oacute;stico de probabilidade tendo informa&ccedil;&atilde;o sobre o RX de t&oacute;rax mas sem conhecimento dos resultados bacteriol&oacute;gicos:\"];\n");
printf ("	tabFields[32] = [\"prob_tb_ativa_com_rx_sem_baar\", \"13 - Qual a probabilidade do diagn&oacute;stico de TB pulmonar ativa com a avalia&ccedil;&atilde;o do RX de t&oacute;rax e sem o BAAR?\"];\n");
printf ("	tabFields[33] = [\"bacilos_negativas\", \"16 - Caso as duas baciloscopias iniciais sejam negativas, qual seria o diagn&oacute;stico de probabilidade de TB?\"];\n");
printf ("	tabFields[34] = [\"prob_tb_ativa_com_rx_baar\", \"17 - Qual a probabilidade do diagn&oacutestico de TB pulmonar ativa com a avalia&ccedil;&atilde;o do RX de t&oacute;rax e do BAAR?\"];\n");
printf ("	tabFields[35] = [\"desfecho_consulta_inicial\", \"18 - Desfecho da consulta inicial:\"];\n");
printf ("	tabFields[36] = [\"caso_tratamento_tb\", \"19 - Em caso de tratamento para TB(marque qual):\"];\n");
printf ("	tabFields[37] = [\"fatores_de_risco\", \"20 - Fatores de risco para TBP MDR:\"];\n");
printf ("	tabFields[38] = [\"comorbidades\", \"06 - Comorbidades:\"];\n");
printf ("	\n");
printf ("	\n");
printf ("	var tabValores= new Array(\"Masculino\", \"Feminino\", \"Presente\", \"Ausente\", \"Ignorado\",\"Sim\", \"N&etilde;o\", \"Branco\", \"N&etilde;o-branco\", \"Negro\", \"Mulato\", \"Índio\", \"Asiático\", \"Outro\", \"Casado\", \"Solteiro\", \"Separado\", \"Viúvo\", \"Pulmão\", \"Pleura\", \"G&acirc;nglio\");\n");
printf ("\n");
printf ("function inicializaOcultos(tabela)\n");
printf ("{\n");
printf ("	\n");
printf ("	document.getElementById(tabela).rows[2].style.display = \"none\";//INH\n");
printf ("	document.getElementById(tabela).rows[3].style.display = \"none\";//RIF\n");
printf ("	document.getElementById(tabela).rows[4].style.display = \"none\";//esquema\n");
/*
if(cagePositivo != NULL)
{
	if(strcmp(cagePositivo,"Sim") != 0)
	{
	printf ("	document.getElementById(tabela).rows[8].style.display = \"none\";//INH\n");
	printf ("	document.getElementById(tabela).rows[9].style.display = \"none\";//RIF\n");
	printf ("	document.getElementById(tabela).rows[10].style.display = \"none\";//data da quimio\n");
	printf ("	document.getElementById(tabela).rows[11].style.display = \"none\";//desfecho\n");
	}
}
else
{
	printf ("	document.getElementById(tabela).rows[8].style.display = \"none\";//INH\n");
	printf ("	document.getElementById(tabela).rows[9].style.display = \"none\";//RIF\n");
	printf ("	document.getElementById(tabela).rows[10].style.display = \"none\";//data da quimio\n");
	printf ("	document.getElementById(tabela).rows[11].style.display = \"none\";//desfecho\n");
}
*/
printf ("	document.getElementById(tabela).rows[8].style.display = \"none\";//INH\n");
printf ("	document.getElementById(tabela).rows[9].style.display = \"none\";//RIF\n");
printf ("	document.getElementById(tabela).rows[10].style.display = \"none\";//data da quimio\n");
printf ("	document.getElementById(tabela).rows[11].style.display = \"none\";//desfecho\n");
printf ("	document.getElementById(tabela).rows[22].style.display = \"none\";//alteracao exame fixico\n");
printf ("	document.getElementById(tabela).rows[27].style.display = \"none\";//cavitacao\n");
printf ("	document.getElementById(tabela).rows[28].style.display = \"none\";//padrao topico\n");
printf ("	document.getElementById(tabela).rows[29].style.display = \"none\";//compativel\n");
printf ("	document.getElementById(tabela).rows[30].style.display = \"none\";//atipico\n");
printf ("	document.getElementById(tabela).rows[31].style.display = \"none\";//NSA\n");
printf ("	document.getElementById(tabela).rows[32].style.display = \"none\";//caso baixa probabilidade\n");
printf ("	document.getElementById(tabela).rows[33].style.display = \"none\";//caso baixa probabilidade\n");
printf ("	document.getElementById(tabela).rows[39].style.display = \"none\";//baar positivo\n");
printf ("	document.getElementById(tabela).rows[41].style.display = \"none\";//baar positivo\n");
printf ("	document.getElementById(tabela).rows[45].style.display = \"none\";//caso tratamento TB\n");
printf ("	document.getElementById(tabela).rows[46].style.display = \"none\";//fatores de risco para tbp mdr\n");
printf ("	document.getElementById(tabela).rows[47].style.display = \"none\";//fatores de risco para tbp mdr*\n");
printf ("}\n");
printf ("</script>	\n");
printf ("</head>\n");
printf ("\n");
printf ("<body onLoad=\"inicializaOcultos('tabelaGenpoint')\">\n");
printf ("\n");

showMenu("consulta",username);

printf ("\n");
printf ("<div align=\"center\">\n");
printf ("<form name=\"check\" method=\"post\" action=\"addPatientInfo.cgi\" onSubmit=\"return validar_consulta_medica(this)\">\n");
printf ("\n");
printf ("	<span style=\"font-size: 13pt\" class=\"bold\"><br />Projeto - Novos M&eacute;todos Diagn&oacute;sicos em TB pulmonar - Policlinica Augusto Amaral Peixoto - SMS - RJ</span>\n");
printf ("	<div align=\"center\">\n");
printf ("		<br /><br />\n");
printf ("	<!-- --><input type=\"hidden\" name=\"form\" value=\"consultaMedica\" />\n");
printf ("	<!-- --><div class=\"h4\"><b>N&#186; Geral (TB Adapt): <input name=\"pid\" size=\"6\" type=\"text\" value=\"%s\" readonly=\"readonly\"> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n",numeroGeral);
printf ("		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
printf ("		Data de inclus&atilde;o&nbsp;:&nbsp;<input maxlength=\"2\" size=\"2\" name=\"dia_inclusao\" onKeyUp=\"if(this.value.length == 2)if(validarDia(this))mes_inclusao.focus();\" onChange=\"if(validarDia(this))mes_inclusao.focus();\">&nbsp;/\n");
printf ("											<input maxlength=\"2\" size=\"2\" name=\"mes_inclusao\" onKeyUp=\"if(this.value.length == 2)this.blur();\" onChange=\"if(validarMes(this))ano_inclusao.focus();\">&nbsp;/\n");
printf ("											<input maxlength=\"4\" size=\"4\" name=\"ano_inclusao\" onKeyUp=\"if(this.value.length == 4)this.blur();\" onChange=\"validarAno(this);\" onBlur=\"validarQualquerData(dia_inclusao,mes_inclusao,ano_inclusao)\">&nbsp; dd/mm/aaaa<br><br>\n");
printf ("\n");
printf ("	<table border=\"0\" cellspacing=\"0\" cellpadding=\"0\" class=\"tabela\" id=\"tabelaGenpoint\">\n");
printf ("	\n");
printf ("	<tr>\n");
printf ("		<td colspan=\"4\" class=\"label\"><b>Consulta M&eacute;dica</b></td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- TRATAMENTO ANTERIOR PARA TB -->\n");
printf ("	<tr class=\"impar\">\n");
printf ("		<td><script>document.write(tabFields[7][1]);</script></td>\n");
printf ("		<td><input name=\"tratamentoAnteriorTB\" type=\"radio\" value=\"sim\" onClick=\"exibeLinhaOculta('tabelaGenpoint', 2);exibeLinhaOculta('tabelaGenpoint', 3);exibeLinhaOculta('tabelaGenpoint', 4)\"> Sim</td>\n");
printf ("		<td><input name=\"tratamentoAnteriorTB\" type=\"radio\" value=\"nao\" onClick=\"ocultaLinha('tabelaGenpoint', 2);ocultaLinha('tabelaGenpoint', 3);ocultaLinha('tabelaGenpoint', 4)\">N&atilde;o</td>\n");
printf ("		<td><input name=\"tratamentoAnteriorTB\" type=\"radio\" value=\"ignorado\" onClick=\"ocultaLinha('tabelaGenpoint', 2);ocultaLinha('tabelaGenpoint', 3);ocultaLinha('tabelaGenpoint', 4)\"> Ignorado</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- INH -->\n");
printf ("	\n");
printf ("	<tr class=\"impar\">\n");
printf ("		<td><script>document.write(tabFields[8][1]);</script></td>\n");
printf ("		<td><input name=\"inh\" type=\"radio\" value=\"sim\">Sim</td>\n");
printf ("		<td><input name=\"inh\" type=\"radio\" value=\"nao\">N&atilde;o</td>\n");
printf ("		<td><input name=\"inh\" type=\"radio\" value=\"ignorado\">Ignorado</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- RIF -->\n");
printf ("	\n");
printf ("	<tr class=\"impar\">\n");
printf ("		<td><script>document.write(tabFields[9][1]);</script></td>\n");
printf ("		<td><input name=\"rif\" type=\"radio\" value=\"sim\">Sim</td>\n");
printf ("		<td><input name=\"rif\" type=\"radio\" value=\"nao\">N&atilde;o</td>\n");
printf ("		<td><input name=\"rif\" type=\"radio\" value=\"ignorado\">Ignorado</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- ESQUEMA -->\n");
printf ("	\n");
printf ("	<tr class=\"impar\">\n");
printf ("		<td><script>document.write(tabFields[10][1]);</script></td>\n");
printf ("		<td colspan=\"3\"><input name=\"qualEsquema\" type=\"text\" size=\"40\" maxlength=\"200\"></td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<tr>\n");
printf ("		<td colspan=\"4\" class=\"label\"><b>Quimioprofilaxia Pr&eacute;via para TB:</b></td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- QUIMIOPROFILAXIA -->\n");
printf ("	\n");
printf ("	<tr class=\"par\">\n");
printf ("		<td><script>document.write(tabFields[11][1]);</script></td>\n");
printf ("		<td><input name=\"quimioprofilaxia\" type=\"radio\" value=\"sim\">Sim</td>\n");
printf ("		<td><input name=\"quimioprofilaxia\" type=\"radio\" value=\"nao\">N&atilde;o</td>\n");
printf ("		<td><input name=\"quimioprofilaxia\" type=\"radio\" value=\"ignorado\">Ignorado</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!--  CAGE POSITIVO  -->\n");
/*
printf ("	<tr class=\"impar\">\n");
printf ("		<td><script>document.write(tabFields[12][1]);</script>:</td>\n");
printf ("		<td colspan=\"3\"><input  name=\"cagePositivo\" type=\"text\" value=\"%s\" readonly=\"readonly\">",cagePositivo);
printf ("	</tr>\n");
*/
printf ("	<tr class=\"impar\">\n");
printf ("		<td><script>document.write(tabFields[12][1]);</script></td>\n");
printf ("		<td><input  name=\"cagePositivo\" type=\"radio\" value=\"sim\" onClick=\"exibeLinhaOculta('tabelaGenpoint', 8);exibeLinhaOculta('tabelaGenpoint', 9);exibeLinhaOculta('tabelaGenpoint', 10);exibeLinhaOculta('tabelaGenpoint', 11)\">Sim</td>\n");
printf ("		<td><input  name=\"cagePositivo\" type=\"radio\" value=\"nao\" onClick=\"ocultaLinha('tabelaGenpoint', 8); ocultaLinha('tabelaGenpoint', 9); ocultaLinha('tabelaGenpoint', 10); ocultaLinha('tabelaGenpoint', 11)\">N&atilde;o</td>\n");
printf ("		<td><input  name=\"cagePositivo\" type=\"radio\" value=\"ignorado\" onClick=\"ocultaLinha('tabelaGenpoint', 8); ocultaLinha('tabelaGenpoint', 9); ocultaLinha('tabelaGenpoint', 10); ocultaLinha('tabelaGenpoint', 11)\">Ignorado</td>\n");
printf ("	</tr>\n");

printf ("	\n");
printf ("	<!-- INH -->\n");
printf ("	\n");
printf ("	<tr class=\"impar\">\n");
printf ("		<td><script>document.write(tabFields[13][1]);</script></td>\n");
printf ("		<td><input name=\"inh1\" type=\"radio\" value=\"sim\">Sim</td>\n");
printf ("		<td><input name=\"inhCagePositivo\" type=\"radio\" value=\"nao\">N&atilde;o</td>\n");
printf ("		<td><input name=\"inhCagePositivo\" type=\"radio\" value=\"ignorado\">Ignorado</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- RIF -->\n");
printf ("	\n");
printf ("	<tr class=\"impar\">\n");
printf ("		<td><script>document.write(tabFields[14][1]);</script>:</td>\n");
printf ("		<td><input name=\"rifCagePositivo\" type=\"radio\" value=\"sim\">Sim</td>\n");
printf ("		<td><input name=\"rifCagePositivo\" type=\"radio\" value=\"nao\">N&atilde;o</td>\n");
printf ("		<td><input name=\"rifCagePositivo\" type=\"radio\" value=\"ignorado\">Ignorado</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- DATA DA QUIMIOPROFILAXIA -->\n");
printf ("	\n");
printf ("	<tr class=\"impar\">\n");
printf ("		<td><script>document.write(tabFields[15][1]);</script></td>\n");
printf ("		<td colspan=\"3\"><input name=\"mes_quimio\" type=\"text\" maxlength=\"2\" size=\"2\" onKeyUp=\"if(this.value.length == 2)this.blur();\" onChange=\"if(validarMes(this))ano_quimio.focus();\"> (m&ecirc;s) / <input name=\"ano_quimio\" type=\"text\" maxlength=\"4\" size=\"4\" onKeyUp=\"if(this.value.length == 4)this.blur();\" onChange=\"validarAno(this);\" onBlur=\"validarQualquerData(1,mes_quimio,ano_quimio);validarDataExame(0,mes_quimio,ano_quimio)\"> (ano)</td>\n");
printf ("	</tr>\n");
printf ("	<!-- DESFECHO -->\n");
printf ("	\n");
printf ("	<tr class=\"impar\">\n");
printf ("		<td><script>document.write(tabFields[16][1]);</script></td>\n");
printf ("		<td><input name=\"desfechoQuimio\" type=\"radio\" value=\"completou\">Completou</td>\n");
printf ("		<td><input name=\"desfechoQuimio\" type=\"radio\" value=\"abandonou\">Abandonou</td>\n");
printf ("		<td><input name=\"desfechoQuimio\" type=\"radio\" value=\"ignorado\">Ignorado</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<tr>\n");
printf ("		<td class=\"label\" colspan=\"4\"><b>HIV/AIDS:</b></td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- HIV TESTE -->\n");
printf ("	\n");
printf ("	<tr class=\"par\">\n");
printf ("		<td><script>document.write(tabFields[17][1]);</script>:</td>\n");
printf ("		<td><input name=\"testeHIV\" type=\"radio\" value=\"positivo\">Positivo</td>\n");
printf ("		<td><input name=\"testeHIV\" type=\"radio\" value=\"negativo\">Negativo</td>\n");
printf ("		<td><input name=\"testeHIV\" type=\"radio\" value=\"ignorado\">N&atilde;o realizado/<br>Resultado desconhecido</br></td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- DATA ANTI-HIV -->\n");
printf ("	\n");
printf ("	<tr class=\"impar\">\n");
printf ("		<td><script>document.write(tabFields[18][1]);</script></td>\n");
printf ("		<td colspan=\"3\"><input name=\"dia_antihiv\" type=\"text\" maxlength=\"2\" size=\"2\" onKeyUp=\"if(this.value.length == 2)this.blur();\" onChange=\"if(validarDia(this))mes_antihiv.focus();\"> / <input name=\"mes_antihiv\" type=\"text\" maxlength=\"2\" size=\"2\" onKeyUp=\"if(this.value.length == 2)this.blur();\" onChange=\"if(validarMes(this))ano_antihiv.focus();\"> / <input name=\"ano_antihiv\" type=\"text\" maxlength=\"4\" size=\"4\" onKeyUp=\"if(this.value.length == 4)this.blur();\" onChange=\"validarAno(this);\" onBlur=\"validarQualquerData(dia_antihiv,mes_antihiv,ano_antihiv);validarDataExame(dia_antihiv,mes_antihiv,ano_antihiv)\"></td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- COMORBIDADES -->\n");
printf ("	\n");
printf ("	<tr class=\"par\">	\n");
printf ("		<td><script>document.write(tabFields[38][1])</script></td>\n");
printf ("		<td><input name=\"comorbidade\" type=\"radio\" value=\"sim\">Sim</td>\n");
printf ("		<td><input name=\"comorbidade\" type=\"radio\" value=\"nao\">N&atilde;o</td>\n");
printf ("		<td><input name=\"comorbidade\" type=\"radio\" value=\"ignorado\">Ignorado</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<tr class=\"par\">\n");
printf ("		<td></td>\n");
printf ("		<td><input name=\"comorbidades\" type=\"checkbox\" value=\"doenca_renal_cronica\">Doen&ccedil;a Renal Cl&iacute;nica</td>\n");
printf ("		<td><input name=\"comorbidades\" type=\"checkbox\" value=\"hepatopatia\">Hepatopatia</td>\n");
printf ("		<td><input name=\"comorbidades\" type=\"checkbox\" value=\"alcoolismo\">Alcoolismo</td>\n");
printf ("	</tr>\n");
printf ("	<tr class=\"par\">\n");
printf ("		<td></td>\n");
printf ("		<td><input name=\"comorbidades\" type=\"checkbox\" value=\"cortidoides\">Uso Cortic&oacute;ides</td>\n");
printf ("		<td><input name=\"comorbidades\" type=\"checkbox\" value=\"neoplasia\">Neoplasia Maligna</td>\n");
printf ("		<td><input name=\"comorbidades\" type=\"checkbox\" value=\"transplante\">Transplante</td>\n");
printf ("	</tr>\n");
printf ("	<tr class=\"par\">\n");
printf ("		<td></td>\n");
printf ("		<td><input name=\"comorbidades\" type=\"checkbox\" value=\"dmnid\">DMNID</td>\n");
printf ("		<td><input name=\"comorbidades\" type=\"checkbox\" value=\"dmid\">DMID</td>\n");
printf ("		<td><input name=\"comorbidades\" type=\"checkbox\" value=\"silicose\">Silicose</td>\n");
printf ("	</tr>\n");
printf ("	<tr class=\"par\">\n");
printf ("		<td></td>\n");
printf ("		<td><input name=\"comorbidades\" type=\"checkbox\" value=\"dpoc\">DPOC</td>\n");
printf ("		<td><input name=\"comorbidades\" type=\"checkbox\" value=\"doenca_renal_cronica\">Doen&ccedil;a Pulmonar Difusa</td>\n");
printf ("		<td><input name=\"comorbidades\" type=\"checkbox\" value=\"doenca_renal_cronica\" onClick=\"if(this.checked){outrascomorbidades.disabled = false;outrascomorbidades.focus();}else{outrascomorbidades.disabled = true}\">Outras:&nbsp;<input name=\"outrascomorbidades\" type=\"text\" size=\"8\" maxlength=\"100\" disabled=\"true\"></td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<tr>\n");
printf ("		<td  class=\"label\" colspan=\"4\"><b>Avalia&ccedil;&atilde;o Cl&iacute;nica:</b></td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- PROBABILIDADE TB ATIVA -->\n");
printf ("	\n");
printf ("	<!-- Exame Fisico -->\n");
printf ("	\n");
printf ("	<tr class=\"impar\">\n");
printf ("		<td><script>document.write(tabFields[19][1]);</script></td>\n");
printf ("		<td><input name=\"exameFisico\" type=\"radio\" value=\"sim\" onClick=\"ocultaLinha('tabelaGenpoint', 22)\">Sim</td>\n");
printf ("		<td><input name=\"exameFisico\" type=\"radio\" value=\"nao\" onClick=\"exibeLinhaOculta('tabelaGenpoint', 22)\">N&atilde;o</td>\n");
printf ("		<td><input name=\"exameFisico\" type=\"radio\" value=\"ignorado\" onClick=\"ocultaLinha('tabelaGenpoint', 22)\">Ignorado</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<tr class=\"impar\">\n");
printf ("		<td><script>document.write(tabFields[20][1]);</script></td>\n");
printf ("		<td colspan=\"3\"><input name=\"alteracoesNoExameFisico\" type=\"text\" size=\"70\"> </td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<tr class=\"par\">\n");
printf ("		<td><script>document.write(tabFields[21][1]);</script></td>\n");
printf ("		<td><input name=\"probTBativa\" type=\"radio\" value=\"alta\">alta (>75%%)</td>\n");
printf ("		<td><input name=\"probTBativa\" type=\"radio\" value=\"media\">m&eacute;dia (entre 25%% e 75%%)</td>\n");
printf ("		<td><input name=\"probTBativa\" type=\"radio\" value=\"baixa\">baixa (<25%%)</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- PROBABILIDADE DE TB SEM RX E BAAR -->\n");
printf ("	\n");
printf ("	<tr class=\"impar\">\n");
printf ("		<td colspan=\"3\" class=\"wrap\"><script>document.write(tabFields[22][1]);</script></td>\n");
printf ("		<td><input name=\"porcentagemProbTBsemRXsemBAAR\" type=\"text\" maxlength=\"3\" size=\"2\" onBlur=\"validarCampoNumerico(this);validarPorcentagem(this)\"> %%</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<tr>\n");
printf ("		<td  class=\"label\" colspan=\"4\"><b>RX de t&oacute;rax (ao entrar no estudo):</b></td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!--PROBABILIDADE TB ATIVA COM RX -->\n");
printf ("	\n");
printf ("	<tr class=\"par\">\n");
printf ("		<td><script>document.write(tabFields[23][1]);</script>:</td>\n");
printf ("		<td><input name=\"probTBativaComRX\" type=\"radio\" value=\"alta\" onClick=\"exibeLinhaOculta('tabelaGenpoint', 27);exibeLinhaOculta('tabelaGenpoint', 28);exibeLinhaOculta('tabelaGenpoint', 29);exibeLinhaOculta('tabelaGenpoint', 30);exibeLinhaOculta('tabelaGenpoint', 31);ocultaLinha('tabelaGenpoint', 32);ocultaLinha('tabelaGenpoint', 33)\">alta</td>\n");
printf ("		<td><input name=\"probTBativaComRX\" type=\"radio\" value=\"media\" onClick=\"exibeLinhaOculta('tabelaGenpoint', 27);exibeLinhaOculta('tabelaGenpoint', 28);exibeLinhaOculta('tabelaGenpoint', 29);exibeLinhaOculta('tabelaGenpoint', 30);exibeLinhaOculta('tabelaGenpoint', 31);ocultaLinha('tabelaGenpoint', 32);ocultaLinha('tabelaGenpoint', 33)\">m&eacute;dia</td>\n");
printf ("		<td><input name=\"probTBativaComRX\" type=\"radio\" value=\"baixa\" onClick=\"ocultaLinha('tabelaGenpoint', 27);ocultaLinha('tabelaGenpoint', 28);ocultaLinha('tabelaGenpoint', 29);ocultaLinha('tabelaGenpoint', 30);ocultaLinha('tabelaGenpoint', 31);exibeLinhaOculta('tabelaGenpoint', 32);exibeLinhaOculta('tabelaGenpoint', 33)\">baixa</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- CAVITACAO -->\n");
printf ("	\n");
printf ("	<tr class=\"par\">\n");
printf ("		<td><script>document.write(tabFields[24][1]);</script>:</td>\n");
printf ("		<td><input name=\"cavitacao\" type=\"radio\" value=\"sim\">Sim</td>\n");
printf ("		<td><input name=\"cavitacao\" type=\"radio\" value=\"nao\">N&atilde;o</td>\n");
printf ("		<td><input name=\"cavitacao\" type=\"radio\" value=\"ignorado\">Ignorado</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- PADRAO TIPICO -->\n");
printf ("\n");
printf ("	<tr class=\"par\">\n");
printf ("		<td class=\"wrap\"><script>document.write(tabFields[25][1]);</script>:</td>\n");
printf ("		<td><input name=\"padraoTipico\" type=\"radio\" value=\"sim\">Sim</td>\n");
printf ("		<td><input name=\"padraoTipico\" type=\"radio\" value=\"nao\">N&atilde;o</td>\n");
printf ("		<td><input name=\"padraoTipico\" type=\"radio\" value=\"ignorado\">Ignorado</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- COMPATIVEL -->\n");
printf ("	\n");
printf ("	<tr class=\"par\">\n");
printf ("		<td class=\"wrap\"><script>document.write(tabFields[26][1]);</script>:</td>\n");
printf ("		<td><input name=\"compativel\" type=\"radio\" value=\"sim\">Sim</td>\n");
printf ("		<td><input name=\"compativel\" type=\"radio\" value=\"nao\">N&atilde;o</td>\n");
printf ("		<td><input name=\"compativel\" type=\"radio\" value=\"ignorado\">Ignorado</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- ATIPICO -->\n");
printf ("	\n");
printf ("	<tr class=\"par\">\n");
printf ("		<td><script>document.write(tabFields[27][1]);</script>:</td>\n");
printf ("		<td><input name=\"atipico\" type=\"radio\" value=\"sim\">Sim</td>\n");
printf ("		<td><input name=\"atipico\" type=\"radio\" value=\"nao\">N&atilde;o</td>\n");
printf ("		<td><input name=\"atipico\" type=\"radio\" value=\"ignorado\">Ignorado</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- NSA -->\n");
printf ("	\n");
printf ("	<tr class=\"par\">\n");
printf ("		<td></td>\n");
printf ("		<td colspan=\"3\"><input name=\"nsa\" type=\"checkbox\" value=\"nsa\">NSA</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- CASO DE BAIXA PRIORIDADE -->\n");
printf ("	\n");
printf ("	<tr class=\"par\">\n");
printf ("		<td><script>document.write(tabFields[29][1]);</script>:\n");
printf ("		<td colspan=\"2\"><input name=\"casoBaixaProbabilidade\" type=\"radio\" value=\"inativa\">TB inativa/seq&uuml;ela</br</td>\n");
printf ("		<td><input name=\"casoBaixaProbabilidade\" type=\"radio\" value=\"outra_doenca\">Outra doen&ccedil;a</td>\n");
printf ("	</tr>\n");
printf ("	<tr class=\"par\">\n");
printf ("		<td></td>\n");
printf ("		<td><input name=\"casoBaixaProbabilidade\" type=\"radio\" value=\"normal\">Normal</td>\n");
printf ("		<td><input name=\"casoBaixaProbabilidade\" type=\"radio\" value=\"ignorado\">Ignorado</td>\n");
printf ("		<td><input name=\"casoBaixaProbabilidade\" type=\"radio\" value=\"nsa\">NSA</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- DATA DO RX -->\n");
printf ("	\n");
printf ("	<tr class=\"impar\">\n");
printf ("		<td><script>document.write(tabFields[30][1]);</script>:</td>\n");
printf ("		<td colspan=\"3\"><input name=\"dia_rx\" type=\"text\" maxlength=\"2\" size=\"2\" onKeyUp=\"if(this.value.length == 2)this.blur();\" onChange=\"if(validarDia(this))mes_rx.focus();\">/<input name=\"mes_rx\" type=\"text\" maxlength=\"2\" size=\"2\" onKeyUp=\"if(this.value.length == 2)this.blur();\" onChange=\"if(validarMes(this))ano_rx.focus();\">/<input name=\"ano_rx\" type=\"text\" maxlength=\"4\" size=\"4\" onKeyUp=\"if(this.value.length == 4)this.blur();\" onChange=\"validarAno(this);\" onBlur=\"validarQualquerData(dia_rx,mes_rx,ano_rx);validarDataExame(dia_rx,mes_rx,ano_rx)\"></td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- PROBABILIDADE COM RX SEM RESULTADOS BACTERIOLOGICOS -->\n");
printf ("	\n");
printf ("	<tr class=\"par\">\n");
printf ("		<td class=\"wrap\"><script>document.write(tabFields[31][1]);</script>:</td>\n");
printf ("		<td colspan=\"3\">\n");
printf ("			<p><input name=\"diagnosticoProbabilidadeRX\" type=\"radio\" value=\"alta_prob\">Alta probabilidade de TB Pulmonar ativa; (>75%%)</p>\n");
printf ("			<p><input name=\"diagnosticoProbabilidadeRX\" type=\"radio\" value=\"media_prob\">M&eacute;dia probabilidade de TB Pulmonar ativa; (entre 25%% e 75%%)</p>\n");
printf ("			<p><input name=\"diagnosticoProbabilidadeRX\" type=\"radio\" value=\"baixa_prob\">Baixa probabilidade de TB Pulmonar ativa; (<25%%)</p>\n");
printf ("			<p><input name=\"diagnosticoProbabilidadeRX\" type=\"radio\" value=\"ignorado\">Ignorado</p>\n");
printf ("		</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- PROBABILIDADE DE TB COM RX E SEM BAAR -->\n");
printf ("	\n");
printf ("	<tr class=\"impar\">\n");
printf ("		<td class=\"wrap\"><script>document.write(tabFields[32][1]);</script>:</td>\n");
printf ("		<td colspan=\"3\"><input name=\"probabilidadeTBcomRXsemBAAR\" type=\"text\" maxlength=\"3\" size=\"2\" onBlur=\"validarCampoNumerico(this);validarPorcentagem(this)\"> %%</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- RESULTADO DA BACILOSCOPIA -->\n");
printf ("	\n");
printf ("	<tr>\n");
printf ("		<td class=\"label\" align=\"left\" colspan=\"4\"><b>Resultado da Baciloscopia:</b></td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<tr class=\"par\">\n");
printf ("		<td align=\"left\">14 - #1</td>\n");
printf ("		<td><input name=\"resultadoBaciloscopia1\" type=\"radio\" value=\"positivo\" onClick=\"exibeLinhaOculta('tabelaGenpoint', 39)\">Positivo</td>\n");
printf ("		<td><input name=\"resultadoBaciloscopia1\" type=\"radio\" value=\"negativo\" onClick=\"ocultaLinha('tabelaGenpoint', 39)\">Negativo</td>\n");
printf ("		<td><input name=\"resultadoBaciloscopia1\" type=\"radio\" value=\"N&atilde;o_realizado\" onClick=\"ocultaLinha('tabelaGenpoint', 39)\">N&atilde;o realizado/<br>Resultado desconhecido</br></td>\n");
printf ("	</tr>\n");
printf ("	<tr class=\"par\">\n");
printf ("		<td align=\"left\">14.1 - Se positivo:</td>\n");
printf ("		<td><input name=\"casoPositivo1\" type=\"radio\" value=\"+\">+</td>\n");
printf ("		<td><input name=\"casoPositivo1\" type=\"radio\" value=\"++\">++</td>\n");
printf ("		<td><input name=\"casoPositivo1\" type=\"radio\" value=\"+++\">+++</td>\n");
printf ("	</tr>\n");
printf ("	<tr class=\"par\">\n");
printf ("		<td align=\"left\">15 - #2</td>\n");
printf ("		<td><input name=\"resultadoBaciloscopia2\" type=\"radio\" value=\"positivo\" onClick=\"exibeLinhaOculta('tabelaGenpoint', 41)\">Positivo</td>\n");
printf ("		<td><input name=\"resultadoBaciloscopia2\" type=\"radio\" value=\"negativo\" onClick=\"ocultaLinha('tabelaGenpoint', 41)\">Negativo</td>\n");
printf ("		<td><input name=\"resultadoBaciloscopia2\" type=\"radio\" value=\"N&atilde;o_realizado\" onClick=\"ocultaLinha('tabelaGenpoint', 41)\">N&atilde;o realizado/<br>Resultado desconhecido</br></td>\n");
printf ("	</tr>\n");
printf ("	<tr class=\"par\">\n");
printf ("		<td align=\"left\">15.1 - Se positivo:</td>\n");
printf ("		<td><input name=\"casoPositivo2\" type=\"radio\" value=\"+\">+</td>\n");
printf ("		<td><input name=\"casoPositivo2\" type=\"radio\" value=\"++\">++</td>\n");
printf ("		<td><input name=\"casoPositivo2\" type=\"radio\" value=\"+++\">+++</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- DUAS BACILOSCOPIAS NEGATIVAS -->\n");
printf ("	\n");
printf ("	<tr class=\"impar\">\n");
printf ("		<td class=\"wrap\"><script>document.write(tabFields[33][1]);</script>:</td>\n");
printf ("		<td colspan=\"3\">\n");
printf ("			<p><input name=\"diagnosticoProbabilidadeCasoDuasNegativas\" type=\"radio\" value=\"alta_prob\">Alta probabilidade de TB Pulmonar ativa; (>75%%)</p>\n");
printf ("			<p><input name=\"diagnosticoProbabilidadeCasoDuasNegativas\" type=\"radio\" value=\"media_prob\">M&eacute;dia probabilidade de TB Pulmonar ativa; (entre 25%% e 75%%)</p>\n");
printf ("			<p><input name=\"diagnosticoProbabilidadeCasoDuasNegativas\" type=\"radio\" value=\"baixa_prob\">Baixa probabilidade de TB Pulmonar ativa; (<25%%)</p>\n");
printf ("			<p><input name=\"diagnosticoProbabilidadeCasoDuasNegativas\" type=\"radio\" value=\"ignorado\">Ignorado</p>\n");
printf ("		</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- PROBABILIDADE DE TB COM RX E BAAR -->\n");
printf ("	\n");
printf ("	<tr class=\"par\">\n");
printf ("		<td class=\"wrap\"><script>document.write(tabFields[34][1]);</script>:</td>\n");
printf ("		<td colspan=\"3\"><input name=\"probabilidadeTBcomRXcomBAAR\" type=\"text\" maxlength=\"3\" size=\"2\" onBlur=\"validarCampoNumerico(this);validarPorcentagem(this)\"> %%</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- DESFECHO DA CONSULTA INICIAL -->\n");
printf ("	\n");
printf ("	<tr class=\"impar\">\n");
printf ("		<td><script>document.write(tabFields[35][1]);</script>:</td>\n");
printf ("		<td colspan=\"3\">\n");
printf ("			<input name=\"desfechoConsultaInicial\" type=\"radio\" value=\"tb_confirmacao\" onClick=\"exibeLinhaOculta('tabelaGenpoint', 45);exibeLinhaOculta('tabelaGenpoint', 46);exibeLinhaOculta('tabelaGenpoint', 47)\">Tratamento impara TB com confirma&ccedil;&atilde;o bacteriol&oacute;gica;\n");
printf ("			<p><input name=\"desfechoConsultaInicial\" type=\"radio\" value=\"tb_probabilidade\" onClick=\"exibeLinhaOculta('tabelaGenpoint', 45);exibeLinhaOculta('tabelaGenpoint', 46);exibeLinhaOculta('tabelaGenpoint', 47)\">Tratamento impara TB por probabilidade;</p>\n");
printf ("			<p><input name=\"desfechoConsultaInicial\" type=\"radio\" value=\"pneumologia\" onClick=\"ocultaLinha('tabelaGenpoint', 45);ocultaLinha('tabelaGenpoint', 46);ocultaLinha('tabelaGenpoint', 47)\">Tratamento na pneumologia de outra patologia N&atilde;o TB;</p>\n");
printf ("			<p><input name=\"desfechoConsultaInicial\" type=\"radio\" value=\"internacao\" onClick=\"ocultaLinha('tabelaGenpoint', 45);ocultaLinha('tabelaGenpoint', 46);ocultaLinha('tabelaGenpoint', 47)\">Transfer&ecirc;ncia impara interna&ccedil;&atilde;o N&atilde;o por TB ou tratamento<br> em outra especialidade</br></p>\n");
printf ("			<p><input name=\"desfechoConsultaInicial\" type=\"radio\" value=\"alta\" onClick=\"ocultaLinha('tabelaGenpoint', 45);ocultaLinha('tabelaGenpoint', 46);ocultaLinha('tabelaGenpoint', 47)\">Alta</p>\n");
printf ("			<p><input name=\"desfechoConsultaInicial\" type=\"radio\" value=\"ignorado\" onClick=\"ocultaLinha('tabelaGenpoint', 45);ocultaLinha('tabelaGenpoint', 46);ocultaLinha('tabelaGenpoint', 47)\">Ignorado</p>\n");
printf ("		</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- CASO TRATAMENTO imparA TB -->\n");
printf ("	\n");
printf ("	<tr class=\"par\">\n");
printf ("		<td><script>document.write(tabFields[36][1]);</script>:</td>\n");
printf ("		<td colspan=\"3\" class=\"wrap\">\n");
printf ("			<p><input name=\"casoTratamentoTB\" type=\"radio\" value=\"tb_virgem\">TB pulmonar (TBP) virgem de tratamento (uso de medicamento &lt; 310 dias);\n");
printf ("			<p><input name=\"casoTratamentoTB\" type=\"radio\" value=\"tb_recidiva\">TB recidiva (completou tratamento tendo sido considerado curado);</p>\n");
printf ("			<p><input name=\"casoTratamentoTB\" type=\"radio\" value=\"tb_retorno\">TB retorno p&oacute;s-abandono (tratou e abandonou antes do t&eacute;rmino);</p>\n");
printf ("			<p><input name=\"casoTratamentoTB\" type=\"radio\" value=\"tb_falencia\">TB fal&ecirc;ncia(em tratamento com BAAR positivo ap&oacute;s 4 meses em paciente usando esquema RHZ ou RHZE ou ap&oacute;s 6 meses em paciente usando esquema alternativo: i.e.: SEEZ)</p>\n");
printf ("		</td>\n");
printf ("	</tr>\n");
printf ("	\n");
printf ("	<!-- FATORES DE RISCO imparA TBP MDR -->\n");
printf ("	\n");
printf ("	<tr class=\"impar\">\n");
printf ("		<td><script>document.write(tabFields[37][1]);</script></td>\n");
printf ("		<td><input name=\"fatoresRisco\" type=\"radio\" value=\"suspeita_recidiva\">Suspeita de recidiva;</td>\n");
printf ("		<td><input name=\"fatoresRisco\" type=\"radio\" value=\"suspeita_falencia\">Suspeita de fal&ecirc;ncia;</td>\n");
printf ("		<td><input name=\"fatoresRisco\" type=\"radio\" value=\"contato_intimo\">Contato intimo de caso de TBP MDR.*</td>\n");
printf ("	</tr>\n");
printf ("	<tr class=\"impar\">\n");
printf ("		<td></td>\n");
printf ("		<td colspan=\"3\" class=\"wrap\">*(reside no mesmo domicilio, ou refere contato di&aacute;rio na comunidade pelo menos nos &uacute;ltimos tr&ecirc;s meses ou dividiu espa&ccedil;o f&iacute;sico na pris&atilde;o ou em hospital)</td>\n");
printf ("	</tr>\n");
printf ("\n");
printf ("	<!-- Observacoes -->\n");
printf ("	<tr class=\"par\">\n");
printf ("		<td colspan=\"1\"> 21 - Observa&ccedil;&otilde;es: </td>\n");
printf ("		<td colspan=\"3\" align=\"center\"><div center><textarea name=\"observacoes\" rows=\"5\" cols=\"50\"></textarea></div></td>\n");
printf ("	</tr>	\n");
printf ("\n");
printf ("	<tr>\n");
printf ("		<td>&nbsp;</td>\n");
printf ("	</tr>\n");
printf ("\n");
printf ("	<tr>\n");
printf ("		<td colspan=\"1\" style=\"text-align:center\">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Avaliado por: <input name=\"avaliador\" type=\"text\"  size=\"25\"></td>\n");
printf ("		<td colspan=\"3\" style=\"text-align:center\">Cadastrado por: <input name=\"quemCadastrou\" type=\"text\" readonly=\"readonly\" value=\"%s\" size=\"25\"></td>\n",username);
printf ("	</tr>\n");
printf ("	\n");
printf ("	<tr>\n");
printf ("		<td>&nbsp;</td>\n");
printf ("	</tr>\n");
printf ("\n");
printf ("	<!--    ENVIAR / Limpar     -->\n");
printf ("	<tr>\n");
printf ("		<td><input value=\"Limpar Formul&aacute;rio\" type=\"reset\" onClick=\"inicializaOcultos('tabelaGenpoint')\"></td>\n");
printf ("		<td></td>\n");
printf ("		<td></td>\n");
printf ("		<td style=\"text-align:right\"><input type=\"submit\" value=\"Enviar Formul&aacute;rio\"></td>\n");
printf ("	</tr>\n");
printf ("	</table>\n");
printf ("</form>\n");
printf ("</div>\n");
printf ("\n");
printf ("</body>\n");
printf ("</html>\n");
printf ("	\n");
	
	cgi_end();
	
	return 0;
}

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/* $RCSfile$ */
