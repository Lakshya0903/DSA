class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int mi = 2000;
        for(int i = 0 ; i < n ; i++)
        {
            int a = nums[i];
            int sum = 0;
            while(a > 0){
                sum += (a % 10);
                a /= 10;
            }
            if (sum == i){
                mi = min(sum , mi);
            }
        }
        if(mi == 2000) return -1;
        return mi;
     }
};