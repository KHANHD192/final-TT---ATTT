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
// test 

int count_Prime(int left,int right){
    int count = 0 ; 
    int sum = 0;
    for(int i = left ; i <= right ; i++){
                if(checkis_prime(i)){
                    printf("%d ",i);
                    sum+=i;
                }
    }
    return sum;
}
int main (){
    int left,right;
 j:   printf("nhap left :");
    scanf("%d",&left);
    printf("nhap right :");
    scanf("%d",&right);
    if(right < left){
        printf("sai yeu cau nhap lai ");
        goto j; 
    }
    printf("tong so nt trong khoang[%d,%d] la %d",left,right,count_Prime(left,right));
    return 0;
}