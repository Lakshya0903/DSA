class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int in = 0;

        for (char c : s) {
            if (c == '(') {
                if (open % 2 == 1) {
                    in++;
                    open--;
                }

                open += 2;
            } 
            else {
                open--;

                if (open < 0) {
                    in++;
                    open = 1;
                }
            }
        }

        return in + open;
    }
};