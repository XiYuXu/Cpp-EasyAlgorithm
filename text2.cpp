#include <iostream>
#include <cmath>
using namespace std;
int n;
void dfs(int state,int num){
    if(num==n){
        for (int i = 0; i < num;i++){
            if(state&(1<<i))
                cout << i+1<<" ";
        }
        cout << endl;
        return;
    }
    dfs(state | (1 << num),  num + 1);
    dfs(state, num + 1);
}
int main(){
    n = 5;
    dfs(0, 0);
    return 0;
}