#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main(void){

  int input = 0, grader = 0;
  float radians = 0, cosin = 0, sinus = 0;
  printf("\n----------------------------\nUppgift 3\n----------------------------\n");
  printf("Ange en positiv vinkel i hela grader:");
  scanf("%d",&input);

  grader = input%360;
  radians = grader*(PI/180);
  sinus = sin(radians);
  cosin = cos(radians);

  if (grader<90&&grader>-1){
    printf("\nDu angav %d grader\n",input);
    printf("sin: %f, cos: %f\n",sinus,cosin);
    printf("Vinkeln är spetsig");
  }
  else if (grader>90&&grader<360){
    printf("\nDu angav %d grader\n",input);
    printf("sin: %f, cos: %f\n",sinus,cosin);
    printf("Vinkeln är trubbig");
  }
  else if (grader==90){
    printf("\nDu angav %d grader\n",input);
    printf("sin: %f, cos: %f\n",sinus,cosin);
    printf("Det är en rät vinkel");
  }
  else printf("\nDu angav inte en positiv vinkel i hela grader!\n");

  printf("\n----------------------------\n\n");
  return 0;
}
