/*
. Cho các số nguyên dương a,k,n, nhập từ bàn phím (0<a,k<n<1000), Viết chương trình 
xác định xem ak mod n có phải là một số nguyên tố hay không (sử dụng thuật toán bình phương 
và nhân có lặp)?
*/

#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<time.h>

//Ham tinh a^b mod n
int power(int a, int b, int n)
{
    int res = 1;
    while(b>0)
    {
        if(b&1) // kiểm tra bit cuối
            res = (res*a) % n;
        a = (a*a) % n; // dịch bit 
        b >>= 1;
    }
    return res;
}
 bool is_prime(int n)
{
    if(n<2)
        return 0;
    for(int i=2; i <= sqrt(n); i++)
        if(n % i ==0)
            return false;
    return true;
}
void solution ( int a, int k , int n ){
     int res = power(a,k,n); 
     if(is_prime(res)){
         printf("%d^%d mod %d bang %d co la SNT",a,k,n,res);
     }else {
        printf("%d^%d mod %d bang %d khong la SNT",a,k,n,res);
     }
     
}
int main (){
    int a,k,n;
   J: printf("nhap a :");
    scanf("%d",&a);
    printf("nhap k :");
    scanf("%d",&k);
    printf("nhap n :");
    scanf("%d",&n);
   if((a < 0 || a > 1000) || (k < 0 || k > 1000) ||(n < 0 || n > 1000)){
    printf("khong dat yeu cau-> nhap lai : ");
    goto J;
   }
   solution(a,k,n);
   return 0;

}