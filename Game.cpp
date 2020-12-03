#include <iostream>
using namespace std;
#define n 4
static int minf=10000, maxf=-10000; 

/**
 * @param i: 链的起点
 * @param s: 断开位置
 * @param j: 链的长度
 */
void minMax(int i,int j,int s,int m[n+1][n+1][2],char op[],int v[]) {
    int e[n+1] ;                  //四个值
    // 在op(i+s) 处进行分割
    int a = m[i][s][0],           // 左半部分最小值
        b = m[i][s][1],           // 左半部分最大值
        r = (i + s - 1) %n+1,         // 取余，防止溢出
        c = m[r][j - s][0],       // 右半部分最小值
        d = m[r][j - s][1];       // 右半部分最大值
    if(op[r-1] == '+') {
        // 对符号进行判断，加号和乘号的处理方式不同
        minf = a + c;
        maxf = b + d;
    } else {
        // 为乘号
        // maxf=max{ac, ad, bc, bd}
        // minf=min{ac, ad, bc, bd}
        e[1] = a * c;
        e[2] = a * d;
        e[3] = b * c;
        e[4] = b * d;
        minf = e[1];
        maxf = e[1];
        for (int k = 2; k <= n; k++) {
            // 查找最大最小值
            if (minf > e[k])
                minf = e[k];
            if (maxf < e[k])
                maxf = e[k];
        }
    }
}

//类似窗口大小不断自增的滑动窗口算法
void polyMax(int m[n+1][n+1][2],char op[],int result[2],int v[]) {
    /****通过递归式迭代填充整个m数组******/
    for(int j = 2; j <= n; j++){            //向链中逐渐增加顶点
        for(int i = 1; i <= n; i++){        //更改起始位置
            for(int s = 1; s < j; s++) {    //断开位置
                // 求m[i][j][1]和m[i][j][0]
                minMax(i,j,s,m,op,v);

                //对数组先进行一个s=1时的初始值填充，再做迭代更新
                if(s==1){
                    m[i][j][0] = minf;
                    m[i][j][1] = maxf;
                    continue;
                }
                if(m[i][j][0] > minf)
                    m[i][j][0] = minf;
                if(m[i][j][1] < maxf)
                    m[i][j][1] = maxf;    
            }
        }
    }
    //填充完毕后，找到最佳的合并起点
    result[0] = m[1][n][1];
    result[1] = m[1][n][0];

    for(int i = 1; i <= n; i++) {
        if (result[0] < m[i][n][1]) {
            result[0] = m[i][n][1];            
        }   
        if (result[1] > m[i][n][0]) {
            result[1] = m[i][n][0];
        }     
    }
}




int main(){
	
    // 案例: -7 + 4 + 2 * 5 *
    int v[n+1] = {0, -7, 4, 2, 5};    // 点集
    char op[n+1] =  {' ', '+', '+', '*', '*'};// 边集   
    int m[n+1][n+1][2];  // 存放中间计算结果
    int result[2];  // 存放最大值和最小值

    for (int i = 1; i <= n; i++) {
        // m[i][j][0] 表示起点为i，链中顶点个数为j个的最小值
        m[i][1][0] = v[i];
        // m[i][j][1] 表示起点为i，链中顶点个数为j个的最大值
        m[i][1][1] = v[i];
    }
    polyMax(m,op,result,v);
    cout<<"最大值: " << result[0] <<"\n最小值: " << result[1];
		
}
	
