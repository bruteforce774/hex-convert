#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// random number generation
int generate(int limit) {
  return rand() % limit;
}

// function to ask for dec to hex conversion
int askfor_hex() {
  char answer[20];
  char correct[20];

  // apply standard but mutable limit of 1000
  int num = generate(1000);

  // obtain and store solution and user response
  sprintf(correct, "%X", num);
  printf("Convert %d to hex: ", num);
  scanf("%19s", answer);

  // for case insensitive handling
  for(int i=0; answer[i] != '\0'; i++) {
    answer[i] = toupper(answer[i]);
  }

  // account for possible 0x prefix
  char *start = answer;
  if(answer[0] == '0' && answer[1] == 'X')
    start = answer + 2;	

  // check answer
  if(!strcmp(start, correct)) {
    printf("Correct!\n");
    return 1;
  }
  printf("Incorrect, the answer was %s\n", correct);
  return 0;
}

int askfor_dec() {
  int guess;
  int num = generate(1000);
  
  // use integer directly
  printf("Convert 0x%X to decimal: ", num);
  int result = scanf("%d", &guess);
  
  // error checking  
  if (result != 1) {
    printf("Please enter a number.\n");
    int c;
    // throw away leftover input
    while ((c = getchar()) != '\n' && c != EOF) {
    }
    return 0;
  }
  
  if (guess == num) {
    printf("Correct!\n");
    return 1;
  }
  printf("Incorrect, the answer was %d\n", num);
  return 0;
}

int main() {
  char reply = 'y';
  int asked = 0;
  int right = 0;
  srand(time(NULL));
  
  // function call based on random value with loop
  while (reply == 'y') {
    // implement scoring logic
    if (generate(2) == 0) right += askfor_hex();
    else right += askfor_dec();
    asked++;
    printf("Another? (y/n): ");
    // add leading space so scanf skips newline 
    scanf(" %c", &reply);
  }
  printf("Score: %d/%d.\n", right, asked); 
  return 0;
}
