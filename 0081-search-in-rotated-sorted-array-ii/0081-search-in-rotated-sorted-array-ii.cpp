class Solution {
public:
    bool search(vector<int>& nums, int t) {

        int l = 0;
        int h = nums.size() - 1;

        while (l <= h) {

            int m = l + (h - l) / 2;

            if (nums[m] == t) {
                return true;
            }

            // Duplicate ambiguity
            if (nums[l] == nums[m] && nums[m] == nums[h]) {
                l++;
                h--;
            }

            // Left half is sorted
            else if (nums[l] <= nums[m]) {

                if (nums[l] <= t && t < nums[m]) {
                    h = m - 1;
                }
                else {
                    l = m + 1;
                }
            }

            // Right half is sorted
            else {

                if (nums[m] < t && t <= nums[h]) {
                    l = m + 1;
                }
                else {
                    h = m - 1;
                }
            }
        }

        return false;
    }
};