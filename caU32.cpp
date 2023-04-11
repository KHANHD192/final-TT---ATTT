/*
Áp dụng các thuật toán đã được học em hãy cài đặt chương trình giải bài toán mô 
phỏng cách mã và giải mã của hệ mật RSA như sau:
- Tìm số nguyên số p, q (trong đó 100 < p, q < 500)
- Tính n = p.q; (n) = (p – 1) (q – 1) 
- Chọn e (1<e< (n)) là số nguyên tố cùng nhau với (n) (gcd(e, (n)) = 1) và tính d = e-1
mod (n)
- Tính bản mã c của thông điệp m, với m = SBD + 123, c = me mod n
- Giải mã thông điệp, tính m = cd mod n
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<time.h>

int is_prime(int n)
{
    if(n<2)
        return 0;
    for(int i=2; i <= sqrt(n); i++)
        if(n % i ==0)
            return 0;
    return 1;
}

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

//Ham tinh a^b mod n
int power(int a, int b, int n)
{
    int res = 1;
    while(b>0)
    {
        if(b&1)
            res = (res*a) % n;
        a = (a*a) % n;
        b >>= 1;
    }
    return res;
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

int main()
{
    int p,q,n,en,sbd,e,ran,tmp=0;
    int d,c,m;
    srand((unsigned int)time(NULL));
    while(tmp>=0) 
    {
        ran = (int)(rand()*(1000-100+1.0)/(1.0+RAND_MAX));
        if(is_prime(ran))
            break;
    }
      p=ran; // random nto p ,100 -> 1000
    while(tmp>=0)
    {
        ran = (int)(rand()*(500-1+1.0)/(1.0+RAND_MAX));
        if(is_prime(ran))
            break;
    }
    q=ran; // ramdom nto q thuoc 1 , 500
    printf("p=%d, q=%d\n",p,q);
    n = p*q; // tinh n 
    printf("\nSo n la: %d\n",n);
    en=(p-1)*(q-1); // tinh phi 
   
     while(tmp>=0) 
    {
        e = (int)(rand()*(en-1+1.0)/(1.0+RAND_MAX));
        if(gcd(e,en)==1)
            break;
    }
   
    d = modInverse(e,en); // tính d = e ^ -1 mod en 
    printf("%d\n",d);
    printf("Nhap so bao danh: ");
    scanf("%d",&sbd);
    m= sbd + 123;
    c = power(m,e,n);
    printf("Thong diep m la: %d\n",m);
    printf("Ban ma c cua thong diep m la: %d\n",c);
    m = power(c,d,n);
    printf("Ban giai ma cua thong diep m la: %d\n",m);
    system("pause");
}
