#include "chess.h"
#include "figures.h"

char charRev(char c);
char** reversex(char** fig);
char** rotateLx(char** fig);
char** rotateRx(char** fig);

void display(){
  char** blackKnight = rotateRx(bishop);
  interpreter(blackKnight);
}

char** rotateRx(char** fig){

	int numF=0;
	int numC=0;
	int i,j,k=0;
	char c;
    
    while(fig[numF])
        numF++;

    while(fig[0][numC])
        numC++;

    char** figrot=(char**)malloc(sizeof(char*)*(numF));

	for(i=0;i< numF;i++){
		figrot[i]=(char*)malloc(sizeof(char) * (numC));
           k=0;
		for(j=numC-1;j>=0;j--){
		    figrot[i][k]=fig[j][i];
            k++;
		}
		figrot[i][k]='\0';
        
	}
	figrot[i]='\0';


    return figrot;
}

char** rotateLx(char** fig){

	int numF=0;
	int numC=0;
	int i,j,k=0;
	char c;
    
    while(fig[numF])
        numF++;

    while(fig[0][numC])
        numC++;

    char** figrot=(char**)malloc(sizeof(char*)*(numF));

	for(i=numF-1;i>=0;i--){
		figrot[k]=(char*)malloc(sizeof(char) * (numC));

		for(j=0;j<numC;j++){
		    figrot[k][j]=fig[j][i];
		}
		figrot[k][j]='\0';
        k++;
	}
	figrot[k]='\0';


    return figrot;
}


char** reversex(char** fig){

	int numF=0;
	int numC=0;
	int i,j;
	char c;
    
    while(fig[numF])
        numF++;

    while(fig[0][numC])
        numC++;

printf("numF:  %d \n",numF);
printf("numC:  %d \n",numC);
	char** figrev=(char**)malloc(sizeof(char*) * (numF));

	for(i=0;i<numF;i++){
		figrev[i]=(char*)malloc(sizeof(char) * (numC));

		for(j=0;j<numC;j++){
			c=charRev(fig[i][j]);
			figrev[i][j]=c;			
		}
		figrev[i][j]='\0';
	}
	figrev[i]='\0';

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

