class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        unordered_map<string, string> m;

        for (auto i : k)
            m[i[0]] = i[1];

        string ans = "";

        for (int i = 0; i < s.size(); ) {

            if (s[i] == '(') {
                string t = "";
                int j;

                for (j = i + 1; j < s.size(); j++) {
                    if (s[j] != ')')
                        t += s[j];
                    else
                        break;
                }

                if (m.find(t) != m.end())
                    ans += m[t];
                else
                    ans += "?";

                i = j + 1;
            }
            else {
                ans += s[i++];
            }
        }

        return ans;
    }
};