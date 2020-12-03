#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int coinChange(int* coins, int coinsSize, int amount)
{
	int *dp = (int *)malloc(sizeof(int) * (amount + 1));    //dp[i]用于保存得到总价值为i的纸币数量
    //初始化为最极端情况，即全部由面额为1的零钱构造
	for (int i = 1; i < amount + 1; i++) {
        dp[i] = amount + 1;
    }
	dp[0] = 0;
    //假设amount为11，coins为[1,2]，则dp[11] = min(dp[11-1]+1 , dp[11-2]+1)
	for (int i = 1; i <= amount; i++) {
		for (int j = 0; j < coinsSize; j++) {
			if (i >= coins[j]) {
				dp[i] = __min(dp[i - coins[j]] + 1, dp[i]);
			}
		}
	}
    int ret = dp[amount];
    free(dp);
	return ret;
}

int main(){
    int coins[10] = {1,2,5,10,50,100 }, amount = 156;
    int temp = coinChange(coins, sizeof(coins)/sizeof(int), amount);
    printf("%d", temp);
    return 0;
}