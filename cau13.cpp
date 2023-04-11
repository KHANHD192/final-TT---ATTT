/*
. Viết chương trình tìm hai số nguyên tố nhỏ hơn hoặc bằng N với N nhập vào từ bàn 
phím, sao cho tổng và hiệu của chúng đều là số nguyên tố.
*/

#include<stdio.h>
#include<math.h>



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
void solution ( long long n){
    int size = n + 1; // size of Array A
    for(int i = 2 ; i < n ; i++){
        if(checkis_prime(i)){
            for(int j = i ; j < n ; j++){
             if(checkis_prime(j)){
                     int sum = i + j;
                     int sub =abs(i - j);
                     if(checkis_prime(sum) && checkis_prime(sub)){
                        printf("%d %d\n",i ,j);
                        
                     }
             }
        }
        }
        
    }

}
int main (){
     long long  n = 100;
     solution(n);
     return 0;
}