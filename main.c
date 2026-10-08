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
  else printf("Incorrect, the answer was %s\n", correct);
}

void askfor_dec() {
  int guess;
  int num = generate(1000);
  // use integer directly
  printf("Convert %X to decimal: ", num);
  scanf("%d", &guess);
  if (guess == num) printf("Correct!\n");
  else printf("Incorrect, the answer was %d\n", num);
}

int main() {
  char reply = 'y';
  srand(time(NULL));
  // function call based on random value with loop
  while (reply == 'y') {
    if (generate(2) == 0) askfor_hex();
    else askfor_dec();
    printf("Another? (y/n): ");
    // add leading space so scanf skips newline 
    scanf(" %c", &reply);
  } 
  return 0;
}
