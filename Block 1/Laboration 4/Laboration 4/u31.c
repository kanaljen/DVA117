#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define INPUT_SIZE 50

//start intro header, färga tal \e[033m%d\e[037m (3=gul,1=röd)
int main();
char name[] = "╦  ╔═╗╔╦╗╔═╗  ╔╦╗╔═╗╦ \n\t║  ║╣  ║ ╠═╣   ║ ╠═╣║  \n\t╩═╝╚═╝ ╩ ╩ ╩   ╩ ╩ ╩╩═╝";
char introtxt[] = "V 1\nProgrammet tar en godtycklig sträng och\nskriver ut första och sedan valfritt ord.";
#include "staffan.h"
//end introheader

void input(char* input){ //Sköter inmatning
  int i;
  for(i=0;i<INPUT_SIZE;i++){//nolla arrayerna
    input[i]=0;
  }
  fpurge(stdin);
  printf("Mata in text: ");
  fgets(input,INPUT_SIZE,stdin);
  for(i=0;i<INPUT_SIZE;i++)if(input[i]=='\n')input[i]='\0'; //Tar bort \n på slutet av inputen
}

//Uppgift 3.1
void printFirst(char* input){
  int i;
  line();
  printf("Uppgift 3.1 - Första ordet är: ");
  for(i=0;isalpha(input[i])>0;i++)printf("\e[033m%c\e[037m",input[i]);
  line();
}

//Uppgift 3.2
void getWords(char* input,int wtoprint){//Indexerar orden med nummer, return antal ord
  int i,j,w=0;
  for(i=0;i<INPUT_SIZE;i++){//Räknar upp strängen
    if(isalpha(input[i])>0){
      w++;//Nytt ord
      if(w==wtoprint)printf("Ord %d: ",w);
      for(j=i;isalpha(input[j])>0;j++){//räkna upp ordet
        if(w==wtoprint)printf("\e[033m%c\e[037m",input[j]);
      }
      i=j;
    }
  }
  if(wtoprint>w)printf("Strängen innehåller bara \e[031m%d\e[037m ord.",w);
  line();
}

//Uppgift 3.3
int main(void) {
  intro();
  char inputTxt[INPUT_SIZE];
  int word;
  input(inputTxt);
  printFirst(inputTxt);
  printf("Vilket ord vill du skriva ut? ");
  scanf("%d",&word);
  getWords(inputTxt,word);
  endgame();
}
