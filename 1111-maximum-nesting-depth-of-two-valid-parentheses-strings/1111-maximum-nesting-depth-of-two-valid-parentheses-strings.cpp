class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        vector<int> ans;
        int co = 0;
        for(char c : s){
            if(c == '('){
                co++;
                ans.push_back(co % 2);
            }
            else if(c == ')'){
                ans.push_back(co % 2);
                co--;
            }
        }
        return ans;
    }
};