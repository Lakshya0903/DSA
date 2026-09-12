class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> ans(n, vector<int>(n));

        int rs = 0;
        int re = n - 1;
        int cs = 0;
        int ce = n - 1;

        int num = 1;
        int i = 0;
        int j = 0;

        while (num <= n * n) {

            // Move Right
            while (j <= ce) {
                ans[i][j] = num++;
                j++;
            }

            j--;
            i++;
            rs++;

            // Move Down
            while (i <= re) {
                ans[i][j] = num++;
                i++;
            }

            i--;
            j--;
            ce--;

            // Move Left
            if (rs <= re) {
                while (j >= cs) {
                    ans[i][j] = num++;
                    j--;
                }

                j++;
                i--;
                re--;
            }

            // Move Up
            if (cs <= ce) {
                while (i >= rs) {
                    ans[i][j] = num++;
                    i--;
                }

                i++;
                j++;
                cs++;
            }
        }

        return ans;
    }
};