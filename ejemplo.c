#include "chess.h"
#include "figures.h"

char charRev(char c);
char** reversex(char** fig);
char** rotateLx(char** fig);
char** rotateRx(char** fig);
char** flipVx(char** fig);
char** flipHx(char** fig);
char** superImposex(char** fig1,char** fig2);
char** joinx(char** fig1,char** fig2);
char** upx(char** fig1,char** fig2);
char** repeatHx(char** fig,int n);
char** repeatVx(char** fig,int n);

void display(){
  char** blackKnight = repeatVx(knight,5);
//char** blackKnight = reverse(knight);
  interpreter(blackKnight);
}


char** repeatVx(char** fig,int n){

	int numF=0;
	int numC=0;
	int i,j,k=0;
    
    while(fig[numF])
        numF++;

    while(fig[0][numC])
        numC++;


    char** figrV=(char**)malloc(sizeof(char*)*(numF*n));

	for(i=0;i< numF*n;i++){
		figrV[i]=(char*)malloc(sizeof(char) * (numC));
  
		for(j=0;j<numC;j++){

                figrV[i][j]=fig[i%numF][j];
		}

        figrV[i][j]='\0';
        
	}

    figrV[i]='\0';
    return figrV;


}
char** repeatHx(char** fig,int n){

	int numF=0;
	int numC=0;
	int i,j,k=0;
    
    while(fig[numF])
        numF++;

    while(fig[0][numC])
        numC++;


    char** figrH=(char**)malloc(sizeof(char*)*(numF));

	for(i=0;i< numF;i++){
		figrH[i]=(char*)malloc(sizeof(char) * (numC*n));
  
		for(j=0;j<numC*n;j++){

                figrH[i][j]=fig[i][j%numC];
		}

        figrH[i][j]='\0';
        
	}

    figrH[i]='\0';
    return figrH;
}
char** upx(char** fig1,char** fig2){

	int numF=0;
	int numC=0;
	int i,j,k=0;
    
    while(fig1[numF])
        numF++;

    while(fig1[0][numC])
        numC++;


    char** figup=(char**)malloc(sizeof(char*)*(numF*2));

	for(i=0;i< numF*2;i++){
		figup[i]=(char*)malloc(sizeof(char) * (numC));
  
		for(j=0;j<numC;j++){

            if(i<numF)
                figup[i][j]=fig1[i][j];
            else
                figup[i][j]=fig2[i-numF][j];
            
		            }

        figup[i][j]='\0';
        
	}
    figup[i]='\0';

    return figup;
}


char** joinx(char** fig1,char** fig2){

	int numF=0;
	int numC=0;
	int i,j,k=0;
    
    while(fig1[numF])
        numF++;

    while(fig1[0][numC])
        numC++;


    char** figj=(char**)malloc(sizeof(char*)*(numF));

	for(i=0;i< numF;i++){
		figj[i]=(char*)malloc(sizeof(char) * (numC*2));
  
		for(j=0;j<numC;j++){
            figj[i][j]=fig1[i][j];
		}
		for(k=0;k<numC;k++){
            figj[i][j]=fig2[i][k];
            j++;
		}
        figj[i][j]='\0';
        
	}

    figj[i]='\0';
    return figj;
}


char** superImposex(char** fig1,char** fig2){
	int numF=0;
	int numC=0;
	int i,j,k=0;
    
    while(fig1[numF])
        numF++;

    while(fig1[0][numC])
        numC++;


    char** figu=(char**)malloc(sizeof(char*)*(numF));

	for(i=0;i< numF;i++){
		figu[i]=(char*)malloc(sizeof(char) * (numC));
  
		for(j=0;j<numC;j++){
            figu[i][j]=fig1[i][j];
		}
        figu[i][j]='\0';

		for(j=0;j<numC;j++){
            figu[i][j]=(' '==fig1[i][j])?fig2[i][j]:fig1[i][j];
		}
        //figu[i][j]='\0';
        
	}

    figu[i]='\0';
    return figu;
}
char** flipHx(char** fig){

	int numF=0;
	int numC=0;
	int i,j,k=0;
    
    while(fig[numF])
        numF++;

    while(fig[0][numC])
        numC++;

    printf("numF:  %d \n",numF);
    printf("numC:  %d \n",numC);

    char** figfh=(char**)malloc(sizeof(char*)*(numF));

	for(i=numF-1;i>=0;i--){
		figfh[k]=(char*)malloc(sizeof(char) * (numC));
        
        figfh[k]=fig[i];
        k++;
	}
	figfh[k]='\0';

    return figfh;


}
char** flipVx(char** fig){

	int numF=0;
	int numC=0;
	int i,j,k=0;
    
    while(fig[numF])
        numF++;

    while(fig[0][numC])
        numC++;


    char** figfv=(char**)malloc(sizeof(char*)*(numF));

	for(i=0;i< numF;i++){
		figfv[i]=(char*)malloc(sizeof(char) * (numC));
           k=0;
		for(j=numC-1;j>=0;j--){
		    figfv[i][k]=fig[i][j];
            k++;
		}
		figfv[i][k]='\0';
        
	}
	figfv[i]='\0';

    return figfv;

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

