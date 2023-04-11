/*
Viết chương trình tìm số nguyên dương x nhỏ nhất và nhỏ hơn N nhập từ bàn phím sao 
cho giá trị của biểu thức 𝐴𝑥2 + 𝐵𝑥 + 𝐶 là một số nguyên tố với A,B,C là các số nguyên nhập vào 
từ bàn phím.
*/
#include<stdio.h>
#include<math.h>
bool is_prime(int n){
     if(n < 2){
        return false;
     }else {
        for(int i = 2; i <= n /2 ; i++ ){
             if(n % i == 0){
                return  false;
             }
        }
     }
     return true;
}
void solution (){
    int A,B,C;
    int n ; 
    printf("nhap n :");
    scanf("%d",&n);  
     fflush(stdin);
       printf("NHAP a b c :");
       scanf("%d %d %d",&A,&B,&C);
       for(int x = 1 ;  x < n ; x++){
          int fx = A*pow(x,2) + B*x + C;
          if(is_prime(fx)){
            printf("%d la gia tri nho nhat thoa man ",x);
            return;
          }
       } 
       printf("khong tim thay gia tri thoa man ");
}

int main (){
   
    solution();
    return 0;
}