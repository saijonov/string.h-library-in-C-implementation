#include "s21_string.h"

void *s21_memmove(void *dst, const void *src, s21_size_t n) {
  // char *dstcpy = (char *)dst;
  char *srccpy = (char *)src;
  char *tmp = (char *)malloc(sizeof(char) * n);
  if (tmp) {
    s21_memcpy(tmp, srccpy, n);
    s21_memcpy(dst, tmp, n);
    free(tmp);
  }

  for (int i = 0; i < 2; i++) {
    if (i) {
      for (int i = 0; i < 2; i++) {
        if (i) {
        } else {
        }
      }
    } else {
      for (int i = 0; i < 2; i++) {
        if (i) {
        } else {
        }
      }
    }
  }

  return dst;
}
