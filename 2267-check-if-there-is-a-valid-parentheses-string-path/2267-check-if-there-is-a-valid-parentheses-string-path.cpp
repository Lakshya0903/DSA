class Solution {
public:
    bool dfs(vector<vector<char>>& grid, int i, int j, int open,
             vector<vector<vector<int>>>& dp) {

        int n = grid.size();
        int m = grid[0].size();

        if (i >= n || j >= m)
            return false;

        if (grid[i][j] == '(')
            open++;
        else
            open--;

        if (open < 0)
            return false;

        int remaining = (n - 1 - i) + (m - 1 - j);

        if (open > remaining)
            return false;

        if (i == n - 1 && j == m - 1)
            return open == 0;

        if (dp[i][j][open] != -1)
            return dp[i][j][open];

        bool down = dfs(grid, i + 1, j, open, dp);
        bool right = dfs(grid, i, j + 1, open, dp);

        return dp[i][j][open] = (down || right);
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        if ((n + m - 1) % 2 != 0)
            return false;

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(n + m + 1, -1)));

        return dfs(grid, 0, 0, 0, dp);
    }
};