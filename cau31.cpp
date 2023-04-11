/*
Áp dụng theo các thuật toán đã được học trong phần lí thuyết em hãy cài đặt chương 
trình: - Tìm số nguyên tố k gần nhất với phần số của mã số sinh viên của mình (trong trường hợp 
khoảng cách bằng nhau thì lấy số nhỏ hơn). - Từ số k tìm được tính ak mod n với a = SBD, n = 123456.
*/
#include<stdio.h>
#include<math.h>
#include<windows.h>

int is_prime(int n)
{
    if(n<2)
        return 0;
    for(int i=2; i <= sqrt(n); i++)
        if(n % i ==0)
            return 0;
    return 1;
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

int main()
{
    long long msv,t,d,kt=0,kd=0,k,n=123456;
    printf("Nhap ma sinh vien: ");
    scanf("%lld",&msv);
    //tim so nguyen to gan nhat nho hon
    for(int i=msv-1; i>=0; i--)
    {
        if(is_prime(i))
        {
            d = i;
            kd++;       //khoang cach
            break;
        }
    }
    //tim so nguyen to gan nhat lon hon
    for(int i=msv+1; i>=0; i--)
    {
        if(is_prime(i))
        {
            t = i;
            kt++;       //khoang cach
            break;
        }
    }
    if(kd<=kt)
        k = d;
    else k = t;
    printf("So nguyen to k thoa man la: %lld\n",k);
    printf("Ket qua la: %lld\n", power(msv,k,n));
    system("pause");
}
