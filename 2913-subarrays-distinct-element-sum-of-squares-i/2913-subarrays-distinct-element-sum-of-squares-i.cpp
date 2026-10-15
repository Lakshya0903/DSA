class Solution {
public:
    int sumCounts(vector<int>& nums) {
        unordered_map<int , int > map;
        int ans = 0;
        for(int i = 0 ; i < nums.size()  ; i++){
            for(int j = i ; j < nums.size() ; j++){
                map[nums[j]]++;
                int t = map.size();
                ans += (t * t);
            }
            map.clear();
        }
        return ans;
    }
};