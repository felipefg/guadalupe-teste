<?xml version="1.0" encoding="ISO-8859-1"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
				xmlns:fo="http://www.w3.org/1999/XSL/Format"
				xmlns="http://www.w3.org/1999/xhtml">


<!-- Critério inicial de triagem para TB pulmonar -->

<xsl:template match="triagem">
			<tr>
				<td class="title1" width="50%">Número Geral:</td>
				<td class="answer1" width="50%"><xsl:value-of select="numeroGeral" /></td>
			</tr>
			<tr>
				<td class="title2">Nome:</td>
				<td class="answer2"><xsl:value-of select="nomeCompleto" /></td>
			</tr>
			<tr>
				<td class="title1">Nome da mãe:</td>
				<td class="answer1"><xsl:value-of select="nomeMae" /></td>
			</tr>
			<tr>
				<td class="title2">Endereço residencial:</td>
				<td class="answer2"><xsl:value-of select="endereco" /></td>
			</tr>
			<tr>
				<td class="title2">Ponto de Referência:</td>
				<td class="answer2"><xsl:value-of select="ptoReferencia" /></td>
			</tr>
			<tr>
				<td class="title2">Bairro:</td>
				<td class="answer2"><xsl:value-of select="bairro" /></td>
			</tr>
			<tr>
				<td class="title2">Cidade:</td>
				<td class="answer2"><xsl:value-of select="cidade" /></td>
			</tr>
			<tr>
				<td class="title2">CEP:</td>
				<td class="answer2"><xsl:value-of select="concat(cep1, '-', cep2)" /></td>
			</tr>
			<tr>
				<td class="title2">Telefone:</td>
				<td class="answer2"><xsl:value-of select="fone" /></td>
			</tr>
			<tr>
				<td class="title1">Celular:</td>
				<td class="answer1"><xsl:value-of select="cel" /></td>
			</tr>
			<tr>
				<td class="title2">Contato para emergência:</td>
				<td class="answer2"><xsl:value-of select="concat(foneContato,' - ', nomeContato)" /></td>
			</tr>
			<tr>
				<td class="title1">Data de Nascimento:</td>
				<td class="answer1"><xsl:value-of select="dia_nascimento" />/<xsl:value-of select="mes_nascimento" />/<xsl:value-of select="ano_nascimento" /></td>
			</tr>
			<tr>
				<td class="title2">Idade:</td>
				<td class="answer2"><xsl:value-of select="concat(idade, ' ', idade/@unidade)" /></td>
			</tr>
			<tr>
				<td class="title1">Naturalidade:</td>
				<td class="answer1"><xsl:value-of select="concat(naturalidadeCidade,' - ',naturalidadeEstado)" /></td>
			</tr>
			<xsl:if test="naturalidadeEestado[(. != 'RJ') and (. != 'Rio de Janeiro')]">
				<tr>
					<td class="title1">Chegou no Rio há quantos anos?</td>
					<td class="answer1"><xsl:value-of select="naturalidadeAnosRio" /></td>
				</tr>
			</xsl:if>
			<tr>
				<td class="title2">Sexo:</td>
				<td class="answer2"><xsl:value-of select="sexo" /></td>
			</tr>
			<tr>
				<td class="title1">Raça-I:</td>
				<td class="answer1"><xsl:value-of select="raca1" /></td>
			</tr>
			<xsl:if test="raca1[. != 'branco']">
				<tr>
					<td class="title1">Especificação:</td>
					<td class="answer1"><xsl:value-of select="raca2" /></td>
				</tr>
			</xsl:if>
			<tr>
				<td class="title2">Estado Civil:</td>
				<td class="answer2"><xsl:value-of select="estadoCivil" /></td>
			</tr>
			<tr>
				<td class="title1">Tem companheiro(a)?</td>
				<td class="answer1"><xsl:value-of select="companheiro" /></td>
			</tr>
			<tr>
				<td class="title2">Peso habitual:</td>
				<td class="answer2"><xsl:value-of select="concat(pesoHabitual,' ',pesoHabitual/@unidade)" /></td>
			</tr>
			<tr>
				<td class="title1">Peso atual:</td>
				<td class="answer1"><xsl:value-of select="concat(pesoAtual,' ',pesoAtual/@unidade)" /></td>
			</tr>
			<!--<tr>
				<td class="title2">Perda de peso:</td>
				<td class="answer2"><xsl:value-of select="concat(perdaDePeso,' - ',perdaDePeso_semanas)" /></td>
			</tr>-->
			<tr>
				<td class="title2">Altura:</td>
				<td class="answer2"><xsl:value-of select="concat(altura, ' ', altura/@unidade)" /></td>
			</tr>
			<tr>
				<td class="title1">IMC:</td>
				<td class="answer1"><xsl:value-of select="imc" /></td>
			</tr>
			
			
			<tr>
				<td class="title4" colspan="2">Sinais e Sintomas</td>
			</tr>
			
			
			<tr>
				<td class="title1">Tosse:</td>
				<td class="answer1"><xsl:value-of select="tosse" />
					<xsl:if test="tosse[(. != 'nao') and (tosse_semanas != '')]">
						<xsl:value-of select="concat('. ',tosse_semanas,' semanas')" />
					</xsl:if>
				</td>
			</tr>
			<tr>
				<td class="title2">Expectoração:</td>
				<td class="answer2"><xsl:value-of select="expectoracao" />
					<xsl:if test="expectoracao[(. != 'nao') and (expectoracao_semanas != '')]">
						<xsl:value-of select="concat('. ',expectoracao_semanas,' semanas')" />
					</xsl:if>
				</td>
				
				<!-- repetir para os outros sintomas que tem como info adicional semanas -->
			</tr>
			<tr>
				<td class="title1">Hemoptóico:</td>
				<td class="answer1"><xsl:value-of select="hemoptoico" /></td>
			</tr>
			<tr>
				<td class="title2">Hemoptise:</td>
				<td class="answer2"><xsl:value-of select="hemoptise" /></td>
			</tr>
			<xsl:if test="hemoptise[. = 'sim']">
				<tr>
					<td class="title2">Quantidade:</td>
					<td class="answer2"><xsl:value-of select="hemoptiseQtd" /></td>
				</tr>
			</xsl:if>
			<tr>
				<td class="title1">Sudorese noturna:</td>
				<td class="answer1"><xsl:value-of select="sudorese" /></td>
			</tr>
			<tr>
				<td class="title2">Febre:</td>
				<td class="answer2"><xsl:value-of select="febre" /></td>
			</tr>
			<tr>
				<td class="title1">Dispnéia:</td>
				<td class="answer1"><xsl:value-of select="dispneia" /></td>
			</tr>
			<tr>
				<td class="title2">Perda do apetite:</td>
				<td class="answer2"><xsl:value-of select="perdaApetite" /></td>
			</tr>
			<tr>
				<td class="title1">Perda de peso (> 10%):</td>
				<td class="answer1"><xsl:value-of select="perdaDePeso" /></td>
			</tr>
			<tr>
				<td class="title2">Dor torácica</td>
				<td class="answer2"><xsl:value-of select="dorToracica" /></td>
			</tr>
			<tr>
				<td class="title1">Total de pontos:</td>
				<td class="answer1"><xsl:value-of select="pontuacao" /></td>
			</tr>
			
			
			<tr>
				<td class="title4" colspan="2">História da Tuberculose</td>
			</tr>
			
			
			<tr>
				<td class="title1">Tratamento anterior para TB:</td>
				<td class="answer1"><xsl:value-of select="tratamentoAnteriorTB" /></td>
			</tr>
			<xsl:if test="tratamentoAnteriorTB[. = 'sim']">
				<tr>
					<td class="title1">Data de diagnóstico de TB no passado:</td>
					<td class="answer1"><xsl:value-of select="concat(mes_diagnostico,'/',ano_diagnostico)" /></td>
				</tr>
				<tr>
					<td class="title1">TB desfecho:</td>
					<td class="answer1"><xsl:value-of select="TBdesfecho" /></td>
				</tr>
			</xsl:if>
			<tr>
				<td class="title2">Esteve internado em hospital?</td>
				<td class="answer2"><xsl:value-of select="internado" /></td>
			</tr>
			<tr>
				<td class="title1">Esteve em prisão?</td>
				<td class="answer1"><xsl:value-of select="prisao" /></td>
			</tr>
			<tr>
				<td class="title2">Esteve em delegacia?</td>
				<td class="answer2"><xsl:value-of select="delegacia" /></td>
			</tr>
			<tr>
				<td class="title1">Teve contato com pessoa com TBP?</td>
				<td class="answer1"><xsl:value-of select="contatoTBP" /></td>
			</tr>
			<xsl:if test="contatoTBP[. = 'sim']">
				<tr>
					<td class="title1">Morava junto?</td>
					<td class="answer1"><xsl:value-of select="contatoTBPmoravaJunto" /></td>
				</tr>
				<tr>
					<td class="title1">Trabalhava junto?</td>
					<td class="answer1"><xsl:value-of select="contatoTBPtrabalhavaJunto" /></td>
				</tr>
				<tr>
					<td class="title1">Era amigo, parente ou colega que não morava junto?</td>
					<td class="answer1"><xsl:value-of select="contatoTBPamigoParenteColega" /></td>
				</tr>
				<tr>
					<td class="title1">Algum destes contatos foi &lt; 3 anos?</td>
					<td class="answer1"><xsl:value-of select="contatoTBPmenorQue3Anos" /></td>
				</tr>
				<tr>
					<td class="title1">Qual?</td>
					<td class="answer1"><xsl:value-of select="contatoTBPqual" /></td>
				</tr>
			</xsl:if>
			<tr>
				<td class="title2">Fuma?</td>
				<td class="answer2"><xsl:value-of select="fuma" /></td>
			</tr>
			<xsl:if test="fuma[. != 'nunca']">
				<tr>
					<td class="title2">Número de cigarros que fuma ou fumava por dia:</td>
					<td class="answer2"><xsl:value-of select="fumaQtd" /></td>
				</tr>
				<tr>
					<td class="title2">Número de anos que fuma ou fumou:</td>
					<td class="answer2"><xsl:value-of select="fumaTempo" /></td>
				</tr>
			</xsl:if>
			<tr>
				<td class="title1 wrap">Antes de ficar doente tomava alguma bebida alcoólica? Qual tipo de bebida prefere ou preferia?</td>
				<td class="answer1"><xsl:value-of select="bebida" /></td>
			</tr>
			<xsl:if test="bebida[. != 'nenhuma']">
				<tr>
					<td class="title1">Tem facilidade de fazer amizades?</td>
					<td class="answer1"><xsl:value-of select="facilidadeFazerAmizades" /></td>
				</tr>
				<tr>
					<td class="title1">Alguma vez sentiu que deveria diminuir a quantidade da bebida?</td>
					<td class="answer1"><xsl:value-of select="diminuirQtdBebida" /></td>
				</tr>
				<tr>
					<td class="title1">Alguém critica ou já criticou seu modo de beber?</td>
					<td class="answer1"><xsl:value-of select="criticaModoBeber" /></td>
				</tr>
				<tr>
					<td class="title1">Costuma beber de manhã para diminuir o nervosismo/ressaca?</td>
					<td class="answer1"><xsl:value-of select="bebidaManha" /></td>
				</tr>
				<tr>
					<td class="title1">Sente-se culpado pela maneira que costuma beber?</td>
					<td class="answer1"><xsl:value-of select="culpadoManeiraBeber" /></td>
				</tr>
			</xsl:if>
			<tr>
				<td class="title2">Cage positivo:</td>
				<td class="answer2"><xsl:value-of select="cage" /></td>
			</tr>
			<tr>
				<td class="title1">Desfecho da consulta inicial:</td>
				<td class="answer1"><xsl:value-of select="desfechoConsultaInicial" /></td>
			</tr>
			<tr>
				<td class="title2">Inclusão:</td>
				<td class="answer2"><xsl:value-of select="inclusao" /></td>
			</tr>
			<xsl:if test="inclusao[. = 'sim']">
				<tr>
					<td class="title2" rowspan="2">Critérios de inclusão:</td>
					<td class="answer2"><xsl:value-of select="criteriosInclusao" /></td>
				</tr>
				<tr>
					<td class="answer2"><xsl:value-of select="criteriosInclusao" /> - <xsl:value-of select="concat(dia_termoConsentimento,'/',mes_termoConsentimento,'/',ano_termoConsentimento)" /></td>
				</tr>
			
				<tr>
					<td class="title1" rowspan="2">Data da coleta dos DOIS espécimes respiratórios:</td>
					<td class="answer1">#1 - <xsl:value-of select="dia_coleta1" />/<xsl:value-of select="mes_coleta1" />/<xsl:value-of select="ano_coleta1" /> - <xsl:value-of select="coleta1" /></td>
				</tr>
				<tr>
					<td class="answer1">#2 - <xsl:value-of select="dia_coleta2" />/<xsl:value-of select="mes_coleta2" />/<xsl:value-of select="ano_coleta2" /> - <xsl:value-of select="coleta2" /></td>
				</tr>
				<tr>
					<td class="title2">Cicatriz da BCG presente?</td>
					<td class="answer2"><xsl:value-of select="cicatrizBCG" /></td>
				</tr>
				<tr>
					<td class="title1">Resultado da leitura (milímetros de enduração):</td>
					<td class="answer1"><xsl:value-of select="resultadoLeitura" /></td>
				</tr>
				<tr>
					<td class="title2">Data da aplicação da prova tuberculínica:</td>
					<td class="answer2"><xsl:value-of select="dia_aplicacao" />/<xsl:value-of select="mes_aplicacao" />/<xsl:value-of select="ano_aplicacao" /></td>
				</tr>
				<tr>
					<td class="title1">Data da leitura:</td>
					<td class="answer1"><xsl:value-of select="dia_leitura" />/<xsl:value-of select="mes_leitura" />/<xsl:value-of select="ano_leitura" /></td>
				</tr>
				<tr>
					<td class="title2">PT primeira dose Leitor:</td>
					<td class="answer2"><xsl:value-of select="PTprimeiraDose" /></td>
				</tr>
			</xsl:if>
			<tr>
				<td class="title1"><xsl:value-of select="concat('Avaliado pelo(a) enfermeiro(a): ', avaliador)" /></td>
				<td class="answer1">Data da avaliação: <xsl:value-of select="dia_inclusao" />/<xsl:value-of select="mes_inclusao" />/<xsl:value-of select="ano_inclusao" />
					<xsl:value-of select="concat(' ', hora_inclusao)" />
				</td>
			</tr>
</xsl:template>


<!-- Questionário custos: Parte A -->

<xsl:template match="custosA">
			<tr>
				<td class="title1">Onde mora?</td>
				<td class="answer1"><xsl:value-of select="ondeMora" /></td>
			</tr>
			<tr>
				<td class="title2">Como veio ao posto?</td>
				<td class="answer2"><xsl:value-of select="transporte" /></td>
			</tr>
			<tr>
				<td class="title2">Quanto custou o transporte?</td>
				<td class="answer2"><xsl:value-of select="custoTransporteA" /></td>
			</tr>
			<tr>
				<td class="title1">Está acompanhado? Por quantas pessoas?</td>
				<td class="answer1"><xsl:value-of select="acompanhadoA" />. <xsl:value-of select="numeroAcompanhantesA" /></td>
			</tr>
			<tr>
				<td class="title2">Que horas saiu de casa?</td>
				<td class="answer1"><xsl:value-of select="horaSaidaCasaA" /></td>
			</tr>
			<tr>
				<td class="title1">Que horas chegou no posto?</td>
				<td class="answer1"><xsl:value-of select="horaChegadaPostoA" /></td>
			</tr>
			<tr>
				<td class="title2">Que horas viu o médico?</td>
				<td class="answer2"><xsl:value-of select="horaMedicoA" /></td>
			</tr>
			<tr>
				<td class="title1">Quanto tempo levou desde que saiu de casa?</td>
				<td class="answer1"><xsl:value-of select="tempoTotalA" /></td>
			</tr>
			<tr>
				<td class="title2">Se o paciente mora fora da cidade do Rio de Janeiro: Amanhã terá que voltar para trazer outra amostra de escarro. Onde vai passar a noite? </td>
				<td class="answer2"><xsl:value-of select="pernoite" /></td>
			</tr>
			<tr>
				<td class="title1">Se o paciente não passar a noite em casa, terá que pagar o pernoite?</td>
				<td class="answer1"><xsl:value-of select="pagarPernoite" /></td>
			</tr>
			<tr>
				<td class="title1">Quanto deverá gastar?</td>
				<td class="answer1"><xsl:value-of select="custoPernoite" /></td>
			</tr>
			<tr>
				<td class="title2">Se o paciente não tiver que pagar: trouxe algo para seus amigos?</td>
				<td class="answer2"><xsl:value-of select="trouxeAlgoAmigos" /></td>
			</tr>
			<tr>
				<td class="title2">Quanto custou?</td>
				<td class="answer2"><xsl:value-of select="custoAmigos" /></td>
			</tr>
			<tr>
				<td class="title1">Desde que saiu de casa, comeu ou bebeu alguma coisa?</td>
				<td class="answer1"><xsl:value-of select="comeuBebeuA" /></td>
			</tr>
			<tr>
				<td class="title1">Quanto custou?</td>
				<td class="answer1"><xsl:value-of select="custoComidaBebidaA" /></td>
			</tr>
			<tr>
				<td class="title2">Teve que pagar algo aqui no posto?</td>
				<td class="answer2"><xsl:value-of select="pagarPostoA" /></td>
			</tr>
			<tr>
				<td class="title2">Quanto custou?</td>
				<td class="answer2"><xsl:value-of select="custoPostoA" /></td>
			</tr>
			<tr>
				<td class="title1">Profissão:</td>
				<td class="answer1"><xsl:value-of select="profissao" /></td>
			</tr>
			<tr>
				<td class="title2">Se o paciente for um estudante, ele perdeu aula hoje?</td>
				<td class="answer2"><xsl:value-of select="estudantePerdeuAula" /></td>
			</tr>
			<tr>
				<td class="title1">Deixou de ganhar dinheiro hoje para poder vir ao posto?</td>
				<td class="answer1"><xsl:value-of select="deixouGanharDinheiroA" /></td>
			</tr>
			<tr>
				<td class="title1">Quanto deixou de ganhar?</td>
				<td class="answer1"><xsl:value-of select="quantoDeixouGanharA" /></td>
			</tr>
			<tr>
				<td class="title2">Se o paciente estiver acompanhado: Quem pagou pela bebida, comida, transporte, hotel, etc? O paciente ou seus acompanhantes?</td>
				<td class="answer2"><xsl:value-of select="quemArcouCustos" /></td>
			</tr>
			<tr>
				<td class="title2">Quanto você gastou com seu acompanhante?</td>
				<td class="answer2"><xsl:value-of select="gastoAcompanhante" /></td>
			</tr>
			<tr>
				<td class="evaluated">Avaliado pelo(a) enfermeiro(a): <xsl:value-of select="avaliadorEnfermeiroA" /></td>
				<td class="evaluated">Data da avaliação: <xsl:value-of select="diaCustoA" />/<xsl:value-of select="mesCustoA" />/<xsl:value-of select="anoCustoA" /></td>
			</tr>
</xsl:template>


<!-- Consulta médica -->

<xsl:template match="consultaMedica">
			
			<tr>
				<td class="title1">INH:</td>
				<td class="answer1"><xsl:value-of select="inh" /></td>
			</tr>
			<tr>
				<td class="title2">RIF:</td>
				<td class="answer2"><xsl:value-of select="rif" /></td>
			</tr>
			<tr>
				<td class="title1">Qual esquema?</td>
				<td class="answer1"><xsl:value-of select="qualEsquema" /></td>
			</tr>
			
			<tr>
				<td class="title4" colspan="2">Quimioprofilaxia Prévia para TB</td>
			</tr>
			
			<tr>
				<td class="title1">Quimioprofilaxia:</td>
				<td class="answer1"><xsl:value-of select="quimioprofilaxia" /></td>
			</tr>
			<tr>
				<td class="title1">Se Cage positivo, usou INH?</td>
				<td class="answer1"><xsl:value-of select="inhCagePositivo" /></td>
			</tr>
			<tr>
				<td class="title1">Se Cage positivo, usou RIF?</td>
				<td class="answer1"><xsl:value-of select="rifCagePositivo" /></td>
			</tr>
			<tr>
				<td class="title1">Data da quimioprofilaxia:</td>
				<td class="answer1"><xsl:value-of select="dataQuimio" /></td>
			</tr>
			<tr>
				<td class="title1">Desfecho:</td>
				<td class="answer1"><xsl:value-of select="desfechoQuimio" /></td>
			</tr>
			
			
			<tr>
				<td class="title4" colspan="2">HIV/AIDS</td>
			</tr>
			
			
			<tr>
				<td class="title1">HIV teste:</td>
				<td class="answer1"><xsl:value-of select="testeHIV" /></td>
			</tr>
			<tr>
				<td class="title2">Data do Anti-HIV:</td>
				<td class="answer2"><xsl:value-of select="dataAntiHIV" /></td>
			</tr>
			<tr>
				<td class="title1">Comorbidades:</td>
				<td class="answer1"><xsl:value-of select="comorbidades" /></td>
			</tr>
			
			
			<tr>
				<td class="title4" colspan="2">Avaliação clínica</td>
			</tr>
			
			
			<tr>
				<td class="title1">Probabilidade de TB ativa: </td>
				<td class="answer1"><xsl:value-of select="probTBativa" /></td>
			</tr>
			<tr>
				<td class="title2">Probabilidade do diagnóstico de TB pulmonar ativa sem avaliar RX de tórax ou BAAR:</td>
				<td class="answer2"><xsl:value-of select="porcentagemProbTBsemRXsemBAAR" /></td>
			</tr>
			
			<tr>
				<td class="title4" colspan="2">RX de tórax</td>
			</tr>
			
			<tr>
				<td class="title1">Probabilidade de TB ativa ao avaliar o RXT:</td>
				<td class="answer1"><xsl:value-of select="probTBativaComRX" /></td>
			</tr>
			<tr>
				<td class="title2">Cavitação:</td>
				<td class="answer2"><xsl:value-of select="cavitacao" /></td>
			</tr>
			<tr>
				<td class="title2">Padrão típico (infiltrado em lobo(s) superior(es) e/ou segmento apical de lobo inferior):</td>
				<td class="answer2"><xsl:value-of select="padraoTipico" /></td>
			</tr>
			<tr>
				<td class="title2">Compatível (alargamento mediastinal ou linf. hilar, padrão miliar,ou derrame pleural):</td>
				<td class="answer2"><xsl:value-of select="compativel" /></td>
			</tr>
			<tr>
				<td class="title2">Atípico (qualquer outro padrão):</td>
				<td class="answer2"><xsl:value-of select="atipico" /></td>
			</tr>
			<tr>
				<td class="title2">NSA</td>
				<td class="answer2"><xsl:value-of select="NSA" /></td>
			</tr>
			<tr>
				<td class="title1">Em caso de baixa probabilidade de TB ativa:</td>
				<td class="answer1"><xsl:value-of select="casoBaixaProbabilidade" /></td>
			</tr>
			<tr>
				<td class="title2">Data do RX:</td>
				<td class="answer2"><xsl:value-of select="dataRX" /></td>
			</tr>
			<tr>
				<td class="title1">Diagnóstico de probabilidade tendo informação sobre o RX de tórax mas sem conhecimento dos resultados bacteriológicos:</td>
				<td class="answer1"><xsl:value-of select="diagnosticoProbabilidadeRX" /></td>
			</tr>
			<tr>
				<td class="title2">Probabilidade do diagnóstico de TB pulmonar ativa com a avaliação do RX de tórax e SEM  RESULTADO DA BACILOSCOPIA (BAAR):</td>
				<td class="answer2"><xsl:value-of select="probabilidadeTBcomRXsemBAAR" /></td>
			</tr>
			<tr>
				<td class="title1">Resultado da Baciloscopia 1:</td>
				<td class="answer1"><xsl:value-of select="resultadoBaciloscopia1" /></td>
			</tr>
			<tr>
				<td class="title1">Resultado da Baciloscopia 2:</td>
				<td class="answer1"><xsl:value-of select="resultadoBaciloscopia2" /></td>
			</tr>
			<tr>
				<td class="title2">Caso as duas baciloscopias iniciais sejam negativas qual seria o diagnóstico de probabilidade de TB?</td>
				<td class="answer2"><xsl:value-of select="diagnosticoProbabilidadeCasoDuasNegativas" /></td>
			</tr>
			<tr>
				<td class="title1">Probabilidade do diagnóstico de TB pulmonar ativa com a avaliação do RX de tórax e do BAAR:</td>
				<td class="answer1"><xsl:value-of select="probabilidadeTBcomRXcomBAAR" /></td>
			</tr>
			<tr>
				<td class="title2">Desfecho consulta inicial:</td>
				<td class="answer2"><xsl:value-of select="desfechoConsultaInicial" /></td>
			</tr>
			<tr>
				<td class="title2">Em caso de tratamento para TB, qual?</td>
				<td class="answer2"><xsl:value-of select="casoTratamentoTB" /></td>
			</tr>
			<tr>
				<td class="title2">Fatores de risco para TBP MDR:</td>
				<td class="answer2"><xsl:value-of select="fatoresRisco" /></td>
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
				<td class="title1">Tem o resultado dos exames?</td>
				<td class="answer1"><xsl:value-of select="resultadoExames" /></td>
			</tr>
			<tr>
				<td class="title2">Quantas vezes veio ao posto para pegar os resultados dos exames?</td>
				<td class="answer2"><xsl:value-of select="quantasVezesVeioPosto" /></td>
			</tr>
			<tr>
				<td class="title1">Como veio ao posto? Em qual transporte?</td>
				<td class="answer1"><xsl:value-of select="comoVeioPosto" /></td>
			</tr>
			<tr>
				<td class="title1">Se não veio a pé quanto custou o transporte?</td>
				<td class="answer1"><xsl:value-of select="custoTransporteB" /></td>
			</tr>
			<tr>
				<td class="title2">Você está acompanhado? Por quantas pessoas?</td>
				<td class="answer2"><xsl:value-of select="acompanhadoB" />. <xsl:value-of select="numeroAcompanhantesB" /></td>
			</tr>
			<tr>
				<td class="title1">Que horas saiu de casa?</td>
				<td class="answer1"><xsl:value-of select="horaSaidaCasaB" /></td>
			</tr>
			<tr>
				<td class="title2">Que horas chegou no posto?</td>
				<td class="answer2"><xsl:value-of select="horaChegadaPostoB" /></td>
			</tr>
			<tr>
				<td class="title1">Que horas viu o médico?</td>
				<td class="answer1"><xsl:value-of select="horaMedicoB" /></td>
			</tr>
			<tr>
				<td class="title2">Quanto tempo levou desde que saiu de casa?</td>
				<td class="answer2"><xsl:value-of select="tempoTotalB" /></td>
			</tr>
			<tr>
				<td class="title1">Quando teve que trazer a segunda amostra de escarro há alguns dias, em que horário escarrou no potinho?</td>
				<td class="answer1"><xsl:value-of select="horarioEscarro" /></td>
			</tr>
			<tr>
				<td class="title2">Que horas acordou no dia de escarrar pela segunda vez no potinho?</td>
				<td class="answer2"><xsl:value-of select="horarioEscarro" /></td><!-- ............... -->
			</tr>
			<tr>
				<td class="title1">Recebeu uma receita com antibióticos?</td>
				<td class="answer1"><xsl:value-of select="receitaAntibioticos" /></td>
			</tr>
			<tr>
				<td class="title2">Pediu para fazer um RX?</td>
				<td class="answer2"><xsl:value-of select="pediuRX" /></td>
			</tr>
			<tr>
				<td class="title1">Desde que saiu de casa, comeu ou bebeu alguma coisa?</td>
				<td class="answer1"><xsl:value-of select="comeuBebeuB" /></td>
			</tr>
			<tr>
				<td class="title1">Quanto custou?</td>
				<td class="answer1"><xsl:value-of select="custoComidaBebidaB" /></td>
			</tr>
			<tr>
				<td class="title2">Teve que pagar algo aqui no posto?</td>
				<td class="answer2"><xsl:value-of select="pagarPostoB" /></td>
			</tr>
			<tr>
				<td class="title2">Quanto custou?</td>
				<td class="answer2"><xsl:value-of select="custoPostoB" /></td>
			</tr>
			<tr>
				<td class="title1">Deixou de ganhar dinheiro hoje para poder vir ao posto?</td>
				<td class="answer1"><xsl:value-of select="deixouGanharDinheiroB" /></td>
			</tr>
			<tr>
				<td class="title1">Quanto deixou de ganhar?</td>
				<td class="answer1"><xsl:value-of select="quantoDeixouGanharB" /></td>
			</tr>
			<tr>
				<td class="title2">Já sabe o resultado dos exames de escarro?</td>
				<td class="answer2"><xsl:value-of select="resultadoExamesEscarro" /></td>
			</tr>
			<tr>
				<td class="title1">Se o paciente tiver TB: Foi registrado no programa de tratamento de TB?</td>
				<td class="answer1"><xsl:value-of select="registroProgramaTratamentoTB" /></td>
			</tr>
			
			<!-- Parte C -->
			
			<tr>
				<td class="title2">Teve que pagar algo aqui no posto?</td>
				<td class="answer2"><xsl:value-of select="pagarPostoC" /></td>
			</tr>
			<tr>
				<td class="title2">Quanto custou?</td>
				<td class="answer2"><xsl:value-of select="custoPostoC" /></td>
			</tr>
			<tr>
				<td class="title1">Há quanto tempo estava sentindo-se diferente ou doente, antes de vir ao posto?</td>
				<td class="answer1"><xsl:value-of select="tempoDoente" /></td>
			</tr>
			<tr>
				<td class="title2">Antes de ser diagnosticado no posto, você foi a alguma outra unidade de saúde?</td>
				<td class="answer2"><xsl:value-of select="outraUnidadeSaude" /></td>
			</tr>
			<tr>
				<td class="title2">Este local era:</td>
				<td class="answer2"><xsl:value-of select="naturezaLocal" /></td>
			</tr>
			<tr>
				<td class="evaluated">Avaliado pelo(a) enfermeiro(a): <xsl:value-of select="avaliadorEnfermeiroBeC" /></td>
				<td class="evaluated">Data da avaliação: <xsl:value-of select="dataEnfermeiroBeC" /></td>
			</tr>
</xsl:template>


<!-- Follow Up -->

<xsl:template match="followUp">
			<tr>
				<td class="title1">Critério de Entrada:</td>
				<td class="answer1"><xsl:value-of select="criterioEntrada" /></td>
			</tr>
			<tr>
				<td class="title2">Tratamento prescrito para TB:</td>
				<td class="answer2"><xsl:value-of select="tratamentoPrescritoTB" /></td>
			</tr>
			<tr>
				<td class="title2">Data do início:</td>
				<td class="answer2"><xsl:value-of select="tratamentoPrescritoTBData" /></td>
			</tr>
			<tr>
				<td class="title2">Fármacos utilizados:</td>
				<td class="answer2"><xsl:value-of select="tratamentoPrescritoTBFarmacos" /></td>
			</tr>
			<tr>
				<td class="title1">Reação adversa dos tuberculostáticos?</td>
				<td class="answer1"><xsl:value-of select="reacoesAdversasTuberculostaticos" /></td>
			</tr>
			<tr>
				<td class="title1">Maiores:</td>
				<td class="answer1"><xsl:value-of select="reacoesAdversasTuberculostaticosMaiores" /></td>
			</tr>
			<tr>
				<td class="title1">Menores:</td>
				<td class="answer1"><xsl:value-of select="reacoesAdversasTuberculostaticosMenores" /></td>
			</tr>
			<tr>
				<td class="title2">Houve óbito?</td>
				<td class="answer2"><xsl:value-of select="obito" /></td>
			</tr>
			<tr>
				<td class="title2">Qual a causa?</td>
				<td class="answer2"><xsl:value-of select="casoObito" /></td>
			</tr>
			<tr>
				<td class="title1">Mudança de esquema de tratamento para TB?</td>
				<td class="answer1"><xsl:value-of select="mudancaEsquemaTratamentoTB" /></td>
			</tr>
			<tr>
				<td class="title1">Data da mudança:</td>
				<td class="answer1"><xsl:value-of select="mudancaData" /></td>
			</tr>
			<tr>
				<td class="title1">Fármacos utilizados:</td>
				<td class="answer1"><xsl:value-of select="mudancaFarmacos" /></td>
			</tr>
			<tr>
				<td class="title1">Motivo:</td>
				<td class="answer1"><xsl:value-of select="mudancaMotivo" /></td>
			</tr>
			<tr>
				<td class="title2">Tosse diminuída:</td>
				<td class="answer2"><xsl:value-of select="tosseDiminuida" /></td>
			</tr>
			<tr>
				<td class="title1">Peso atual:</td>
				<td class="answer1"><xsl:value-of select="concat(pesoAtual90dias, ' ', pesoAtual90dias/@unidade)" /></td>
			</tr>
			<tr>
				<td class="title2">Probabilidade de TB ativa ao avaliar o RXT:</td>
				<td class="answer2"><xsl:value-of select="probabilidadeTBAtivaAposEstudoRX" /></td>
			</tr>
			<tr>
				<td class="title1">Cavitação:</td>
				<td class="answer1"><xsl:value-of select="cavitacao90dias" /></td>
			</tr>
			<tr>
				<td class="title1">Padrão típico (infiltrado em lobo(s) superior(es) e/ou segmento apical de lobo inferior):</td>
				<td class="answer1"><xsl:value-of select="padraoTipico90dias" /></td>
			</tr>
			<tr>
				<td class="title1">Compatível (alargamento mediastinal ou linf. hilar , padrão miliar,ou derrame pleural):</td>
				<td class="answer1"><xsl:value-of select="compativel90dias" /></td>
			</tr>
			<tr>
				<td class="title1">Atípico (qualquer outro padrão):</td>
				<td class="answer1"><xsl:value-of select="atipico90dias" /></td>
			</tr>
			<tr>
				<td class="title1">NSA</td>
				<td class="answer1"><xsl:value-of select="NSA90dias" /></td>
			</tr>
			<tr>
				<td class="title2">Em caso de baixa probabilidade de TB ativa:</td>
				<td class="answer2"><xsl:value-of select="casoBaixaProbabilidade90dias" /></td>
			</tr>
			<tr>
				<td class="title1">Data do RX:</td>
				<td class="answer1"><xsl:value-of select="dataRX90dias" /></td>
			</tr>
			<tr>
				<td class="title2">Follow up do RX de Tórax (compare com o RXT inicial como o atual):</td>
				<td class="answer2"><xsl:value-of select="followUpRXTorax" /></td>
			</tr>
			<tr>
				<td class="title1">HIV teste:</td>
				<td class="answer1"><xsl:value-of select="testeHIV90dias" /></td>
			</tr>
			<tr>
				<td class="title2">Data do Anti-HIV:</td>
				<td class="answer2"><xsl:value-of select="dataAntiHIV90dias" /></td>
			</tr>
			<tr>
				<td class="title1">Diagnóstico 90 dias:</td>
				<td class="answer1"><xsl:value-of select="diagnostico90dias" /></td>
			</tr>
			<tr>
				<td class="title2">Em caso de outro diagnóstico diferente de TB, qual?</td>
				<td class="answer2"><xsl:value-of select="diagnosticoFinal" /></td>
			</tr>
			<tr>
				<td class="evaluated">Avaliado pelo(a) médico(a): <xsl:value-of select="avaliadorMedicoFollowUp" /></td>
				<td class="evaluated">Data da avaliação: <xsl:value-of select="dataMedicoFollowUp" /></td>
			</tr>
</xsl:template>

</xsl:stylesheet>
