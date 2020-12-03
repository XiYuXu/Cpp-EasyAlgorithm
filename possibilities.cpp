#include <iostream>
#include <cmath>
using namespace std;


void CalculatePossible(int z,double q){
    double possible = 1.0;
    double lamda = z*(q/(1-q));
    double temp = exp(-lamda);
    possible -= temp*(1-pow(q/(1-q),z));
    for (int k = 1; k <= z; k++)
    {
        temp = temp * lamda/ k;
        possible -= temp*(1-pow(q/(1-q),z-k));
    }
    cout << "Z="<<z<<"   攻击成功概率："<<possible << endl;
}

int main(){
    int z;
    cout << "当q=0.3时，诚实节点自分叉点挖到Z块时攻击概率" << endl;
    double q = 0.3; //坏人打包一个区块的概率
    for (z = 0; z < 10; z++)
        CalculatePossible(z, q);
    return 0;
}