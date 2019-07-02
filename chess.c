#include <stdio.h>
#include <stdlib.h>
#include "chess.h"
#include <string.h>

char charRev(char c);
void display(){}

char** reverse(char** fig){

	int numF=60+1;
	int numC=60+1;
	int i,j;
	char c;

	char** figrev=(char**)malloc(sizeof(char*) * (numF));

	for(i=0;i<numF;i++){
		figrev[i]=(char*)malloc(sizeof(char) * (numC));

		for(j=0;j<numC;j++){
			c=charRev(fig[i][j]);
			figrev[i][j]=c;			
		}
		figrev[i][j]=0;
	}
	figrev[i]=0;

	return figrev;

}
char charRev(char c)
{
	switch(c){
		case '_': return '=';
		case '=': return '_';
		case '.': return '@';
		case '@': return '.';
		case ' ': return ' ';
	}

	return '#';
}



