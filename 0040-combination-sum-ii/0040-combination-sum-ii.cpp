class Solution {
public:
    void fun(vector<int>& a, int n, int i, vector<vector<int>>& ans,
             vector<int>& t, int target) {
        if (target == 0) {
            vector<int> d = t;
            sort(d.begin(), d.end());
            ans.push_back(d);
            return;
        }
        if (i == n || target < 0)
            return;

        t.push_back(a[i]);
        fun(a, n, i + 1, ans, t, target - a[i]);
        t.pop_back();
        int j = i + 1;

        while (j < n && a[j] == a[i])
            j++;

        fun(a,n, j,  ans, t , target);
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        sort(a.rbegin(), a.rend());
        vector<vector<int>> ans;
        int n = a.size();
        vector<int> t;
        fun(a, n, 0, ans, t, target);
        return ans;
    }
};
