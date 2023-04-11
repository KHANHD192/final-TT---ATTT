/*
Một số gọi là Q-prime khi nó có đúng 4 ước số nguyên dương. Hãy viết chương trình in ra
các số Q-Prime nhỏ hơn hoặc bằng một số N cho trước nhập từ bàn phím
*/

#include<stdio.h>
#include<math.h>

bool checkQ_prime (int n){
    int d=2; // nó và 1 
    for(int i = 2 ; i <=n/2 ; i++){
          if(n%i == 0) {
            d++;
          }
    }    
    if(d== 4){
         return true;
    }else{
        return false;
    }
}


int main (){
    int n ; 
    printf("nhap n :");
    scanf("%d",&n);
    for(int i = 6 ; i <=n ; i++){
             if(checkQ_prime(i)){
                printf("%d ",i);
             }
    }
    return 0;
}