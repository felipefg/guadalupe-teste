<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<!-- Criterio inicial de triagem para TB pulmonar -->
<xsl:template match="triagem">
	<xsl:call-template name="filtro" />
</xsl:template>

</xsl:stylesheet>
