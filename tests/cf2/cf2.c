/*
  Test:
  implict data flow due to the length of loop.
  m should be 33
*/

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"

int main (int argc, char** argv) {
  if (argc < 2) return 0;

  FILE *fp;
  char buf[255];
  size_t ret;

  fp = fopen(argv[1], "rb");

  if (!fp) {
    printf("st err\n");
    return 0;
  }

  int len = 20;
  ret = fread(buf, sizeof *buf, len, fp);
  fclose(fp);
  if (ret < len) {
    printf("input fail \n");
    return 0;
  }

  int32_t  y = 0;
  int32_t m = 0;

  memcpy(&m, buf + 15, 4);

  int i = 0;

  for (; i < 100; i++) {
    if (m == i) break;
  }

  if (i == 33) {
    abort();
  }

  return 0;
}
