/*
Viết chương trình in ra các số nguyên dương x nằm trong khoảng [m,l] sao cho giá trị của biểu thức 𝐴𝑥2 + 𝐵𝑥 + 𝐶 là một số nguyên tố. Với A,B,C, m,l là các số nguyên nhập từ bàn 
phím (m<l).
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
    int  m,l;
       printf("NHAP a b c :");
       scanf("%d %d %d",&A,&B,&C);
      j: printf("nhap m :");
       scanf("%d",&m);
       printf("nhap l :");
       scanf("%d",&l);
         if(l < m){
            printf("sai yeu cau, nhap lai dk(m < l):");
             goto j;
         }
       for(int x = m ;  x <=l ; x++){
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