#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//#include "functions.h"
//#include "const.h"
//#include "error.h"
#include "ntbError.h"

/*
int getUsername(char*, char*);
int getUsername(char *conteudo, char *username)
{
	long unsigned indice, indiceAux;
	if (!(conteudo))
		return(1);
	indice=indiceAux=0;
	while ((conteudo[indice] != '=') && (indice<=9))
		indice++;
	if(!(strncmp("username",conteudo,indice)))
	{
		indice++;
		while ((indice<=9+MAX_LENGTH_USERNAME)) //while ((conteudo[indice] != '&') && (indice<=9+MAX_LENGTH_USERNAME))
		{
			username[indiceAux]=conteudo[indice];
			indice++;
			indiceAux++;	
		}
		username[indiceAux]='\0';
	}
	
	else
		return(WRONG_FIELD_NAME);

	return(0);
}
*/
int main(int argc, char **argv)
{
	printf("Content-Type: text/html\r\n");
	printf("Location: login.html\r\n");
	printf("\r\n");
	
	return (ok);
}
