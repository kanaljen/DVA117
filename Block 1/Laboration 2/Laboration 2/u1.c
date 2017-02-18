#include <stdio.h>
#include <stdlib.h>

float medelfunc(int sum, int antal){
  float sumf, antalf;
  sumf = sum;
  antalf = antal;
  return (sumf / antalf);
}

int main(void){
system("clear");
int input, high, low, sum=0, antal=0;
float medel;
  printf("\n----------------------------\n\t\e[031mTALRÄKNAREN\n\e[037m----------------------------\n");
  printf("Ange ett negativt tal för att avsluta\ninmatningen och visa resultat.\n\n");
  printf("Ange ett tal för att starta:\e[031m ");
  scanf("%d",&input);
  high=input;
  low=input;
  while (input>=0) {
    antal = antal + 1;
    if (input>=high)high = input;
    if (input<=low)low = input;
    sum = sum + input;
    printf("\e[037mGe tal för att fortsätta:\e[031m ");
    scanf("%d",&input);
    medel = medelfunc(sum,antal);
  }
  printf("\e[037m\nResult\n----------------------------\n");
  printf("Det störrsta talet: \e[031m%d\e[037m\n",high);
  printf("Det minsta talet: \e[031m%d\e[037m\n",low);
  printf("Summan av talen: \e[031m%d\e[037m\n",sum);
  printf("Medelvärdet: \e[031m%.2f\e[037m\n",medel);
  printf("----------------------------\n\n");
  return 0;
}
