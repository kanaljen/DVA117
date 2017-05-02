#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int r,try;

int main(void);

void randgen(void){
  srand((unsigned) time(NULL));
  r=rand() % 100 + 1;
}

int guessfunc(void){
  int guess;
  scanf("%d",&guess);
  try = try + 1;
  return (guess);
}

void game(int guess){
  while (guess!=r){
    if (guess<r){
      printf("\nGissning: %d Du gissade för lågt, försök igen\t",guess);
      guess=guessfunc();
    }
    else if (guess>r){
      printf("\nGissning: %d Du gissade för högt, försök igen\t",guess);
      guess=guessfunc();
    }
  }
  printf("\nGissning: %d Grattis, det var rätt!\n",guess);
  printf("Du gjorde %d försök.\n",try);
  printf("\n----------------------------\n");
}

void endgame(void){
  char replay;
  printf("\nVill du spela igen (y/n)?");
  scanf(" %c",&replay);
  if (replay == 'y'||replay == 'Y') main();
}

int main(void){
  system("clear");
  printf("\n----------------------------\n\tGISSA TAL\n----------------------------\n");
  try = 0;
  printf("\nJag ”tänker” på ett tal mellan 1 och 100, gissa vilket!\t");
  randgen();
  game(guessfunc());
  endgame();
  system("clear");
 return(0);
}
