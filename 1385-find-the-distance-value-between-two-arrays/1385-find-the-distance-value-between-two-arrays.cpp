class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;

        for(int i : arr1) {
            int c = 0;

            for(int j : arr2) {
                int a = abs(i - j);

                if(a <= d) {
                    c++;
                    break;
                }
            }

            if(c == 0) {
                ans++;
            }
        }

        return ans;
    }
};
