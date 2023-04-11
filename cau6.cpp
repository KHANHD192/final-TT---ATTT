// hai so than thiet 
/*
. Hai số tạo thành một cặp số thân thiết khi chúng tuân theo quy luật: Số này bằng tổng tất 
cả các ước của số kia (trừ chính số đó) và ngược lại. Viết chương trình tìm hai số dạng này nhỏ 
hơn N (với N nhập vào từ bàn phím).
*/
#include <stdio.h>

int sum_of_divisors(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        // 1 chiều
        int sum1 = sum_of_divisors(i);
        // TRUYỀN NGƯỢC LẠI KIỂM TRA 
        int sum2 = sum_of_divisors(sum1);
        // chiều còn lại
        if (i == sum2 && sum1 > i) {
            printf("(%d, %d)\n", i, sum1);
        }
    }
    return 0;
}

