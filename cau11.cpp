/*
Viết chương trình tính tổng của các số nguyên tố nhỏ hơn hoặc bằng N với N được nhập 
từ bàn phím.
*/
#include<stdio.h>
#include<math.h>

bool is_prime (int n){
    if(n<2 ){
        return false;
    }else {
        for(int i = 2; i <= n/2 ; i++){
                 if(n % i == 0){
                    return false ;
                 }
        }
        return true;
    }
}

long long sumOfPrime(int n){
    long long  sum = 0 ;
       for(int i = 2 ; i <= n ; i++){
               if(is_prime(i)){
                printf("%d ",i);
                sum+=i;
               }
     }
     return sum;
}

int main (){
    int n; 
    printf("nhap n  :");
    scanf("%d",&n);
    printf("Tong cac snt nho hon %d la %lld",n,sumOfPrime(n));
    return 0;
}