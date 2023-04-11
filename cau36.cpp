/*
Lập trình tìm kiếm xâu S1 trong xâu S2 theo thuật toán Boyer-Moore, in giá trị của bảng. 
Trong trường hợp nào thì thuật toán Boyer-Moore được xem là cải tiến hơn thuật toán tìm kiếm 
vét cạn
*/
// boyer-more 
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
        while (j >= 0 && text[k] == pattern[j]) { // tìm kiếm chuyên sâu 
            j--;
            k--;
        }
        if (j < 0) { // return 
            printf("Found pattern at index %d\n", k + 1);
            i++;
        } else { // nhảy DỰA VÀO BADCHAR
            i += badchar[(int) text[i]];
        }
    }
}
int main() {
    char text[100];
    char pattern[100];
    printf("moi nhap chuoi T :");
    gets(text);
    printf("moi nhap chuoi P :");
    gets(pattern);
    boyer_moore(text, pattern);
    return 0;
}
