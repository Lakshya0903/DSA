class Solution {
public:

    int fun(vector<vector<int>>& a, int i, int j,
            int n, int m, vector<vector<int>>& dp) {

        if (i >= n || j >= m) {
            return 0;
        }

 
        if (a[i][j] == 1) {
            return 0;
        }

        if (i == n - 1 && j == m - 1) {
            return 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int down = fun(a, i + 1, j, n, m, dp);
        int right = fun(a, i, j + 1, n, m, dp);

        dp[i][j] = down + right;

        return dp[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& a) {

        int n = a.size();
        int m = a[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return fun(a, 0, 0, n, m, dp);
    }
};