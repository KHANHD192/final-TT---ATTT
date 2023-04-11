#include<stdio.h>
#include<math.h>
#include<time.h>

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
void count_prime (int n){
    int s = 0 ,k = 0,q=0,p =0; 
    for(int i = 1 ; i <= n  ; i++){
            if(n % i == 0){
                     s++;
                     p+=i;
                     if(checkis_prime(i)){
                        k++;
                        q+=i;
                     }    
                  }
    }
    printf("%d ",n +p+s-q-k);
    
}

int main (){
    int n = 24;
    count_prime(24);
}