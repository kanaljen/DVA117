void line(){
  printf("\n═══════════════════════════════════════\n");
}
void intro(void){
  system("clear");
  line();
  printf("\t\e[031m%s\e[037m",name);
  line();
  printf("%s\n",introtxt);
}
void endgame(void){
  char replay;
  printf("\nVill du köra programmet igen (y)?");
  scanf(" %c",&replay);
  if (replay == 'y'||replay == 'Y')main();
}
