#include <stdio.h>
#include <stdlib.h>

int sek;
float euro;

int input(void){
  int kr;
  printf("\n----------------------------\n\t\e[031mVALUTAVÄXLING\e[037m\n----------------------------\n\n");
  printf("Ange antal hela svenska kronor som ska växlas:\e[031m ");
  scanf("%d",&kr);
  return (kr);
}

float convert(int kr){
  float rate = 9.30156157,eu;
  char change;
  printf("\e[037mEnligt google är \e[031m1\e[037m\u20AC värd \e[031m%f\e[037mkr.\n",rate);
  printf("Vill du ändra växlingskurs (\e[032my\e[037m)? ");
  scanf(" %c",&change);
  if (change == 'y'||change == 'Y'){
    printf("\nAnge en ny växlingskurs.\n");
    printf("Hur mycket är \e[031m1\e[037m\u20AC värd i svenska kronor? \e[031m");
    scanf("%f",&rate);
  }
  eu = kr / rate;
  return (eu);
}

void result(void){
  printf("\e[037m\n\e[031m%d\e[037mkr är värda \e[031m%.2f\e[037m\u20AC.\n\n",sek,euro);
}

int main(void) {
  system("clear");
  sek = input();
  euro = convert(sek);
  result();
  return 0;
}
