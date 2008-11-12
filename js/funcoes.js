function putDate()
{
	var d = new Date();
	var day = d.getDate();
	var month = d.getMonth() + 1;
	var year = d.getFullYear();
	
	document.write(day + "/" + month + "/" + year);
}

function exibeLinhaOculta(tabela, linha)
{
	document.getElementById(tabela).rows[linha].style.display = "";
}

function ocultaLinha(tabela, linha)
{
	document.getElementById(tabela).rows[linha].style.display = "none";
}


var totalPontos = 0;

function pontuacaoIdade()
{
	if (document.check.idade.value < 59)
	{
		totalPontos += 1;
	}
}

function getCheckedValue(radioObj)
{
	if (!radioObj)
		return "";
	var radioLength = radioObj.length;
	if (radioLength == undefined)
		if (radioObj.checked)
			return radioObj.value;
		else
			return "";
	for (var i = 0; i < radioLength; i++)
	{
		if (radioObj[i].checked)
		{
			return radioObj[i].value;
		}
	}
	return "";
}

function pontuacaoSimples(doenca,pontos)
{
	if (doenca == "sim")
	{
		totalPontos += pontos;
	}
}

function pontuacaoSemanas(doenca,semanas)
{
	if (doenca == "sim")
	{
		if (semanas > 2)
		{
			totalPontos += 2;
		}
		else
		{
			totalPontos += 1;
		}
	}
}

function pontosEmagrecimento(pesoAtual,pesoHabitual)
{
	var emagrecimento = pesoHabitual - pesoAtual
	
	if (pesoAtual <= 70)
	{	
		if (emagrecimento >= 3)
		{
			totalPontos += 2
		}
	}
	else
	{
		if (emagrecimento >= 5)
		{
			totalPontos += 2
		}
	}
}

function diagnostico()
{	
	document.check.pontuacao.value = totalPontos
}

/*
function enviar()
{
	var i,j,len;
	var str = "Linhas escondidas: ";
	var nroLinhas = document.getElementById('tabelaSintomas').rows.length - 8;
	if (confirm('Tem certeza que quer enviar este formulario?'))
	{
		for (i = 0; i < nroLinhas; i++)
			if (document.getElementById('tabelaSintomas').rows[i].style.display != "none")
			{
				len = document.getElementById('tabelaSintomas').rows[i].getElementsByTagName("input").length;
				for (j = 0; j < len; j++)
				{
					nomeCampo = document.getElementById('tabelaSintomas').rows[i].getElementsByTagName("input")[j].name;
					switch (document.getElementsByName(nomeCampo).length)
					{
						case 1:
							if(document.getElementById('tabelaSintomas').rows[i].getElementsByTagName("input")[j].value == "")
							{
								alert("Falha no envio: ha campos nao preenchidos.");
								return false;
							}
						break;
						case 2:
						if(document.getElementById('tabelaSintomas').rows[i].getElementsByTagName("input")[j].checked == false && document.getElementById('tabelaSintomas').rows[i].getElementsByTagName("input")[++j].checked == false)
						{
							alert("Falha no envio: ha campos nao preenchidos.");
							return false;
						}
						break;
						case 3:
						if(document.getElementById('tabelaSintomas').rows[i].getElementsByTagName("input")[j].checked == false && document.getElementById('tabelaSintomas').rows[i].getElementsByTagName("input")[++j].checked == false && document.getElementById('tabelaSintomas').rows[i].getElementsByTagName("input")[++j].checked == false)
						{
							alert("Falha no envio: ha campos nao preenchidos.");
							return false;
						}
						break;
					}
				}
			}
		return true;
	}
	else
	{
		return false;
	}
}
*/

function enviar()
{
	var i,j,len,c1,c2;
	var nLinhas = document.getElementById('tabelaSintomas').rows.length;
	c1 = c2 = 0;
	
	if (confirm('Tem certeza que quer enviar este formulario?'))
	{
		for (i = 0; i < nLinhas; i++)
			if (document.getElementById('tabelaSintomas').rows[i].style.display != "none")
			{
				len = document.getElementById('tabelaSintomas').rows[i].getElementsByTagName("input").length;
				for (j = 0; j < len; j++)
				{
					tipo = document.getElementById('tabelaSintomas').rows[i].getElementsByTagName("input")[j].type;
					valor = document.getElementById('tabelaSintomas').rows[i].getElementsByTagName("input")[j].value;
					checked = document.getElementById('tabelaSintomas').rows[i].getElementsByTagName("input")[j].checked;
					
					if (((tipo == "text") || (tipo == "password")) && (valor == ""))
					{
						//document.getElementById('tabelaSintomas').rows[i].getElementsByTagName("input")[j].style.border = medium solid red;
						alert ("Falha no envio: ha campos nao preenchidos.");
						
						return false;
					}
					
					else if (((tipo == "checkbox") || (tipo == "radio")) && (checked == "false") && (valor != ""))
					{
						c2++;
					}
				}
			}
		return true;
	}
	
	else
		return false;
}


function isNumberString(InString)
{
	if(InString.length==0)
		return (true);
	var RefString="1234567890";
	for (Count=0; Count < InString.length; Count++)
	{
		TempChar= InString.substring (Count, Count+1);
		if (RefString.indexOf (TempChar, 0)==-1)
			return (false);
	}
	return (true);
}

function validarCampoNumerico(campo)
{
	if (!isNumberString(campo.value))
	{
		alert("Valor invalido, digite somente numeros.");
		campo.value = '';
		campo.focus();
	}
}

function validarNumEPonto (campo)
{
	if(campo.length == 0)
		return(true);
	var stringRef = ".1234567890";
	for (indice = 0; indice < campo.length; indice ++)
	{
		if(stringRef.indexOf(campo.charAt(indice),0) == -1 )
			return (false);
	}

	return (true);
}

function validarCampoPeso (campo)
{	
	if(validarNumEPonto(campo.value) == false)
	{
		alert("Valor invalido, digite somente numeros \".\"");
		campo.focus();
		campo.select();
	}
}


function validarPorcentagem(campo)
{
	if (campo.value > 100)
	{
		alert("Digite um valor entre 0 e 100.");
		campo.focus();
		campo.select();
	}
}

function validarDia(campoDia)
{
	if(campoDia.value != '')
	{
		if(campoDia.value.length != 2)
		{
			alert("O campo dia deve conter dois digitos.");
			campoDia.value = '';
			campoDia.focus();
			return false;
		}
		if(!isNumberString(campoDia.value))
		{
			alert("Valor invalido para dia, digite somente numeros.");
			campoDia.value = '';
			campoDia.focus();
			return false;
		}
		if(campoDia.value < 1 || campoDia.value > 31)
		{
			alert("Dia invalido:" +"\n" +"Use valores entre 01 e 31");
			campoDia.value = '';
			campoDia.focus();
			return false;
		}
	}
	return true;
}

function validarMes(campoMes)
{
	if(campoMes.value != '')
	{
		if(campoMes.value.length != 2)
		{
			alert("O campo mês deve conter dois digitos.");
			campoMes.value = '';
			campoMes.focus();
			return false;
		}
		if (!isNumberString(campoMes.value))
		{
			alert("Valor invalido para mês, digite somente numeros.");
			campoMes.value = '';
			campoMes.focus();
			return false;
		}
		if (campoMes.value < 1 || campoMes.value > 12)
		{
			alert("Mês invalido:" +"\n" +"Use valores entre 01 e 12");
			campoMes.value = '';
			campoMes.focus();
			return false;
		}
	}
	return true;
}

function validarAno(campoAno)
{
	if(campoAno.value != '')
	{
		if(campoAno.value.length != 4)
		{
			alert("O campo ano deve conter quatro digitos!!!.");
			campoAno.value = '';
			campoAno.focus();
			return false;
		}
		if(!isNumberString(campoAno.value))
		{
			alert("Valor invalido para ano, digite somente numeros.");
			campoAno.value = '';
			campoAno.focus();
			return false;
		}
	}
	return true;
}

function validarIdade(campoIdade)
{
	if(!isNumberString(campoIdade.value))
	{
		alert("Valor invalido para idade, digite somente numeros.");
		campoIdade.focus();
		campoIdade.select();
		return false;
	}			
	if ((campoIdade.value < 1 || campoIdade.value > 120) && campoIdade.value != "")
	{
		alert("Ano invalido:\n A idade nao deve ser maior que 120 anos, nem menor do que 1 ano.");
		campoIdade.focus();
		campoIdade.select();
		return false;
	}
	return true;
}

function validarData(form)
{
	today = new Date();
	dia = form.dia_nascimento.value;
	mes = form.mes_nascimento.value;
	ano = form.ano_nascimento.value;
	dia_atual =today.getDate();
	mes_atual =today.getMonth();
	ano_atual =today.getFullYear();

	switch(mes)
	{
		case '01'://janeiro
			if(dia<1 || dia>31)
			{
				alert("Dia invalido:" +"\n" +"Use valores entre 01 e 31");
				form.dia_nascimento.focus();
				form.dia_nascimento.select();
				return false;
			}
		break;
		case '02'://fevereiro
		if((retcode=(ano-1900)%4 )== 0) // Se o ano e bissexto
		{
			if(dia<1 || dia>29)
			{
				alert("Dia invalido:" +"\n" +"Use valores entre 01 e 29, pois este e o mes de Fevereiro");
				form.dia_nascimento.focus();
				form.dia_nascimento.select();
				return false;
			}
		}
		else 
			if(dia<1 || dia>28)//O ano nao e bissexto
			{
				alert("Dia invalido:" +"\n" +"Use valores entre 01 e 28, pois este e o mes de Fevereiro");
				form.dia_nascimento.focus();
				form.dia_nascimento.select();
				return false;
			}
		break;
		case '03'://marco
			if(dia<1 || dia>31)
			{
				alert("Dia invalido:" +"\n" +"Use valores entre 01 e 31");
				form.dia_nascimento.focus();
				form.dia_nascimento.select();
				return false;
			}
		break;
		case '04'://abril
		if(dia<1 || dia>30)
		{
			alert("Dia invalido:" +"\n" +"Use valores entre 01 e 30");
			form.dia_nascimento.focus();
			form.dia_nascimento.select();
			return false;
		}
		break;
		case '05'://maio
			if(dia<1 || dia>31)
			{
				alert("Dia invalido:" +"\n" +"Use valores entre 01 e 31");
				form.dia_nascimento.focus();
				form.dia_nascimento.select();
				return false;
			}
		break;
		case '06'://junho
		if(dia<1 || dia>30)
		{
			alert("Dia invalido:" +"\n" +"Use valores entre 01 e 30");
			form.dia_nascimento.focus();
			form.dia_nascimento.select();
			return false;
		}
		break;
		case '07'://julho
			if(dia<1 || dia>31)
			{
				alert("Dia invalido:" +"\n" +"Use valores entre 01 e 31");
				form.dia_nascimento.focus();
				form.dia_nascimento.select();
				return false;
			}
		break;
		case '08'://agosto
			if(dia<1 || dia>31)
			{
				alert("Dia invalido:" +"\n" +"Use valores entre 01 e 31");
				form.dia_nascimento.focus();
				form.dia_nascimento.select();
				return false;
			}
		break;
		case '09'://setembro
			if(dia<1 || dia>30)
			{
				alert("Dia invalido:" +"\n" +"Use valores entre 01 e 30");
				form.dia_nascimento.focus();
				form.dia_nascimento.select();
				return false;
			}
		break;
		case '10'://outubro
			if(dia<1 || dia>31)
			{
				alert("Dia invalido:" +"\n" +"Use valores entre 01 e 31");
				form.dia_nascimento.focus();
				form.dia_nascimento.select();
				return false;
			}
		break;
		case '11'://novembro
			if(dia<1 || dia>30)
			{
				alert("Dia invalido:" +"\n" +"Use valores entre 01 e 30");
				form.dia_nascimento.focus();
				form.dia_nascimento.select();
				return false;
			}
		break;
		case '12'://dezembro
			if(dia<1 || dia>31)
			{
				alert("Dia invalido:" +"\n" +"Use valores entre 01 e 31");
				form.dia_nascimento.focus();
				form.dia_nascimento.select();
				return false;
			}
		break;
		default://mes invalido
		alert("Mes invalido:" +"\n" +"Use valores entre 01 e 12");
		form.mes_nascimento.focus();
		form.mes_nascimento.select();
		return false;
	}
	if ((ano_atual - ano < 1) || (ano_atual - ano > 120) || (ano_atual - ano == 1 && mes_atual - mes < 1) || (ano_atual - ano == 1 && mes_atual == mes && dia_atual - dia < 1))
	{
		alert("Ano invalido:\n A idade nao deve ser maior que 120 anos, nem menor do que 1 ano.");
		form.ano_nascimento.focus();
		form.ano_nascimento.select();
		return false;
	}
	BirthDay = new Date(ano, mes-1 ,dia);
	if(BirthDay.getTime()>today.getTime())
	{
		alert("A data de nascimento nao pode ser posterior a data de hoje");
		form.ano_nascimento.focus();
		form.ano_nascimento.select();
		return false;
	}
	return true;
}

function habilitaIdade(form)
{
	if (form.habilita_idade.checked)
 	{
		form.dia_nascimento.value = "XX";
		form.mes_nascimento.value = "XX";
		form.ano_nascimento.value = "XXXX";
		form.idade.value = "";
		form.idade.readOnly = false;
		form.dia_nascimento.readOnly = true;
		form.mes_nascimento.readOnly = true;
		form.ano_nascimento.readOnly = true;
		form.idade.focus();
		document.getElementById("aproximadamente").innerHTML = tabFields[14][1] + " aproximada:";
	}
	else
	{
		form.dia_nascimento.value = '';
		form.mes_nascimento.value = '';
		form.ano_nascimento.value = '';
		form.idade.value= '';
		form.idade.readOnly = true;
		form.dia_nascimento.readOnly = false;
		form.mes_nascimento.readOnly = false;
		form.ano_nascimento.readOnly = false;
		document.getElementById("aproximadamente").innerHTML = tabFields[14][1] + ":";
		form.dia_nascimento.focus();
	}
}

function calcularAnoNascimento(idade)
{
	today = new Date();
	anoAtual = today.getFullYear();
	return (anoAtual - idade);
}

function calcularIdade(diaNascimento, mesNascimento, anoNascimento)
{
	today = new Date();
	diaAtual =today.getDate();
	mesAtual =today.getMonth();
	anoAtual = today.getFullYear();
	idade= (anoAtual - anoNascimento);
	if(mesNascimento-1 > mesAtual)
		idade--;
	if(mesNascimento-1 == mesAtual)
		if(diaNascimento > diaAtual)
			idade--;
	return(idade);
}

function getElement(aID){ 
    return (document.getElementById(aID)) || document.all[aID];
}

function validarHora(campo)
{
	if (campo.value > 23)
	{
		alert("Digite um valor entre 0 e 23.");
		campo.focus();
		campo.select();
		return false;
	}
	return true;
}

function validarMinuto(campo)
{
	if (campo.value > 59)
	{
		alert("Digite um valor entre 0 e 59.");
		campo.focus();
		campo.select();
		return false;
	}
	return true;
}

function validarTempo(campo)
{
	if(parseInt(document.check.idade.value) < parseInt(campo.value))
	{
		alert("O valor deve ser menor do que a idade do paciente.");
		campo.focus();
		campo.select();
	}
}

function validarQualquerData(campoDia,campoMes,campoAno)
{
	today = new Date();
	dia = Number(campoDia.value);
	mes = Number(campoMes.value);
	ano = Number(campoAno.value);
	dia_atual = today.getDate();
	mes_atual = today.getMonth() + 1;
	ano_atual = today.getFullYear();

	if((dia == 0) && (mes == 0) && (ano == 0))
		return true;
	
	switch(mes)
	{
		case 1://janeiro
			if(dia<1 || dia>31)
			{
				alert("Dia invalidoChange:" +"\n" +"Use valores entre 01 e 31");
				campoDia.value = '';
				campoDia.focus();
				return false;
			}
		break;
		case 2://fevereiro
			if((retcode=(ano-1900)%4 )== 0) // Se o ano e bissexto
			{
				if(dia<1 || dia>29)
				{
					alert("Dia invalido:" +"\n" +"Use valores entre 01 e 29, pois este e o mes de Fevereiro");
					campoDia.value = '';
					campoDia.focus();
					return false;
				}
			}
			else 
				if(dia<1 || dia>28)//O ano nao e bissexto
				{
					alert("Dia invalido:" +"\n" +"Use valores entre 01 e 28, pois este e o mes de Fevereiro");
					campoDia.value = '';
					campoDia.focus();
					return false;
				}
		break;
		case 3://marco
			if(dia<1 || dia>31)
			{
				alert("Dia invalido:" +"\n" +"Use valores entre 01 e 31");
				campoDia.value = '';
				campoDia.focus();
				return false;
			}
		break;
		case 4://abril
			if(dia<1 || dia>30)
			{
				alert("Dia invalido:" +"\n" +"Use valores entre 01 e 30");
				campoDia.value = '';
					campoDia.focus();
				return false;
			}
		break;
		case 5://maio
			if(dia<1 || dia>31)
			{
				alert("Dia invalido:" +"\n" +"Use valores entre 01 e 31");
				campoDia.value = '';
				campoDia.focus();
				return false;
			}
		break;
		case 6://junho
			if(dia<1 || dia>30)
			{
				alert("Dia invalido:" +"\n" +"Use valores entre 01 e 30");
				campoDia.value = '';
					campoDia.focus();
				return false;
			}
		break;
		case 7://julho
			if(dia<1 || dia>31)
			{
				alert("Dia invalido:" +"\n" +"Use valores entre 01 e 31");
				campoDia.value = '';
				campoDia.focus();
				return false;
			}
		break;
		case 8://agosto
			if(dia<1 || dia>31)
			{
				alert("Dia invalido:" +"\n" +"Use valores entre 01 e 31");
				campoDia.value = '';
				campoDia.focus();
				return false;
			}
		break;
		case 9://setembro
			if(dia<1 || dia>30)
			{
				alert("Dia invalido:" +"\n" +"Use valores entre 01 e 30");
				campoDia.value = '';
				campoDia.focus();
				return false;
			}
		break;
		case 10://outubro
			if(dia<1 || dia>31)
			{
				alert("Dia invalido:" +"\n" +"Use valores entre 01 e 31");
				campoDia.value = '';
				campoDia.focus();
				return false;
			}
		break;
		case 11://novembro
			if(dia<1 || dia>30)
			{
				alert("Dia invalido:" +"\n" +"Use valores entre 01 e 30");
				campoDia.value = '';
				campoDia.focus();
				return false;
			}
		break;
		case 12://dezembro
			if(dia<1 || dia>31)
			{
				alert("Dia invalido:" +"\n" +"Use valores entre 01 e 31");
				campoDia.value = '';
				campoDia.focus();
				return false;
			}
		break;
		default://mes invalido
		alert("Mes invalido:" +"\n" +"Use valores entre 01 e 12");
		campoMes.value = '';
		campoMes.focus();
		return false;
	}
	/*if ((ano_atual - ano < 1) || (ano_atual - ano > 120) || (ano_atual - ano == 1 && mes_atual - mes < 1) || (ano_atual - ano == 1 && mes_atual == mes && dia_atual - dia < 1))
	{
		alert("Ano invalido:\n A idade nao deve ser maior que 120 anos, nem menor do que 1 ano.");
		campoAno.focus();
		campoAno.select();
		return false;
	}
	BirthDay = new Date(ano, mes-1 ,dia);
	if(BirthDay.getTime()>today.getTime())
	{
		alert("A data de nascimento nao pode ser posterior a data de hoje");
		campoAno.focus();
		campoAno.select();
		return false;
	} */
	
	if(((dia > dia_atual) && (mes == mes_atual) && (ano == ano_atual)) || ((mes > mes_atual) && (ano == ano_atual)) || (ano > ano_atual))
	{ 	
			alert("A data preenchida não pode ser posterior a data de hoje!");
			campoDia.value = '';
			campoMes.value = '';
			campoAno.value = '';
			campoDia.focus();
			return false;
	}
	
	return true;
}

function showmenu(elmnt)
{
	document.getElementById(elmnt).style.visibility = "visible";
}
function hidemenu(elmnt)
{
	document.getElementById(elmnt).style.visibility = "hidden";
}

function calcularCage(campo)
{
	if (campo == "sim")
	{
		cagePontos += 1;
	}
}

function escreverCage()
{
	if (getCheckedValue(document.check.facilidadeFazerAmizades) == "sim")
	{
		document.check.cage.value = "POSITIVO";
	}
	else
	{
		cagePontos = 0;

		calcularCage(getCheckedValue(document.check.diminuirQtdBebida));
		calcularCage(getCheckedValue(document.check.criticaModoBeber));
		calcularCage(getCheckedValue(document.check.bebidaManha));
		calcularCage(getCheckedValue(document.check.culpadoManeiraBeber));
	
		if (cagePontos < 4)
		{
			document.check.cage.value = "POSITIVO";
		}
		else
		{
			document.check.cage.value = "NEGATIVO";
		}
	}
}

function definirCage()
{
	document.check.cage.value = "Negativo";		
	
	if ((getCheckedValue(document.check.diminuirQtdBebida) == "sim") && (getCheckedValue(document.check.criticaModoBeber) == "sim"))
	{
		document.check.cage.value = "Positivo";
	}
	
	if ((getCheckedValue(document.check.diminuirQtdBebida) == "sim") && (getCheckedValue(document.check.bebidaManha) == "sim"))
	{
		document.check.cage.value = "Positivo";
	}
	
	if ((getCheckedValue(document.check.diminuirQtdBebida) == "sim") && (getCheckedValue(document.check.culpadoManeiraBeber) == "sim"))
	{
		document.check.cage.value = "Positivo";
	}
	
	if ((getCheckedValue(document.check.criticaModoBeber) == "sim") && (getCheckedValue(document.check.bebidaManha) == "sim"))
	{
		document.check.cage.value = "Positivo";
	}
		
	if ((getCheckedValue(document.check.criticaModoBeber) == "sim") && (getCheckedValue(document.check.culpadoManeiraBeber) == "sim"))
	{
		document.check.cage.value = "Positivo";
	}
	
	if ((getCheckedValue(document.check.bebidaManha) == "sim") && (getCheckedValue(document.check.culpadoManeiraBeber) == "sim"))
	{
		document.check.cage.value = "Positivo";
	}
}

function confirmar(form)
{ 
    if (confirm('Tem certeza que quer enviar este formulario?'))
	{ 
       document.form.submit() 
    } 
} 

function arredondarNcasasDecimais (valor, casas)
{
   var numeroArredondado = Math.round(valor * Math.pow(10,casas)) / Math.pow(10,casas);

   //valor = numeroArredondado;
   
   return numeroArredondado;
}

function perdaPeso(habitual,atual)
{
	var perda;
	var habitualDez
	
	perda = habitual - atual;
	habitualDez = habitual * 0.1;
	if (perda > habitualDez)
	{
		document.check.perdaDePeso.value = "SIM";
		document.check.perdaDePeso_semanas.disabled = false;
		document.check.perdaDePeso_semanas.value = '';
	}
	else
	{
		document.check.perdaDePeso.value = "nao";
		document.check.perdaDePeso_semanas.disabled = true;
	}
}

function validarDataExame(dia,mes,ano)
{	
	var d = new Date();
	var Dia = d.getDate();
	var Mes = d.getMonth() + 1;
	var Ano = d.getFullYear();
		
	if (ano.value > Ano)
	{
		alert("Data invalida. Por favor, digite uma data anterior a data de hoje.");
		dia.value="";
		mes.value="";
		ano.value="";
		dia.focus();
	}	
	else
	{
		if (ano.value == Ano)
		{
			if (mes.value > Mes)
			{
				alert("Data invalida. Por favor, digite uma data anterior a data de hoje.");
				dia.value="";
				mes.value="";
				ano.value="";
				dia.focus();
			}
			else
			{
				if (mes.value == Mes)
				{
					if (dia.value > Dia)
					{
						alert("Data invalida. Por favor, digite uma data anterior a data de hoje.");
						dia.value="";
						mes.value="";
						ano.value="";
						dia.focus();
					}	
				}
			}
		}
	}
}


function naturalidade ( campo1, campo2) /* naturalidadeEstado,,, naturalidadeCidade */
{
	if(campo1.value != 'RJ' && campo1.value != '')
		return false;

	if(campo1.value == 'RJ')
		if(campo2.value.toUpperCase() != "RIO DE JANEIRO")
			return false;

	return true;
}

function validar_tempo_de_viagem_custos_A (horaA,minA,horaB,minB,horaC,minC,tempoTotalHora,tempoTotalMin)
/**
	A - Que horas você saiu de casa?
	B - Que horas você chegou no posto?
	C - Que horas você viu o médico?
**/
{
	var tempoA,tempoB,tempoC;
	tempoA = tempoB = tempoC = 0;
	
	tempoA = (Number(horaA.value)*60) + Number(minA.value);
	tempoB = (Number(horaB.value)*60) + Number(minB.value);
	tempoC = (Number(horaC.value)*60) + Number(minC.value);

	if((horaA.value != '') && (minA.value != '') && (horaB.value != '') && (minB.value != ''))
	{
		if(tempoB < tempoA)
		{
			alert("A hora que você chegou no posto de saúde não pode ser anterior a hora que você saiu de casa!");
			horaB.value = '';
			minB.value = '';
			horaB.focus();
			return false;
		}
		
		if((tempoB < tempoA) && (tempoC < tempoB))
		{
			alert("A hora que você chegou no posto de saúde e a hora em que você viu o médico não podem ser anteriores a hora que você saiu de casa!");
			horaB.value = '';
			minB.value = '';
			horaC.value = '';
			minC.value = '';
			horaB.focus();
			return false;
		}
		
		if((horaC.value != '') && (minC.value != ''))
		{	
			if(tempoC < tempoB)
			{
				alert("A hora em que você viu o médico não pode ser anterior a hora que você saiu de casa!");
				horaC.value = '';
				minC.value = '';
				horaC.focus();
				return false
			}
	
			/** CALCULO DO TEMPO QUE LEVOU PARA SAIR DE CASA ATEH SER ATENDIDO PELO MEDICO **/
			
			tempoTotalHora.value = horaC.value - horaA.value;
			
			tempoTotalMin.value = (tempoC - tempoA) % 60;	
		}
	
	}
	
	return true;
}

function validar_hora_escarro (horaA,minA,horaB,minB)
{
/**
	A - Quando você teve que trazer a 2ª amostra de escarro há alguns dias, em que horário você escarrou no potinho?
	B - Que horas você acordou no dia de escarrar pela segunda vez no potinho?
**/
	var tempoA = tempoB = 0;
	
	tempoA = (Number(horaA.value)*60) + Number(minA.value);
	tempoB = (Number(horaB.value)*60) + Number(minB.value);
	
	if((horaA.value != '') && (minA.value != '') && (horaB.value != '') && (minB.value != ''))
		if(tempoA < tempoB)
		{
			alert("A hora em que você coletou o escarro no potinho não pode ser anterior a hora em que você acordou para coletar o escarro!");
			horaB.value = '';
			minB.value = '';
			horaA.value = '';
			minA.value = '';
			horaA.focus();
			return false;
		}
	
	return true;
}
