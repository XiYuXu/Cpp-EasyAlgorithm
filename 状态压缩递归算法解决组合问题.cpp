#include <iostream>
int n = 5,m = 1;
using namespace std;

//通过state标识各个位数元素的选择情况
void dfs(int state,int sum,int num){
    //若是还没有选择的元素比剩下可以选择的元素数目还要多则直接返回
    if(n-num<m-sum)
        return;
    //取完了m个元素则打印
    if(sum==m){
        for (int i = 0; i < n;i++){
            if((state>>i)&1)
                cout << i + 1 << " ";
        }
        cout << endl;
        return;
    }
    //对两种情况进行递归
    if(sum<m){
        dfs(state | (1 << num),sum+1, num + 1);
        dfs(state , sum,num + 1);
    }
}

int main(){
    dfs(0, 0, 0);
    return 0;
}