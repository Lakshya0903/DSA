class Solution {
public:
    string digitSum(string s, int k) {

        while(s.size() > k) {

            string nw = "";

            for(int i = 0; i < s.size(); ) {

                int num = 0;
                int j;

                for(j = i; j < i + k && j < s.size(); j++) {
                    num += s[j] - '0';
                }

                nw += to_string(num);

                i = j;
            }

            s = nw;
        }

        return s;
    }
};