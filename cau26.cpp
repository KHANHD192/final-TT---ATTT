/*
Một số được gọi là số mạnh mẽ khi nó đồng thời vừa chia hết cho số nguyên tố và chia 
hết cho bình phương của số nguyên tố đó. Tìm số mạnh mẽ nhỏ hơn số N cho trước (N < 10000
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

void solution (int n){
    for(int i = 1 ;  i < n ; i++){
        for(int j = 2 ; j < n ;j++){
            if(is_prime(j)){
                if(i %  j == 0 && i % (int)pow(j,2)==0){
                    printf("%d la so manh me\n ",i);
                    break;
                }
            }
        }
    }
}
int main (){
    int n;
    j :printf("nhap n :");
    scanf("%d",&n);
    if(n > 10000){
        printf("nhap lai :");
        goto j;
    }
    solution(n);
    return 0;
}