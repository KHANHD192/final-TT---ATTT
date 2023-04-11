/*
Một số gọi là siêu số nguyên tố nếu số lượng các số nguyên tố từ 1 đến X (ngoại trừ X) là 
một số nguyên tố. Hãy viết chương trình đếm số lượng các siêu số nguyên tố này trong khoảng 
[A,B] cho trước nhập từ bàn phím.
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

int  count_prime (int X){
    int count = 0 ;
    for(int i = 2 ; i < X ; i++){
          if(is_prime(i)){
            count++;
          }
    }
    return count;
}
void check_Super_Prime(int A,int B){
   for(int  i = A ; i<= B ;i++){
     if(is_prime(i) && is_prime(count_prime(i))){
            printf("%d la so sieu nguyen to \n",i);
    }
   }
}
int main (){
    int A,B;
    printf("nhap A va B :");
    scanf("%d %d",&A,&B);
    check_Super_Prime(A,B);
    return 0;
}