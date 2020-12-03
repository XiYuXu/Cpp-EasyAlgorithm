#include <iostream>
using namespace std;

/**
 * 参数说明：n表示总元素个数，n表示目标获取个数，k表示还没取到的个数
 * 
 */
void print(int a[],int target_Size){
    for (int i = 0; i < target_Size;i++){
        cout << a[i]<<" ";
    }
    cout << endl;
}

//a为程序输入原集合 ,n为当前要抽取的目标集合，
//m为程序输入抽取的总个数，k为还未抽取的个数，
//target数组用于记录抽取到的元素下标
void group(int a[],int n,int m,int k,int target[]){

    //每进入一层循环的k都是不同的，
    //用循环控制target数组第k个元素的填充，从而控制某位元素是否选择
    for (int i = n; i >=k; i--){
        target[k-1] = i;    //通过循环填充第k层的不同元素，剩下的元素只能从该元素之后选取
        if(k==1){           //已经取完m个数则打印
            print(target,m);
        }else{              //第i个元素已经被选取，在剩下的i-1个元素中选取k-1个数
            group(a, i-1, m, k - 1, target);
        }
        
    }
}

int main(){
    int a[5] = {1, 2, 3, 4,5};
    int n = 5;
    int m = 3;
    int target[m];
    for (int i = 0; i < m;i++){
        target[i] = 0;
    }
    group(a, n, m, m, target);
    return 0;
}