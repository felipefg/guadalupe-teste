<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
				xmlns:fo="http://www.w3.org/1999/XSL/Format"
				xmlns="http://www.w3.org/1999/xhtml">
<!--
<xsl:variable name="uid" select="string('medico')" />
<xsl:variable name="id" select="string('86')" />

<xsl:template match="/">
	<xsl:apply-templates select="pacientes/paciente" />
</xsl:template>
-->
<xsl:template match="pacientes/paciente">
<xsl:if test="triagem/numeroGeral = $id">
	<table border="0" margin="0" cellspacing="0" cellpadding="0" align="center">
		<tr>
			<td><span class="bold">Número Geral: </span><xsl:value-of select="triagem/numeroGeral" /></td>
		</tr>
		<tr>
			<td><span class="bold">Paciente: </span><xsl:value-of select="triagem/nomeCompleto" /></td>
		</tr>
		<tr>
			<td height="15"></td>
		</tr>
		<tr>
			<td>
				<table class="form" cellspacing="0" cellpadding="0">
				<!--<xsl:for-each select="*">
				<tr>
					<td>
						<xsl:choose>
						<xsl:when test=".">
							<img src="../images/full.png" width="9" height="9" />
						</xsl:when>
						<xsl:otherwise>
							<img src="../images/empty.jpg" width="20" height="8" />
						</xsl:otherwise>
						</xsl:choose>
					</td>
					<td><a href="">Criterio Inicial de Triagem para TB</a></td>
				</tr>
				</xsl:for-each>-->
				<tr>
					<xsl:choose>
					<xsl:when test="triagem">
					<td>
						<a class="full" href="" onclick="self.close(); opener.top.location='editForm.cgi?uid={$uid}&amp;pid={$id}';return false;">
							<img src="images/full.png" width="9" height="9" />
							Critério Inicial de Triagem para TB
						</a>
					</td>
					</xsl:when>
					<xsl:otherwise>
					<td>
						<a class="empty" href="javascript:;">
							<img src="images/empty.png" width="9" height="9" />
							Critério Inicial de Triagem para TB
						</a>
					</td>
					</xsl:otherwise>
					</xsl:choose>
					
				</tr>
				<tr>
					<xsl:choose>
					<xsl:when test="custosA">
					<td>
						<a class="full" href="javascript:;">
							<img src="images/full.png" width="9" height="9" />
							Questionário de Custos - Parte A
						</a>
					</td>
					</xsl:when>
					<xsl:otherwise>
					<td>
						<a class="empty" href="" onclick="self.close(); opener.top.location='custosA.cgi?uid={$uid}&amp;pid={$id}'; return false;">
							<img src="images/empty.png" width="9" height="9" />
							Questionário de Custos - Parte A
						</a>
					</td>
					</xsl:otherwise>
					</xsl:choose>
				</tr>
				<tr>
					<xsl:choose>
					<xsl:when test="consultaMedica">
					<td>
						<a class="full" href="javascript:;">
							<img src="images/full.png" width="9" height="9" />
							Consulta Médica
						</a>
					</td>
					</xsl:when>
					<xsl:otherwise>
					<td>
						<a class="empty" href="" onclick="self.close(); opener.top.location='incluirForm.cgi?uid={$uid}&amp;pid={$id}'; return false;"><!-- &cage={$cage} ? -->
							<img src="images/empty.png" width="9" height="9" />
							Consulta Médica
						</a>
					</td>
					</xsl:otherwise>
					</xsl:choose>
				</tr>
				<tr>
					<xsl:choose>
					<xsl:when test="custosBeC">
					<td>
						<a class="full" href="javascript:;">
							<img src="images/full.png" width="9" height="9" />
							Questionário de Custos - Partes B e C
						</a>
					</td>
					</xsl:when>
					<xsl:otherwise>
					<td>
						<a class="empty" href="" onclick="self.close(); opener.top.location='custosBeC.cgi?uid={$uid}&amp;pid={$id}'; return false;">
							<img src="images/empty.png" width="9" height="9" />
							Questionário de Custos - Partes B e C
						</a>
					</td>
					</xsl:otherwise>
					</xsl:choose>
				</tr>
				<tr>
					<xsl:choose>
					<xsl:when test="followUp">
					<td>
						<a class="full" href="javascript:;">
							<img src="images/full.png" width="9" height="9" />
							Follow up
						</a>
					</td>
					</xsl:when>
					<xsl:otherwise>
					<td>
						<a class="empty" href="" onclick="self.close(); opener.top.location='followUp.cgi?uid={$uid}&amp;pid={$id}'; return false;">
							<img src="images/empty.png" width="9" height="9" />
							Follow up
						</a>
					</td>
					</xsl:otherwise>
					</xsl:choose>
				</tr>
				</table>
			</td>
		</tr>
		<tr>
			<td height="15"></td>
		</tr>
		<tr>
			<td>Legenda:</td>
		</tr>
		<tr>
			<td><img src="images/empty.png" width="9" height="9" /> Formulário não preenchido</td>
		</tr>
		<tr>
			<td><img src="images/full.png" width="9" height="9" /> Formulário preenchido</td>
		</tr>
		<tr>
			<td height="15"></td>
		</tr>
		<tr>
			<td class="right"><a href="" onclick="window.close()">Fechar</a></td>
		</tr>
	</table>
	<br />
</xsl:if>
</xsl:template>

</xsl:stylesheet>
