<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
				xmlns="http://www.w3.org/1999/xhtml">

<xsl:include href="filtro.xsl" />

<xsl:template match="/">
		<xsl:apply-templates select="pacientes" />
</xsl:template>


<xsl:template match="pacientes">
	<table>
		<tr>
			<th class="title3">Nº Geral</th>
			<th class="title3" width="40%">Paciente</th>
			<th class="title3" width="30%">Nome da Mãe</th>
			<th class="title3">Data de Nascimento</th>
			<th class="title3">Incluído em</th>
			<th class="title3">Visualizar</th>
			<th class="title3">Remover</th>
			<th class="title3">Editar</th>
		</tr>
		<xsl:for-each select="paciente[@removido = 'nao']">
		<xsl:sort select="descendant::nomeCompleto" />
			<xsl:apply-templates select="triagem" />
		</xsl:for-each>
	</table>
</xsl:template>


<!-- Criterio inicial de triagem para TB pulmonar -->
<xsl:template name="filtro">
		<tr>
			<td class="answer center"><xsl:value-of select="numeroGeral" /></td>
			<td class="answer"><xsl:value-of select="nomeCompleto" /></td>
			<td class="answer"><xsl:value-of select="nomeMae" /></td>
			<td class="answer center"><xsl:value-of select="concat(dia_nascimento,'/', mes_nascimento,'/', ano_nascimento)" /></td>
			<td class="answer center"><xsl:value-of select="concat(dia_inclusao,'/', mes_inclusao,'/', ano_inclusao)" /></td>
			<td class="answer center"><a href="viewPatient.cgi?pid={numeroGeral}"><img alt="Ver" src="images/ver.gif" style="border: 0px" /></a></td>
			<td class="answer center"><a href="removePatient.cgi?numeroGeral={numeroGeral}" onclick="return confirm('Deseja remover o paciente?');"><img alt="Remover" src="images/remove.gif" style="border: 0px" /></a></td>
			<td class="answer center"><a href="" onclick="window.open ('formsStatus.cgi?uid=medico&amp;pid={numeroGeral}','formularios','toolbar=no, width=300, height=280,resizable=yes'); return false;"><img src="images/forms.gif" style="border: 0px" /></a></td>
		</tr></xsl:template>

</xsl:stylesheet>
