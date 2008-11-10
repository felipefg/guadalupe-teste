<?xml version="1.0" encoding="ISO-8859-1"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
				xmlns:fo="http://www.w3.org/1999/XSL/Format"
				xmlns="http://www.w3.org/1999/xhtml">


<!-- Crit�rio inicial de triagem para TB pulmonar -->

<xsl:template match="triagem">
			<tr>
				<td class="title" width="50%">N�mero Geral:</td>
				<td class="answer" width="50%"><xsl:value-of select="numeroGeral" /></td>
			</tr>
			<!--<tr>
				<td class="title2">Nome:</td>
				<td class="amswer"><xsl:value-of select="nomeCompleto" /></td>
			</tr>-->
			<tr>
				<td class="title">Idade:</td>
				<td class="answer"><xsl:value-of select="concat(idade, ' ', idade/@unidade)" /></td>
			</tr>
			<tr>
				<td class="title">Sexo:</td>
				<td class="answer"><xsl:value-of select="sexo" /></td>
			</tr>
			<tr>
				<td class="title">Ra�a:</td>
				<td class="answer"><xsl:value-of select="raca1" /></td>
			</tr>
			<xsl:if test="raca1[. != 'branco']">
				<tr>
					<td class="title">Especifica��o:</td>
					<td class="answer"><xsl:value-of select="raca2" /></td>
				</tr>
			</xsl:if>
			<tr>
				<td class="title">Peso habitual:</td>
				<td class="answer"><xsl:value-of select="pesoHabitual" /> kg</td>
			</tr>
			<tr>
				<td class="title">Peso atual:</td>
				<td class="answer"><xsl:value-of select="pesoAtual" /> kg</td>
			</tr>
			
			
			<tr>
				<td class="label" colspan="2">Sinais e Sintomas</td>
			</tr>
			
			
			<tr>
				<td class="title">Tosse:</td>
				<td class="answer"><xsl:value-of select="tosse" />
					<xsl:if test="tosse[(. != 'nao') and (tosse_semanas != '')]">
						<xsl:value-of select="concat('. ',tosse_semanas,' semanas')" />
					</xsl:if>
				</td>
			</tr>
			<tr>
				<td class="title">Expectora��o:</td>
				<td class="answer"><xsl:value-of select="expectoracao" />
					<xsl:if test="expectoracao[(. != 'nao') and (expectoracao_semanas != '')]">
						<xsl:value-of select="concat('. ',expectoracao_semanas,' semanas')" />
					</xsl:if>
				</td>
				
				<!-- repetir para os outros sintomas que tem como info adicional semanas -->
			</tr>
			<tr>
				<td class="title">Hemopt�ico:</td>
				<td class="amswer"><xsl:value-of select="hemoptoico" /></td>
			</tr>
			<tr>
				<td class="title">Hemoptise:</td>
				<td class="answer"><xsl:value-of select="hemoptise" /></td>
			</tr>
			<xsl:if test="hemoptise[. = 'sim']">
				<tr>
					<td class="title">Quantidade:</td>
					<td class="answer"><xsl:value-of select="hemoptiseQtd" /></td>
				</tr>
			</xsl:if>
			<tr>
				<td class="title">Sudorese noturna:</td>
				<td class="answer"><xsl:value-of select="sudorese" /></td>
			</tr>
			<tr>
				<td class="title">Febre:</td>
				<td class="answer"><xsl:value-of select="febre" /></td>
			</tr>
			<tr>
				<td class="title">Dispn�ia:</td>
				<td class="answer"><xsl:value-of select="dispneia" /></td>
			</tr>
			<tr>
				<td class="title">Perda do apetite:</td>
				<td class="answer"><xsl:value-of select="perdaApetite" /></td>
			</tr>
			<tr>
				<td class="title">Perda de peso (> 10%):</td>
				<td class="answer"><xsl:value-of select="perdaDePeso" /></td>
			</tr>
			<tr>
				<td class="title">Dor tor�cica</td>
				<td class="answer"><xsl:value-of select="dorToracica" /></td>
			</tr>
			<tr>
				<td class="title">Total de pontos:</td>
				<td class="answer"><xsl:value-of select="pontuacao" /></td>
			</tr>
			
			
			<tr>
				<td class="label" colspan="2">Hist�ria da Tuberculose</td>
			</tr>
			
			
			<tr>
				<td class="title">Tratamento anterior para TB:</td>
				<td class="answer"><xsl:value-of select="tratamentoAnteriorTB" /></td>
			</tr>
			<xsl:if test="tratamentoAnteriorTB[. = 'sim']">
				<tr>
					<td class="title">Data de diagn�stico de TB no passado:</td>
					<td class="answer"><xsl:value-of select="concat(mes_diagnostico,'/',ano_diagnostico)" /></td>
				</tr>
				<tr>
					<td class="title">TB desfecho:</td>
					<td class="answer"><xsl:value-of select="TBdesfecho" /></td>
				</tr>
			</xsl:if>
			<tr>
				<td class="title">Esteve internado em hospital?</td>
				<td class="answer"><xsl:value-of select="internado" /></td>
			</tr>
			<tr>
				<td class="title">Fuma?</td>
				<td class="answer"><xsl:value-of select="fuma" /></td>
			</tr>
			<xsl:if test="fuma[. != 'nunca']">
				<tr>
					<td class="title">N�mero de cigarros que fuma ou fumava por dia:</td>
					<td class="answer"><xsl:value-of select="fumaQtd" /></td>
				</tr>
				<tr>
					<td class="title">N�mero de anos que fuma ou fumou:</td>
					<td class="answer"><xsl:value-of select="fumaTempo" /></td>
				</tr>
			</xsl:if>
			<tr>
				<td class="title">Cage:</td>
				<td class="answer"><xsl:value-of select="cage" /></td>
			</tr>
			<tr>
				<td class="title">Desfecho da consulta inicial:</td>
				<td class="answer"><xsl:value-of select="desfechoConsultaInicial" /></td>
			</tr>
			<tr>
				<td class="label" colspan="2">Resultado PPD</td>
			</tr>
			<tr>
				<td class="e4">Aplica��o da prova tubercul�nica:</td>
				<td class="answer"><xsl:value-of select="inclusao" /></td>
			</tr>
			<xsl:if test="inclusao[. = 'sim']">
				<tr>
					<td class="e4">Data da aplica��o da prova tubercul�nica:</td>
					<td class="answer"><xsl:value-of select="concat(dia_aplicacao,'/',mes_aplicacao,'/',ano_aplicacao)" /></td>
				</tr>
				<tr>
					<td class="e4">Data da leitura:</td>
					<td class="answer"><xsl:value-of select="concat(dia_leitura,'/',mes_leitura,'/',ano_leitura)" /></td>
				</tr>
				<tr>
					<td class="e4">Resultado da leitura (mil�metros de endura��o):</td>
					<td class="answer"><xsl:value-of select="resultadoLeitura" /></td>
				</tr>
				<tr>
					<td class="e4">PT primeira dose Leitor:</td>
					<td class="answer"><xsl:value-of select="PTprimeiraDose" /></td>
				</tr>
			</xsl:if>
			<tr>
				<td class="label" colspan="2"></td>
			</tr>
			<tr>
				<td class="title">Avaliado pelo(a) enfermeiro(a):</td>
				<td class="answer"><xsl:value-of select="avaliador" /></td>
			</tr>
			<tr>
				<td class="title">Data da avalia��o:</td>
				<td class="answer"><xsl:value-of select="concat(dia_inclusao,'/',mes_inclusao,'/',ano_inclusao,' ',hora_inclusao)" /></td>
			</tr>
			<tr>
				<td class="title">Observa��es:</td>
				<td class="answer"><xsl:value-of select="observacoes" /></td>
			</tr>
</xsl:template>


<!-- Question�rio custos: Parte A -->

<xsl:template match="custosA">
			<tr>
				<td class="title">Onde mora?</td>
				<td class="amswer"><xsl:value-of select="ondeMora" /></td>
			</tr>
			<tr>
				<td class="title2">Como veio ao posto?</td>
				<td class="amswer"><xsl:value-of select="transporte" /></td>
			</tr>
			<tr>
				<td class="title2">Quanto custou o transporte?</td>
				<td class="amswer"><xsl:value-of select="custoTransporteA" /></td>
			</tr>
			<tr>
				<td class="title">Est� acompanhado? Por quantas pessoas?</td>
				<td class="amswer"><xsl:value-of select="acompanhadoA" />. <xsl:value-of select="numeroAcompanhantesA" /></td>
			</tr>
			<tr>
				<td class="title2">Que horas saiu de casa?</td>
				<td class="amswer"><xsl:value-of select="horaSaidaCasaA" /></td>
			</tr>
			<tr>
				<td class="title">Que horas chegou no posto?</td>
				<td class="amswer"><xsl:value-of select="horaChegadaPostoA" /></td>
			</tr>
			<tr>
				<td class="title2">Que horas viu o m�dico?</td>
				<td class="amswer"><xsl:value-of select="horaMedicoA" /></td>
			</tr>
			<tr>
				<td class="title">Quanto tempo levou desde que saiu de casa?</td>
				<td class="amswer"><xsl:value-of select="tempoTotalA" /></td>
			</tr>
			<tr>
				<td class="title2">Se o paciente mora fora da cidade do Rio de Janeiro: Amanh� ter� que voltar para trazer outra amostra de escarro. Onde vai passar a noite? </td>
				<td class="amswer"><xsl:value-of select="pernoite" /></td>
			</tr>
			<tr>
				<td class="title">Se o paciente n�o passar a noite em casa, ter� que pagar o pernoite?</td>
				<td class="amswer"><xsl:value-of select="pagarPernoite" /></td>
			</tr>
			<tr>
				<td class="title">Quanto dever� gastar?</td>
				<td class="amswer"><xsl:value-of select="custoPernoite" /></td>
			</tr>
			<tr>
				<td class="title2">Se o paciente n�o tiver que pagar: trouxe algo para seus amigos?</td>
				<td class="amswer"><xsl:value-of select="trouxeAlgoAmigos" /></td>
			</tr>
			<tr>
				<td class="title2">Quanto custou?</td>
				<td class="amswer"><xsl:value-of select="custoAmigos" /></td>
			</tr>
			<tr>
				<td class="title">Desde que saiu de casa, comeu ou bebeu alguma coisa?</td>
				<td class="amswer"><xsl:value-of select="comeuBebeuA" /></td>
			</tr>
			<tr>
				<td class="title">Quanto custou?</td>
				<td class="amswer"><xsl:value-of select="custoComidaBebidaA" /></td>
			</tr>
			<tr>
				<td class="title2">Teve que pagar algo aqui no posto?</td>
				<td class="amswer"><xsl:value-of select="pagarPostoA" /></td>
			</tr>
			<tr>
				<td class="title2">Quanto custou?</td>
				<td class="amswer"><xsl:value-of select="custoPostoA" /></td>
			</tr>
			<tr>
				<td class="title">Profiss�o:</td>
				<td class="amswer"><xsl:value-of select="profissao" /></td>
			</tr>
			<tr>
				<td class="title2">Se o paciente for um estudante, ele perdeu aula hoje?</td>
				<td class="amswer"><xsl:value-of select="estudantePerdeuAula" /></td>
			</tr>
			<tr>
				<td class="title">Deixou de ganhar dinheiro hoje para poder vir ao posto?</td>
				<td class="amswer"><xsl:value-of select="deixouGanharDinheiroA" /></td>
			</tr>
			<tr>
				<td class="title">Quanto deixou de ganhar?</td>
				<td class="amswer"><xsl:value-of select="quantoDeixouGanharA" /></td>
			</tr>
			<tr>
				<td class="title2">Se o paciente estiver acompanhado: Quem pagou pela bebida, comida, transporte, hotel, etc? O paciente ou seus acompanhantes?</td>
				<td class="amswer"><xsl:value-of select="quemArcouCustos" /></td>
			</tr>
			<tr>
				<td class="title2">Quanto voc� gastou com seu acompanhante?</td>
				<td class="amswer"><xsl:value-of select="gastoAcompanhante" /></td>
			</tr>
			<tr>
				<td class="evaluated">Avaliado pelo(a) enfermeiro(a): <xsl:value-of select="avaliadorEnfermeiroA" /></td>
				<td class="evaluated">Data da avalia��o: <xsl:value-of select="diaCustoA" />/<xsl:value-of select="mesCustoA" />/<xsl:value-of select="anoCustoA" /></td>
			</tr>
</xsl:template>


<!-- Consulta m�dica -->

<xsl:template match="consultaMedica">
			
			<tr>
				<td class="title">INH:</td>
				<td class="amswer"><xsl:value-of select="inh" /></td>
			</tr>
			<tr>
				<td class="title2">RIF:</td>
				<td class="amswer"><xsl:value-of select="rif" /></td>
			</tr>
			<tr>
				<td class="title">Qual esquema?</td>
				<td class="amswer"><xsl:value-of select="qualEsquema" /></td>
			</tr>
			
			<tr>
				<td class="title4" colspan="2">Quimioprofilaxia Pr�via para TB</td>
			</tr>
			
			<tr>
				<td class="title">Quimioprofilaxia:</td>
				<td class="amswer"><xsl:value-of select="quimioprofilaxia" /></td>
			</tr>
			<tr>
				<td class="title">Se Cage positivo, usou INH?</td>
				<td class="amswer"><xsl:value-of select="inhCagePositivo" /></td>
			</tr>
			<tr>
				<td class="title">Se Cage positivo, usou RIF?</td>
				<td class="amswer"><xsl:value-of select="rifCagePositivo" /></td>
			</tr>
			<tr>
				<td class="title">Data da quimioprofilaxia:</td>
				<td class="amswer"><xsl:value-of select="dataQuimio" /></td>
			</tr>
			<tr>
				<td class="title">Desfecho:</td>
				<td class="amswer"><xsl:value-of select="desfechoQuimio" /></td>
			</tr>
			
			
			<tr>
				<td class="title4" colspan="2">HIV/AIDS</td>
			</tr>
			
			
			<tr>
				<td class="title">HIV teste:</td>
				<td class="amswer"><xsl:value-of select="testeHIV" /></td>
			</tr>
			<tr>
				<td class="title2">Data do Anti-HIV:</td>
				<td class="amswer"><xsl:value-of select="dataAntiHIV" /></td>
			</tr>
			<tr>
				<td class="title">Comorbidades:</td>
				<td class="amswer"><xsl:value-of select="comorbidades" /></td>
			</tr>
			
			
			<tr>
				<td class="title4" colspan="2">Avalia��o cl�nica</td>
			</tr>
			
			
			<tr>
				<td class="title">Probabilidade de TB ativa: </td>
				<td class="amswer"><xsl:value-of select="probTBativa" /></td>
			</tr>
			<tr>
				<td class="title2">Probabilidade do diagn�stico de TB pulmonar ativa sem avaliar RX de t�rax ou BAAR:</td>
				<td class="amswer"><xsl:value-of select="porcentagemProbTBsemRXsemBAAR" /></td>
			</tr>
			
			<tr>
				<td class="title4" colspan="2">RX de t�rax</td>
			</tr>
			
			<tr>
				<td class="title">Probabilidade de TB ativa ao avaliar o RXT:</td>
				<td class="amswer"><xsl:value-of select="probTBativaComRX" /></td>
			</tr>
			<tr>
				<td class="title2">Cavita��o:</td>
				<td class="amswer"><xsl:value-of select="cavitacao" /></td>
			</tr>
			<tr>
				<td class="title2">Padr�o t�pico (infiltrado em lobo(s) superior(es) e/ou segmento apical de lobo inferior):</td>
				<td class="amswer"><xsl:value-of select="padraoTipico" /></td>
			</tr>
			<tr>
				<td class="title2">Compat�vel (alargamento mediastinal ou linf. hilar, padr�o miliar,ou derrame pleural):</td>
				<td class="amswer"><xsl:value-of select="compativel" /></td>
			</tr>
			<tr>
				<td class="title2">At�pico (qualquer outro padr�o):</td>
				<td class="amswer"><xsl:value-of select="atipico" /></td>
			</tr>
			<tr>
				<td class="title2">NSA</td>
				<td class="amswer"><xsl:value-of select="NSA" /></td>
			</tr>
			<tr>
				<td class="title">Em caso de baixa probabilidade de TB ativa:</td>
				<td class="amswer"><xsl:value-of select="casoBaixaProbabilidade" /></td>
			</tr>
			<tr>
				<td class="title2">Data do RX:</td>
				<td class="amswer"><xsl:value-of select="dataRX" /></td>
			</tr>
			<tr>
				<td class="title">Diagn�stico de probabilidade tendo informa��o sobre o RX de t�rax mas sem conhecimento dos resultados bacteriol�gicos:</td>
				<td class="amswer"><xsl:value-of select="diagnosticoProbabilidadeRX" /></td>
			</tr>
			<tr>
				<td class="title2">Probabilidade do diagn�stico de TB pulmonar ativa com a avalia��o do RX de t�rax e SEM  RESULTADO DA BACILOSCOPIA (BAAR):</td>
				<td class="amswer"><xsl:value-of select="probabilidadeTBcomRXsemBAAR" /></td>
			</tr>
			<tr>
				<td class="title">Resultado da Baciloscopia 1:</td>
				<td class="amswer"><xsl:value-of select="resultadoBaciloscopia1" /></td>
			</tr>
			<tr>
				<td class="title">Resultado da Baciloscopia 2:</td>
				<td class="amswer"><xsl:value-of select="resultadoBaciloscopia2" /></td>
			</tr>
			<tr>
				<td class="title2">Caso as duas baciloscopias iniciais sejam negativas qual seria o diagn�stico de probabilidade de TB?</td>
				<td class="amswer"><xsl:value-of select="diagnosticoProbabilidadeCasoDuasNegativas" /></td>
			</tr>
			<tr>
				<td class="title">Probabilidade do diagn�stico de TB pulmonar ativa com a avalia��o do RX de t�rax e do BAAR:</td>
				<td class="amswer"><xsl:value-of select="probabilidadeTBcomRXcomBAAR" /></td>
			</tr>
			<tr>
				<td class="title2">Desfecho consulta inicial:</td>
				<td class="amswer"><xsl:value-of select="desfechoConsultaInicial" /></td>
			</tr>
			<tr>
				<td class="title2">Em caso de tratamento para TB, qual?</td>
				<td class="amswer"><xsl:value-of select="casoTratamentoTB" /></td>
			</tr>
			<tr>
				<td class="title2">Fatores de risco para TBP MDR:</td>
				<td class="amswer"><xsl:value-of select="fatoresRisco" /></td>
			</tr>
			<tr>
				<td class="evaluated">Avaliado pelo(a) m�dico(a): <xsl:value-of select="avaliadorMedico1" /></td>
				<td class="evaluated">Data da avalia��o: <xsl:value-of select="dataMedico1" /></td>
			</tr>
</xsl:template>


<!-- Question�rio custos: Partes B e C -->

<xsl:template match="custosBeC">
			
			<!-- Parte B -->
			
			<tr>
				<td class="title">Tem o resultado dos exames?</td>
				<td class="amswer"><xsl:value-of select="resultadoExames" /></td>
			</tr>
			<tr>
				<td class="title2">Quantas vezes veio ao posto para pegar os resultados dos exames?</td>
				<td class="amswer"><xsl:value-of select="quantasVezesVeioPosto" /></td>
			</tr>
			<tr>
				<td class="title">Como veio ao posto? Em qual transporte?</td>
				<td class="amswer"><xsl:value-of select="comoVeioPosto" /></td>
			</tr>
			<tr>
				<td class="title">Se n�o veio a p� quanto custou o transporte?</td>
				<td class="amswer"><xsl:value-of select="custoTransporteB" /></td>
			</tr>
			<tr>
				<td class="title2">Voc� est� acompanhado? Por quantas pessoas?</td>
				<td class="amswer"><xsl:value-of select="acompanhadoB" />. <xsl:value-of select="numeroAcompanhantesB" /></td>
			</tr>
			<tr>
				<td class="title">Que horas saiu de casa?</td>
				<td class="amswer"><xsl:value-of select="horaSaidaCasaB" /></td>
			</tr>
			<tr>
				<td class="title2">Que horas chegou no posto?</td>
				<td class="amswer"><xsl:value-of select="horaChegadaPostoB" /></td>
			</tr>
			<tr>
				<td class="title">Que horas viu o m�dico?</td>
				<td class="amswer"><xsl:value-of select="horaMedicoB" /></td>
			</tr>
			<tr>
				<td class="title2">Quanto tempo levou desde que saiu de casa?</td>
				<td class="amswer"><xsl:value-of select="tempoTotalB" /></td>
			</tr>
			<tr>
				<td class="title">Quando teve que trazer a segunda amostra de escarro h� alguns dias, em que hor�rio escarrou no potinho?</td>
				<td class="amswer"><xsl:value-of select="horarioEscarro" /></td>
			</tr>
			<tr>
				<td class="title2">Que horas acordou no dia de escarrar pela segunda vez no potinho?</td>
				<td class="amswer"><xsl:value-of select="horarioEscarro" /></td><!-- ............... -->
			</tr>
			<tr>
				<td class="title">Recebeu uma receita com antibi�ticos?</td>
				<td class="amswer"><xsl:value-of select="receitaAntibioticos" /></td>
			</tr>
			<tr>
				<td class="title2">Pediu para fazer um RX?</td>
				<td class="amswer"><xsl:value-of select="pediuRX" /></td>
			</tr>
			<tr>
				<td class="title">Desde que saiu de casa, comeu ou bebeu alguma coisa?</td>
				<td class="amswer"><xsl:value-of select="comeuBebeuB" /></td>
			</tr>
			<tr>
				<td class="title">Quanto custou?</td>
				<td class="amswer"><xsl:value-of select="custoComidaBebidaB" /></td>
			</tr>
			<tr>
				<td class="title2">Teve que pagar algo aqui no posto?</td>
				<td class="amswer"><xsl:value-of select="pagarPostoB" /></td>
			</tr>
			<tr>
				<td class="title2">Quanto custou?</td>
				<td class="amswer"><xsl:value-of select="custoPostoB" /></td>
			</tr>
			<tr>
				<td class="title">Deixou de ganhar dinheiro hoje para poder vir ao posto?</td>
				<td class="amswer"><xsl:value-of select="deixouGanharDinheiroB" /></td>
			</tr>
			<tr>
				<td class="title">Quanto deixou de ganhar?</td>
				<td class="amswer"><xsl:value-of select="quantoDeixouGanharB" /></td>
			</tr>
			<tr>
				<td class="title2">J� sabe o resultado dos exames de escarro?</td>
				<td class="amswer"><xsl:value-of select="resultadoExamesEscarro" /></td>
			</tr>
			<tr>
				<td class="title">Se o paciente tiver TB: Foi registrado no programa de tratamento de TB?</td>
				<td class="amswer"><xsl:value-of select="registroProgramaTratamentoTB" /></td>
			</tr>
			
			<!-- Parte C -->
			
			<tr>
				<td class="title2">Teve que pagar algo aqui no posto?</td>
				<td class="amswer"><xsl:value-of select="pagarPostoC" /></td>
			</tr>
			<tr>
				<td class="title2">Quanto custou?</td>
				<td class="amswer"><xsl:value-of select="custoPostoC" /></td>
			</tr>
			<tr>
				<td class="title">H� quanto tempo estava sentindo-se diferente ou doente, antes de vir ao posto?</td>
				<td class="amswer"><xsl:value-of select="tempoDoente" /></td>
			</tr>
			<tr>
				<td class="title2">Antes de ser diagnosticado no posto, voc� foi a alguma outra unidade de sa�de?</td>
				<td class="amswer"><xsl:value-of select="outraUnidadeSaude" /></td>
			</tr>
			<tr>
				<td class="title2">Este local era:</td>
				<td class="amswer"><xsl:value-of select="naturezaLocal" /></td>
			</tr>
			<tr>
				<td class="evaluated">Avaliado pelo(a) enfermeiro(a): <xsl:value-of select="avaliadorEnfermeiroBeC" /></td>
				<td class="evaluated">Data da avalia��o: <xsl:value-of select="dataEnfermeiroBeC" /></td>
			</tr>
</xsl:template>


<!-- Follow Up -->

<xsl:template match="followUp">
			<tr>
				<td class="title">Crit�rio de Entrada:</td>
				<td class="amswer"><xsl:value-of select="criterioEntrada" /></td>
			</tr>
			<tr>
				<td class="title2">Tratamento prescrito para TB:</td>
				<td class="amswer"><xsl:value-of select="tratamentoPrescritoTB" /></td>
			</tr>
			<tr>
				<td class="title2">Data do in�cio:</td>
				<td class="amswer"><xsl:value-of select="tratamentoPrescritoTBData" /></td>
			</tr>
			<tr>
				<td class="title2">F�rmacos utilizados:</td>
				<td class="amswer"><xsl:value-of select="tratamentoPrescritoTBFarmacos" /></td>
			</tr>
			<tr>
				<td class="title">Rea��o adversa dos tuberculost�ticos?</td>
				<td class="amswer"><xsl:value-of select="reacoesAdversasTuberculostaticos" /></td>
			</tr>
			<tr>
				<td class="title">Maiores:</td>
				<td class="amswer"><xsl:value-of select="reacoesAdversasTuberculostaticosMaiores" /></td>
			</tr>
			<tr>
				<td class="title">Menores:</td>
				<td class="amswer"><xsl:value-of select="reacoesAdversasTuberculostaticosMenores" /></td>
			</tr>
			<tr>
				<td class="title2">Houve �bito?</td>
				<td class="amswer"><xsl:value-of select="obito" /></td>
			</tr>
			<tr>
				<td class="title2">Qual a causa?</td>
				<td class="amswer"><xsl:value-of select="casoObito" /></td>
			</tr>
			<tr>
				<td class="title">Mudan�a de esquema de tratamento para TB?</td>
				<td class="amswer"><xsl:value-of select="mudancaEsquemaTratamentoTB" /></td>
			</tr>
			<tr>
				<td class="title">Data da mudan�a:</td>
				<td class="amswer"><xsl:value-of select="mudancaData" /></td>
			</tr>
			<tr>
				<td class="title">F�rmacos utilizados:</td>
				<td class="amswer"><xsl:value-of select="mudancaFarmacos" /></td>
			</tr>
			<tr>
				<td class="title">Motivo:</td>
				<td class="amswer"><xsl:value-of select="mudancaMotivo" /></td>
			</tr>
			<tr>
				<td class="title2">Tosse diminu�da:</td>
				<td class="amswer"><xsl:value-of select="tosseDiminuida" /></td>
			</tr>
			<tr>
				<td class="title">Peso atual:</td>
				<td class="amswer"><xsl:value-of select="concat(pesoAtual90dias, ' ', pesoAtual90dias/@unidade)" /></td>
			</tr>
			<tr>
				<td class="title2">Probabilidade de TB ativa ao avaliar o RXT:</td>
				<td class="amswer"><xsl:value-of select="probabilidadeTBAtivaAposEstudoRX" /></td>
			</tr>
			<tr>
				<td class="title">Cavita��o:</td>
				<td class="amswer"><xsl:value-of select="cavitacao90dias" /></td>
			</tr>
			<tr>
				<td class="title">Padr�o t�pico (infiltrado em lobo(s) superior(es) e/ou segmento apical de lobo inferior):</td>
				<td class="amswer"><xsl:value-of select="padraoTipico90dias" /></td>
			</tr>
			<tr>
				<td class="title">Compat�vel (alargamento mediastinal ou linf. hilar , padr�o miliar,ou derrame pleural):</td>
				<td class="amswer"><xsl:value-of select="compativel90dias" /></td>
			</tr>
			<tr>
				<td class="title">At�pico (qualquer outro padr�o):</td>
				<td class="amswer"><xsl:value-of select="atipico90dias" /></td>
			</tr>
			<tr>
				<td class="title">NSA</td>
				<td class="amswer"><xsl:value-of select="NSA90dias" /></td>
			</tr>
			<tr>
				<td class="title2">Em caso de baixa probabilidade de TB ativa:</td>
				<td class="amswer"><xsl:value-of select="casoBaixaProbabilidade90dias" /></td>
			</tr>
			<tr>
				<td class="title">Data do RX:</td>
				<td class="amswer"><xsl:value-of select="dataRX90dias" /></td>
			</tr>
			<tr>
				<td class="title2">Follow up do RX de T�rax (compare com o RXT inicial como o atual):</td>
				<td class="amswer"><xsl:value-of select="followUpRXTorax" /></td>
			</tr>
			<tr>
				<td class="title">HIV teste:</td>
				<td class="amswer"><xsl:value-of select="testeHIV90dias" /></td>
			</tr>
			<tr>
				<td class="title2">Data do Anti-HIV:</td>
				<td class="amswer"><xsl:value-of select="dataAntiHIV90dias" /></td>
			</tr>
			<tr>
				<td class="title">Diagn�stico 90 dias:</td>
				<td class="amswer"><xsl:value-of select="diagnostico90dias" /></td>
			</tr>
			<tr>
				<td class="title2">Em caso de outro diagn�stico diferente de TB, qual?</td>
				<td class="amswer"><xsl:value-of select="diagnosticoFinal" /></td>
			</tr>
			<tr>
				<td class="evaluated">Avaliado pelo(a) m�dico(a): <xsl:value-of select="avaliadorMedicoFollowUp" /></td>
				<td class="evaluated">Data da avalia��o: <xsl:value-of select="dataMedicoFollowUp" /></td>
			</tr>
</xsl:template>

</xsl:stylesheet>
