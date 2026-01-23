#include<stdio.h>

#define INPUT_LEN=1024;

int main() {
  printf("Clinterprit started...\n");
  while (1) {
    char buff[INPUT_LEN];
    printf(">>>");
    fgets(buff,sizeof(buff),stdin);
  }

  return 0;
}
