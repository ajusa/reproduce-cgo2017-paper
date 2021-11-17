#include <stdio.h>

int main() {
  printf("hello world\n");
  printf("%d \n", add(3, 4));
  return 0;
}

int add(int a, int b){
  return a + b;
}
