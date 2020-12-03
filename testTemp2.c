#include<stdio.h>
 
void combine(int n,int m,int a[],int b[],const int M){
    //n代表当前集合的个数，M代表选择的数量3
    for(int j=n;j>=m;j--){
        b[m-1]=j-1;
        if(m>1){
            combine(j-1,m-1,a,b,M);
        }
        else{
            for(int i=M-1;i>=0;i--)
                printf("%d ",a[b[i]]);
            printf("\n");
        }
    }
}
 
int main(){
    
    int a[3];   //总元素个数
    int b[2];   //选择的元素个数

    for(int i=0;i<3;i++)
        a[i]=i+1;

    const int M=2;
    

    combine(3,2,a,b,M);
}