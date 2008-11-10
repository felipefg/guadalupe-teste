/*
 *	Autor: Igor Cunha Braganca
 */
 
function validar_triagem (form)
{

	var estado = true;
	
	for(indice = 0; indice < 250; indice ++)
	{
		/****************************************************************************************************************************/
		if(indice == 32)/* TRATAMENTO PARA O CAMPO RACA */
		{
			if(form.elements[indice].checked == true) /* raca1 == branco */
			{
				indice += 8;
			}
			else
			{
				indice ++;
				if(form.elements[indice].checked == false)
				{
					estado = false;
					indice += 7;
				}
				else
				{
					indice ++;
					for(contador = 0, radioIndice = 0; form.elements[indice].name == form.elements[indice + 1].name; indice ++, contador ++)
					{
						if(form.elements[indice].checked == true)
							radioIndice ++;
					}
					
					if(form.elements[indice].checked == true)
							radioIndice ++;
					
					if((contador > 1) && (radioIndice != 1)  && (form.elements[indice].disabled == false)) 
					{
						estado = false;
					}
					
					indice ++;
				}
			}
		}
		/****************************************************************************************************************************/
		if(indice == 53)/* TRATAMENTO PARA AS PERGUNTAS DE SINAIS E SINTOMAS */	
		{
			for(;indice < 92; indice ++)
			{
				if(indice == 65)/* Pergunta Hemoptise */
				{
					if(form.elements[indice].checked == true) /* Sim */
					{
						indice += 3;
						if((form.elements[indice].value == "") && (form.elements[indice].disabled == false))
						{
							estado = false;
						}
						
						indice ++;
						for(contador = 0, radioIndice = 0; form.elements[indice].name == form.elements[indice + 1].name; indice ++, contador ++)
						{
							if(form.elements[indice].checked == true)
								radioIndice ++;
						}
						
						if(form.elements[indice].checked == true)
								radioIndice ++;
						
						if((contador > 1) && (radioIndice != 1)  && (form.elements[indice].disabled == false)) 
						{
							estado = false;
						}
					}
					else /* nao ou ignorado */
					{
						indice += 2;
						if((form.elements[indice - 1].checked == false) && (form.elements[indice].checked == false))
						{
							estado = false;
						}
						indice += 4;
					}
				}
				else
				{
					if(form.elements[indice].checked == true) /* Sim */
					{
						indice += 3;
						if((form.elements[indice].value == "") && (form.elements[indice].disabled == false))
						{
							estado = false;
						}
					}
					else /* nao ou ignorado */
					{
						indice += 2;
						if((form.elements[indice - 1].checked == false) && (form.elements[indice].checked == false))
						{
							estado = false;
						}
						indice ++;
					}
				}
			}
			
			if(form.elements[indice + 1].value == "")
			{
							estado = false;
			}
			indice += 2;
		}
		/****************************************************************************************************************************/
		if(indice == 94)/*TRATAMENTO PARA O CAMPO TRATAMENTO TB ANTERIOR  */
		{
			if((form.elements[indice + 1].checked == true) || (form.elements[indice + 2].checked == true))
			{
				indice += 12;
			}
			else
			{
				if(form.elements[indice].checked == false)
					estado = false;
					
				indice += 3;
			}
		}
		/****************************************************************************************************************************/
		if(indice == 115) /* TRATAMENTO PARA O CAMPO Contato com pessoas com TBP */
		{
			if((form.elements[indice + 1].checked == true) || (form.elements[indice + 2].checked == true))
			{
				indice += 18;
			}
			else
			{
				if(form.elements[indice].checked == false)
					estado = false;
					
				indice += 3;
			}
		}
		/****************************************************************************************************************************/
		if(indice == 133) /* TRATAMENTO PARA O CAMPO Fuma */
		{
			if(form.elements[indice + 2].checked == true)
			{
				indice += 5;
			}
			else
			{
				if((form.elements[indice].checked == false) && (form.elements[indice + 1].checked == false))
					estado = false;
				indice += 3;
			}
		}
		/****************************************************************************************************************************/
		if(indice == 138) /*TRATAMENTO PARA O CAMPO Tipo de bebida preferida: */
		{
			if(form.elements[indice + 5].checked == true)
				indice += 17;
			else
			{
				if((form.elements[indice].checked == false) && (form.elements[indice + 1].checked == false) && (form.elements[indice + 2].checked == false) && (form.elements[indice + 3].checked == false) && (form.elements[indice + 4].checked == false))
					estado = false;
				
				indice += 6;
			}
		}
		/****************************************************************************************************************************/
		if((indice == 161)) /* TRATAMENTO PARA O CAMPO Foi emcaminhado para o Posto pelo P. Saúde de Família */
		{
			if((form.elements[indice + 1].checked == true) || (form.elements[indice + 2].checked == true))
			{
				indice += 4;
			}
			else
			{
				if(form.elements[indice].checked == false)
					estado = false;
					
				indice += 3;
			}
		}
		/****************************************************************************************************************************/
		if((indice == 165)) /* TRATAMENTO PARA O CAMPO Foi encaminhado por unidade de saú do SUS */
		{
			if((form.elements[indice + 1].checked == true) || (form.elements[indice + 2].checked == true))
			{
				indice += 4;
			}
			else
			{
				if(form.elements[indice].checked == false)
					estado = false;
					
				indice += 3;
			}
		}
		/****************************************************************************************************************************/
		if((indice == 169)) /* TRATAMENTO PARA O CAMPO Foi encaminhado por unidade de saú Particular */
		{
			if((form.elements[indice + 1].checked == true) || (form.elements[indice + 2].checked == true))
			{
				indice += 4;
			}
			else
			{
				if(form.elements[indice].checked == false)
					estado = false;
					
				indice += 3;
			}
		}
		/****************************************************************************************************************************/
		if((indice == 173) || (indice == 182)) /* TRATAMENTO PARA O CAMPO Decidiu sozinho por auxílio médico na Policlínica ou Fez algum tratamento para tosse, ultimamente*/
		{
			if((form.elements[indice + 1].checked == true) || (form.elements[indice + 2].checked == true))
			{
				if(indice == 182)
					indice ++;
					
				indice += 4;
			}
			else
			{
				if(form.elements[indice].checked == false)
					estado = false;
					
				indice += 3;
			}
		}
		/****************************************************************************************************************************/
		if((indice == 202)) /* TRATAMENTO PARA O CAMPO Trouxe algum outro resultado */
		{
			if((form.elements[indice + 1].checked == true) || (form.elements[indice + 2].checked == true))
			{
				indice += 4;
			}
			else
			{
				if(form.elements[indice].checked == false)
					estado = false;
					
				indice += 3;
			}
		}
		/****************************************************************************************************************************/
		if(indice == 206) /* TRATAMENTO PARA O CAMPO  Desfecho da Consulta Inicial */
		{
			if((form.elements[indice].checked == true) || (form.elements[indice + 1].checked == true) || (form.elements[indice + 4].checked == true) || (form.elements[indice + 7].checked == true))
				indice += 8;
			else
			{
				if((form.elements[indice + 2].checked == false) && (form.elements[indice + 5].checked == false))
					estado = false;
				else
				{
					if((form.elements[indice + 2].checked == true) && (form.elements[indice + 3].value == ''))
						estado = false;
					if((form.elements[indice + 5].checked == true) && (form.elements[indice + 6].value == ''))
						estado = false;
				}
				indice += 8;
			}
		}
		/****************************************************************************************************************************/
		if(indice == 214) /* TRATAMENTO PARA O CAMPO Inclusão: */
		{
			if((form.elements[indice + 1].checked == true) || (form.elements[indice + 2].checked == true))
			{
				indice += 34;
			}
			else
			{
				if(form.elements[indice].checked == false)
					estado = false;
				
				indice += 3;
			}
		}
		/****************************************************************************************************************************/

		if(form.elements[indice].type == "text")
		{
			if((form.elements[indice].value == "") && (form.elements[indice].disabled == false))
				estado = false;
		}
		else
		{
			if(form.elements[indice].type == "radio")
			{
				for(contador = 0, radioIndice = 0; form.elements[indice].name == form.elements[indice + 1].name; indice ++, contador ++)
				{
					if(form.elements[indice].checked == true)
						radioIndice ++;
				}
				
				if(form.elements[indice].checked == true)
						radioIndice ++;
				
				if((contador > 1) && (radioIndice != 1)  && (form.elements[indice].disabled == false)) 
					estado = false;
			}
			else
			{
				if(form.elements[indice].type == "checkbox")
				{
					if((form.elements[indice].name == form.elements[indice + 1].name) && (form.elements[indice].name == form.elements[indice + 2].name))
					{
						if((form.elements[indice].checked == false) && (form.elements[indice+1].checked == false) && (form.elements[indice+2].checked == false))
							estado = false;
											
						indice += 2;
					}
				}
				else
				{
					if(form.elements[indice].type == "select-one")
					{
						if((form.elements[indice].value == "") && (form.elements[indice].disabled == false))
							estado = false;
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
		return false;
	}
	
	if(confirm("Deseja enviar os dados ?"))
		return true;
	else
		return false;
}

function validar_consulta_medica (form)
{
	var estado = true;

	for(indice = 0; indice < 124 ; indice ++)
	{
		/****************************************************************************************************************************/
		if(indice == 5) /* TRATAMENTO PARA O CAMPO Tratamento de TB anterior */
		{
			if((form.elements[indice+1].checked == true) || (form.elements[indice+2].checked == true))
				indice += 10;
			else
			{
				if(form.elements[indice].checked == false)
					estado = false;
				else
					indice += 3;
			}
		}
		/****************************************************************************************************************************/
		if(indice == 18) /* TRATAMENTO PARA O CAMPO Cage positivo */
		{
			if((form.elements[indice+1].checked == true) || (form.elements[indice+2].checked == true))
				indice += 13;
			else
			{
				if(form.elements[indice].checked == false)
					estado = false;
				else
					indice += 3;
			}
		}
		/****************************************************************************************************************************/
		if(indice == 38) /* TRATAMENTO PARA O CAMPO Comorbidades */
		{
			if((form.elements[indice+1].checked == true) || (form.elements[indice+2].checked == true))
				indice += 15;
			else
			{
				if(form.elements[indice].checked == false)
					estado = false;
				else
					indice += 3;
			}
		}
		/****************************************************************************************************************************/
		if(indice == 54) /* TRATAMENTO PARA O CAMPO Exame físico normal */
		{
			if((form.elements[indice].checked == true) || (form.elements[indice+2].checked == true))
				indice += 4;
			else
			{
				if(form.elements[indice+1].checked == false)
					estado = false;
				else
					indice += 3;
			}
		}
		/****************************************************************************************************************************/
		if(indice == 78) /* TRATAMENTO PARA O CAMPO Probabilidade de TB ativa ao avaliar o RXT  (alta, ou media)*/
		{
			indice += 5;
		}
		/****************************************************************************************************************************/
		if(indice == 62) /* TRATAMENTO PARA O CAMPO Probabilidade de TB ativa ao avaliar o RXT (baixa)*/
		{
			if((form.elements[indice].checked == true) || (form.elements[indice+1].checked == true))
				indice += 3;
			else
			{
				if(form.elements[indice+2].checked == false)
					estado = false;
				else
					indice += 15;
			}
		}
		/****************************************************************************************************************************/
		if(indice == 91) /* TRATAMENTO PARA O CAMPO Resultado da Baciloscopia 1 */
		{
			if((form.elements[indice+1].checked == true) || (form.elements[indice+2].checked == true))
				indice += 6;
			else
			{
				if(form.elements[indice].checked == false)
					estado = false;
				indice += 3;
			}
		}
		/****************************************************************************************************************************/
		if(indice == 97) /* TRATAMENTO PARA O CAMPO Resultado da Baciloscopia 2 */
		{
			if((form.elements[indice+1].checked == true) || (form.elements[indice+2].checked == true))
				indice += 6;
			else
			{
				if(form.elements[indice].checked == false)
					estado = false;
				else
					indice += 3;
			}
		}
		/****************************************************************************************************************************/
		if(indice == 108) /* TRATAMENTO PARA O CAMPO Desfecho da consulta inicial */
		{
			if((form.elements[indice].checked == true) || (form.elements[indice+1].checked == true))
				indice += 6;
			else
			{
				if((form.elements[indice+2].checked == false) && (form.elements[indice+3].checked == false) && (form.elements[indice+4].checked == false) && (form.elements[indice+5].checked == false))
					estado = false;
				else
					indice += 13;
			}
		}
		/****************************************************************************************************************************/
		if(form.elements[indice].type == "text")
		{
			if((form.elements[indice].value == "") && (form.elements[indice].disabled == false))
				estado = false;
		}
		else
		{
			if(form.elements[indice].type == "radio")
			{
				for(contador = 0, radioIndice = 0; form.elements[indice].name == form.elements[indice + 1].name; indice ++, contador ++)
				{
					if(form.elements[indice].checked == true)
						radioIndice ++;
				}
				
				if(form.elements[indice].checked == true)
						radioIndice ++;
				
				if((contador > 1) && (radioIndice != 1)  && (form.elements[indice].disabled == false)) 
					estado = false;
			}
			else
			{
				if(form.elements[indice].type == "checkbox")
				{
					if((form.elements[indice].name == form.elements[indice + 1].name) && (form.elements[indice].name == form.elements[indice + 2].name) && (form.elements[indice].name == form.elements[indice + 3].name) && (form.elements[indice].name == form.elements[indice + 4].name) && (form.elements[indice].name == form.elements[indice + 5].name) && (form.elements[indice].name == form.elements[indice + 6].name) && (form.elements[indice].name == form.elements[indice + 7].name) && (form.elements[indice].name == form.elements[indice + 8].name) && (form.elements[indice].name == form.elements[indice + 9].name) && (form.elements[indice].name == form.elements[indice + 10].name) && (form.elements[indice].name == form.elements[indice + 11].name))
					{
						if((form.elements[indice].checked == false) && (form.elements[indice+1].checked == false) && (form.elements[indice+2].checked == false) && (form.elements[indice+3].checked == false) && (form.elements[indice+4].checked == false) && (form.elements[indice+5].checked == false) && (form.elements[indice+6].checked == false) && (form.elements[indice+7].checked == false) && (form.elements[indice+8].checked == false) && (form.elements[indice+9].checked == false) && (form.elements[indice+10].checked == false) && (form.elements[indice+11].checked == false))
							estado = false;
						indice += 2;
					}
				}
				else
				{
					if(form.elements[indice].type == "select-one")
					{
						if((form.elements[indice].value == "") && (form.elements[indice].disabled == false))
							estado = false;
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
		return false;
	}
	
	if(confirm("Deseja enviar os dados ?"))
		return true;
	else
		return false;
}

function validar_custos_a (form)
{
	var estado = true;
	
	var aux1, aux2;
	
	aux1 = aux2 = 0;
	
	for(indice = 0; indice < 51	; indice ++)
	{
		/****************************************************************************************************************************/
		if(indice == 2)/* TRATAMENTO PARA O CAMPO Onde você mora? */
		{
			if(form.elements[indice].checked == true)
				indice += 2;
			else
			{
				if(form.elements[indice+1].checked == false)
					estado = false;
				
				aux1 = 1;
			}
		}
		/****************************************************************************************************************************/
		if(indice == 4)/* TRATAMENTO PARA O CAMPO Como você veio ao posto? Em qual transporte? */
		{
			if(form.elements[indice].checked == true)
				indice += 4;
			else
			{
				if((form.elements[indice+1].checked == false) && (form.elements[indice+2].checked == false))
					estado = false;
					
				indice += 3;
			}
		}
		/****************************************************************************************************************************/
		if(indice == 8)/* TRATAMENTO PARA O CAMPO Você está acompanhado? */
		{
			if(form.elements[indice].checked == true)
				aux2 = 1;

			if((form.elements[indice].checked == false) && (form.elements[indice+1].checked == false))
				estado = false;
					
			indice += 2;
		}
		/****************************************************************************************************************************/
		if(indice == 19)/* TRATAMENTO PARA O CAMPO Amanhã você terá que voltar para trazer outra amostra de escarro. Onde você vai passar a noite? */
		{
			if(aux1 == 0)
				indice += 9;
			else
			{
				if(form.elements[indice].checked == true)
					indice += 9;
				else
				{
					if(form.elements[indice+1].checked == true)
						indice += 3;
					else
					{
						if(form.elements[indice+2].checked == false)
							estado = false;
						indice += 3;
						if((form.elements[indice].checked == false) && (form.elements[indice+1].checked == false))
							estado = false;
						indice += 2;
						if(form.elements[indice].value == "")
							estado = false;
						indice += 4;	
					}					
				}
			}
		}
		/****************************************************************************************************************************/
		if(indice == 34)/* TRATAMENTO PARA O CAMPO Você é estudante? */
		{
			if(form.elements[indice].checked == true)
				indice += 2;
			else
			{
				if(form.elements[indice+1].checked == false)
					estado = false
				indice += 4;
			}
		}
		/****************************************************************************************************************************/
		if(indice == 42)/* TRATAMENTO PARA O CAMPO Quem pagou pela bebida, comida, transporte, hotel, etc.? Você ou seus acompanhantes? */
		{
			if(aux2 == 0)
				indice += 3;
			else
			{
				if(form.elements[indice].checked == true)
					indice += 2;
				else
				{
					if(form.elements[indice+1].checked == false)
						estado = false;
					
					indice += 3;
				}
			}
		}
		/****************************************************************************************************************************/
		if(form.elements[indice].type == "text")
		{
			if((form.elements[indice].value == "") && (form.elements[indice].disabled == false))
				estado = false;
		}
		else
		{
			if(form.elements[indice].type == "radio")
			{
				for(contador = 0, radioIndice = 0; form.elements[indice].name == form.elements[indice + 1].name; indice ++, contador ++)
				{
					if(form.elements[indice].checked == true)
						radioIndice ++;
				}
				
				if(form.elements[indice].checked == true)
						radioIndice ++;
				
				if((contador > 0) && (radioIndice != 1)  && (form.elements[indice].disabled == false)) 
					estado = false;
			}
			else
			{
				if(form.elements[indice].type == "checkbox")
				{
					if((form.elements[indice].name == form.elements[indice + 1].name) && (form.elements[indice].name == form.elements[indice + 2].name) && (form.elements[indice].name == form.elements[indice + 3].name) && (form.elements[indice].name == form.elements[indice + 4].name) && (form.elements[indice].name == form.elements[indice + 5].name) && (form.elements[indice].name == form.elements[indice + 6].name) && (form.elements[indice].name == form.elements[indice + 7].name) && (form.elements[indice].name == form.elements[indice + 8].name) && (form.elements[indice].name == form.elements[indice + 9].name) && (form.elements[indice].name == form.elements[indice + 10].name) && (form.elements[indice].name == form.elements[indice + 11].name))
					{
						if((form.elements[indice].checked == false) && (form.elements[indice+1].checked == false) && (form.elements[indice+2].checked == false) && (form.elements[indice+3].checked == false) && (form.elements[indice+4].checked == false) && (form.elements[indice+5].checked == false) && (form.elements[indice+6].checked == false) && (form.elements[indice+7].checked == false) && (form.elements[indice+8].checked == false) && (form.elements[indice+9].checked == false) && (form.elements[indice+10].checked == false) && (form.elements[indice+11].checked == false))
							estado = false;
						indice += 2;
					}
				}
				else
				{
					if(form.elements[indice].type == "select-one")
					{
						if((form.elements[indice].value == "") && (form.elements[indice].disabled == false))
							estado = false;
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
		return false;
	}
	
	if(confirm("Deseja enviar os dados ?"))
		return true;
	else
		return false;
}

function validar_custos_b_e_c (form)
{
	var estado = true;
	
	for(indice = 0; indice < 61 ; indice ++)
	{
		/****************************************************************************************************************************/
		if(indice == 8)
		{
			if(form.elements[indice].checked == true)
				indice += 4;
			else
			{
				if((form.elements[indice+1].checked == false) && (form.elements[indice+2].checked == false))
					estado = false;
					
				indice += 3;
			}
		}
		/****************************************************************************************************************************/
		if(indice == 48)
		{
			if(form.elements[indice].checked == true)
				indice += 2;
			else
			{
				if(form.elements[indice+1].checked == false)
					estado = false;
					
				indice += 7;
			}
		}
		/****************************************************************************************************************************/
		if(form.elements[indice].type == "text")
		{
			if((form.elements[indice].value == "") && (form.elements[indice].disabled == false))
				estado = false;
		}
		else
		{
			if(form.elements[indice].type == "radio")
			{
				for(contador = 0, radioIndice = 0; form.elements[indice].name == form.elements[indice + 1].name; indice ++, contador ++)
				{
					if(form.elements[indice].checked == true)
						radioIndice ++;
				}
				
				if(form.elements[indice].checked == true)
						radioIndice ++;
				
				if((contador > 0) && (radioIndice != 1)  && (form.elements[indice].disabled == false)) 
					estado = false;
			}
			else
			{
				if(form.elements[indice].type == "checkbox")
				{
					if((form.elements[indice].name == form.elements[indice + 1].name) && (form.elements[indice].name == form.elements[indice + 2].name) && (form.elements[indice].name == form.elements[indice + 3].name) && (form.elements[indice].name == form.elements[indice + 4].name) && (form.elements[indice].name == form.elements[indice + 5].name) && (form.elements[indice].name == form.elements[indice + 6].name) && (form.elements[indice].name == form.elements[indice + 7].name) && (form.elements[indice].name == form.elements[indice + 8].name) && (form.elements[indice].name == form.elements[indice + 9].name) && (form.elements[indice].name == form.elements[indice + 10].name) && (form.elements[indice].name == form.elements[indice + 11].name))
					{
						if((form.elements[indice].checked == false) && (form.elements[indice+1].checked == false) && (form.elements[indice+2].checked == false) && (form.elements[indice+3].checked == false) && (form.elements[indice+4].checked == false) && (form.elements[indice+5].checked == false) && (form.elements[indice+6].checked == false) && (form.elements[indice+7].checked == false) && (form.elements[indice+8].checked == false) && (form.elements[indice+9].checked == false) && (form.elements[indice+10].checked == false) && (form.elements[indice+11].checked == false))
							estado = false;
						indice += 2;
					}
				}
				else
				{
					if(form.elements[indice].type == "select-one")
					{
						if((form.elements[indice].value == "") && (form.elements[indice].disabled == false))
							estado = false;
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
		return false;
	}
	
	if(confirm("Deseja enviar os dados ?"))
		return true;
	else
		return false;

}

function validar_follow_up (form)
{
	var estado = true;
	var aux1 = 0;
	
	for(indice = 0; indice < 153 ; indice ++)
	{
		/****************************************************************************************************************************/
		if(indice == 9)/* TRATAMENTO PARA O CAMPO 02 - Tratamento prescrito para TB:*/
		{
			if((form.elements[indice+1].checked == true) || (form.elements[indice+2].checked == true))
				indice += 15;
			else
			{
				if(form.elements[indice].checked == false)
					estado = false;
				
				indice += 3;
			}
		}
		/****************************************************************************************************************************/
		if(indice == 24)/* TRATAMENTO PARA O CAMPO 03 - Reação adversa dos tuberculostáticos?*/
		{
			if((form.elements[indice+1].checked == true) || (form.elements[indice+2].checked == true) || (form.elements[indice+3].checked == true))
				indice += 34;
			else
			{
				if(form.elements[indice].checked == false)
					estado = false;
				
				indice += 4;
			}
		}
		/****************************************************************************************************************************/
		if(indice == 58)/* TRATAMENTO PARA O CAMPO 04 - Houve óbito?*/
		{
			if((form.elements[indice+1].checked == true) || (form.elements[indice+2].checked == true))
				indice += 6;
			else
			{
				if(form.elements[indice].checked == false)
					estado = false;
				
				indice += 3;
			}
		}
		/****************************************************************************************************************************/
		if(indice == 64)/* TRATAMENTO PARA O CAMPO 05 - Mudança de esquema de tratamento para TB?*/
		{
			if((form.elements[indice+1].checked == true) || (form.elements[indice+2].checked == true) || (form.elements[indice+3].checked == true))
				indice += 21;
			else
			{
				if(form.elements[indice].checked == false)
					estado = false;
				
				indice += 4;
			}
		}
		/****************************************************************************************************************************/
		if(indice == 91)/* TRATAMENTO PARA O CAMPO 09 - Probabilidade de TB ativa ao avaliar o RXT:*/
		{
			if((form.elements[indice].checked == true) || (form.elements[indice+1].checked == true))
			{
				indice += 3;
				aux1 = 1;
			}
			else
			{
				if(form.elements[indice+2].checked == false)
					estado = false;
				
				indice += 16;
			}
		}
		/****************************************************************************************************************************/
		if((indice == 107) && (aux1 == 1))/* TRATAMENTO PARA O CAMPO 09 - Probabilidade de TB ativa ao avaliar o RXT:(caso baixa)*/
		{
			indice += 6;
			aux1 = 0;
		}
		/****************************************************************************************************************************/
		if(indice == 125)/* TRATAMENTO PARA O CAMPO 09 - Probabilidade de TB ativa ao avaliar o RXT:(caso baixa)*/
		{
			if((form.elements[indice].checked == true) || (form.elements[indice+1].checked == true) || (form.elements[indice+2].checked == true) || (form.elements[indice+4].checked == true))
				indice += 15;
			else
			{
				if(form.elements[indice+3].checked == false)
					estado = false;
				
				indice += 5;
			}
		}
		/****************************************************************************************************************************/
		if(form.elements[indice].type == "text")
		{
			if((form.elements[indice].value == "") && (form.elements[indice].disabled == false))
				estado = false;
		}
		else
		{
			if(form.elements[indice].type == "radio")
			{
				for(contador = 0, radioIndice = 0; form.elements[indice].name == form.elements[indice + 1].name; indice ++, contador ++)
				{
					if(form.elements[indice].checked == true)
						radioIndice ++;
				}
				
				if(form.elements[indice].checked == true)
						radioIndice ++;
				
				if((contador > 0) && (radioIndice != 1)  && (form.elements[indice].disabled == false)) 
					estado = false;
			}
			else
			{
				if(form.elements[indice].type == "checkbox")
				{
					for(contador = 0, checkboxIndice = 0; form.elements[indice].name == form.elements[indice + 1].name; indice ++, contador ++)
					{
						if(form.elements[indice].checked == true)
							checkboxIndice ++;
					}
					
					if(form.elements[indice].checked == true)
							checkboxIndice ++;
					
					if((contador > 0) && (checkboxIndice == 0)  && (form.elements[indice].disabled == false)) 
						estado = false;
				}
				else
				{
					if(form.elements[indice].type == "select-one")
					{
						if((form.elements[indice].value == "") && (form.elements[indice].disabled == false))
							estado = false;
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
		return false;
	}
	
	if(confirm("Deseja enviar os dados ?"))
		return true;
	else
		return false;

}
