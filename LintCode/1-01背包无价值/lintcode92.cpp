/*
在 n个物品中挑选若干物品装入背包，最多能装多满？假设背包的大小为 m，每个物品的大小为 A[i]。
你不可以将物品进行切割。

样例 1:
    输入:  [3,4,8,5], backpack n=10
    输出:  9

样例 2:
    输入:  [2,3,5,7], backpack n=12
    输出:  12
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
    /*
    提示：
        dp[i][j]：前 i 个物品(不包括 i)放入容量为 j 的背包的最大重量；
        dp[i-1][j-A[i]] + A[i]：放入第 i 个物品时的重量；
        dp[i-1][j]：不放第 i 个物品时的重量；

        在遇到第 i 个物品时，需要考虑该物品是放入还是不放入
        状态转移方程为：
        dp[i][j] = max(dp[i-1][j-A[i]] + A[i], dp[i-1][j])

        第一层循环 i：0 ~ n
        第二层循环 j：m ~ A[i]，倒序是因为每个物品只能用一次。

        可简化成一维，令 dp[j] 为容量 j 的背包，装起物品的最大重量。
        dp[j] = max(dp[j - A[i]] + A[i], dp[j])
    */
        // write your code here
        int n = A.size();
        if (n <= 0 || m <= 0)
            return 0;
        vector<int> dp(m + 1, 0);
        for (int i = 0; i < n; ++i)
            for (int j = m; j >= A[i]; --j)
                dp[j] = max(dp[j - A[i]] + A[i], dp[j]);
                //dp[j] = dp[j - A[i]] + A[i] > dp[j] ? dp[j - A[i]] + A[i] : dp[j];
        return dp[m];
    }
};