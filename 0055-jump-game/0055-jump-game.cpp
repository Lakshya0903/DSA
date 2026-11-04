class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int mi = 0 ;
        for(int i = 0; i < n ; i++){
            if( i > mi ) return false;
            mi = max ( mi , nums[i] + i);
        }
        return true;
    }
};