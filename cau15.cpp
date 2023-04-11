/*
. Viết chương trình Hai số nguyên tố sinh đôi là hai số nguyên tố hơn kém nhau 2 đơn vị. 
Tìm hai số nguyên tố sinh đôi nhỏ hơn hoặc bằng N, với N được nhập vào từ bàn phím.
*/
#include<stdio.h>
#include<math.h>
#include<string.h>

void eratos(long long n ,bool A[]){
     for(long long i = 2; i <= n ; i++){
         A[i] = true;
     }

       for(long long  i=2;i<=n;i++)
    {
        if(A[i]==true)
        {
            for(long long  j=2*i;j<=n;j+=i) // chính là x2 sau đó tăng lên thành x3 ....
            {
                A[j]=false;
            }
        }
    }
}

void solution (long long n, bool A[]){
    eratos(n,A);
    for(int i = 2; i<=n ; i++){
         if(A[i]){
            if(A[i+2]){
                printf("%d %d\n",i,i+2);
            }
         }
    }
}
int main (){ // nhớ điều kiện n 
    int n = 20;
    bool A[n+1];
    solution(n, A);
    return 0;
}