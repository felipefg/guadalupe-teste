# Makefile - Neural TB Project


# * Universidade Federal do Rio de Janeiro
# * Escola Politecnica
# * Departamento de Engenharia Eletronica e de Computacao
# *
# * Laboratorio de Processamento de Sinais
# * Projeto Neural TB
# * Autor: Patrick Svaiter
# *
# * $Author$
# * $Date$
# * $Log$

CC = gcc
LD = gcc

CFLAGS = -Wall -c
LFLAGS = -Wall -o
XML_CFLAGS = `xml2-config --cflags`
XML_LFLAGS = `xml2-config --libs`

LIBCGIDIR = libs/libcgi-1.0
LIBCGIFLAGS = -L$(LIBCGIDIR) -lcgi

USERNAME = dhiana 

CGIDIR = ..
XMLDIR =


ADDPATIENT_OBJS = ntbFunctions.o ntbCgiAddPatient.o
ADDPATIENTINFO_OBJS = ntbFunctions.o ntbCgiAddPatientInfo.o
BACKUP_OBJS = backup.o
FORMSSTATUS_OBJS = ntbFunctions.o ntbCgiFormsStatus.o
LOGIN_OBJS = functions.o ntbCgiLogin.o
LOGOUT_OBJS = ntbCgiLogout.o
SEARCHPATIENT_OBJS = ntbFunctions.o ntbCgiSearchPatient.o
VIEWPATIENT_OBJS = ntbFunctions.o ntbCgiViewPatient.o
LISTPATIENTS_OBJS = ntbCgiListPatients.o
REMOVEPATIENT_OBJS = ntbCgiRemovePatient.o
EDIT_PATIENT_OBJS = ntbFunctions.o ntbCgiEditPatient.o

HTML_TRIAGEM_OBJS = functions.o ntbCgiTriagem.o
HTML_CUSTOSA_OBJS = functions.o ntbCgiCustosA.o
HTML_CUSTOSBC_OBJS = functions.o ntbCgiCustosBeC.o
HTML_CONSULTAMEDICA_OBJS = functions.o ntbCgiConsultaMedica.o
HTML_FOLLOWUP_OBJS = functions.o ntbCgiFollowUp.o
HTML_VERLADO_OBJS = ntbFunctions.o ntbCgiVerLado.o
HTML_INCLUIRFORM_OBJS = ntbFunctions.o ntbCgiAcrescentarOutrosForms.o

HTML_EDIT_OBJS = functions.o ntbCgiFormEdit.o
HTML_BUSCA_OBJS = functions.o ntbCgiBusca.o
HTML_LISTAR_OBJS = functions.o ntbCgiListar.o
HTML_IMPRIMIR_OBJS = ntbFunctions.o ntbCgiImprimir.o

NTB_CGI = addPatient.cgi addPatientInfo.cgi backup.cgi  login.cgi logout.cgi\
	triagem.cgi custosA.cgi custosBeC.cgi consultaMedica.cgi followUp.cgi\
	formsStatus.cgi searchPatient.cgi viewPatient.cgi busca.cgi listar.cgi\
	listPatients.cgi imprimir.cgi removePatient.cgi editPatient.cgi editForm.cgi\
	verLado.cgi incluirForm.cgi

FORMS = triagem.cgi custosA.cgi custosBeC.cgi consultaMedica.cgi followUp.cgi busca.cgi listar.cgi
	
EXECS = $(NTB_CGI)

#-------------------------------------------------------------------------------
.c.o:
	$(CC) $(CFLAGS) $< $(XML_CFLAGS)

all: $(EXECS)

forms: $(FORMS)
#-------------------------------------------------------------------------------
ntbCgis: $(NTB_CGI)

addPatient.cgi: $(ADDPATIENT_OBJS)
	$(LD) $(LFLAGS) $@ $(ADDPATIENT_OBJS) $(XML_LFLAGS) $(LIBCGIFLAGS)
	mv -f $@ $(CGIDIR)/$@

addPatientInfo.cgi: $(ADDPATIENTINFO_OBJS)
	$(LD) $(LFLAGS) $@ $(ADDPATIENTINFO_OBJS) $(XML_LFLAGS) $(LIBCGIFLAGS)
	mv -f $@ $(CGIDIR)/$@

backup.cgi: $(BACKUP_OBJS)
	$(LD) $(LFLAGS) $@ $(BACKUP_OBJS)
	mv -f $@ $(CGIDIR)/$@

formsStatus.cgi: $(FORMSSTATUS_OBJS)
	$(LD) $(LFLAGS) $@ $(FORMSSTATUS_OBJS) $(XML_LFLAGS) $(LIBCGIFLAGS)
	mv -f $@ $(CGIDIR)/$@
	
triagem.cgi: $(HTML_TRIAGEM_OBJS)
	$(LD) $(LFLAGS) $@ $(HTML_TRIAGEM_OBJS) $(LIBCGIFLAGS)
	mv -f $@ $(CGIDIR)/$@

custosA.cgi: $(HTML_CUSTOSA_OBJS)
	$(LD) $(LFLAGS) $@ $(HTML_CUSTOSA_OBJS) $(LIBCGIFLAGS)
	mv -f $@ $(CGIDIR)/$@

custosBeC.cgi: $(HTML_CUSTOSBC_OBJS)
	$(LD) $(LFLAGS) $@ $(HTML_CUSTOSBC_OBJS) $(LIBCGIFLAGS)
	mv -f $@ $(CGIDIR)/$@

consultaMedica.cgi: $(HTML_CONSULTAMEDICA_OBJS)
	$(LD) $(LFLAGS) $@ $(HTML_CONSULTAMEDICA_OBJS) $(LIBCGIFLAGS)
	mv -f $@ $(CGIDIR)/$@

followUp.cgi: $(HTML_FOLLOWUP_OBJS)
	$(LD) $(LFLAGS) $@ $(HTML_FOLLOWUP_OBJS) $(LIBCGIFLAGS)
	mv -f $@ $(CGIDIR)/$@

busca.cgi: $(HTML_BUSCA_OBJS)
	$(LD) $(LFLAGS) $@ $(HTML_BUSCA_OBJS) $(LIBCGIFLAGS)
	mv -f $@ $(CGIDIR)/$@
	
listar.cgi: $(HTML_LISTAR_OBJS)
	$(LD) $(LFLAGS) $@ $(HTML_LISTAR_OBJS) $(LIBCGIFLAGS)
	mv -f $@ $(CGIDIR)/$@	
	
imprimir.cgi: $(HTML_IMPRIMIR_OBJS)
	$(LD) $(LFLAGS) $@ $(HTML_IMPRIMIR_OBJS) $(XML_LFLAGS) $(LIBCGIFLAGS)
	mv -f $@ $(CGIDIR)/$@
	
login.cgi: $(LOGIN_OBJS)
	$(LD) $(LFLAGS) $@ $(LOGIN_OBJS) $(LIBCGIFLAGS)
	mv -f $@ $(CGIDIR)/$@

logout.cgi: $(LOGOUT_OBJS)
	$(LD) $(LFLAGS) $@ $(LOGOUT_OBJS)
	mv -f $@ $(CGIDIR)/$@

searchPatient.cgi: $(SEARCHPATIENT_OBJS)
	$(LD) $(LFLAGS) $@ $(SEARCHPATIENT_OBJS) $(XML_LFLAGS) $(LIBCGIFLAGS)
	mv -f $@ $(CGIDIR)/$@

viewPatient.cgi: $(VIEWPATIENT_OBJS)
	$(LD) $(LFLAGS) $@ $(VIEWPATIENT_OBJS) $(XML_LFLAGS) $(LIBCGIFLAGS)
	mv -f $@ $(CGIDIR)/$@
	
listPatients.cgi: $(LISTPATIENTS_OBJS)
	$(LD) $(LFLAGS) $@ $(LISTPATIENTS_OBJS) $(XML_LFLAGS) $(LIBCGIFLAGS)
	mv -f $@ $(CGIDIR)/$@
	
removePatient.cgi: $(REMOVEPATIENT_OBJS)
	$(LD) $(LFLAGS) $@ $(REMOVEPATIENT_OBJS) $(XML_LFLAGS) $(LIBCGIFLAGS)
	mv -f $@ $(CGIDIR)/$@
	
editForm.cgi: $(HTML_EDIT_OBJS)
	$(LD) $(LFLAGS) $@ $(HTML_EDIT_OBJS) $(XML_LFLAGS) $(LIBCGIFLAGS)
	mv -f $@ $(CGIDIR)/$@
	
editPatient.cgi: $(EDIT_PATIENT_OBJS)
	$(LD) $(LFLAGS) $@ $(EDIT_PATIENT_OBJS) $(XML_LFLAGS) $(LIBCGIFLAGS)
	mv -f $@ $(CGIDIR)/$@
	
verLado.cgi: $(HTML_VERLADO_OBJS)
	$(LD) $(LFLAGS) $@ $(HTML_VERLADO_OBJS) $(XML_LFLAGS) $(LIBCGIFLAGS)
	mv -f $@ $(CGIDIR)/$@

incluirForm.cgi: $(HTML_INCLUIRFORM_OBJS)
	$(LD) $(LFLAGS) $@ $(HTML_INCLUIRFORM_OBJS) $(XML_LFLAGS) $(LIBCGIFLAGS)
	mv -f $@ $(CGIDIR)/$@
	
#-------------------------------------------------------------------------------
clean:
	rm -f *.o

clobber: clean
	rm -f $(CGIDIR)/*.cgi

# * $RCSfile$
