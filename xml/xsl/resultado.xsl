<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
				xmlns:fo="http://www.w3.org/1999/XSL/Format"
				xmlns="http://www.w3.org/1999/xhtml">

<xsl:include href="formStatus.xsl" />

<xsl:variable name="uid" select="string('enfermeira')" />
<xsl:variable name="id" select="string('PCR163')" />

<xsl:template match="/">
	<xsl:apply-templates select="pacientes/paciente" />
</xsl:template>

</xsl:stylesheet>