<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="pacientes">
	
    <h1>Lista de Pacientes:</h1>
	
    <table>
	  <tr> <th>Nomes:</th> </tr>
      <xsl:for-each select="paciente[@removido = 'nao']/triagem">
	  <xsl:sort select="nomeCompleto" />
      <tr> <td><a href="viewPatient.cgi?pid={numeroGeral}"><xsl:value-of select="nomeCompleto"/></a> </td> </tr>
	  </xsl:for-each>
    </table>
</xsl:template></xsl:stylesheet>
