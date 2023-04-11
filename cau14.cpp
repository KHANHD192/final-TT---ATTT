/*
Viết chương trình tìm số nguyên tố có ba chữ số, biết rằng nếu viết số đó theo thứ tự 
ngược lại thì ta được một số là lập phương của một số tự nhiên
*/
#include <stdio.h>
#include <ctype.h>
#include<math.h>
#include<time.h>

int convertToBin(int k , int A[]){  // chuyển k qua bit 
       int i = 0;
       while(k > 0){
        A[i] = k % 2;
        k /=2;
        i++;
       }
       return i; // LẤY RA LENGTH của array lưu bit 
}
long long solution(int x, int k ,int K[],int m){ // nhân bình phương có lặp 33
     int length =convertToBin(k,K);
     int p = 1;
     for(int i = length - 1; i>= 0 ; i--){
        p = (p *p) % m ; 
        if(K[i]){
                p = (p *x) % m;
        }

     }
     return p;
}

bool fermat(int n,int t){
  if(n % 2 == 0){
     return false ;
  }else {
       for(int i = 1 ; i <=t ; i++){
          time_t t;
          srand((unsigned) time(&t));
           int a = rand() % (2- (n-2) + 1);
           int K[100];
           int r = solution(a,n-1,K,n); // áp dung định lý fermat : a^k-1 = 1mod(k) , neen nếu #1 false luôn 
           if(r != 1){
            
            return false ;
           }
       }
       return true;
  }
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
void isPrime (){
    //N chu so 
    for(int i  = 100 ; i <= 999 ; i++){
             if(fermat(i,4)){
               int number_reverse = inverseNumber(i);
               for(int z = 1; z <= sqrt(number_reverse); z++)
			{
				if(z * z * z == number_reverse)
				{
 				printf("Vay so can tim la %d va lap phuong cua no la: %d", i, number_reverse);
				}
			}
             }
         }
    }

int main (){
    isPrime();

}