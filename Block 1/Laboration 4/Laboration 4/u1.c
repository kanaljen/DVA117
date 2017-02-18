#include <stdio.h>
#include <stdlib.h>

//start intro header, färga tal \e[031m%d\e[037m
int main();
char name[] = "PRIMTAL";
char introtxt[] = "Kontrollerar om en sekvens positiva\ntal är primtal eller inte.\n";
#include "staffan.h"
//end introheader

void input(int num,int* numbers){ //Input och skriver till array
  int i;
  if(num>10)num=10;
    for(i=0;i<num&&i<10;i++){
      printf("Skriv tal %d --> ",i+1);
      scanf("%d",&numbers[i]);
    }
}

int arraySize(int* array){ //Räknar storleken på arrayen, minus \0
  int i,size=0;
  for(i=0;array[i]!='\0';i++)size++;
  return size;
}

int keepPrimes(int* input,int size){ //Identifierar och behålller primtal
  int i,j,p=0;
  for(i=0;i<size;i++){
    if(input[i]<0)return -1;
    else if(input[i]<2){
      input[i]=-1;

    }
    else if(input[i]>1){
      for(j=2;j<=input[i];j++){
        if((input[i]%j)==0&&input[i]!=j){
          input[i]=-1;
          break;
        }
      else if ((input[i]%j)==0&&input[i]==j)p++;
    }
  }
}
return p;
}

int output(int prime,int* input,int size){
  int i;
  line();
  if(prime==-1){
    printf("Sekvensen innehåller ett \e[031mnegativt\e[037m tal.");
    return 0;
  }
  else if(prime==0){
    printf("Sekvensen innehåller \e[033minga\e[037m primtal.");
    return 0;
  }
  printf("Sekvensen följande \e[032m%d\e[037m primtal:\n",prime);
  for(i=0;i<size;i++)if(input[i]!=-1)printf("%d ",input[i]);
  return 0;
}

int main(){
  int numbers[11]={0,0,0,0,0,0,0,0,0,0};
  int num, prime;
  intro();
  printf("Hur många tal vill du mata in (\e[033m1-10\e[037m)? ");
  scanf("%d",&num);
  input(num,numbers);
  prime = keepPrimes(numbers,arraySize(numbers));
  output(prime,numbers,arraySize(numbers));
  line();
  endgame();
}
