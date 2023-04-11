#include<stdio.h>
#include<math.h>

bool checkT_prime (int n){
    int d=2; // nó và 1 
    for(int i = 2 ; i <=n/2 ; i++){
          if(n%i == 0) {
            d++;
          }
    }    
    if(d== 3){
         return true;
    }else{
        return false;
    }
}


int main (){
    int n ; 
    printf("nhap n :");
    scanf("%d",&n);
    for(int i = 4 ; i <=n ; i++){
             if(checkT_prime(i)){
                printf("%d ",i);
             }
    }
    return 0;
}