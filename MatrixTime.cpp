#include <stdio.h>

int n = 4;                              //假设有四个矩阵相乘
int main(){
    int m[5][5];                        //记录乘法次数
    for (int i = 0; i < 4;i++){         //初始化
        for (int j = 0; j < 4;j++)
            m[i][j] = 0;
    }
    int p[5] = { 10,10,10,10,5 };       //维数矩阵

    /****
     * 以下开始填充二位数组m
     * 
     ****/
    /**填充对角线**/
    for (int i = 1; i <= n;i++){
        m[i][i] = 0;
    }
    for (int step = 2; step <= n; step++)//按照步长，从小到大自主对角线沿右上角填充
    {
        for (int start = 1; start <= n - step + 1; start++)     //控制不同的初始位置
        {
            int end = start + step - 1;                         //控制当前步长下的终止位置
            m[start][end] = m[start + 1][end] + p[start - 1] * p[start] * p[end];  //给一个初始值，默认从1加括号方式
            for (int k = start + 1; k < end; k++)       //通过控制k的值，遍历加括号的位置，
            {
                //以下过程类似min函数
                int times = m[start][k] + m[k + 1][end] + p[start - 1] * p[k] * p[end];
                if (times < m[start][end]){
                    m[start][end] = times;
                }
            }
        }
    }
    //打印m数组结果
    for (int i = 1; i <= 4;i++){
        for (int j = 1; j <= 4;j++){
            printf("%-6d", m[i][j]);
        }
        printf("\n");
    }
    //打印最终结果
    printf("%d", m[1][n]);
    return 0;
}