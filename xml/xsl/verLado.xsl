<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
				xmlns:fo="http://www.w3.org/1999/XSL/Format"
				xmlns="http://www.w3.org/1999/xhtml">

<xsl:include href="dadosResumidos.xsl" />

<xsl:template match="/">
		
		<xsl:apply-templates select="pacientes" />
		
</xsl:template>


<xsl:template match="pacientes">
	<!-- Tags' values -->
	<xsl:for-each select="paciente[@removido = 'nao']">
	<xsl:sort select="descendant::nomeCompleto" />
		<xsl:if test="triagem/numeroGeral = '99'">
			<span class="label" style="font-size:10pt; font-weight:bold;">Nome: <span style="font-weight:normal" class="underline"><xsl:value-of select="triagem/nomeCompleto" /></span></span>
			<br /><br />
			<table border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td class="title3" colspan="2">Triagem</td>
			</tr>
			<xsl:apply-templates select="triagem" />
			<tr>
				<td class="title3" colspan="2" height="10"></td>
			</tr>
			<!--
			<tr>
				<td class="title3" colspan="2">Custos - Parte A</td>
			</tr>
			<xsl:apply-templates select="custosA" />
			<tr>
				<td class="title3" colspan="2" height="10"></td>
			</tr>
			-->
		<xsl:if test="consultaMedica">
			<tr>
				<td class="title3" colspan="2">Consulta M�dica</td>
			</tr>
			<xsl:apply-templates select="consultaMedica" />
			<tr>
				<td class="title3" colspan="2" height="10"></td>
			</tr>
		</xsl:if>
			<!--
			<tr>
				<td class="title3" colspan="2">Custos - Partes B e C</td>
			</tr>
			<xsl:apply-templates select="custosBeC" />
			<tr>
				<td class="title3" colspan="2" height="10"></td>
			</tr>
			-->
		<xsl:if test="followUp">
			<tr>
				<td class="title3" colspan="2">Follow Up</td>
			</tr>
			<xsl:apply-templates select="followUp" />
			<tr>
				<td class="title3" colspan="2" height="10"></td>
			</tr>
		</xsl:if>
			<!--
			<tr>
				<td class="title1">Gr�fico de Grupo</td>
				<td><a href="{concat(graficoGrupo, triagem/numeroGeral)}" target="_blank">Visualizar</a></td>
			</tr>
			-->
			</table>
			<br /><br />
		</xsl:if>
	</xsl:for-each>
	
</xsl:template>

</xsl:stylesheet>
