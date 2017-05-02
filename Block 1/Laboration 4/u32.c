#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//start intro header, färga tal \e[033m%d\e[037m (3=gul,1=röd)
int main();
char name[] = "LETA ORD";
char introtxt[] = "V 2\nProgrammet tar en godtycklig sträng och\nskriver ut första och sedan valfritt ord.";
#include "staffan.h"
//end introheader

char* input(char* input){
  fpurge(stdin);
  printf("\nMata in en string: ");
  fgets(input,100,stdin);
  return input;
}

int selectWord(){
  int word;
  fpurge(stdin);
  line();
  printf("Vilket ord vill du skriva ut? ");
  scanf("%d",&word);
  return word;
}

int getWord(char* input, int word){
  int i,j,c=0;
  for(i=0;i<100;i++){//gå igenom strängen
    if(isalpha(input[i])>0){
      c++;
      for(j=i;isalpha(input[j])>0;j++);//gå igenom ordet
      if(c==word)return i;
      i=j;
    }
  }
  return -1;
}

void printWord(char* input, int word){
  int i;
  i = getWord(input,word);
  if(i<0){
    printf("Du har angivit ett ord som inte finns med!");
    line();
  }
  else{
    printf("Ord %d i strängen är: ",word);
    for(;isalpha(input[i])>0;i++){
      printf("%c",input[i]);
    }
    line();
  }

}

int main() {
  intro();
  char inputTxt[100];
  printWord(input(inputTxt),selectWord());
  endgame();
}
