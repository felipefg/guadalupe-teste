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
	
/*pagina html questionario custo parte A*/

printf ("<html>\n");
printf ("<head>\n");
printf ("	<title>Questionário Custos - Parte A</title>\n");
printf ("	<link rel=\"stylesheet\" type=\"text/css\" href=\"css/main.css\">\n");
printf ("	<link rel=\"stylesheet\" type=\"text/css\" href=\"css/menu.css\">\n");
printf ("	<link rel=\"stylesheet\" type=\"text/css\" href=\"css/form.css\">\n");
printf ("	<script language=javascript src=\"js/funcoes.js\"></script>\n");
printf ("	<script language=javascript src=\"js/validar.js\"></script>\n");
printf ("	<script>\n");
printf ("	tabFields= new Array(26);\n");
printf ("	tabFields[0] = [\"onde_mora\", \"01 - Onde você mora?\"];\n");
printf ("	tabFields[1] = [\"como_veio_posto\", \"02 - Como você veio ao posto? Em qual transporte?\"];\n");
printf ("	tabFields[2] = [\"custo_transporte\", \"02.1 - Se você não veio a pé, quanto custou o transporte?\"];\n");
printf ("	tabFields[3] = [\"companhia\", \"03 - Você está acompanhado?\"];\n");
printf ("	tabFields[4] = [\"saiu_casa\", \"04 - Que horas você saiu de casa?\"];\n");
printf ("	tabFields[5] = [\"chegou_posto\", \"05 - Que horas você chegou no posto?\"];\n");
printf ("	tabFields[6] = [\"horario_medico\", \"06 - Que horas você viu o médico?\"];\n");
printf ("	tabFields[7] = [\"tempo_saiu_de_casa\", \"07 - Quanto tempo levou desde que você saiu de casa at&eacute; ver o m&eacute;dico?\"];\n");
printf ("	tabFields[8] = [\"pernoite\", \"08 - Amanhã você terá que voltar para trazer outra amostra de escarro. Onde você vai passar a noite?\"];\n");
printf ("	tabFields[9] = [\"custo_pernoite\", \"08.1 - Você terá que pagar o pernoite? Quanto você deverá gastar?\"];\n");
printf ("	tabFields[10] = [\"custo_amigos\", \"08.2 - Você trouxe algo para os seus amigos?\"];\n");
printf ("	tabFields[11] = [\"comeu_bebeu\", \"09 - Desde que você saiu de casa, você comeu ou bebeu alguma coisa? Quanto custou?\"];\n");
printf ("	tabFields[12] = [\"pagar_algo_posto\", \"10 - Você teve que pagar algo aqui no posto? Quanto custou?\"];\n");
printf ("	tabFields[13] = [\"profissao\", \"12 - Qual a sua profissão?\"];\n");
printf ("	tabFields[14] = [\"perdeu_aula\", \"11.1 - Você perdeu aula hoje?\"];\n");
printf ("	tabFields[15] = [\"deixou_ganhar_dinheiro\", \"13 - Deixou de ganhar dinheiro hoje para poder vir ao posto?  Quanto?\"];\n");
printf ("	tabFields[16] = [\"quem_pagou\", \"14 - Quem pagou pela bebida, comida, transporte, hotel, etc.? Você ou seus acompanhantes?\"];\n");
printf ("	tabFields[17] = [\"custo_acompanhante\", \"15 - Quanto você gastou com o seu acompanhante?\"];\n");
printf ("	tabFields[18] = [\"estudante\", \"11 - Você é estudante?\"];\n");
printf ("	\n");
printf ("	function inicializaOcultos(tabela)\n");
printf ("	{\n");
printf ("		document.getElementById(tabela).rows[2].style.display = \"none\";//custo do transporte\n");
printf ("		document.getElementById(tabela).rows[8].style.display = \"none\";//pernoite\n");
printf ("		document.getElementById(tabela).rows[9].style.display = \"none\";//custo do pernoite\n");
printf ("		document.getElementById(tabela).rows[10].style.display = \"none\";//custo dos amigos\n");
printf ("		document.getElementById(tabela).rows[14].style.display = \"none\";//perdeu aula\n");
printf ("		document.getElementById(tabela).rows[17].style.display = \"none\";//quem arcou com os custos\n");
printf ("		document.getElementById(tabela).rows[18].style.display = \"none\";//gasto com o acompanhante\n");
printf ("	}	\n");
printf ("	</script>\n");
printf ("</head>\n");
printf ("<body onLoad=\"inicializaOcultos('parteA')\">\n");

showMenu("custosA",username);

printf ("\n");
printf ("<div align=\"center\" >\n");
printf ("	<h3>Projeto - Novos Métodos Diagnósicos em TB pulmonar - Policlinica Augusto Amaral Peixoto-SMS-RJ</br></h4>\n");
printf ("	<h4>Questionário Custos</h3>\n");
printf ("	<i>(aplicar em 1 a cada 4 pacientes incluídos)</i>\n");
printf ("\n");
printf ("	<br /><br />\n");
printf ("	<b>Parte A</b>\n");
printf ("	<form name=\"check\" method=\"post\" action=\"addPatientInfo.cgi\" onSubmit=\"return validar_custos_a (this)\">\n");
printf ("	<!-- --><input type=\"hidden\" name=\"form\" value=\"custosA\" />\n");
printf ("		<br>\n");
printf ("		<!-- Numero Geral -->\n");
printf ("		\n");
printf ("	<!-- --><b>N&uacute;mero Geral : </b><input name=\"pid\" type=\"text\" size=\"6\" value=\"%s\" readonly=\"readonly\" > &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<br><br>\n",numeroGeral);
printf ("		\n");
printf ("		<table border=\"0\" class=\"tabela custo\" id=\"parteA\">\n");
printf ("		\n");
printf ("		<!-- ONDE MORA -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("		\n");
printf ("		<!-- definicao da largura dos titulos: 30%%, 'pressionando' o resto contra o canto direito da tabela -->\n");
printf ("			<td class=\"wrap\"><script>document.write(tabFields[0][1])</script></td>\n");
printf ("			<td><input name=\"ondeMora\" type=\"radio\" value=\"rio\" onClick=\"ocultaLinha('parteA', 8)\">Município do Rio</td>\n");
printf ("			<td><input name=\"ondeMora\" type=\"radio\" value=\"fora_rio\" onClick=\"exibeLinhaOculta('parteA', 8)\">Fora do Rio</td>\n");
printf ("			<!--<td width=\"15%%\"></td>-->\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- COMO VEIO AO POSTO -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("\n");
printf ("		<td class=\"wrap\"><script>document.write(tabFields[1][1])</script></td>\n");
printf ("			<td><input name=\"transporte\" type=\"radio\" value=\"pe\" onClick=\"ocultaLinha('parteA', 2)\">A pé</td>\n");
printf ("			<td><input name=\"transporte\" type=\"radio\" value=\"onibus\" onClick=\"exibeLinhaOculta('parteA', 2)\">Ônibus</td>\n");
printf ("			<td><input name=\"transporte\" type=\"radio\" value=\"taxi_carro\" onClick=\"exibeLinhaOculta('parteA', 2)\">Táxi/carro</td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- CUSTO DO TRANSPORTE -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td class=\"wrap\"><script>document.write(tabFields[2][1])</script></td>\n");
printf ("			<td>R$ <input name=\"custoTransporteA\" type=\"text\" maxlength=\"3\" size=\"1\" onBlur=\"validarCampoNumerico(this)\">,00</td>\n");
printf ("			<td></td>\n");
printf ("			<td></td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- ACOMPANHADO -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td class=\"wrap\"><script>document.write(tabFields[3][1])</script></td>\n");
printf ("			<td><input name=\"acompanhadoA\" type=\"radio\" value=\"sim\" onClick=\"exibeLinhaOculta('parteA', 17); numeroAcompanhantesA.readOnly = false;numeroAcompanhantesA.value='';numeroAcompanhantesA.focus();\">Sim</td>\n");
printf ("			<td><input name=\"acompanhadoA\" type=\"radio\" value=\"nao\" onClick=\"ocultaLinha('parteA', 17);numeroAcompanhantesA.value='NA'; numeroAcompanhantesA.readOnly = true\">Não</td>\n");
printf ("			<td>Nº de pessoas: <input name=\"numeroAcompanhantesA\" type=\"text\" maxlength=\"2\" size=\"1\" onBlur=\"validarCampoNumerico(this)\"></td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- HORARIO SAIU DE CASA -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td class=\"wrap\"><script>document.write(tabFields[4][1])</script></td>\n");
printf ("			<td>Hora: <input name=\"horaSaidaCasaA\" type=\"text\" maxlength=\"2\" size=\"1\" onKeyUp=\"if(this.value.length == 2) minutoSaidaCasaA.focus();\" onBlur=\"validarCampoNumerico(this);validarHora(this);validar_tempo_de_viagem_custos_A(horaSaidaCasaA,minutoSaidaCasaA,horaChegadaPostoA,minutoChegadaPostoA,horaMedicoA,minutoMedicoA,horaTotalA,minutoTotalA);\">:<input name=\"minutoSaidaCasaA\" type=\"text\" maxlength=\"2\" size=\"1\" onKeyUp=\"if(this.value.length == 2) horaChegadaPostoA.focus();\" onBlur=\"validarCampoNumerico(this);validarMinuto(this);validar_tempo_de_viagem_custos_A(horaSaidaCasaA,minutoSaidaCasaA,horaChegadaPostoA,minutoChegadaPostoA,horaMedicoA,minutoMedicoA,horaTotalA,minutoTotalA);\"></td>\n");
printf ("			<td></td>\n");
printf ("			<td></td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- HORARIO CHEGOU NO POSTO -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td class=\"wrap\"><script>document.write(tabFields[5][1])</script></td>\n");
printf ("			<td>Hora: <input name=\"horaChegadaPostoA\" type=\"text\" maxlength=\"2\" size=\"1\" onKeyUp=\"if(this.value.length == 2) minutoChegadaPostoA.focus();\" onBlur=\"validarCampoNumerico(this);validarHora(this);validar_tempo_de_viagem_custos_A(horaSaidaCasaA,minutoSaidaCasaA,horaChegadaPostoA,minutoChegadaPostoA,horaMedicoA,minutoMedicoA,horaTotalA,minutoTotalA);\">:<input name=\"minutoChegadaPostoA\" type=\"text\" maxlength=\"2\" size=\"1\" onKeyUp=\"if(this.value.length == 2) horaMedicoA.focus();\" onBlur=\"validarCampoNumerico(this);validarMinuto(this);validar_tempo_de_viagem_custos_A(horaSaidaCasaA,minutoSaidaCasaA,horaChegadaPostoA,minutoChegadaPostoA,horaMedicoA,minutoMedicoA,horaTotalA,minutoTotalA);\"></td>\n");
printf ("			<td></td>\n");
printf ("			<td></td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- HORARIO MEDICO -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td class=\"wrap\"><script>document.write(tabFields[6][1])</script></td>\n");
printf ("			<td>Hora: <input name=\"horaMedicoA\" type=\"text\" maxlength=\"2\" size=\"1\" onKeyUp=\"if(this.value.length == 2) minutoMedicoA.focus();\" onBlur=\"validarCampoNumerico(this);validarHora(this);validar_tempo_de_viagem_custos_A(horaSaidaCasaA,minutoSaidaCasaA,horaChegadaPostoA,minutoChegadaPostoA,horaMedicoA,minutoMedicoA,horaTotalA,minutoTotalA);\">:<input name=\"minutoMedicoA\" type=\"text\" maxlength=\"2\" size=\"1\" onKeyUp=\"if(this.value.length == 2)this.blur();\" onBlur=\"validarCampoNumerico(this);validarMinuto(this);validar_tempo_de_viagem_custos_A(horaSaidaCasaA,minutoSaidaCasaA,horaChegadaPostoA,minutoChegadaPostoA,horaMedicoA,minutoMedicoA,horaTotalA,minutoTotalA);\"></td>\n");
printf ("			<td></td>\n");
printf ("			<td></td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- TEMPO TOTAL -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td class=\"wrap\"><script>document.write(tabFields[7][1])</script></td>\n");
printf ("			<td colspan=\"2\">Tempo total: <input name=\"horaTotalA\" type=\"text\" maxlength=\"2\" size=\"1\" readonly=\"readonly\" >h e<input name=\"minutoTotalA\" type=\"text\" maxlength=\"2\" size=\"1\" readonly=\"readonly\">min.</td>\n");
printf ("			<td></td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- SE MORAR FORA DO RIO -->\n");
printf ("		\n");
printf ("		<!-- Onde vai passar a noite -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td class=\"wrap\"><script>document.write(tabFields[8][1])</script></td>\n");
printf ("			<td><input name=\"pernoite\" type=\"radio\" value=\"casa\" onClick=\"ocultaLinha('parteA', 9);ocultaLinha('parteA', 10)\">Em casa</td>\n");
printf ("			<td><input name=\"pernoite\" type=\"radio\" value=\"radio\" value=\"amigos\" onClick=\"exibeLinhaOculta('parteA', 9);exibeLinhaOculta('parteA', 10)\">Com amigos</td>\n");
printf ("			<td><input name=\"pernoite\" type=\"radio\" value=\"radio\" value=\"hotel\" onClick=\"exibeLinhaOculta('parteA', 9);ocultaLinha('parteA', 10)\">Hotel</td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- Pagar o pernoite -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td class=\"wrap\"><script>document.write(tabFields[9][1])</script></td>\n");
printf ("			<td><input name=\"pagarPernoite\" type=\"radio\" value=\"sim\" onclick=\"custoPernoite.readOnly = false;custoPernoite.value=''\">Sim</td>\n");
printf ("			<td><input name=\"pagarPernoite\" type=\"radio\" value=\"nao\" onclick=\"custoPernoite.value='0'; custoPernoite.readOnly = true\">Não</td>\n");
printf ("			<td>R$ <input class=\"preco\" name=\"custoPernoite\" type=\"text\" maxlength=\"3\" size=\"1\" onBlur=\"validarCampoNumerico(this)\">,00</td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- Trouxe algo para os amigos -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td class=\"wrap\"><script>document.write(tabFields[10][1])</script></td>\n");
printf ("			<td><input name=\"trouxeAlgoAmigos\" type=\"radio\" value=\"sim\" onclick=\"custoAmigos.readOnly = false;custoAmigos.value=''\">Sim</td>\n");
printf ("			<td><input name=\"trouxeAlgoAmigos\" type=\"radio\" value=\"nao\" onclick=\"custoAmigos.value='0'; custoAmigos.readOnly = true\">Não</td>\n");
printf ("			<td>R$ <input name=\"custoAmigos\" type=\"text\" maxlength=\"3\" size=\"1\" onBlur=\"validarCampoNumerico(this)\">,00</td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- COMEU E/OU BEBEU -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td class=\"wrap\"><script>document.write(tabFields[11][1])</script></td>\n");
printf ("			<td><input name=\"comeuBebeuA\" type=\"radio\" value=\"sim\" onclick=\"custoComidaBebidaA.readOnly = false;custoComidaBebidaA.value=''\">Sim</td>\n");
printf ("			<td><input name=\"comeuBebeuA\" type=\"radio\" value=\"nao\" onclick=\"custoComidaBebidaA.value='0'; custoComidaBebidaA.readOnly = true\">Não</td>\n");
printf ("			<td>R$ <input name=\"custoComidaBebidaA\" type=\"text\" maxlength=\"3\" size=\"1\" onBlur=\"validarCampoNumerico(this)\">,00</td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- PAGOU ALGO NO POSTO -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td class=\"wrap\"><script>document.write(tabFields[12][1])</script></td>\n");
printf ("			<td><input name=\"pagarPostoA\" type=\"radio\" value=\"sim\" onclick=\"custoPostoA.readOnly = false;custoPostoA.value=''\">Sim</td>\n");
printf ("			<td><input name=\"pagarPostoA\" type=\"radio\" value=\"nao\" onclick=\"custoPostoA.value='0'; custoPostoA.readOnly = true\">Não</td>\n");
printf ("			<td>R$ <input name=\"custoPostoA\" type=\"text\" maxlength=\"3\" size=\"1\" onBlur=\"validarCampoNumerico(this)\">,00</td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- ESTUDANTE OU NÃO-ESTUDANTE -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td class=\"wrap\"><script>document.write(tabFields[18][1])</script></td>\n");
printf ("			<td><input name=\"estudante\" type=\"radio\" value=\"estudante\" onClick=\"exibeLinhaOculta('parteA', 14)\">Estudante</td>\n");
printf ("			<td><input name=\"estudante\" type=\"radio\" value=\"nao_estudante\" onClick=\"ocultaLinha('parteA', 14)\">Não-estudante</td>\n");
printf ("			<td></td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- CASO ESTUDANTE -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td class=\"wrap\"><script>document.write(tabFields[14][1])</script></td>\n");
printf ("			<td><input name=\"estudantePerdeuAula\" type=\"radio\" value=\"sim\">Sim</td>\n");
printf ("			<td><input name=\"estudantePerdeuAula\" type=\"radio\" value=\"nao\">Não</td>\n");
printf ("			<td></td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- PROFISSAO -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td class=\"wrap\"><script>document.write(tabFields[13][1])</script></td>\n");
printf ("			<td colspan=\"3\"><input name=\"profissao\" type=\"text\" maxlength=\"100\" size=\"25\"></td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- DEIXOU DE GANHAR DINHEIRO -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td class=\"wrap\"><script>document.write(tabFields[15][1])</script></td>\n");
printf ("			<td><input name=\"deixouGanharDinheiroA\" type=\"radio\" value=\"sim\" onclick=\"quantoDeixouGanharA.readOnly = false;quantoDeixouGanharA.value=''\">Sim</td>\n");
printf ("			<td><input name=\"deixouGanharDinheiroA\" type=\"radio\" value=\"nao\" onclick=\"quantoDeixouGanharA.value='0'; quantoDeixouGanharA.readOnly = true\">Não</td>\n");
printf ("			<td>R$ <input name=\"quantoDeixouGanharA\" type=\"text\" maxlength=\"3\" size=\"1\" onBlur=\"validarCampoNumerico(this);\">,00</td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!-- QUEM ARCOU COMS OS CUSTOS -->\n");
printf ("		\n");
printf ("		<tr>\n");
printf ("			<td class=\"wrap\"><script>document.write(tabFields[16][1])</script></td>\n");
printf ("			<td><input name=\"quemArcouCustos\" type=\"radio\" value=\"voce\" onClick=\"exibeLinhaOculta('parteA', 18)\">Você</td>\n");
printf ("			<td><input name=\"quemArcouCustos\" type=\"radio\" value=\"acompanhante\" onClick=\"ocultaLinha('parteA', 18)\">Acompanhante</td>\n");
printf ("			<td></td>\n");
printf ("		</tr>		\n");
printf ("\n");
printf ("		<!-- GASTO DO ACOMPANHANTE -->\n");
printf ("\n");
printf ("		<tr>\n");
printf ("			<td class=\"wrap\"><script>document.write(tabFields[17][1])</script></td>\n");
printf ("			<td>R$ <input name=\"gastoAcompanhante\" type=\"text\" maxlength=\"3\" size=\"1\" onBlur=\"validarCampoNumerico(this);\">,00</td>\n");
printf ("			<td></td>\n");
printf ("			<td></td>\n");
printf ("		</tr>\n");
printf ("\n");
printf ("		\n");
printf ("		<!-- Observacoes -->\n");
printf ("		<tr class=\"wrap\">\n");
printf ("			<td colspan=\"1\"> 16 - Observa&ccedil;&otilde;es: </td>\n");
printf ("			<td colspan=\"4\"><div center><textarea name=\"observacoes\" rows=\"3\" cols=\"40\"></textarea></div></td>\n");
printf ("		</tr>\n");
printf ("		<tr>\n");
printf ("			<td colspan=\"4\"><hr /></td>\n");
printf ("		</tr>\n");
printf ("\n");
printf ("		\n");
printf ("		<tr>			\n");
printf ("			<td colspan=\"4\" align=\"center\">\n");
printf ("			Avaliado por: <input name=\"avaliadorEnfermeiroA\" type=\"text\" size=\"25\">\n");
printf ("			&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf ("			Cadastrado por: <input name=\"quemCadastrou\" type=\"text\" readonly=\"readonly\" value=\"%s\" size=\"25\">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;",username);
printf ("			&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf ("			Data: <input name=\"dia_CustoA\" type=\"text\" maxlength=\"2\" size=\"2\" onKeyUp=\"if(this.value.length == 2) mes_CustoA.focus();\" onBlur=\"if(validarDia(this))mes_CustoA.focus();\">/<input type=\"text\" name=\"mes_CustoA\" maxlength=\"2\" size=\"2\" onKeyUp=\"if(this.value.length == 2) ano_CustoA.focus()\" onBlur=\"if(validarMes(this))ano_CustoA.focus();\">/<input type=\"text\" name=\"ano_CustoA\" maxlength=\"4\" size=\"4\" onKeyUp=\"if(this.value.length == 4) this.blur();\" onBlur=\"validarAno(this); validarQualquerData(dia_CustoA,mes_CustoA,ano_CustoA);\">\n");
printf ("			</td>\n");
printf ("			<!--Data: <input name=\"diaCustoA\" type=\"text\" maxlength=\"2\" size=\"2\" onKeyUp=\"if(this.value.length == 2)this.blur();\" onChange=\"if(validarDia(this))mesCustoA.focus();\">/<input type=\"text\" name=\"mesCustoA\" maxlength=\"2\" size=\"2\" onKeyUp=\"if(this.value.length == 2)this.blur();\" onChange=\"if(validarMes(this))anoCustoA.focus();\">/<input type=\"text\" name=\"anoCustoA\" maxlength=\"4\" size=\"4\" onKeyUp=\"if(this.value.length == 4)this.blur();\" onChange=\"validarAno(this);\" onBlur=\"validarQualquerData(diaCustoA,mesCustoA,anoCustoA)\"></td>-->		</tr>		\n");
printf ("		<tr>\n");
printf ("			<td>&nbsp;</td>\n");
printf ("		</tr>\n");
printf ("		\n");
printf ("		<!--    ENVIAR / LIMPAR     -->\n");
printf ("		<tr>\n");
printf ("			<td><input value=\"Limpar Formulário\" type=\"reset\"></td>\n");
printf ("			<td></td>\n");
printf ("			<td></td>\n");
printf ("			<td style=\"text-align:right\"><input type=\"submit\" value=\"Enviar Formul&aacute;rio\"></td>\n");
printf ("		</tr>\n");
printf ("		</table>\n");
printf ("\n");
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
