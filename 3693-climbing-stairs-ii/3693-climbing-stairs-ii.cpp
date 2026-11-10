class Solution {
public:

    int fun(vector<int>& costs, int n, int i, vector<int>& dp) {

        
        if (i == n) return 0;

        if (dp[i] != -1) return dp[i];

        int ans = INT_MAX;
        for (int j = 1; j <= 3; j++) {

            if (i + j <= n) {

                int curr = costs[i + j - 1] + j * j
                         + fun(costs, n, i + j, dp);

                ans = min(ans, curr);
            }
        }

        return dp[i] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {

        vector<int> dp(n + 1, -1);

        return fun(costs, n, 0, dp);
    }
};