/**
 * 
 * 作者：周川
 * 题目: 输入N，得到N元集的集族（全集的所有子集的组合）
 * 拓扑：首先为集族，并满足内部任意两个元素的交和并依然在子集中
 *
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int result = 0;     //最终结果，拓扑的个数
int nums = 0;       //用来保存去除空集和全集的子集个数，值为2的N次方减2


void group(int *a,int *b,int n,int m,const int M);  //组合函数
void panduan(int *a, int *b, int M);                //判断两个

/*****
 * 主函数
 * 功能：获取拓扑数
*/
int main(){
    int N = 0;  //表示输入数据的个数
    clock_t start_t,finish_t;   //时间变量，用于测试函数算法时间
    double total_t = 0;         //保存算法以秒为单位的运行时间

    scanf("%d", &N);
    start_t = clock();          //从输入数据的个数后开始计时
    
    /******
     * 用各个二进制位编码集合中字母是否出现
    */
    int SubArraySize = (int)pow(2, N)-2;    //去除空集以及全集
    nums = SubArraySize;                    //用来保存去除空集和全集的子集个数，值为2的N次方减2

    //定义长度为nums的数组，可以编码1 ~ 2的N-2
    int temp[SubArraySize];                 
    for (int i = 1; i <= SubArraySize;i++){
        temp[i-1] = i;
    }

    //b数组用于保存组合中元素的下标
    int b[SubArraySize];

    //循环生成包含1到2的n次方-2个元素组合
    for (int i = 1; i <= SubArraySize;i++){
        group(temp,b,SubArraySize,i,i);
    }

    printf("%d\n", result+1);   //打印结果，加上只含有空集和全集的组合

    finish_t = clock();         //记录结束时的时间
    total_t = (double)(finish_t - start_t) / CLOCKS_PER_SEC;    //将时间转换为秒
    printf("共运行了%lfs", total_t);                             //打印秒单位的时间
    return 0;
}

//分组
void group(int *a,int *b,int n,int m,const int M){
    for (int i = n; i >= m;i--){
        b[m-1] = i-1;
        if(m>1){
            group(a, b, i-1, m - 1, M);
        }else{
            // for (int j = M-1; j >= 0;j--){
            //     printf("%d ", a[b[j]]);
            // }
            // printf("\n");
            panduan(a,b,M);  //M代表组合的元素个数，b数组表示的是参与构成组合的元素下标
        }
    }
}

//判断交和并在集合中
void panduan(int *a,int *b,int M){
    int temp[nums + 2];
    for (int i = 0; i < nums + 2;i++){
        temp[i] = 0;
    }
    temp[nums + 1] = 1;
    temp[0] = 1;
    for (int i = 0; i < M;i++){
        temp[a[b[i]]] = 1;   
    }

    for (int i = 0; i <= M - 2; i++)
    {
        for (int j = i + 1; j <= M - 1; j++)
        {
            // printf("temp1: %d\n",temp[a[b[i]]&a[b[j]]]);
            // printf("temp1: %d\n",temp[a[b[i]]|a[b[j]]]);
            if (!(temp[a[b[i]]&a[b[j]]] && temp[a[b[i]] | a[b[j]]])){
                return;
            }
        }
    }
    // for (int i = 0; i < M;i++){
    //     printf("%d ", a[b[i]]);
    // }
    // printf("\n------------\n");
    result++;
}