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
  srand(time(NULL));
  int num = generate(1000);
  sprintf(correct, "%X", num);
  printf("Convert %d to hex: ", num);
  scanf("%19s", answer);
  printf("Answer given: %s\n", answer);
  printf("The right answer is: %s\n", correct);
  return 0;
}
