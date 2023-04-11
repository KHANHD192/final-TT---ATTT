/*
Viết chương trình tìm các số nguyên tố có N chữ số với N nhập từ bàn phím và 2 ≤ N ≤
10.
dùng sàng số nguyên tố 
*/

#include<stdio.h>
#include<math.h>
#include<time.h>

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
 bool fermat (int n,int t){
     //Tính a^(n-1) mod n
    int kq;
    for(int i=0; i<t; i++)
    {
        //chọn ngẫu nhiên số a
        int a=0, ran;
        while(a>=0)
        {
            ran = rand();
            if((ran>=2)&&(ran<=(n-2)))
                break;
        }
         a=ran;
        //tinh a^(n-1) mod n
        kq = power(a,n-1,n);
        if(kq!=1)
        {
            kq=0;
            break;
        }
    }
    if(kq==1){
    return true;
    }
    else{
        return false;
    }
 }
void isPrime (int n){
    //N chu so 
    int left = pow(10,n -1);
    int right = pow(10,n) - 1;
    for(int i  = left ; i < right ; i++){
             if(fermat(i,3)){
                printf("%d ",i);
             }
         }
    }

int main (){
    int n;
     printf ("nhap n :");
     scanf("%d",&n);
     isPrime(n);
     return 0;
}
