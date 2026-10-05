#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int generate(int limit) {
  return rand() % limit;
}

int main() {
  char answer[20];
  char correct[20];
  
  // obtain random number for exercise
  srand(time(NULL));
  int num = generate(1000);

  // fill array for correct answer and ask question
  sprintf(correct, "%X", num);
  printf("Convert %d to hex: ", num);
  scanf("%19s", answer);

  // check answer
  if(!strcmp(answer,correct)) printf("Correct!\n");
  else printf("Incorrect, the answer was %s\n", correct);

  return 0;
}
