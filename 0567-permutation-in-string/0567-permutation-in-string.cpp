class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m, cnt;
        for (char c : s1) m[c]++;
        int init = 0, h = 0, n = s2.size();
        while (h < n) {
            char c = s2[h];
            cnt[c]++;
           if (!m.contains(c)) {
                while (init <= h) {
                    cnt[s2[init]]--;
                    init++;
                }
            }
            else if (cnt[c] > m[c]) {
                while (s2[init] != c) {
                    cnt[s2[init]]--;
                    init++;
                }
                cnt[s2[init]]--;
                init++;
            }
            if (h - init + 1 == s1.size())
                return true;
            h++;
        }
        return false;
    }
};