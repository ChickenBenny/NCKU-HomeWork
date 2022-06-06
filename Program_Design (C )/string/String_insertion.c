#include <stdio.h>
#include <string.h>
#define MAX_LEN_P 100000
#define MAX_LEN_S 100

void strins(char *P, char *s, char *t);

int main() {
  char P[MAX_LEN_P + 1], s[MAX_LEN_S + 2], t[MAX_LEN_S + 2];
  size_t P_len = 0;
  for (char buf[MAX_LEN_P + 1] = ""; strcmp(buf, "---\n"); fgets(buf, MAX_LEN_P + 1, stdin)) {
    size_t len = strlen(buf);
    if (len + P_len > MAX_LEN_P) {
      fprintf(stderr, "The length of the paragraph exceeds %d\n", MAX_LEN_P);
      return 1;
    }
    strncat(P, buf, len + 1);
    P_len += len;
  }
  fgets(s, MAX_LEN_S + 2, stdin);
  s[strlen(s) - 1] = '\0';  // remove newline
  fgets(t, MAX_LEN_S + 2, stdin);
  t[strlen(t) - 1] = '\0';  // remove newline
  strins(P, s, t);
  printf("%s", P);
  return 0;
}

void strins(char *P, char *s, char *t) {
    int index = 0, tmp_index = 0, turn = 1, s_len = strlen(s), t_len = strlen(t);
    char *ch, tmp[MAX_LEN_P] = {0};
    while (turn == 1) {
        ch = P + index;
        if (*ch == '\0') {
            turn = -1;
            tmp_index += 1;
            *(tmp + tmp_index) = '\0';
            continue;
        } else {
            *(tmp + tmp_index) = *ch;
            if (*ch == *s) {
                int inside_count = 1, compare = 1;
                while (inside_count < s_len) {
                    if (*(ch + inside_count) != *(s + inside_count)) {
                        compare = 0;
                        break;
                    }
                    inside_count += 1;
                }
                if (compare == 1) {
                    for (int i = 1; i < s_len; i++) {
                        index += 1;
                        tmp_index += 1;
                        *(tmp + tmp_index) = *(P + index);
                    }
                    for (int i = 0; i < t_len; i++) {
                        tmp_index += 1;
                        *(tmp + tmp_index) = *(t + i);
                    }
                }
            }
            index += 1;
            tmp_index += 1;
        }
    }
    for (int i = 0;i <= tmp_index;i ++){
        *(P + i) = *(tmp + i);
    }
}