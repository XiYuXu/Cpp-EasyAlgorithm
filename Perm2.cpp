#include <iostream>
using namespace std;

void swap(int a[],int i,int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void print(int a[],int length){
    for (int i = 0; i < length;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void perm(int a[],int start,int target_Size){
    if(start == target_Size-1){
        print(a, target_Size);
    }
    for (int i = start; i < target_Size;i++){
        swap(a, i, start);
        perm(a, start + 1, target_Size);
        swap(a, i, start);
    }
}
int main(){
    int a[4] = {1, 2, 3, 4};
    int tartget_Size = sizeof(a) / sizeof(int);
    perm(a,0,tartget_Size);
    return 0;
}