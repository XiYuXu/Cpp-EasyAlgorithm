#include <iostream>
using namespace std;

int a[8][8];

void Arrange(int length){
    //递归结束条件
    if(length==8){
        return;
    }
    //先填充右边，右边的矩阵内的值大一个边长
    for (int i = 0; i < length;i++){
        for (int j = length; j < 2*length;j++){
            a[i][j] = a[i][j-length]+length;
        }
    }
    //再填充下面，左下角的矩阵和右上角矩阵等价
    for (int i = length; i < 2*length;i++){
        for (int j = 0; j <length;j++){
            a[i][j] = a[i-length][j+length];
        }
    }
    //填充右下角，右下角的矩阵等价于左上角矩阵
    for (int i = length; i < 2*length;i++){
        for (int j = length; j <2*length;j++){
            a[i][j] = a[i-length][j-length];
        }
    }
    Arrange(length * 2);
}

int main(){
    
    for (int i = 0; i < 8;i++){
        for (int j = 0; j < 8;j++){
            a[i][j] = 0;
        }
    }
    Arrange(1);
    for (int i = 0; i < 8;i++){
        for (int j = 0; j < 8;j++){
            cout << a[i][j]+1 << " ";
        }
        cout << endl;
    }
    return 0;
}