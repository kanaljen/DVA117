#include <stdio.h>
#include <stdlib.h>
#define INPUT_SIZE 50

//start intro header, färga tal \e[031m%d\e[037m
int main(void);
char name[] = "PALINDROM";
char introtxt[] = "Ett program som avgör om en inmatad\ntext är ett palindrom eller ej.\n";
#include "staffan.h"
//end introheader

char inputString[INPUT_SIZE];

int countChar(char* input);

char* inputf(void){ //Sköter inmatning
  fpurge(stdin);
  printf("Mata in text att kontrollera: ");
  fgets(inputString,INPUT_SIZE,stdin);
  inputString[countChar(inputString)-1]='\0'; //Tar bort \n på slutet av inputen
  printf("\n\"%s\"",inputString);
  return inputString;
}

char* changeUpper(char* input){ //Ändrar stora botstäver till små
  int i;
  for(i=0;input[i]!='\0';i++){
    if(input[i]>=65&&input[i]<=90)input[i]=input[i]+32;

  }
  return input;
}

char* removeSpace(char* input){ //Tar bort space
  int i,x;
  for(i=0;input[i]!='\0';i++){
    if(input[i]==32){
      for(x=i;input[x]!='\0';x++)input[x]=input[x+1];
    }
  }
  input[i]='\0'; //Tar bort nollan från forloopen
  return input;
}

int countChar(char* input){ //räknar alla tecken inklusive \0
  int i,c=0;
  for(i=0;input[i]!='\0';i++)c++;
  //printf("%d\n",c);
  return c;
}

int isPalindrome(char* input){
  int c=countChar(input)-1,i,bo=0; //-1 för \0
  for(i=0;i<c;i++){
    if(input[i]==input[c-i])bo++;
    else break;
  }
if (bo==c)return 1;
else return 0;
}

void output(int pal){
  if (pal==1)printf(" \e[032mÄR\e[037m ett palindrom!");
  if (pal==0)printf(" är \e[031mINTE\e[037m ett palindrom :(");
}

int main() {
  system("clear");
  intro();
  output(isPalindrome(removeSpace(changeUpper(inputf()))));
  line();
  endgame();
  return 0;
}
