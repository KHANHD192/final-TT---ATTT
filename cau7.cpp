/*
Một số emirp là một số nguyên tố mà khi đảo ngược vị trí các chữ số của nó, ta cũng được 
một số nguyên tố. Viết chương trình liệt kê các số emirp nhỏ hơn N với N nhập vào từ bàn phím.
*/
#include<stdio.h>
#include<math.h>
#include <time.h>

bool checkis_prime (int n){ 
    if(n < 2){
        return false;
    }
    for(int i = 2 ; i <=n/2 ; i++){
          if(n%i == 0) {
                return false;
          }
    }    
           return true;
    
}
int inverseNumber(int number)
{
    int result = 0;

    while (number > 0)
    {
        int tmp = number % 10;
        result = (result * 10) + tmp;
        number /= 10;
    }

    return result;
}
void check_emirp(int n){
    for(int i = 2 ; i < n ; i++){
        if(checkis_prime(i)){
            if(checkis_prime(inverseNumber(i))){
                printf("%d ",i);
            }
        }
    }
 }
int main (){
    int n;
     printf("nhap n:");
     scanf("%d",&n);
     check_emirp(n);
     return 0;
}
