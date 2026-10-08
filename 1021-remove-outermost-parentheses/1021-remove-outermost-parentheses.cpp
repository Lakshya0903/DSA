class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else {
                int a = st.top();
                st.pop();
                if (st.empty()) {
                    s.replace(a, 1, " ");
                    s.replace(i , 1, " ");
                }
            }
        }
        string ans = "";
        for(char c : s){
            if(c != ' '){
                ans += c;
            }
        }

        return ans;
    }
};