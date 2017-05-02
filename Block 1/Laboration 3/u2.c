#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//start intro header, färga tal \e[031m%d\e[037m
int main(void);
char name[] = "YATZY KAST";
char introtxt[] = "Ett program som ""grafiskt"" visar fem tärningar och dess resultat på skärmen.\n";
#include "staffan.h"
//end introheader

char dice[6][3][3]=
  {
    {
      {' ',' ',' '},
      {' ','*',' '},
      {' ',' ',' '}
    },
    {
      {'*',' ',' '},
      {' ',' ',' '},
      {' ',' ','*'}
    },
    {
      {'*',' ',' '},
      {' ','*',' '},
      {' ',' ','*'}
    },
    {
      {'*',' ','*'},
      {' ',' ',' '},
      {'*',' ','*'}
    },
    {
      {'*',' ','*'},
      {' ','*',' '},
      {'*',' ','*'}
    },
    {
      {'*',' ','*'},
      {'*',' ','*'},
      {'*',' ','*'}
    },
  };
int dicenum[5];

int throw(int x){
  dicenum[x]=rand()%6+1;
  return dicenum[x];
}

int sum(void){
  int x,sum=0;
  for(x=0;x<5;x++)sum = sum + dicenum[x];
  return sum;
}

void drawdice(int z){
  int x,y;
  for(x=0;x<3;x++){
    printf("\e[47m \e[40m");
    for(y=0;y<3;y++){
      printf("\e[47m\e[30m%c \e[37m\e[40m",dice[z-1][x][y]);
    }
    printf("\n");
  }
  printf("\n");
}

void compare(void){
  int x,y,tva=0,tre=0,fyr=0,fem=0,num=0;
  for(x=0;x<5;x++){
    for(y=0;y<5;y++){
      if (dicenum[x]==dicenum[y]&&x!=y)num=num+1;
    }
      switch (num) {
        case 1: tva=tva+1;break;
        case 2: tre=tre+1;break;
        case 3: fyr=fyr+1;break;
        case 4: fem=fem+1;break;
        default: break;
      }
    num=0;
  }
  tva=tva/2;
  tre=tre/3;
  fyr=fyr/4;
  fem=fem/5;

  printf("Du fick ");
  if (tva==1&&tre==0)printf("ett par!");
  else if (tva==2)printf("två par!");
  else if (tre==1&&tva==0)printf("en triss!");
  else if (fyr==1)printf("ett fyrtal!");
  else if (tva==1&&tre==1)printf("en kåk!");
  else if (fem==1)printf("Yatzy!");
  else printf("inget speciellt :(");
  printf("\n");
}

int main(void){
  int x;
  srand((unsigned) time(NULL));
  system("clear");
  intro();
  for(x=0;x<5;x++)drawdice(throw(x));
  printf("Summa (\e[031m%d\e[037m+\e[031m%d\e[037m+\e[031m%d\e[037m+\e[031m%d\e[037m+\e[031m%d\e[037m): \e[031m%d\e[037m\n\n",dicenum[0],dicenum[1],dicenum[2],dicenum[3],dicenum[4],sum());
  compare();
  endgame();
}
