/*
Viết chương trình in ra màn hình YES trong trường hợp tổng của các số nguyên tố trong 
khoảng [A, B] là cũng là một số nguyên tố và NO nếu ngược lại. Với A,B là hai số được nhập vào 
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

void sumOfPrime(int a, int b){
    long long  sum = 0 ;
       for(int i = a ; i <= b ; i++){
               if(is_prime(i)){
                printf("%d ",i);
                sum+=i;
               }
     }
     if(is_prime(sum)){
        printf("YES vi %d la SNT",sum);
        return;
     }else{
        printf("No vi %d ko la SNT",sum);
        return;
     }
}
int main (){
    int a,b;
    printf("nhap a va b :");
    scanf("%d %d",&a,&b);
    sumOfPrime(a,b);
    return 0;
}