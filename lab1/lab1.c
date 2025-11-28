#include <stdio.h>

void print_binary(unsigned int a) {
  unsigned int mask = 1;
  do {
    mask <<= 1;
    if (mask == 0x80000000)
      break;
  } while (mask < a);
  if (!(mask & a))
    mask >>= 1;
  while (mask) {
    printf("%d", (a & mask) ? 1 : 0);
    mask >>= 1;
  }
  printf("\n");
}

unsigned int count_units(unsigned int a) {
  unsigned int res = 0;
  while (a) {
    if (a & 1)
      res += 1;
    a >>= 1;
  }
  return res;
}

int tmp(int b, unsigned char c) {
  b &= 0xFF00FFFF;
  b |= (c << 16);
  return b;
}

int main() {
  unsigned int a;
  int b;
  unsigned char c;

  printf("Целое положительное число: ");
  scanf("%u", &a);
  print_binary(a);

  printf("Целое отрицательное число: ");
  scanf("%u", &a);
  print_binary(a);

  printf("Целое положительное число: ");
  scanf("%u", &a);
  printf("Количество единиц: %u\n", count_units(a));

  printf("Целое положительное число: ");
  scanf("%d", &b);
  printf("Число для замены третьего байта: ");
  scanf("%hhu", &c);
  printf("Результат замены: %d\n", tmp(b, c));

  return 0;
}