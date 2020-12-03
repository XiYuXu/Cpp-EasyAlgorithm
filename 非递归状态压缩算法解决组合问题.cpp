#include <iostream>
#include <stack>
using namespace std;
 
struct State {
    int num, sum, state;
};
 
int main() {
    int n, m;
    cin >> n >> m;
    stack<State> stk;//栈记录好你遍历分支的哪一个部分
    stk.push({ 0,0,0 });

    //若栈不为空则循环
    while (stk.size()) {
        auto t = stk.top();
        stk.pop();
        //取不了了
        if (t.sum + n - t.num < m) 
            continue;
        //若是已取完
        if (t.sum == m) {
            for (int i = 0; i < n; i++)
                if (t.state >> i & 1)
                    cout << i + 1 << " ";
            cout << endl;
            continue;
        }
        
        stk.push({ t.num + 1,t.sum,t.state });                  //表示未取得该数
        stk.push({ t.num + 1,t.sum + 1,t.state | 1 << t.num }); //表示取得该数
    }
    return 0;
}
