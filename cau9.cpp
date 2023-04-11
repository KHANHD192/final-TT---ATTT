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

int count_Prime(int n){
    int count = 0 ; 
    for(int i = 2; i <= n ; i++){
                if(checkis_prime(i)){
                    printf("%d ",i);
                    count++;
                }
    }
    return count;
}
int main (){
    int n ;
    printf("nhap n :");
    scanf("%d",&n);
   printf("so snt nho hon %d la %d",n,count_Prime(n));
    return 0;
}