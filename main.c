#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// random number generation
int generate(int limit) {
  return rand() % limit;
}

// function to ask for dec to hex conversion
void askfor_hex() {
  char answer[20];
  char correct[20];

  // apply standard but mutable limit of 1000
  int num = generate(1000);

  // obtain and store solution and user response
  sprintf(correct, "%X", num);
  printf("Convert %d to hex: ", num);
  scanf("%19s", answer);

  // check answer
  if(!strcmp(answer, correct)) printf("Correct!\n");
  else printf("Incorect, the answer was %s\n", correct);
}

int main() {
  srand(time(NULL));
  askfor_hex();
  return 0;
}
