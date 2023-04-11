/*
Đặt S1, S2 là các mảng chứa giá trị bình phương của các số nguyên. Hãy viết chương 
trình in ra số lượng tất cả các số nguyên tố nằm trong khoảng [a,b] sao cho số này cũng là tổng
của hai số x và y với x thuộc S1 và y thuộc S2. Trong đó, a,b là các số được nhập từ bàn phím
Ví dụ: với a=10, b =15, in ra giá trị là 1 vì trong khoảng [10,15] chỉ có 2 số nguyên tố 11 và 13, 
nhưng chỉ có 13 = 2^2 + 3^2=4+9
*/
#include<stdio.h>
#include<math.h>
#include<windows.h>

int nto(int n)
{
    if(n<=1)
        return 0;
    for(int i=2; i<=sqrt(n); i++)
        if(n%i==0)
            return 0;
    return 1;
}

int main()
{
    int a,b, count=0;
    printf("Moi nhap gioi han a,b: ");
    scanf("%d%d",&a,&b);
    int s1[b], s2[b], A[b], j=0, x=0;
    while(x<=sqrt(b))
    {
        s1[x]= (x+1)*(x+1);
        s2[x]= (x+1)*(x+1);
        x++;
    }
    for(int i=a; i<=b; i++)
        if(nto(i))
        {
            A[j] = i;
            j++;
        }
    int d=0;
    for(int i=0; i<j; i++)
    {
        for(int k=0; k<x; k++)
            for(int l=0; l<x; l++)
                if((A[i]==(s1[k]+s2[l]))&&(A[i]!=d))
                {
                     count++;
                     printf("%d ",A[i]);
                     d=A[i];
                }
    }
    printf("Ket qua la: %d\n",count);
    system("pause");
}
