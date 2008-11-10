/*
 *	Autor: Igor Cunha Braganca
 */
 
 function returnNameCampo (name)
 {
	var newName = "";
	var estado = false;
	
 	tabela_triagem = new Array();
	tabela_triagem[0] = ["nomeCompleto", "01 - Nome"];
	tabela_triagem[1] = ["nomeMae","02 - Nome da Mãe"];
	tabela_triagem[2] = ["endereco","03 - Endereço Residencial"];
	tabela_triagem[3] = ["ptoReferencia","04 - Ponto de Referência"];
	tabela_triagem[4] = ["bairro","05 - Bairro"];
	tabela_triagem[5] = ["cep1","CEP"];
	tabela_triagem[6] = ["cidade","06 - Cidade"];
	tabela_triagem[7] = ["fone", "07 - Telefone"];
	tabela_triagem[8] = ["cel", "Celular"];
	tabela_triagem[9] = ["foneContato", "08 - Telefone contato"];
	tabela_triagem[10] = ["nomeContato", "Nome do contato"];
	tabela_triagem[11] = ["dia_nascimento", "09 - Data de Nascimento"];
	tabela_triagem[12] = ["mes_nascimento", "09 - Data de Nascimento"];
	tabela_triagem[13] = ["ano_nascimento", "09 - Data de Nascimento"];
	tabela_triagem[14] = ["idade", "10 - Idade"];
	tabela_triagem[15] = ["naturalidadeEstado", "11 - Naturalidade"];
	tabela_triagem[16] = ["naturalidadeCidade", "Cidade"];
	tabela_triagem[17] = ["naturalidadeAnosRio", "11.1 - Chegou no Rio há"];
	tabela_triagem[18] = ["sexo", "12 - Sexo"];
	tabela_triagem[19] = ["raca1", "13 - Raça"];
	tabela_triagem[20] = ["raca2", "13.1 - Especifique"];
	tabela_triagem[21] = ["estadoCivil", "14 - Estado Civil"];
	tabela_triagem[22] = ["companheiro", "15 - Tem companheiro(a)"];
	tabela_triagem[23] = ["pesoHabitual", "16 - Peso Habitual"];
	tabela_triagem[24] = ["pesoAtual", "17 - Peso Atual"];
	tabela_triagem[25] = ["perdaDePeso", "18 - Perda de peso "];
	tabela_triagem[26] = ["altura", "19 - Altura"];
	tabela_triagem[27] = ["imc", "20 - IMC"];
	tabela_triagem[28] = ["tosse", "21 - Tosse"];
	tabela_triagem[29] = ["tosse_semanas", "Semanas"];
	tabela_triagem[30] = ["expectoracao", "22 - Expectoração"];
	tabela_triagem[31] = ["expectoracao_semanas", "Semanas"];
	tabela_triagem[32] = ["hemoptoico", "23 - Hemoptóico"];
	tabela_triagem[33] = ["hemoptoico_semanas", "Semanas"];
	tabela_triagem[34] = ["hemoptise", "24 - Hemoptise"];
	tabela_triagem[35] = ["hemoptise_semanas", "Semanas"];
	tabela_triagem[36] = ["hemoptiseQtd", "24.1 - Quantidade:"];
	tabela_triagem[37] = ["sudorese", "25 - Sudorese Noturna"];
	tabela_triagem[38] = ["sudorese_semanas", "Semanas"];
	tabela_triagem[39] = ["febre", "26 - Febre"];
	tabela_triagem[40] = ["febre_semanas", "Semanas"];
	tabela_triagem[41] = ["dispneia", "27 - Dispnéia"];
	tabela_triagem[42] = ["dispneia_semanas", "Semanas"];
	tabela_triagem[43] = ["perdaApetite", "28 - Perda de apetite"];
	tabela_triagem[44] = ["perdaApetite_semanas", "Semanas"];
	tabela_triagem[45] = ["dorToracica", "29 - Dor Torácica"];
	tabela_triagem[46] = ["dorToracica_semanas", "Semanas"];
	tabela_triagem[47] = ["result", "Resultado"];//Sinais e Sintomas
	tabela_triagem[48] = ["tratamentoAnteriorTB", "30 - Tratamento de TB anterior"];
	tabela_triagem[49] = ["mes_diagnostico", "30.1 - Data do diagn&oacute;stico de TB no passado"];
	tabela_triagem[50] = ["ano_diagnostico", "30.1 - Data do diagn&oacute;stico de TB no passado"];	
	tabela_triagem[51] = ["TBdesfecho", "30.2 - Desfecho de TB"];
	tabela_triagem[52] = ["internado", "31 - Internação Hospitalar"];
	tabela_triagem[53] = ["prisao", "32 - Esteve em prisão"];
	tabela_triagem[54] = ["delegacia", "33 - Esteve em delegacia"];
	tabela_triagem[55] = ["contatoTBP", "34 - Contato com pessoas com TBP"];
	tabela_triagem[56] = ["contatoTBPmoravaJunto", "34.1 - Morava com você"];
	tabela_triagem[57] = ["contatoTBPtrabalhavaJunto", "34.2 - Trabalhava com você"];
	tabela_triagem[58] = ["contatoTBPamigoParenteColega", "34.3 - Amigo, parente ou colega que não morava com você"];
	tabela_triagem[59] = ["contatoTBPmenorQue3Anos", "34.4 - Alguns destes contatos foi menor do que 3 anos"];
	tabela_triagem[60] = ["contatoTBPqual", "34.5 - Especifique esse contato (pode marcar mais de um)"];
	tabela_triagem[61] = ["fuma", "35 - Fuma"];
	tabela_triagem[62] = ["fumaQtd", "35.1 - Número de cigarros por dia"];
	tabela_triagem[63] = ["fumaTempo", "35.2 - Número de anos que fumou/fuma"];
	tabela_triagem[64] = ["bebida", "36 - Tipo de bebida preferida"];
	tabela_triagem[65] = ["facilidadeFazerAmizades", "36.1 - Possui facilidade em fazer amizades"];
	tabela_triagem[66] = ["diminuirQtdBebida", "36.2 - Já sentiu necessidade de diminuir a quantidade da bebida"];
	tabela_triagem[67] = ["criticaModoBeber", "36.3 - Alguém critica ou já criticou o modo de beber"];
	tabela_triagem[68] = ["bebidaManha", "36.4 - Costuma beber de manhã para diminuir nervosismo/ressaca"];
	tabela_triagem[69] = ["culpadoManeiraBeber", "36.5 - Sente culpa pela maneira que bebe"];
	tabela_triagem[70] = ["cage", "Cage"];
	tabela_triagem[71] = ["primeiraProcuraParaAuxiliodeSaude", "37 - Quando procurou pela primeira vez auxilio para seu problema de sa&uacute;de?"];
	tabela_triagem[72] = ["lugarDaPrimeiraConsulta", "38 - Onde foi?"];
	tabela_triagem[73] = ["causaDaPrimeiraConsulta", "39 - Porque procurou? "];
	tabela_triagem[74] = ["veioAcompanhadoDeFamiliares", "40 - Veio acompanhado de familiares?"];
	tabela_triagem[75] = ["veioEncaminhadoPorAlgumPostodeSaude", "41 - Foi encaminhado para o Posto pelo P. Sa&uacute;de de Fam&iacute;lia"];
	tabela_triagem[76] = ["deQualPostoDeSaudeFoiEncaminhado", "41.1 - Qual?"];
	tabela_triagem[77] = ["veioEncaminhadoPorUnidadedDeSaudeSUS", "42 - Foi encaminhado por unidade de sa&uacute;de do SUS?"];
	tabela_triagem[78] = ["deQualPostoDeSaudeDoSUSFoiEncaminhado", "42.1 - Qual?"];
	tabela_triagem[79] = ["veioEncaminhadoPorUnidadedDeSaudeParticular", "43 - Foi encaminhado por unidade de sa&uacute;de Particular?"];
	tabela_triagem[80] = ["deQualPostoDeSaudeparticularFoiEncaminhado", "43.1 - Qual?"];	
	tabela_triagem[81] = ["decidiuSozinhoPorAuxilioMedico", "44 - Decidiu sozinho por aux&iacute;lio m&eacute;dico na Policl&iacute;nica?"];	
	tabela_triagem[82] = ["porqueDecidiuSozinhoPorAuxilioMedico", "44.1 - Porque?"];	
	tabela_triagem[83] = ["encaminhadoParaQualSetorDaPoliclinica", "45 - O encaminhamento foi para atendimento em qual setor da Policl&iacute;nica?"];	
	tabela_triagem[84] = ["algumTratamentoParaTosseRecente", "46 - Fez algum tratamento para tosse, ultimamente?"];	
	tabela_triagem[85] = ["qualFoiTratamentoRecenteFeito", "46.1 - Qual?"];	
	tabela_triagem[86] = ["quantoDiasDurouTratamentoRecenteFeito", "46.2 - Durante quantos dias (total)?"];	
	tabela_triagem[87] = ["trouxeRXdeTorax", "47 - Trouxe RX de t&oacute;rax?"];	
	tabela_triagem[88] = ["trouxeAlgumResultadoDeRXdeTorax", "48 - Trouxe algum resultado de RX de t&oacute;rax?"];	
	tabela_triagem[89] = ["trouxeMaterialDeExacarro", "49 - Trouxe material de escarro?"];	
	tabela_triagem[90] = ["trouxeAlgumResultadoDeMaterialDeExacarro", "50 - Trouxe algum resultado de exame de escarro?"];	
	tabela_triagem[91] = ["trouxeAlgumResultadoDeBiopasia", "51 - Trouxe algum resultado de bi&oacute;psia?"];	
	tabela_triagem[92] = ["trouxeAlgumOutroResultado", "52 - Trouxe algum outro resultado?"];	
	tabela_triagem[93] = ["qualOutroResultado", "52.1 - Qual?"];	
	tabela_triagem[94] = ["desfechoConsultaInicial", "37 - Desfecho da Consulta Inicial"];	
	tabela_triagem[95] = ["inclusao", "38 - Inclusão"];	
	tabela_triagem[96] = ["criteriosInclusao", "38.1 - Critérios de Inclusão"];	
	tabela_triagem[97] = ["", "38.2 - Data de Coleta dos DOIS Esp&eacute;cimes Respirat&oacute;rios:"];	
	tabela_triagem[98] = ["coleta_1", "#1"];	
	tabela_triagem[99] = ["coleta_2", "#2"];	
	tabela_triagem[100] = ["cicatrizBCG", "38.3 - Cicatriz de BCG"];	
	tabela_triagem[101] = ["resultadoLeitura", "38.4 - Resultado da leitura"];	
	tabela_triagem[102] = ["data_aplicacao", "38.5 - Data de aplicação da prova tuberculínica"];	
	tabela_triagem[103] = ["data_leitura", "38.6 - Data da Leitura"];	
	tabela_triagem[104] = ["PTprimeiraDose", "38.7 - PT 1ª dose leitor"];	
	tabela_triagem[105] = ["observacoes", "39 - Observações"];
	tabela_triagem[106] = ["numeroGeral","Nº Geral (TB Adapt)"];
	tabela_triagem[107] = ["dia_inclusao","Data de inclusão"];
	tabela_triagem[108] = ["mes_inclusao","Data de inclusão"];
	tabela_triagem[109] = ["ano_inclusao","Data de inclusão"];
	tabela_triagem[110] = ["cep2","CEP"];
	tabela_triagem[111] = ["avaliador","Avaliado por"];
	tabela_triagem[112] = ["coleta1","38.2 - Data de Coleta dos DOIS Espécimes Respiratórios (#1)"];
	tabela_triagem[113] = ["dia_coleta1","38.2 - Data de Coleta dos DOIS Espécimes Respiratórios (#1)"];
	tabela_triagem[114] = ["mes_coleta1","38.2 - Data de Coleta dos DOIS Espécimes Respiratórios (#1)"];
	tabela_triagem[115] = ["ano_coleta1","38.2 - Data de Coleta dos DOIS Espécimes Respiratórios (#1)"];
	tabela_triagem[116] = ["coleta2","38.2 - Data de Coleta dos DOIS Espécimes Respiratórios (#2)"];
	tabela_triagem[117] = ["dia_coleta2","38.2 - Data de Coleta dos DOIS Espécimes Respiratórios (#2)"];
	tabela_triagem[118] = ["mes_coleta2","38.2 - Data de Coleta dos DOIS Espécimes Respiratórios (#2)"];
	tabela_triagem[119] = ["ano_coleta2","38.2 - Data de Coleta dos DOIS Espécimes Respiratórios (#2)"];
	tabela_triagem[120] = ["dia_aplicacao","38.5 - Data de aplicação da prova tuberculínica"];
	tabela_triagem[121] = ["mes_aplicacao","38.5 - Data de aplicação da prova tuberculínica"];
	tabela_triagem[122] = ["ano_aplicacao","38.5 - Data de aplicação da prova tuberculínica"];
	tabela_triagem[123] = ["dia_leitura","38.6 - Data da Leitura"];
	tabela_triagem[124] = ["mes_leitura","38.6 - Data da Leitura"];
	tabela_triagem[125] = ["ano_leitura","38.6 - Data da Leitura"];
	tabela_triagem[126] = ["perdaDePeso_semanas","Semanas"];
	tabela_triagem[127] = ["dia_termoConsentimento","38.1 - Critérios de Inclusão"];
	tabela_triagem[128] = ["mes_termoConsentimento","38.1 - Critérios de Inclusão"];
	tabela_triagem[129] = ["ano_termoConsentimento","38.1 - Critérios de Inclusão"];
	tabela_triagem[130] = ["pontuacao","Resultado"];
	
	var indice = 0;
	while((indice < 131) && (estado != true))
	{
		if(tabela_triagem[indice][0] == name)
		{
			estado = true;
			newName = tabela_triagem[indice][1];
		}
		indice ++;
	}
	return newName;
}

 function validar_triagem (form)
{
	
	var estado = true;
	var texto="";
	var tamanho = 0;
	var novoNome1, novoNome2;
	novoNome1 = "-";
	
	tamanho = form.elements.length;
	
	texto="As seguintes perguntas não foram preenchidas:\n";
	
	for(indice = 0; indice < tamanho; indice ++)
	{

		if(form.elements[indice].type == "text")
		{
			if((form.elements[indice].value == "") && (form.elements[indice].disabled == false))
			{
				estado = false;
				/***********************/
				novoNome2 = returnNameCampo(form.elements[indice].name);
				if(novoNome2 == novoNome1)
					novoNome1 = novoNome2;
				else
				{
					texto = texto + novoNome2 + "\n";
					novoNome1 = novoNome2;
				}
				/***********************/
			}	
		}
		else
		{
			if(form.elements[indice].type == "radio")
			{
				if(form.elements[indice].name == "desfechoConsultaInicial")
				{
					if((form.elements[indice].checked == true) || (form.elements[indice+1].checked == true) || (form.elements[indice+2].checked == true) || (form.elements[indice+4].checked == true) || (form.elements[indice+5].checked == true) || (form.elements[indice+7].checked == true))
					{
						if((form.elements[indice+2].checked == true) && (form.elements[indice+3].value == "") && (form.elements[indice+3].disabled == false))
						{
							estado = false;
							/***********************/
							novoNome2 = returnNameCampo(form.elements[indice].name);
							if(novoNome2 == novoNome1)
								novoNome1 = novoNome2;
							else
							{
								texto = texto + novoNome2 + "\n";
								novoNome1 = novoNome2;
							}
							/***********************/
						}
						if((form.elements[indice+5].checked == true) && (form.elements[indice+6].value == "") && (form.elements[indice+6].disabled == false))
						{
							estado = false;
							/***********************/
							novoNome2 = returnNameCampo(form.elements[indice].name);
							if(novoNome2 == novoNome1)
								novoNome1 = novoNome2;
							else
							{
								texto = texto + novoNome2 + "\n";
								novoNome1 = novoNome2;
							}
							/***********************/
						}
					}
					else
					{
						estado = false;
						/***********************/
						novoNome2 = returnNameCampo(form.elements[indice].name);
						if(novoNome2 == novoNome1)
							novoNome1 = novoNome2;
						else
						{
							texto = texto + novoNome2 + "\n";
							novoNome1 = novoNome2;
						}
						/***********************/
					}
					indice += 7;
				}
				else
				{
					for(contador = 0, radioIndice = 0; form.elements[indice].name == form.elements[indice + 1].name; indice ++, contador ++)
					{
						if(form.elements[indice].checked == true)
							radioIndice ++;
					}
					
					if(form.elements[indice].checked == true)
					{
						contador ++
						radioIndice ++;
					}
					
					if(((contador > 1)||(contador == 1)) && (radioIndice != 1)  && (form.elements[indice].disabled == false)) 
					{
						estado = false;
						/***********************/
						novoNome2 = returnNameCampo(form.elements[indice].name);
						if(novoNome2 == novoNome1)
							novoNome1 = novoNome2;
						else
						{
							texto = texto + novoNome2 + "\n";
							novoNome1 = novoNome2;
						}
						/***********************/
					}
				}
			}
			else
			{
				if(form.elements[indice].type == "checkbox")
				{
					if((form.elements[indice].name == form.elements[indice + 1].name) && (form.elements[indice].name == form.elements[indice + 2].name))
					{
						if((form.elements[indice].checked == false) && (form.elements[indice+1].checked == false) && (form.elements[indice+2].checked == false) && (form.elements[indice].disabled == false))
						{
							estado = false;
							/***********************/
							novoNome2 = returnNameCampo(form.elements[indice].name);
							if(novoNome2 == novoNome1)
								novoNome1 = novoNome2;
							else
							{
								texto = texto + novoNome2 + "\n";
								novoNome1 = novoNome2;
							}
							/***********************/
						}	
						indice += 2;
					}
				}
				else
				{
					if(form.elements[indice].type == "select-one")
					{
						if((form.elements[indice].value == "") && (form.elements[indice].disabled == false))
						{
							estado = false;
							/***********************/
							novoNome2 = returnNameCampo(form.elements[indice].name);
							if(novoNome2 == novoNome1)
								novoNome1 = novoNome2;
							else
							{
								texto = texto + novoNome2 + "\n";
								novoNome1 = novoNome2;
							}
							/***********************/
						}
					}
					else
					{
					}
				}
				
			}
		}	
	}
	
	if(estado == false)
	{
		alert("Preencha todos os campos do formulario, obrigado.\n\nOBS:Não se esqueça de clicar no botão \"Resultado\" no grupo de perguntas Sinais e Sintomas.");
		alert(texto);
		return false;
	}
	
	if(confirm("Deseja enviar os dados ?"))
		return true;
	else
		return false;
}

function returnNameCampoCustosA (name)
{
	var newName = "";
	var estado = false;
	
	tabela_custosA= new Array();
	tabela_custosA[0] = ["ondeMora", "01 - Onde você mora?"];
	tabela_custosA[1] = ["transporte", "02 - Como você veio ao posto? Em qual transporte?"];
	tabela_custosA[2] = ["custoTransporteA", "02.1 - Se você não veio a pé, quanto custou o transporte?"];
	tabela_custosA[3] = ["acompanhadoA", "03 - Você está acompanhado?"];
	tabela_custosA[4] = ["horaSaidaCasaA", "04 - Que horas você saiu de casa?"];
	tabela_custosA[5] = ["horaChegadaPostoA", "05 - Que horas você chegou no posto?"];
	tabela_custosA[6] = ["horaMedicoA", "06 - Que horas você viu o médico?"];
	tabela_custosA[7] = ["horaTotalA", "07 - Quanto tempo levou desde que você saiu de casa at&eacute; ver o m&eacute;dico?"];
	tabela_custosA[8] = ["pernoite", "08 - Amanhã você terá que voltar para trazer outra amostra de escarro. Onde você vai passar a noite?"];
	tabela_custosA[9] = ["pagarPernoite", "08.1 - Você terá que pagar o pernoite? Quanto você deverá gastar?"];
	tabela_custosA[10] = ["trouxeAlgoAmigos", "08.2 - Você trouxe algo para os seus amigos?"];
	tabela_custosA[11] = ["comeuBebeuA", "09 - Desde que você saiu de casa, você comeu ou bebeu alguma coisa? Quanto custou?"];
	tabela_custosA[12] = ["pagarPostoA", "10 - Você teve que pagar algo aqui no posto? Quanto custou?"];
	tabela_custosA[13] = ["profissao", "12 - Qual a sua profissão?"];
	tabela_custosA[14] = ["estudantePerdeuAula", "11.1 - Você perdeu aula hoje?"];
	tabela_custosA[15] = ["deixouGanharDinheiroA", "13 - Deixou de ganhar dinheiro hoje para poder vir ao posto?  Quanto?"];
	tabela_custosA[16] = ["quemArcouCustos", "14 - Quem pagou pela bebida, comida, transporte, hotel, etc.? Você ou seus acompanhantes?"];
	tabela_custosA[17] = ["gastoAcompanhante", "15 - Quanto você gastou com o seu acompanhante?"];
	tabela_custosA[18] = ["estudante", "11 - Você é estudante?"];
	tabela_custosA[19] = ["minutoSaidaCasaA", "04 - Que horas você saiu de casa?"];
	tabela_custosA[20] = ["minutoChegadaPostoA", "05 - Que horas você chegou no posto?"];
	tabela_custosA[21] = ["minutoMedicoA", "06 - Que horas você viu o médico?"];
	tabela_custosA[22] = ["minutoTotalA", "07 - Quanto tempo levou desde que você saiu de casa at&eacute; ver o m&eacute;dico?"];
	tabela_custosA[23] = ["numeroAcompanhantesA","03 - Você está acompanhado?"];
	tabela_custosA[24] = ["custoComidaBebidaA","09 - Desde que você saiu de casa, você comeu ou bebeu alguma coisa? Quanto custou?"];
	tabela_custosA[25] = ["custoPostoA","10 - Você teve que pagar algo aqui no posto? Quanto custou?"];
	tabela_custosA[26] = ["pid","Número Geral"];
	tabela_custosA[27] = ["avaliadorEnfermeiroA","Avaliado por"];
	tabela_custosA[28] = ["quemCadastrou","Cadastrado por"];
	tabela_custosA[29] = ["dia_CustoA","Data"];
	tabela_custosA[30] = ["mes_CustoA","Data"];
	tabela_custosA[31] = ["ano_CustoA","Data"];
	tabela_custosA[32] = ["quantoDeixouGanharA","13 - Deixou de ganhar dinheiro hoje para poder vir ao posto? Quanto?"];
	
	var indice = 0;
	while((indice < 33) && (estado != true))
	{
		if(tabela_custosA[indice][0] == name)
		{
			estado = true;
			newName = tabela_custosA[indice][1];
		}
		indice ++;
	}
	return newName;
}

 function validar_custos_a (form)
{
	
	var estado = true;
	var texto="";
	var tamanho = 0;
	var novoNome1, novoNome2;
	novoNome1 = "-";
	
	tamanho = form.elements.length;
	texto="As seguintes perguntas não foram preenchidas:\n";
	
	for(indice = 0; indice < tamanho; indice ++)
	{

		if(form.elements[indice].type == "text")
		{
			if((form.elements[indice].value == "") && (form.elements[indice].disabled == false))
			{
				estado = false;
				/***********************/
				novoNome2 = returnNameCampoCustosA(form.elements[indice].name);
				if(novoNome2 == novoNome1)
					novoNome1 = novoNome2;
				else
				{
					texto = texto + novoNome2 + "\n";
					novoNome1 = novoNome2;
				}
				/***********************/
			}	
		}
		else
		{
			if(form.elements[indice].type == "radio")
			{
				if(form.elements[indice].name == "desfechoConsultaInicial")
				{
					if((form.elements[indice].checked == true) || (form.elements[indice+1].checked == true) || (form.elements[indice+2].checked == true) || (form.elements[indice+4].checked == true) || (form.elements[indice+5].checked == true) || (form.elements[indice+7].checked == true))
					{
						if((form.elements[indice+2].checked == true) && (form.elements[indice+3].value == "") && (form.elements[indice+3].disabled == false))
						{
							estado = false;
							/***********************/
							novoNome2 = returnNameCampoCustosA(form.elements[indice].name);
							if(novoNome2 == novoNome1)
								novoNome1 = novoNome2;
							else
							{
								texto = texto + novoNome2 + "\n";
								novoNome1 = novoNome2;
							}
							/***********************/
						}
						if((form.elements[indice+5].checked == true) && (form.elements[indice+6].value == "") && (form.elements[indice+6].disabled == false))
						{
							estado = false;
							/***********************/
							novoNome2 = returnNameCampoCustosA(form.elements[indice].name);
							if(novoNome2 == novoNome1)
								novoNome1 = novoNome2;
							else
							{
								texto = texto + novoNome2 + "\n";
								novoNome1 = novoNome2;
							}
							/***********************/
						}
					}
					else
					{
						estado = false;
						/***********************/
						novoNome2 = returnNameCampoCustosA(form.elements[indice].name);
						if(novoNome2 == novoNome1)
							novoNome1 = novoNome2;
						else
						{
							texto = texto + novoNome2 + "\n";
							novoNome1 = novoNome2;
						}
						/***********************/
					}
					indice += 7;
				}
				else
				{
					for(contador = 0, radioIndice = 0; form.elements[indice].name == form.elements[indice + 1].name; indice ++, contador ++)
					{
						if(form.elements[indice].checked == true)
							radioIndice ++;
					}
					
					if(form.elements[indice].checked == true)
					{
						contador ++
						radioIndice ++;
					}
					
					if(((contador > 1)||(contador == 1)) && (radioIndice != 1)  && (form.elements[indice].disabled == false)) 
					{
						estado = false;
						/***********************/
						novoNome2 = returnNameCampoCustosA(form.elements[indice].name);
						if(novoNome2 == novoNome1)
							novoNome1 = novoNome2;
						else
						{
							texto = texto + novoNome2 + "\n";
							novoNome1 = novoNome2;
						}
						/***********************/
					}
				}
			}
			else
			{
				if(form.elements[indice].type == "checkbox")
				{
					if((form.elements[indice].name == form.elements[indice + 1].name) && (form.elements[indice].name == form.elements[indice + 2].name))
					{
						if((form.elements[indice].checked == false) && (form.elements[indice+1].checked == false) && (form.elements[indice+2].checked == false) && (form.elements[indice].disabled == false))
						{
							estado = false;
							/***********************/
							novoNome2 = returnNameCampoCustosA(form.elements[indice].name);
							if(novoNome2 == novoNome1)
								novoNome1 = novoNome2;
							else
							{
								texto = texto + novoNome2 + "\n";
								novoNome1 = novoNome2;
							}
							/***********************/
						}	
						indice += 2;
					}
				}
				else
				{
					if(form.elements[indice].type == "select-one")
					{
						if((form.elements[indice].value == "") && (form.elements[indice].disabled == false))
						{
							estado = false;
							/***********************/
							novoNome2 = returnNameCampoCustosA(form.elements[indice].name);
							if(novoNome2 == novoNome1)
								novoNome1 = novoNome2;
							else
							{
								texto = texto + novoNome2 + "\n";
								novoNome1 = novoNome2;
							}
							/***********************/
						}
					}
					else
					{
					}
				}
				
			}
		}	
	}
	
	if(estado == false)
	{
		alert("Preencha todos os campos do formulario, obrigado.");
		alert(texto);
		return false;
	}
	
	if(confirm("Deseja enviar os dados ?"))
		return true;
	else
		return false;
}
