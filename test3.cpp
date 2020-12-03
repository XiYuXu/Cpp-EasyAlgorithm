#include <stdio.h>
int main(){
    //一次整数循环就遍历了所有状态
    for (int state = 0; state <= 7;state++){
        for (int i = 0; i < 3;i++){
            if((state >> i) & 1)        //判断第i位的取值
                printf("%d", i+1);
        }
        printf("\n");
    }
    return 0;
}