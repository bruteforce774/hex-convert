#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generate(int limit) {
  return rand() % limit;
}

int main() {
  char answer[20];
  srand(time(NULL));
  int num = generate(1000);
  printf("Convert %d to hex: ", num);
  scanf("%19s", answer);
  printf("Answer given: %s\n", answer);
  return 0;
}
