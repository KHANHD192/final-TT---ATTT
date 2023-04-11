/*
Viết chương trình tìm các số Carmichael (là các số giả nguyên tố n thoả mãn điều kiện là 
hợp số và thoả mãn 𝑏𝑛−1 ≡ 1 (𝑚𝑜𝑑 𝑛) với mọi số nguyên dương b nguyên tố cùng nhau với n) 
nhỏ hơn một số N cho trước nhập vào từ bàn phím (với điều kiện 0 ≤ 𝑁 ≤ 10000.
*/
#include <stdio.h>

// Hàm tính a^b mod n
long long power(long long a, long long b, long long n) {
    long long res = 1;
    a %= n;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % n;
        }
        a = (a * a) % n;
        b >>= 1;
    }
    return res;
}

// Hàm kiểm tra tính nguyên tố của một số
int is_prime(long long n) {
    if (n < 2) {
        return 0;
    }
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Hàm kiểm tra tính Carmichael của một số
int is_carmichael(long long n) {
    if (n < 2 || is_prime(n)) {
        return 0;
    }
    for (long long a = 2; a < n; a++) {
        if (power(a, n, n) != a) { // a^n == a mod(n), nhana a vao bt, kiểm tra từ 2 - n -2 
            return 0;
        }
    }
    return 1;
}
 int count_carmichael(long long  n){
       int count = 0 ;
       for(int i = 2 ; i < n ; i++){
            if(is_carmichael(i)){
                count++;
            }
       }
       return count;
 }
 long long sum_carmichael(long long  n){
       long long sum = 0 ;
       for(int i = 2 ; i < n ; i++){
            if(is_carmichael(i)){
                sum+=i;
            }
       }
       return sum;
 }
// Hàm main
int main() {
    long long n;
  j:  printf("Nhap mot so nguyen duong: ");
    scanf("%lld", &n);
    if(n < 0 || n >10000){
           goto j;
    }
    if (is_carmichael(n)) {
        printf("%lld la so Carmichael.\n", n);
    } else {
        printf("%lld khong phai la so Carmichael.\n", n);
    }
    printf("so so Carmichael nho hon %lld la %d\n",n,count_carmichael(n));
    printf("Tong so so Carmichael nho hon %lld la %lld",n,sum_carmichael(n));
    return 0;
}

