/*
Với một số nguyên dương N thoả mãn 0<N<10000, đặt:
F ( N ) = N nếu N là một số nguyên tố
F ( N ) = 0 nếu là hợp số
Cho L và R nhập vào từ bàn phím, với mọi cặp i , j trong khoảng [ L , R ] hãy viết chương trình 
in ra màn hình giá trị tổng của F ( i ) * F ( j ) với j > i.
*/
#include<math.h>
#include<stdio.h>
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
int Fx(int n){
    if(fermat(n,3)){
        return n;
    }else {
        return 0;
    }
}
int main()
{
    int L, R, Tong=0;
   j: printf("Nhap gioi han dau L: ");
    scanf("%d", &L);
    printf("Nhap gioi han cuoi R: ");
    scanf("%d", &R);
    if(R< L || L > 10000 ){
        goto j ;
    }
    printf("F[i] * F[j] =\n");
    printf("----------------------------\n");
    for(int i=L; i<R; i++)
    {
        for(int j=L+1; j<=R; j++)
        {
            if (j>i)
            {
                printf("F[%d] * F[%d] = %d\n", i, j,Fx(i)*Fx(j));
            	Tong= Tong + Fx(i)*Fx(j);
			}
        }
    }
	printf("Tong= %d",Tong);
}