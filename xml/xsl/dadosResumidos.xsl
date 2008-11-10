<?xml version="1.0" encoding="ISO-8859-1"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
				xmlns:fo="http://www.w3.org/1999/XSL/Format"
				xmlns="http://www.w3.org/1999/xhtml">


<!-- Critério inicial de triagem para TB pulmonar -->

<xsl:template match="triagem">
			<tr>
				<td class="title" width="50%">Número Geral:</td>
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
				<td class="title">Raça:</td>
				<td class="answer"><xsl:value-of select="raca1" /></td>
			</tr>
			<xsl:if test="raca1[. != 'branco']">
				<tr>
					<td class="title">Especificação:</td>
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
				<td class="title">Expectoração:</td>
				<td class="answer"><xsl:value-of select="expectoracao" />
					<xsl:if test="expectoracao[(. != 'nao') and (expectoracao_semanas != '')]">
						<xsl:value-of select="concat('. ',expectoracao_semanas,' semanas')" />
					</xsl:if>
				</td>
				
				<!-- repetir para os outros sintomas que tem como info adicional semanas -->
			</tr>
			<tr>
				<td class="title">Hemoptóico:</td>
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
				<td class="title">Dispnéia:</td>
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
				<td class="title">Dor torácica</td>
				<td class="answer"><xsl:value-of select="dorToracica" /></td>
			</tr>
			<tr>
				<td class="title">Total de pontos:</td>
				<td class="answer"><xsl:value-of select="pontuacao" /></td>
			</tr>
			
			
			<tr>
				<td class="label" colspan="2">História da Tuberculose</td>
			</tr>
			
			
			<tr>
				<td class="title">Tratamento anterior para TB:</td>
				<td class="answer"><xsl:value-of select="tratamentoAnteriorTB" /></td>
			</tr>
			<xsl:if test="tratamentoAnteriorTB[. = 'sim']">
				<tr>
					<td class="title">Data de diagnóstico de TB no passado:</td>
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
					<td class="title">Número de cigarros que fuma ou fumava por dia:</td>
					<td class="answer"><xsl:value-of select="fumaQtd" /></td>
				</tr>
				<tr>
					<td class="title">Número de anos que fuma ou fumou:</td>
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
				<td class="e4">Aplicação da prova tuberculínica:</td>
				<td class="answer"><xsl:value-of select="inclusao" /></td>
			</tr>
			<xsl:if test="inclusao[. = 'sim']">
				<tr>
					<td class="e4">Data da aplicação da prova tuberculínica:</td>
					<td class="answer"><xsl:value-of select="concat(dia_aplicacao,'/',mes_aplicacao,'/',ano_aplicacao)" /></td>
				</tr>
				<tr>
					<td class="e4">Data da leitura:</td>
					<td class="answer"><xsl:value-of select="concat(dia_leitura,'/',mes_leitura,'/',ano_leitura)" /></td>
				</tr>
				<tr>
					<td class="e4">Resultado da leitura (milímetros de enduração):</td>
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
				<td class="title">Data da avaliação:</td>
				<td class="answer"><xsl:value-of select="concat(dia_inclusao,'/',mes_inclusao,'/',ano_inclusao,' ',hora_inclusao)" /></td>
			</tr>
			<tr>
				<td class="title">Observações:</td>
				<td class="answer"><xsl:value-of select="observacoes" /></td>
			</tr>
</xsl:template>


<!-- Questionário custos: Parte A -->

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
				<td class="title">Está acompanhado? Por quantas pessoas?</td>
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
				<td class="title2">Que horas viu o médico?</td>
				<td class="amswer"><xsl:value-of select="horaMedicoA" /></td>
			</tr>
			<tr>
				<td class="title">Quanto tempo levou desde que saiu de casa?</td>
				<td class="amswer"><xsl:value-of select="tempoTotalA" /></td>
			</tr>
			<tr>
				<td class="title2">Se o paciente mora fora da cidade do Rio de Janeiro: Amanhã terá que voltar para trazer outra amostra de escarro. Onde vai passar a noite? </td>
				<td class="amswer"><xsl:value-of select="pernoite" /></td>
			</tr>
			<tr>
				<td class="title">Se o paciente não passar a noite em casa, terá que pagar o pernoite?</td>
				<td class="amswer"><xsl:value-of select="pagarPernoite" /></td>
			</tr>
			<tr>
				<td class="title">Quanto deverá gastar?</td>
				<td class="amswer"><xsl:value-of select="custoPernoite" /></td>
			</tr>
			<tr>
				<td class="title2">Se o paciente não tiver que pagar: trouxe algo para seus amigos?</td>
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
				<td class="title">Profissão:</td>
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
				<td class="title2">Quanto você gastou com seu acompanhante?</td>
				<td class="amswer"><xsl:value-of select="gastoAcompanhante" /></td>
			</tr>
			<tr>
				<td class="evaluated">Avaliado pelo(a) enfermeiro(a): <xsl:value-of select="avaliadorEnfermeiroA" /></td>
				<td class="evaluated">Data da avaliação: <xsl:value-of select="diaCustoA" />/<xsl:value-of select="mesCustoA" />/<xsl:value-of select="anoCustoA" /></td>
			</tr>
</xsl:template>


<!-- Consulta médica -->

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
				<td class="title4" colspan="2">Quimioprofilaxia Prévia para TB</td>
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
				<td class="title4" colspan="2">Avaliação clínica</td>
			</tr>
			
			
			<tr>
				<td class="title">Probabilidade de TB ativa: </td>
				<td class="amswer"><xsl:value-of select="probTBativa" /></td>
			</tr>
			<tr>
				<td class="title2">Probabilidade do diagnóstico de TB pulmonar ativa sem avaliar RX de tórax ou BAAR:</td>
				<td class="amswer"><xsl:value-of select="porcentagemProbTBsemRXsemBAAR" /></td>
			</tr>
			
			<tr>
				<td class="title4" colspan="2">RX de tórax</td>
			</tr>
			
			<tr>
				<td class="title">Probabilidade de TB ativa ao avaliar o RXT:</td>
				<td class="amswer"><xsl:value-of select="probTBativaComRX" /></td>
			</tr>
			<tr>
				<td class="title2">Cavitação:</td>
				<td class="amswer"><xsl:value-of select="cavitacao" /></td>
			</tr>
			<tr>
				<td class="title2">Padrão típico (infiltrado em lobo(s) superior(es) e/ou segmento apical de lobo inferior):</td>
				<td class="amswer"><xsl:value-of select="padraoTipico" /></td>
			</tr>
			<tr>
				<td class="title2">Compatível (alargamento mediastinal ou linf. hilar, padrão miliar,ou derrame pleural):</td>
				<td class="amswer"><xsl:value-of select="compativel" /></td>
			</tr>
			<tr>
				<td class="title2">Atípico (qualquer outro padrão):</td>
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
				<td class="title">Diagnóstico de probabilidade tendo informação sobre o RX de tórax mas sem conhecimento dos resultados bacteriológicos:</td>
				<td class="amswer"><xsl:value-of select="diagnosticoProbabilidadeRX" /></td>
			</tr>
			<tr>
				<td class="title2">Probabilidade do diagnóstico de TB pulmonar ativa com a avaliação do RX de tórax e SEM  RESULTADO DA BACILOSCOPIA (BAAR):</td>
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
				<td class="title2">Caso as duas baciloscopias iniciais sejam negativas qual seria o diagnóstico de probabilidade de TB?</td>
				<td class="amswer"><xsl:value-of select="diagnosticoProbabilidadeCasoDuasNegativas" /></td>
			</tr>
			<tr>
				<td class="title">Probabilidade do diagnóstico de TB pulmonar ativa com a avaliação do RX de tórax e do BAAR:</td>
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
				<td class="evaluated">Avaliado pelo(a) médico(a): <xsl:value-of select="avaliadorMedico1" /></td>
				<td class="evaluated">Data da avaliação: <xsl:value-of select="dataMedico1" /></td>
			</tr>
</xsl:template>


<!-- Questionário custos: Partes B e C -->

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
				<td class="title">Se não veio a pé quanto custou o transporte?</td>
				<td class="amswer"><xsl:value-of select="custoTransporteB" /></td>
			</tr>
			<tr>
				<td class="title2">Você está acompanhado? Por quantas pessoas?</td>
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
				<td class="title">Que horas viu o médico?</td>
				<td class="amswer"><xsl:value-of select="horaMedicoB" /></td>
			</tr>
			<tr>
				<td class="title2">Quanto tempo levou desde que saiu de casa?</td>
				<td class="amswer"><xsl:value-of select="tempoTotalB" /></td>
			</tr>
			<tr>
				<td class="title">Quando teve que trazer a segunda amostra de escarro há alguns dias, em que horário escarrou no potinho?</td>
				<td class="amswer"><xsl:value-of select="horarioEscarro" /></td>
			</tr>
			<tr>
				<td class="title2">Que horas acordou no dia de escarrar pela segunda vez no potinho?</td>
				<td class="amswer"><xsl:value-of select="horarioEscarro" /></td><!-- ............... -->
			</tr>
			<tr>
				<td class="title">Recebeu uma receita com antibióticos?</td>
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
				<td class="title2">Já sabe o resultado dos exames de escarro?</td>
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
				<td class="title">Há quanto tempo estava sentindo-se diferente ou doente, antes de vir ao posto?</td>
				<td class="amswer"><xsl:value-of select="tempoDoente" /></td>
			</tr>
			<tr>
				<td class="title2">Antes de ser diagnosticado no posto, você foi a alguma outra unidade de saúde?</td>
				<td class="amswer"><xsl:value-of select="outraUnidadeSaude" /></td>
			</tr>
			<tr>
				<td class="title2">Este local era:</td>
				<td class="amswer"><xsl:value-of select="naturezaLocal" /></td>
			</tr>
			<tr>
				<td class="evaluated">Avaliado pelo(a) enfermeiro(a): <xsl:value-of select="avaliadorEnfermeiroBeC" /></td>
				<td class="evaluated">Data da avaliação: <xsl:value-of select="dataEnfermeiroBeC" /></td>
			</tr>
</xsl:template>


<!-- Follow Up -->

<xsl:template match="followUp">
			<tr>
				<td class="title">Critério de Entrada:</td>
				<td class="amswer"><xsl:value-of select="criterioEntrada" /></td>
			</tr>
			<tr>
				<td class="title2">Tratamento prescrito para TB:</td>
				<td class="amswer"><xsl:value-of select="tratamentoPrescritoTB" /></td>
			</tr>
			<tr>
				<td class="title2">Data do início:</td>
				<td class="amswer"><xsl:value-of select="tratamentoPrescritoTBData" /></td>
			</tr>
			<tr>
				<td class="title2">Fármacos utilizados:</td>
				<td class="amswer"><xsl:value-of select="tratamentoPrescritoTBFarmacos" /></td>
			</tr>
			<tr>
				<td class="title">Reação adversa dos tuberculostáticos?</td>
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
				<td class="title2">Houve óbito?</td>
				<td class="amswer"><xsl:value-of select="obito" /></td>
			</tr>
			<tr>
				<td class="title2">Qual a causa?</td>
				<td class="amswer"><xsl:value-of select="casoObito" /></td>
			</tr>
			<tr>
				<td class="title">Mudança de esquema de tratamento para TB?</td>
				<td class="amswer"><xsl:value-of select="mudancaEsquemaTratamentoTB" /></td>
			</tr>
			<tr>
				<td class="title">Data da mudança:</td>
				<td class="amswer"><xsl:value-of select="mudancaData" /></td>
			</tr>
			<tr>
				<td class="title">Fármacos utilizados:</td>
				<td class="amswer"><xsl:value-of select="mudancaFarmacos" /></td>
			</tr>
			<tr>
				<td class="title">Motivo:</td>
				<td class="amswer"><xsl:value-of select="mudancaMotivo" /></td>
			</tr>
			<tr>
				<td class="title2">Tosse diminuída:</td>
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
				<td class="title">Cavitação:</td>
				<td class="amswer"><xsl:value-of select="cavitacao90dias" /></td>
			</tr>
			<tr>
				<td class="title">Padrão típico (infiltrado em lobo(s) superior(es) e/ou segmento apical de lobo inferior):</td>
				<td class="amswer"><xsl:value-of select="padraoTipico90dias" /></td>
			</tr>
			<tr>
				<td class="title">Compatível (alargamento mediastinal ou linf. hilar , padrão miliar,ou derrame pleural):</td>
				<td class="amswer"><xsl:value-of select="compativel90dias" /></td>
			</tr>
			<tr>
				<td class="title">Atípico (qualquer outro padrão):</td>
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
				<td class="title2">Follow up do RX de Tórax (compare com o RXT inicial como o atual):</td>
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
				<td class="title">Diagnóstico 90 dias:</td>
				<td class="amswer"><xsl:value-of select="diagnostico90dias" /></td>
			</tr>
			<tr>
				<td class="title2">Em caso de outro diagnóstico diferente de TB, qual?</td>
				<td class="amswer"><xsl:value-of select="diagnosticoFinal" /></td>
			</tr>
			<tr>
				<td class="evaluated">Avaliado pelo(a) médico(a): <xsl:value-of select="avaliadorMedicoFollowUp" /></td>
				<td class="evaluated">Data da avaliação: <xsl:value-of select="dataMedicoFollowUp" /></td>
			</tr>
</xsl:template>

</xsl:stylesheet>
