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
    int s = 0 ,k = 0;
    for(int i = 1 ; i <= n  ; i++){
            if(n % i == 0){
                     s++;   
                     if(checkis_prime(i)){
                        k++;
                        
                     }    
                  }
    }
    printf("so uoc cua %d la %d va so uoc nt la %d ",n,s,k);
    
}

int main (){
    int n = 24;
    count_prime(24);
}