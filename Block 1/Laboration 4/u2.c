#include <stdio.h>
#include <stdlib.h>

//start intro header, färga tal \e[033m%d\e[037m (3=gul,1=röd)
int main();
char name[] = "FREKVENSANALYS";
char introtxt[] = "Mata in tal mellan \e[033m1\e[037m och \e[033m1000\e[037m. Avsluta inmatningen\ngenom att ange ett \e[031mnegativt\e[037m tal.\n";
#include "staffan.h"
//end introheader

void input(int* freq,int* index){//fyller arrayen med input, ger arrayen tillbaka
  int i;
  for(i=0;i<20;i++){//nolla arrayerna
    freq[i]=0;
    index[i]=0;
  }
  i=0;
  do{
    do{
      printf("Ange tal %d --> ",i+1);
      scanf("%d",&freq[i]);
      if(freq[i]==0||freq[i]>1000)printf("Talet ligger utanför intervallet. Försök igen!\n");
    }while(freq[i]==0||freq[i]>1000);
    if(freq[i]>0)index[i]=1;
    i++;
  }while(i<20&&freq[i-1]>0);
}

void count(int* freq,int* index){//Jämför num i arrayen, +1 i index för varje match
  int i,j;
  for(i=0;i<20;i++){
    if(index[i]>0){
      for(j=i+1;j<=20;j++){
        if(freq[i]==freq[j]){//Add/Remove
          index[i]++;
          freq[j]=-1;//matchen blir -1 för att inte räknas igen
          index[j]=0;
        }
      }
    }
  }
}

int compare(int* freq,int* index){//Vilket nummer förekommer oftast, och hur många gånger
  int i,hnum=0,hindex;
  for(i=0;i<20;i++){
    if(index[i]>hnum){
      hnum=index[i];
      hindex=i;
    }
  }
  return hindex;
}

void output(int n,int* freq,int* index){//Skriver ut resultat
  line();
  printf("\nTalet \e[033m%d\e[037m förekommer flest gånger, totalt \e[033m%d\e[037m gånger.\n",freq[n],index[n]);
  line();
}

int main(){
  int inputFreq[20],indexFreq[20];
  intro();
  input(inputFreq,indexFreq);
  count(inputFreq,indexFreq);
  output(compare(inputFreq,indexFreq),inputFreq,indexFreq);
  endgame();
  return 0;
}
