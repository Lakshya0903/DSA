class Solution {
public:
    string countAndSay(int n) {
        string ans = "";

        for (int i = 0; i < n; i++) {

            if (i == 0) {
                ans = "1";
            }
            else {
                string t = "";

                char c = ans[0];
                int f = 1;

                for (int j = 1; j < ans.size(); j++) {

                    if (ans[j] == c) {
                        f++;
                    }
                    else {
                        t += to_string(f);
                        t += c;

                        c = ans[j];
                        f = 1;
                    }
                }

                // Process the last group
                t += to_string(f);
                t += c;

                ans = t;
            }
        }

        return ans;
    }
};