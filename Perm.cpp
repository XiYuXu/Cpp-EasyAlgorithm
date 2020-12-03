#include <iostream>
using namespace std;
int index = 1;
void swap(int array[],int i,int j){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void print(int array[],int arrSize){
    for (int i = 0; i < arrSize;i++){
        cout << array[i]<<" ";
    }
    cout <<index++<<endl;
}

void Perm(int array[],int m,int arrSize){
    if(m == arrSize-1){
        print(array, arrSize);
        return;
    }
    for (int i = m; i < arrSize;i++){
        swap(array, i, m);
        Perm(array, m + 1, arrSize);
        swap(array, i, m);
    }    
}
int main(){
    int array[5] = {1, 2, 3, 4, 5};
    int length = sizeof(array) / sizeof(int);
    Perm(array, 0, length);
    return 0;
}