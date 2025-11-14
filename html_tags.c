#include <stdio.h>
#include <string.h>

int is_valid_tag(const char *s) {
    int len = (int)strlen(s);
    if (len < 4) return 0;
    if (!(s[0] == '<' && s[1] == '/')) return 0;
    if (s[len - 1] != '>') return 0;
    int body_len = len - 3;
    if (body_len <= 0) return 0;
    for (int i = 2; i < len - 1; ++i) {
        char c = s[i];
        if (!((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))) return 0;
    }
    return 1;
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    char buf[2005];
    while (T--) {
        if (scanf("%2000s", buf) != 1) return 0;
        if (is_valid_tag(buf)) {
            printf("Success\n");
        } else {
            printf("Error\n");
        }
    }
    return 0;
}