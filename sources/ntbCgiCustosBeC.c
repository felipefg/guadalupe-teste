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
	char *numeroGeral;
	//CGI process
	
	cgi_init();
	cgi_process_form();
	username = cgi_param("uid");
	numeroGeral = cgi_param("pid");

	cgi_init_headers();
	
/*pagina html questionario custo parte B e C*/

printf ("<html>\n");
printf ("<head>\n");
printf ("	<title>Questionário Custos - Partes B e C</title>\n");
printf ("	<link rel=\"stylesheet\" type=\"text/css\" href=\"css/main.css\">\n");
printf ("	<link rel=\"stylesheet\" type=\"text/css\" href=\"css/menu.css\">\n");
printf ("	<link rel=\"stylesheet\" type=\"text/css\" href=\"css/form.css\">\n");
printf ("	<script language=javascript src=\"js/funcoes.js\"></script>\n");
printf ("	<script language=javascript src=\"js/validar.js\"></script>\n");
printf ("\n");
printf ("	<script>\n");
printf ("	tabFields= new Array(26);\n");
printf ("\n");
printf ("	tabFields[0] = [\"resultado_exames\", \"01 - Você tem o resultado dos exames?\"];\n");
printf ("	tabFields[1] = [\"quantas_vezes_veio_ao_posto\", \"02 - Quantas vezes veio ao posto para pegar os resultados dos exames?\"];\n");
printf ("	tabFields[2] = [\"como_veio_ao_posto\", \"03 - Como você veio ao posto? Em qual transporte?\"];\n");
printf ("	tabFields[3] = [\"custo_transporte\", \"03.1 - Quanto custou o transporte?\"];\n");
printf ("	tabFields[4] = [\"acompanhado\", \"04 - Você está acompanhado?\"];\n");
printf ("	tabFields[5] = [\"saida_casa\", \"05 - Que horas você saiu de casa?\"];\n");
printf ("	tabFields[6] = [\"chegada_posto\", \"06 - Que horas você chegou no posto?\"];\n");
printf ("	tabFields[7] = [\"viu_medico\", \"07 - Que horas você viu o médico?\"];\n");
printf ("	tabFields[8] = [\"tempo_total\", \"08 - Quanto tempo levou desde que você saiu de casa at&eacute; ver o m&eacute;dico?\"];\n");
printf ("	tabFields[9] = [\"segunda_amostra_escarro\", \"09 - Quando você teve que trazer a 2ª amostra de escarro há alguns dias, em que horário você escarrou no potinho?\"];\n");
printf ("	tabFields[10] = [\"horario_escarrou\", \"10 - Que horas você acordou no dia de escarrar pela segunda vez no potinho?\"];\n");
printf ("	tabFields[11] = [\"antibioticos\", \"11 - Você recebeu uma receita com antibióticos?\"];\n");
printf ("	tabFields[12] = [\"rx\", \"12 - Você pediu para fazer um RX?\"];\n");
printf ("	tabFields[13] = [\"comeu_bebeu\", \"13 - Desde que você saiu de casa, você comeu ou bebeu alguma coisa? Quanto custou?\"];\n");
printf ("	tabFields[14] = [\"pagar_algo_posto\", \"14 - Você teve que pagar algo aqui no posto?\"];\n");
printf ("	tabFields[15] = [\"ganhar_dinheiro\", \"15 - Deixou de ganhar dinheiro hoje para poder vir ao posto? Quanto deixou de ganhar?\"];\n");
printf ("	tabFields[16] = [\"resultado_exames_escarro\", \"16 - Você já sabe o resutado dos exames de escarro?\"];\n");
printf ("	tabFields[17] = [\"registro_programa_tratamento_tb\", \"17 - Se o paciente tiver TB: Você foi registrado no programa de tratamento de TB?\"];\n");
printf ("	tabFields[18] = [\"tempo_doente_diferente\", \"19 - Há quanto tempo você estava sentindo-se diferente ou doente,antes de vir ao posto?\"];\n");
printf ("	tabFields[19] = [\"outra_unidade_saude\", \"20 - Antes de você ser diagnosticado no posto, você foi a alguma outra unidade de saúde?\"];\n");
printf ("	tabFields[20] = [\"qual\", \"Este local era:\"];\n");
printf ("	tabFields[21] = [\"pagar_algo_posto\", \"18 - Você teve que pagar algo aqui no posto?\"];\n");
printf ("	tabFields[22] = [\"registro_programa_tratamento_tb\", \"21 - Se o paciente tiver TB: Você foi registrado no programa de tratamento de TB?\"];\n");
printf ("\n");
printf ("	function inicializaOcultos(tabela)\n");
printf ("	{\n");
printf ("		if(tabela == \"parteB\")\n");
printf ("			document.getElementById(tabela).rows[3].style.display = \"none\";//custo do transporte(parte B)\n");
printf ("		else\n");
printf ("		{\n");
printf ("			document.getElementById(tabela).rows[3].style.display = \"none\";//Se o paciente tiver TB: Você foi registrado no programa de tratamento de TB?(parte C)\n");
printf ("			document.getElementById(tabela).rows[4].style.display = \"none\";//outra unidade de saude(parte C)\n");
printf ("		}\n");
printf ("	}\n");
printf ("	</script>\n");
printf ("\n");
printf ("</head>\n");
printf ("<body onLoad=\"inicializaOcultos('parteB');inicializaOcultos('parteC');\">\n");

showMenu("custosBC",username);

printf ("\n");
printf ("<div align=\"center\">\n");
printf ("\n");
printf ("	<h3>Projeto - Novos Métodos Diagnósicos em TB pulmonar - Policlinica Augusto Amaral Peixoto-SMS-RJ</br></h3>\n");
printf ("	<h4>Questionário Custos</h4>\n");
printf ("	<i>(aplicar em 1 a cada 4 pacientes incluídos)</i>\n");
printf ("\n");
printf ("	<br /><br />\n");
printf ("\n");
printf ("	<form name=\"check\" method=\"post\" action=\"addPatientInfo.cgi\" onSubmit=\"return validar_custos_b_e_c (this)\">\n");
printf ("	\n");
printf ("	<!-- --><input type=\"hidden\" name=\"form\" value=\"custosBeC\" />\n");
printf ("		\n");
printf ("		<b>Parte B</b>\n");
printf ("		<br /><br />\n");
printf ("\n");
printf ("		<!-- Numero Geral -->\n");
printf ("		\n");
printf ("	<!-- --><b>N&uacute;mero Geral : </b><input name=\"pid\" type=\"text\" value=\"%s\" size=\"6\" readonly=\"readonly\">\n",numeroGeral);
printf ("\n");
printf ("	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<br><br>\n");
printf ("		\n");
printf ("		<table border=\"0\" id=\"parteB\" class=\"tabela custo\">\n");
printf ("		\n");
printf ("		<!-- RESULTADO DOS EXAMES -->	\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td><script>document.write(tabFields[0][1])</script></td>\n");
printf ("			<td><input name=\"resultadoExames\" type=\"radio\" value=\"sim\">Sim</td>\n");
printf ("			<td><input name=\"resultadoExames\" type=\"radio\" value=\"nao\">Não</td>\n");
printf ("			<td></td>\n");
printf ("\n");
printf ("			<td></td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- QUANTAS VEZES VEIO AO POSTO -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td><script>document.write(tabFields[1][1])</script></td>\n");
printf ("			<td><input name=\"quantasVezesVeioPosto\" type=\"radio\" value=\"uma\">1</td>\n");
printf ("			<td><input name=\"quantasVezesVeioPosto\" type=\"radio\" value=\"duas\">2</td>\n");
printf ("\n");
printf ("			<td><input name=\"quantasVezesVeioPosto\" type=\"radio\" value=\"tres\">3</td>\n");
printf ("			<td><input name=\"quantasVezesVeioPosto\" type=\"radio\" value=\"quatro_ou_mais\">4+</td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- COMO VEIO AO POSTO -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td><script>document.write(tabFields[2][1])</script></td>\n");
printf ("			<td><input name=\"comoVeioPosto\" type=\"radio\" value=\"pe\" onClick=\"ocultaLinha('parteB', 3)\">A pé</td>\n");
printf ("\n");
printf ("			<td><input name=\"comoVeioPosto\" type=\"radio\" value=\"onibus\" onClick=\"exibeLinhaOculta('parteB', 3)\">Ônibus</td>\n");
printf ("			<td colspan=\"2\"><input name=\"comoVeioPosto\" type=\"radio\" value=\"taxi_carro\" onClick=\"exibeLinhaOculta('parteB', 3)\">Táxi/carro</td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- CUSTO DO TRANSPORTE -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td><script>document.write(tabFields[3][1])</script></td>\n");
printf ("			<td colspan=\"2\">R$ <input name=\"custoTransporteB\" type=\"text\" maxlength=\"3\" size=\"1\" onBlur=\"validarCampoNumerico(this)\">,00</td>\n");
printf ("\n");
printf ("			<td></td>\n");
printf ("			<td></td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- ACOMPANHADO -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td><script>document.write(tabFields[4][1])</script></td>\n");
printf ("			<td><input name=\"acompanhadoB\" type=\"radio\" value=\"sim\" onClick=\"numeroAcompanhantesB.value = ''; \">Sim</td>\n");
printf ("			<td><input name=\"acompanhadoB\" type=\"radio\" value=\"nao\" onClick=\"numeroAcompanhantesB.value='NA'; numeroAcompanhantesB.readOnly = true\">Não</td>\n");
printf ("\n");
printf ("			<td colspan=\"2\">Nº de pessoas: <input name=\"numeroAcompanhantesB\" type=\"text\" maxlength=\"2\" size=\"1\" onBlur=\"validarCampoNumerico(this)\"></td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- HORARIO SAIU DE CASA -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td><script>document.write(tabFields[5][1])</script></td>\n");
printf ("			<td colspan=\"4\">Hora: <input name=\"horaSaidaCasaB\" type=\"text\" maxlength=\"2\" size=\"1\" onKeyUp=\"if(this.value.length == 2) minutoSaidaCasaB.focus();\" onBlur=\"validarCampoNumerico(this);validarHora(this);validar_tempo_de_viagem_custos_A(horaSaidaCasaB,minutoSaidaCasaB,horaChegadaPostoB,minutoChegadaPostoB,horaMedicoB,minutoMedicoB,horaTotalB,minutoTotalB);\">:<input name=\"minutoSaidaCasaB\" type=\"text\" maxlength=\"2\" size=\"1\" onKeyUp=\"if(this.value.length == 2) horaChegadaPostoB.focus();\" onBlur=\"validarCampoNumerico(this);validarMinuto(this);validar_tempo_de_viagem_custos_A(horaSaidaCasaB,minutoSaidaCasaB,horaChegadaPostoB,minutoChegadaPostoB,horaMedicoB,minutoMedicoB,horaTotalB,minutoTotalB);\"></td>\n");
printf ("		</tr>\n");
printf ("\n");
printf ("		\n");
printf ("		<!-- HORARIO CHEGOU NO POSTO -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td><script>document.write(tabFields[6][1])</script></td>\n");
printf ("			<td colspan=\"4\">Hora: <input name=\"horaChegadaPostoB\" type=\"text\" maxlength=\"2\" size=\"1\" onKeyUp=\"if(this.value.length == 2) minutoChegadaPostoB.focus();\" onBlur=\"validarCampoNumerico(this);validarHora(this);validar_tempo_de_viagem_custos_A(horaSaidaCasaB,minutoSaidaCasaB,horaChegadaPostoB,minutoChegadaPostoB,horaMedicoB,minutoMedicoB,horaTotalB,minutoTotalB);\">:<input name=\"minutoChegadaPostoB\" type=\"text\" maxlength=\"2\" size=\"1\" onKeyUp=\"if(this.value.length == 2) horaMedicoB.focus();\" onBlur=\"validarCampoNumerico(this);validarMinuto(this);validar_tempo_de_viagem_custos_A(horaSaidaCasaB,minutoSaidaCasaB,horaChegadaPostoB,minutoChegadaPostoB,horaMedicoB,minutoMedicoB,horaTotalB,minutoTotalB);\"></td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- HORARIO MEDICO -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("\n");
printf ("			<td><script>document.write(tabFields[7][1])</script></td>\n");
printf ("			<td colspan=\"4\">Hora: <input name=\"horaMedicoB\" type=\"text\" maxlength=\"2\" size=\"1\" onKeyUp=\"if(this.value.length == 2) minutoMedicoB.focus();\" onBlur=\"validarCampoNumerico(this);validarHora(this);validar_tempo_de_viagem_custos_A(horaSaidaCasaB,minutoSaidaCasaB,horaChegadaPostoB,minutoChegadaPostoB,horaMedicoB,minutoMedicoB,horaTotalB,minutoTotalB);\">:<input name=\"minutoMedicoB\" type=\"text\" maxlength=\"2\" size=\"1\" onKeyUp=\"if(this.value.length == 2) horaEscarro.focus();\" onBlur=\"validarCampoNumerico(this);validarMinuto(this);validar_tempo_de_viagem_custos_A(horaSaidaCasaB,minutoSaidaCasaB,horaChegadaPostoB,minutoChegadaPostoB,horaMedicoB,minutoMedicoB,horaTotalB,minutoTotalB);\"></td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- TEMPO TOTAL -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td><script>document.write(tabFields[8][1])</script></td>\n");
printf ("			<td colspan=\"4\">Tempo total: <input name=\"horaTotalB\" type=\"text\" maxlength=\"2\" size=\"1\" readonly=\"readonly\">h e<input name=\"minutoTotalB\" type=\"text\" maxlength=\"2\" size=\"1\" readonly=\"readonly\">min.</td>\n");
printf ("\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- SEGUNDA AMOSTRA DE ESCARRO -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td class=\"wrap\"><script>document.write(tabFields[9][1])</script></td>\n");
printf ("			<td colspan=\"4\">Hora: <input name=\"horaEscarro\" type=\"text\" maxlength=\"2\" size=\"1\" onKeyUp=\"if(this.value.length == 2) minutoEscarro.focus();\" onBlur=\"validarCampoNumerico(this);validarHora(this);validar_hora_escarro (horaEscarro,minutoEscarro,horaAcordouEscarro,minutoAcordouEscarro);\">:<input name=\"minutoEscarro\" type=\"text\" maxlength=\"2\" size=\"1\" onKeyUp=\"if(this.value.length == 2) horaAcordouEscarro.focus();\" onBlur=\"validarCampoNumerico(this);validarMinuto(this);validar_hora_escarro (horaEscarro,minutoEscarro,horaAcordouEscarro,minutoAcordouEscarro);\"></td>\n");
printf ("		</tr>	\n");
printf ("		\n");
printf ("		<!-- HORARIO QUE ACORDOU PARA ESCARRAR NO POTINHO -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("\n");
printf ("			<td><script>document.write(tabFields[10][1])</script></td>\n");
printf ("			<td colspan=\"4\">Hora: <input name=\"horaAcordouEscarro\" type=\"text\" maxlength=\"2\" size=\"1\" onKeyUp=\"if(this.value.length == 2) minutoAcordouEscarro.focus();\" onBlur=\"validarCampoNumerico(this);validarHora(this);validar_hora_escarro (horaEscarro,minutoEscarro,horaAcordouEscarro,minutoAcordouEscarro);\">:<input name=\"minutoAcordouEscarro\" type=\"text\" maxlength=\"2\" size=\"1\" onKeyUp=\"if(this.value.length == 2) this.blur();\" onBlur=\"validarCampoNumerico(this);validarMinuto(this);validar_hora_escarro (horaEscarro,minutoEscarro,horaAcordouEscarro,minutoAcordouEscarro);\"></td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- ANTIBIOTICO -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td><script>document.write(tabFields[11][1])</script></td>\n");
printf ("			<td><input name=\"receitaAntibioticos\" type=\"radio\" value=\"sim\">Sim</td>\n");
printf ("\n");
printf ("			<td><input name=\"receitaAntibioticos\" type=\"radio\" value=\"nao\">Não</td>\n");
printf ("			<td></td>\n");
printf ("			<td></td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- PEDIDO RAIO-X -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td><script>document.write(tabFields[12][1])</script></td>\n");
printf ("			<td><input name=\"pediuRX\" type=\"radio\" value=\"sim\">Sim</td>\n");
printf ("\n");
printf ("			<td><input name=\"pediuRX\" type=\"radio\" value=\"nao\">Não</td>\n");
printf ("			<td></td>\n");
printf ("			<td></td>\n");
printf ("		</tr>	\n");
printf ("		\n");
printf ("		<!-- COMEU E/OU BEBEU -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td class=\"wrap\"><script>document.write(tabFields[13][1])</script></td>\n");
printf ("			<td><input name=\"comeuBebeuB\" type=\"radio\" value=\"sim\" onclick=\"custoComidaBebidaB.readOnly = false;custoComidaBebidaB.value=''\">Sim</td>\n");
printf ("\n");
printf ("			<td><input name=\"comeuBebeuB\" type=\"radio\" value=\"nao\" onclick=\"custoComidaBebidaB.value='0'; custoComidaBebidaB.readOnly = true\">Não</td>\n");
printf ("			<td colspan=\"2\">R$ <input name=\"custoComidaBebidaB\" type=\"text\" maxlength=\"3\" size=\"1\" onBlur=\"validarCampoNumerico(this)\">,00</td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- PAGOU ALGO NO POSTO -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td><script>document.write(tabFields[14][1])</script></td>\n");
printf ("			<td><input name=\"pagarPostoB\" type=\"radio\" value=\"sim\" onclick=\"custoPostoB.readOnly = false;custoPostoB.value=''\">Sim</td>\n");
printf ("\n");
printf ("			<td><input name=\"pagarPostoB\" type=\"radio\" value=\"nao\" onclick=\"custoPostoB.value='0'; custoPostoB.readOnly = true\">Não</td>\n");
printf ("			<td colspan=\"2\">R$ <input name=\"custoPostoB\" type=\"text\" maxlength=\"3\" size=\"1\" onBlur=\"validarCampoNumerico(this)\">,00</td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- DEIXOU DE GANHAR DINHEIRO -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td class=\"wrap\"><script>document.write(tabFields[15][1])</script></td>\n");
printf ("			<td><input name=\"deixouGanharDinheiroB\" type=\"radio\" value=\"sim\" onclick=\"quantoDeixouGanharB.readOnly = false;quantoDeixouGanharB.value=''\">Sim</td>\n");
printf ("\n");
printf ("			<td><input name=\"deixouGanharDinheiroB\" type=\"radio\" value=\"nao\" onclick=\"quantoDeixouGanharB.value='0'; quantoDeixouGanharB.readOnly = true\">Não</td>\n");
printf ("			<td colspan=\"2\">R$ <input name=\"quantoDeixouGanharB\" type=\"text\" maxlength=\"3\" size=\"1\" onBlur=\"validarCampoNumerico(this)\">,00</td>\n");
printf ("		</tr>	\n");
printf ("		\n");
printf ("		<!-- RESULTADO DOS EXAMES DE ESCARRO -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td><script>document.write(tabFields[16][1])</script></td>\n");
printf ("			<td><input name=\"resultadoExameEscarro\" type=\"radio\" value=\"sim\">Sim</td>\n");
printf ("\n");
printf ("			<td><input name=\"resultadoExameEscarro\" type=\"radio\" value=\"nao\">Não</td>\n");
printf ("			<td></td>\n");
printf ("			<td></td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- REGISTRO PROGRAMA DE TRATAMENTO DE TB -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td class=\"wrap\"><script>document.write(tabFields[17][1])</script></td>\n");
printf ("			<td><input name=\"programaTB\" type=\"radio\" value=\"sim\">Sim</td>\n");
printf ("\n");
printf ("			<td><input name=\"programaTB\" type=\"radio\" value=\"nao\">Não</td>\n");
printf ("			<td></td>\n");
printf ("			<td></td>\n");
printf ("		</tr>\n");
printf ("		</table>\n");
printf ("		\n");
printf ("		<br /><br />\n");
printf ("		\n");
printf ("		<b>Parte C</b>\n");
printf ("		<br />\n");
printf ("\n");
printf ("		<i>(Em caso de diagnótico de TB pulmonar)</i>\n");
printf ("		\n");
printf ("		<table border=\"0\" id=\"parteC\" class=\"tabela custo\">\n");
printf ("		\n");
printf ("		<!-- PAGOU ALGO NO POSTO -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td><script>document.write(tabFields[21][1])</script></td>\n");
printf ("			<td width=\"10%%\"><input name=\"pagarPostoC\" type=\"radio\" value=\"sim\" onclick=\"custoPostoC.readOnly = false;custoPostoC.value=''\">Sim</td>\n");
printf ("			<td width=\"10%%\"><input name=\"pagarPostoC\" type=\"radio\" value=\"nao\" onclick=\"custoPostoC.value='0'; custoPostoC.readOnly = true\">Não</td>\n");
printf ("\n");
printf ("			<td width=\"12%%\">R$ <input name=\"custoPostoC\" type=\"text\" maxlength=\"3\" size=\"1\" onBlur=\"validarCampoNumerico(this)\">,00</td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- TEMPO SE SENTINDO DIFERENTE/DOENTE -->\n");
printf ("\n");
printf ("		<tr>\n");
printf ("			<td class=\"wrap\"><script>document.write(tabFields[18][1])</script></td>\n");
printf ("			<td colspan=\"3\">Semanas: <input name=\"tempoDoente\" type=\"text\" maxlength=\"2\" size=\"1\" onBlur=\"validarCampoNumerico(this)\"></td>\n");
printf ("\n");
printf ("		</tr>\n");
printf ("\n");
printf ("		<!-- OUTRA UNIDADE DE SAUDE -->\n");
printf ("\n");
printf ("		<tr>\n");
printf ("			<td class=\"wrap\"><script>document.write(tabFields[19][1])</script></td>\n");
printf ("			<td><input name=\"outraUnidadeSaude\" type=\"radio\" value=\"sim\" onClick=\"exibeLinhaOculta('parteC', 3);exibeLinhaOculta('parteC', 4)\">Sim</td>\n");
printf ("			<td><input name=\"outraUnidadeSaude\" type=\"radio\" value=\"nao\" onClick=\"ocultaLinha('parteC', 3);ocultaLinha('parteC', 4)\">Não</td>\n");
printf ("\n");
printf ("			<td></td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- QUAL? -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td><script>document.write(tabFields[22][1])</script></td>\n");
printf ("			<td><input name=\"naturezaLocal\" type=\"radio\" value=\"publico\" onClick=\"qual_outro.disabled = true; qual_outro.value='';\">Público</td>\n");
printf ("			<td><input name=\"naturezaLocal\" type=\"radio\" value=\"privado\" onClick=\"qual_outro.disabled = true; qual_outro.value='';\">Privado</td>\n");
printf ("\n");
printf ("			<td><input name=\"naturezaLocal\" type=\"radio\" value=\"rezadeira\" onClick=\"qual_outro.disabled = true; qual_outro.value='';\">Rezadeira</td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td>&nbsp;</td>\n");
printf ("			<td colspan=\"3\"><input name=\"naturezaLocal\" type=\"radio\" value=\"rezadeira\" onClick=\"qual_outro.disabled = false; qual_outro.value='';qual_outro.focus();\">Outro: <input name=\"qual_outro\" type=\"text\" maxlength=\"50\" size=\"5\" readOnly=\"true\"></td>\n");
printf ("		</tr>\n");
printf ("		</table>\n");
printf ("		\n");
printf ("		<br /><br />\n");
printf ("\n");
printf ("		\n");
printf ("		Avaliado por: <input name=\"avaliadorEnfermeiroBeC\" type=\"text\" maxlength=\"100\" size=\"25\">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf ("		Cadastrado por: <input name=\"quemCadastrou\" type=\"text\" readonly=\"readonly\" value=\"%s\" size=\"25\">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\r\n",username);
printf ("		Data: <input name=\"diaCustoBC\" type=\"text\" maxlength=\"2\" size=\"2\" onKeyUp=\"if(this.value.length == 2)this.blur();\" onChange=\"if(validarDia(this))mesCustoBC.focus();\">/<input type=\"text\" name=\"mesCustoBC\" maxlength=\"2\" size=\"2\" onKeyUp=\"if(this.value.length == 2)this.blur();\" onChange=\"if(validarMes(this))anoCustoBC.focus();\">/<input type=\"text\" name=\"anoCustoBC\" maxlength=\"4\" size=\"4\" onKeyUp=\"if(this.value.length == 4)this.blur();\" onChange=\"validarAno(this);\" onBlur=\"validarQualquerData(diaCustoBC,mesCustoBC,anoCustoBC)\"></td>\n");
printf ("\n");
printf ("\n");
printf ("	<!--    ENVIAR / LIMPAR     -->\n");
printf ("\n");
printf ("	<br><br>\n");
printf ("\n");
printf ("	<input value=\"Limpar Formulário\" type=\"reset\">\n");
printf ("	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf ("	<input type=\"submit\" value=\"Enviar Formul&aacute;rio\">\n");
printf ("	<br><br>\n");
printf ("	\n");
printf ("	</form>\n");
printf ("</div>\n");
printf ("\n");
printf ("</body>\n");
printf ("</html>");

/*****************************************************/

	cgi_end();
	
	return 0;
}

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/* $RCSfile$ */
