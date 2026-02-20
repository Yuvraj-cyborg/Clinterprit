#include<stdio.h>
#include<stddef.h>
#define INPUT_LEN 1024

typedef enum {
  NUMBER,
  ADD,
  SUBTRACT,
  MULTIPLY,
  DIVIDE,
  EOF,
}TokenType;

typedef struct {
  TokenType type;
  int value;
}Token;

//void calculate();

void parse_expressions(char* input) {
  while(*input != '\0') {    
    input
  }
}

void lexer(char* input) {
  Token input; 
  while(*input != '\0')
}

int main() {
  char buff[INPUT_LEN];
  printf("Clinterprit started...\n");
  while (1) {
    printf(">>>");
    fgets(buff,sizeof(buff),stdin);
    //calc(buff);
    lexer(buff);
  }

  return 0;
}
