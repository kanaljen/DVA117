#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//start intro header, färga tal \e[031m%d\e[037m
int main(void);
char name[] = "LETA TAL";
char introtxt[] = "Här är ett program som slumpar fram 10 heltal.\n";
#include "staffan.h"
//end introheader

int tal[10];

void randomizer(void){
  int num;
  for(num=0;num<10;num++){
    tal[num]=rand() % 10 + 1;
  }
}

int search(num){
  int x;
  int times=0;
  for(x=0;x<10;x++)if(num==tal[x])times=times+1;
  return times;
}

void output(int stage){
  int print;
  int lookfor;
  switch(stage){
    case 0: intro(); break;
    case 1:
    for(print=0;print<10;print++)printf("Tal %d: \e[031m%d\e[037m\n",print + 1,tal[print]);
    line();
    printf("\nVilket tal ska jag leta efter? \e[031m");
    scanf("%d",&lookfor);
    printf("\n\e[031m%d\e[037m förekommer \e[031m%d\e[037m gånger.\n",lookfor,search(lookfor));
    line();
    break;
  }
}

int main(){
  system("clear");
  srand((unsigned) time(NULL));
  output(0);
  randomizer();
  output(1);
  endgame();
  return 0;
}
