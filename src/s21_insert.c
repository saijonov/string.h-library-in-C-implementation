#include "s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *rez = NULL;
  if (src != NULL && start_index <= s21_strlen(src)) {
    size_t src_len = s21_strlen(src);
    size_t str_len = (str != NULL) ? s21_strlen(str) : 0;
    size_t new_len = src_len + str_len + 1;
    rez = calloc(new_len, sizeof(char));
    if (rez != NULL) {
      size_t i, j = 0;
      for (i = 0; i < src_len; i++) {
        if (i == start_index) {
          size_t k;
          for (k = 0; k < str_len; k++) {
            rez[j++] = str[k];
          }
        }
        rez[j++] = src[i];
      }

      rez[new_len - 1] = '\0';
    }
  }
  return (void *)rez;
}
