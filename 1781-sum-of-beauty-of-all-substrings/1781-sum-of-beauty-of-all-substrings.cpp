class Solution {
public:
    int beautySum(string s) {
        vector<int> freq(26, 0);

        int n = s.size();
        int beauty = 0;

        for (int h = 0; h < n; h++) {
            fill(freq.begin(), freq.end(), 0);

            int cc = 0;
            int l = h;

            while (l >= 0) {

                int num = s[l] - 'a';

                if (freq[num] == 0)
                    cc++;

                freq[num]++;

                if (cc > 1) {
                    int mx = 0;
                    int mn = INT_MAX;

                    for (int f : freq) {
                        if (f > 0) {
                            mx = max(mx, f);
                            mn = min(mn, f);
                        }
                    }

                    beauty += mx - mn;
                }

                l--;
            }
        }

        return beauty;
    }
};