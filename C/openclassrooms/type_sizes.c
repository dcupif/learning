#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  printf("char : %ld octets\n", sizeof(char));
  printf("int : %ld octets\n", sizeof(int));
  printf("long : %ld octets\n", sizeof(long));
  printf("double : %ld octets\n", sizeof(double));
  return 0;
}
