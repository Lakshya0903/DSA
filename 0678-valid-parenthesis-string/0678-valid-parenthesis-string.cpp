class Solution {
public:
    bool fun(string &s, int i, int open, vector<vector<int>>& dp) {

        if (open < 0)
            return false;

        if (i == s.size())
            return open == 0;

        if (dp[i][open] != -1)
            return dp[i][open];

        bool ans = false;

        if (s[i] == '(') {
            ans = fun(s, i + 1, open + 1, dp);
        }

        else if (s[i] == ')') {
            ans = fun(s, i + 1, open - 1, dp);
        }

        else { 

            
            ans = fun(s, i + 1, open + 1, dp);

            if (!ans)
                ans = fun(s, i + 1, open - 1, dp);

      
            if (!ans)
                ans = fun(s, i + 1, open, dp);
        }

        return dp[i][open] = ans;
    }

    bool checkValidString(string s) {

        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return fun(s, 0, 0, dp);
    }
};