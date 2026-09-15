class Solution {
public:

    void fun(vector<vector<int>> &ans , vector<int> &t , int k , int n , int i , int sum){
   
        if(sum == n){
            if(t.size() == k){
                ans.push_back(t);
            }
            return;
        }
        if(sum >= n) return;
        for(int j = i ; j <= 9 ; j++){
            t.push_back(j);
            fun(ans, t, k , n , j+1 , sum + j);
            t.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> t;
        fun(ans , t ,k , n , 1 , 0);
        return ans;

    }
};