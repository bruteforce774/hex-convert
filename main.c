#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generate(int limit) {
  return rand() % limit;
}

int main() {
  srand(time(NULL));
  int num = generate(1000);
  printf("%d is %X in hex\n", num, num);
  return 0;
}
