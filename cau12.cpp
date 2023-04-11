/*
Viết chương trình tìm bốn số nguyên tố liên tiếp, sao cho tổng của chúng là số nguyên tố
nhỏ hơn hoặc bằng N (với N được nhập vào từ bàn phím).
*/
// Bài này lừa đấy, chỉ có 1 dãy số thỏa mãn thôi nhé, klaim đi nếu bấm 10000 k ra nhiều
/*
cau 12 :  Viết chương trình tìm bốn số nguyên tố liên tiếp, sao cho tổng của chúng là số nguyên tố
nhỏ hơn hoặc bằng N (với N được nhập vào từ bàn phím).
*/
#include<stdio.h>
#include<math.h>

void Eratosnt(long long int n , bool check[] )
{
   
    for(long long int i=2;i<=n;i++)
    {
        check[i]=true;
    }
    for(long long int i=2;i<=n;i++)
    {
        if(check[i]==true)
        {
            for(long long int j=2*i;j<=n;j+=i) // chính là x2 sau đó tăng lên thành x3 ....
            {
                check[j]=false;
            }
        }
    }
  
}
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
void solution (long long n, bool A[]){
    if(n < 17){
        printf("khong tim thay ");
        return;
    }
       int size = n + 1;
       Eratosnt(n,A);
       for(int i = 2 ; i < size ; i++){
            int sum = 0 ;
            int count = 0;
                int b[4]; // lưu index
            for(int j = i ;; j++){
                 if(A[j]){           
                    b[count]= j; 
                    sum+=j;
                    count++;
                 }
                 if(count == 4){
                     if(checkis_prime(sum) && sum <=n){
                      for(int i = 0 ; i < 4 ; i++){       
                          printf("%d ",b[i]);
                          }
                          printf("\n");
                          break;
                      }
                     
            }
                    
                 }
                
            }
           
             
       }
int main (){
    long long  n = 30; 
     bool check[n+1]; // mảng boolean 
     solution(n,check);
     return 0;
}