/*
Cho mảng A gồm các số nguyên thuộc 𝐹𝑝 nhập vào từ bàn phím, hãy viết chương trình in 
ra mảng B có các phần tử là nghịch đảo của các phần tử tương ứng trong A.
*/
#include<stdio.h>
#include<math.h>
#include<time.h>


void nhapmang(int A[],int n,int p ){
        for(int i = 0 ; i < n ; i++){
            printf("A[%d] :",i);
            int k ;
            scanf("%d",&k);
             A[i] = k % p ;
        }
}
void xuatmang(int A[],int n){
    printf("mang sau khi nghich dao !\n");
    for(int i = 0 ; i < n ; i++){
         if(A[i] == -1 ){
            continue;
         }
        printf("B[%d] = %d \n",i,A[i]);
    }
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
int modInverse(int e, int n) { // tính nghịch đảo 
    int g = gcd(e, n);
    if (g != 1) {
        // Không tồn tại nghịch đảo modular của e trên fP 
        return -1;
    }
    else {
        // Tìm nghịch đảo modular của e trên Fp
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
void solution (int A[],int B[],int n,int p){
     for(int i = 0 ; i < n ; i++){
         B[i] = modInverse(A[i],p);
     }
     xuatmang(B,n);
}

int main (){
    int n,p ; 
   j: printf("nhap so phan tu trong mang :");
    scanf("%d",&n);
    printf("nhap truong P :");
    scanf("%d",&p);
    if(n < 0 || p < 0){
        printf("nhap lai :");
        goto j ;
    }
    int A[n],B[n];
    nhapmang(A,n,p);
    solution(A,B,n,p);
    return 0;
}