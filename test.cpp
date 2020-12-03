#include <iostream>
using namespace std;
void print(int a[],int size){
    for (int i = 0; i < size;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
void group(int a[],int target[],int n,int m,int k){
    for (int i=n; i >= k;i--){
        target[k-1] = i;
        if(k==1){
            print(target,m);
        }else{
            group(a, target, i - 1, m, k - 1);
        }
    }
}

int main(){
    int a[5] = {1, 2, 3, 4, 5};
    int n = 6;
    int m = 4;
    int target[m];
    for(int i = 0; i < m;i++){
        target[i] = 0;
    }
    group(a, target,n,m,m);
    
    return 0;
}