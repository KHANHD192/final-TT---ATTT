#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

void boyer_moore(char* text, char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    int i, j, k;
    int badchar[MAX_CHAR];

    // Khởi tạo bảng badchar // để step 
    for (i = 0; i < MAX_CHAR; i++) {
        badchar[i] = m;
    }
    for (i = 0; i < m - 1; i++) {
        badchar[(int) pattern[i]] = m - i - 1;
    }

    // Bắt đầu tìm kiếm
    i = m - 1;
    while (i < n) {
        j = m - 1;
        k = i;
        while (j >= 0 && text[k] == pattern[j]) {
            j--;
            k--;
        }
        if (j < 0) {
            printf("Found pattern at index %d\n", k + 1);
            i++;
        } else {
            i += badchar[(int) text[i]];
        }
    }
}
int main() {
    char text[100];
    char pattern[100];
    gets(text);
    gets(pattern);
    boyer_moore(text, pattern);
    return 0;
}
