/*
. Tìm nghịch đảo của một số a trong trường 𝐹𝑝 với a và p được nhập từ bàn phím.
*/
#include<stdio.h>
#include<math.h>
#include<time.h>

int gcd(int a, int b)
{
    while(b>0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int modInverse(int e, int n) { // tính nghịch đảo 
    int g = gcd(e, n);
    if (g != 1) {
        // Không tồn tại nghịch đảo modular của e trên Z_n
        return -1;
    }
    else {
        // Tìm nghịch đảo modular của e trên Z_n
        int x = 0, y = 1, u = 1, v = 0;
        int a = e, b = n;
        while (a != 0) {
            int q = b / a;
            int r = b % a;
            int m = x - u * q;
            int n = y - v * q;
            b = a;
            a = r;
            x = u;
            y = v;
            u = m;
            v = n;
        }
        int d = (x % n + n) % n;
        return d;
    }
}
int main (){
    int a;
    long long p ;
    j:printf("nhap a : ");
    scanf("%d",&a);
    if(a <= 0){
        goto j; 
    }
   k: printf("nhap p :");
    scanf("%lld",&p);
     if(p <= 0){
        goto k; 
    }
    if(modInverse(a,p) != -1){
        printf("nghich dao cua %d tren truong %lld la %d",a,p,modInverse(a,p));
    }else {
        printf("khong ton tai phan tu nghich dao tren truong %lld",p);
    }
    return 0;
}