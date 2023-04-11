/*
Áp dụng thuật toán đã được học để viết chương trình tính tổng của hai số nguyên lớn, 
hiển thị dưới mạng mảng và dạng số nguyên.
*/
#include<stdio.h>
#include<math.h>
// cộng chính xác bội 
void ChangesToArray(long long a,int A[],int n, int w_bit){
    for(int i = n -1 ; i>= 0 ;i--){
                  A[i]= a /(long long)pow(2,(i*w_bit));
                  a%= (long long)pow(2,(i*w_bit));
    }
    //    for(int i = n -1 ; i>= 0 ;i--){
    //             printf("%d ",A[i]);
    // }
} 
long long ArrayToNumber(int A[],int n,int w_bit ){
     long long b = 0 ;
     for(int i = n -1 ; i>=0;  i--){
        b+= pow(2,(i)*w_bit)*A[i];
     }
     return b;
}

void MULTIPLE_PRECISION_PLUS(long long a, long long b,int n ,int w_bit){
    int A[n],B[n];
    ChangesToArray(a,A,n,w_bit);
    ChangesToArray(b,B,n,w_bit);
    int c[n];
    int  e = 0;
    for (int i = 0; i < n; i++)
    {
        c[i] = A[i] + B[i] + e;
       int  h = pow(2, w_bit);
        if (c[i] >= h)
        {
            e = 1;
            c[i] %= h;
        }
        else
        {
            e = 0;
            c[i] %= h;
        }
    }
     printf("mang C = A + B : \n");
   for(int i = n -1 ; i>= 0 ;i--){
                printf("%d ",c[i]);
    }
    printf("\ntong C = %lld ",ArrayToNumber(c,n,w_bit));
    
}

int main (){
  long long  p = 2147483647 ;
  int w_bit = 8;
  int lenghtofbit = ceil(log2(p));
  int lenghtofTens = ceil(((float)lenghtofbit/w_bit));
  long long a,b;
  printf("nhap a :");
  scanf("%lld",&a);
  printf("nhap b :");
  scanf("%lld",&b);
  int C[lenghtofTens];
  MULTIPLE_PRECISION_PLUS(a,b,lenghtofTens,w_bit);
  return 0;
}