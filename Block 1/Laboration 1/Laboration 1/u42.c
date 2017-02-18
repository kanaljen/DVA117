#include <stdio.h>
int num, loop;

int main(void){
do{
printf("\n----------------------------\nUppgift 4.1\n----------------------------\nAnge ett tal mellan 0 och 5: ");
scanf("%d",&num);

printf("Morsekod: ");
    switch(num){

        case 0 : printf("-----"); break;
        case 1 : printf(".----"); break;
        case 2 : printf("..---"); break;
        case 3 : printf("...--"); break;
        case 4 : printf("....-"); break;
        case 5 : printf("....."); break;
        default : printf("ERROR");break;
    }
printf("\n1: Kör igen\n2: Avsluta\n");
scanf("%d",&loop);
printf("\n----------------------------\n");
}while(loop == 1);
return 0;
}