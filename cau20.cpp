/*
. Viết chương trình in ra các cặp số (A,B) nằm trong khoảng (M,N) sao cho ước số chung 
lớn nhất của A và B có giá trị là một số D cho trước. Với M,N,D nhập vào từ bàn phím. (0<M,N, 
D < 1000).
*/
#include<stdio.h>
#include<math.h>
int GCD(int A,int B) {
    if (B == 0)
        return A;
    return GCD(B, A%B);
}
void Find_GCD(int m,int n , int d){
       for(int i = m ; i < n ; i++){
        for(int j = i + 1;j < n ; j++){
            if(GCD(i,j) == d){
                printf("%d %d la hai so (A,B) can tim\n",i,j);
            }
        }
       }
}

int main (){
    int m,n,d;
    printf("nhap m :");
    scanf("%d",&m);
    printf("nhap n :");
    scanf("%d",&n);
    printf("nhap d :");
    scanf("%d",&d);
    Find_GCD(m,n,d);
    return 0;
}