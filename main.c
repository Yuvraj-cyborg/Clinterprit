#include<stdio.h>
#define INPUT_LEN 1024

void calculate();

void parse_expressions(char* input) {
  int i=0;
  while(input[i] != '\0') {
    input
  }
}

void interpret(char* input){
  char c;
  while((c = *input) != '\0') {
    printf("%c\n",c);
    input++;
  }
};


int main() {
  char buff[INPUT_LEN];
  printf("Clinterprit started...\n");
  while (1) {
    printf(">>>");
    fgets(buff,sizeof(buff),stdin);
    interpret(buff);
  }

  return 0;
}
