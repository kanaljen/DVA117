#include "stdio.h"
#include "stdlib.h"

typedef struct{
  int ID, quantity;
  char name[15],unit[2];
}item;

void flushInput(int mode){ //flushar input, om mode = 1 skriv ut text
  int ch;
  if(mode == 1)printf("\nPress Any Key to Continue");
  while ((ch=getchar()) != EOF && ch != '\n');
}

//Globala variabler
int PostNo = -1; //Totalt antal poster, -1 = ingen lista, 0 = tom lista
item *list = NULL; //Pekare till listan med varor
char listName[20]; //namn på listan

void newList(){ //skapa en ny lista
  system("clear");
  printf("NEW LIST\n\n");
  char answ;
  int i,c;
  flushInput(0);
  if(PostNo>-1){ //Om det finns en lista fråga om den ska tas bort
    printf("If you create a new list, your old one will be deleated.\n");
    printf("Are you sure you want to create a new list (Y)? ");
    answ = getchar();
    printf("\n");
  }
  if(PostNo == -1 || answ == 'y' || answ == 'Y'){
    if(PostNo>-1){
      free(list); //om det finns en lista frigör minnet
      list = NULL;
    }
    PostNo = 0;
    //list = (item*)malloc(sizeof(item)); //allokera minne för nya listan
    printf("Name of new list? ");
    do{
      scanf(" %s",listName);
      c=0;
      for(i=0;listName[i] != '\0';i++)c++; //räkna input tecken
      if(c>15)printf("\e[031mERROR! Input too long!\x1b[0m\n");
    }while(c>15); //loopa om det är för många tecken
  }
}

int loadList(){
  system("clear");
  printf("LOAD LIST\n\n");
  int i;
  char fileName[21] = {"files/\0"}; //skapa början av filnamn med dir
  flushInput(0);
  printf("Name of list to load? ");
  scanf(" %s",&fileName[6]);
  printf("\n");
  FILE *file = fopen(fileName, "r");
  if(file == NULL){ //Om filen inte finns
    printf("\e[031mERROR! Could not open file!\x1b[0m\n");
    flushInput(1);
  }
  else{ //öppna filen
    if(PostNo>0){ // om det finns en lista
      free(list); //frigör minnet
      list = NULL;
    }
    fscanf(file, "%s\n%d\n",listName,&PostNo);
    list = (item*)realloc(list,sizeof(item)*PostNo);// allokera minne för nya listan
    for(i=0;i<PostNo;i++){
      fscanf(file,"%d %s %d %s\n",&list[i].ID,list[i].name,&list[i].quantity,list[i].unit);
    }
    printf("List \e[033m%s\x1b[0m loaded!\n",listName);
    flushInput(1);
    fclose(file);
  }
  return 1;
}

int saveList(int n) {
  int i;
  system("clear");
  printf("PRINT LIST\n\n");
  char fileName[21] = {"files/\0"}; //skapa början av filnamn med dir
  for(i=6;listName[i-6] != '\0';i++)fileName[i]=listName[i-6]; //lägg till listans namn
  FILE *file = fopen(fileName, "w"); // öppna filen och associera pekaren file
  if(file == NULL){
    printf("\e[031mERROR! Could not open file!\x1b[0m\n");
    flushInput(1);
    return 0;
  }
  //starta skrivning
  fprintf(file,"%s\n%d\n",listName,PostNo);
  for(i=0;i<n;i++)fprintf(file,"%-2d %-15s %-4d %-4s\n",list[i].ID,list[i].name,list[i].quantity,list[i].unit);
  //avsluta skrivning
  fclose(file);//stäng filen
  printf("List saved to file \e[033m%s\x1b[0m\n",listName);
  flushInput(1);
  return 1;
}

void printList(int n){ //skriv ut listan på skärmen
  int i;
  system("clear");
  printf("PRINT LIST\n\n");
  printf("ID Name            #    Unit\n");
  for(i=0;i<n;i++)printf("%-2d %-15s %-4d %-4s\n",list[i].ID,list[i].name,list[i].quantity,list[i].unit);
  flushInput(1);
}

void inputForm(int n){ //form för att redigera structen
  flushInput(0);
  int c,i;
  printf("\n");
  list[n].ID=n;
  printf("Name of item? ");
  do{
    scanf(" %s",list[n].name);
    c=0;
    for(i=0;list[n].name[i] != '\0';i++)c++; //räkna input tecken
    if(c>15)printf("\e[031mERROR! Input too long!\x1b[0m\n");
  }while(c>15); //loopa om det är för många tecken
  //scanf(" %s",list[n].name);
  printf("SI unit symbol of \e[033m%s\x1b[0m? ",list[n].name);
  do{
    scanf(" %s",list[n].unit);
    c=0;
    for(i=0;list[n].unit[i] != '\0';i++)c++; //räkna input tecken
    if(c>2)printf("\e[031mERROR! Input too long!\x1b[0m\n");
  }while(c>2); //loopa om det är för många tecken
  printf("How many \e[033m%s\x1b[0m of \e[033m%s\x1b[0m? ",list[n].unit,list[n].name);
  while(scanf(" %d",&list[n].quantity)==0){
    printf("\e[031mERROR! Invalid input!\x1b[0m\n");
    flushInput(0);
  }
}

void addItem(int n){ //lägg till vara
  system("clear");
  char c;
  printf("ADD ITEM\n");
  do{
    PostNo++;
    list = (item*)realloc(list,sizeof(item)*PostNo);// allokera minne för nya posten
    inputForm(n);
    flushInput(0);
    printf("\nAdd another item (Y)? ");
    n++;
    c = getchar();
  }while(c=='y' || c=='Y');
}

void editItem(int n){
  system("clear");
  int e;
  printf("ADD ITEM\n\n");
  printf("Item ID to edit? ");
  scanf(" %d",&e);
  if(e>(n-1)||e<0){
    printf("\n\e[031mERROR! Invalid id!\e[037m\n\n");
    flushInput(1);
  }
  else inputForm(e);
}

void removeItem(int n){
  system("clear");
  int rm,i,c;
  printf("REMOVE ITEM\n\n");
  printf("Item ID to edit? ");
  scanf(" %d",&rm);
  if(rm>(n-1)||rm<0){
    printf("\n\e[031mERROR! Invalid id!\e[037m\n\n");
  }
  else{
    for(i=rm;i<=n;i++){
      list[i].ID = list[i+1].ID;
      list[i].quantity = list[i+1].quantity;
      for(c=0;list[i+1].name[c]!='\0';c++)list[i].name[c] = list[i+1].name[c];
      for(c=0;list[i+1].unit[c]!='\0';c++)list[i].unit[c] = list[i+1].unit[c];
    }
  PostNo--; //ta bort en post
  list = (item*)realloc(list,sizeof(item)*PostNo); //allokera nyt minne
  }
  flushInput(1);
}

int fLauncher(char option){ //startar alla funktioner från huvudmenyn
  switch(option){ //alltid tillgängliga
    case '1':newList(); break;
    case '2':loadList(); break;
    default: break;
  }
  if(PostNo>-1){ //tillgängliga om det finns en lista "laddad"
    switch(option){
      case '3':saveList(PostNo); break;
      case '4':printList(PostNo); break;
      case '5':addItem(PostNo); break;
      case '6':editItem(PostNo); break;
      case '7':removeItem(PostNo); break;
      case 'Q':return -1;
      default: break;
    }
  }
return 0;
}

int mainMenu(){
  system("clear");
  printf("MAIN MENU\n");
  if(PostNo>-1)printf("Currently editing: \e[033m%s\x1b[0m",listName);
  else printf("no active list");
  printf("\n\n1 – New List\n");
  printf("2 – Load List\n");
  if(PostNo>-1){//tillgängliga om det finns en lista "laddad"
    printf("3 – Save List\n");
    printf("4 – Print List\n");
    printf("5 – Add Item\n");
    printf("6 – Edit Item\n");
    printf("7 – Remove Item\n");
  }
  printf("\nQ – Quit\n");
  return fLauncher(getchar());
}

int main() {
  while(mainMenu()!=-1)flushInput(0);
}
