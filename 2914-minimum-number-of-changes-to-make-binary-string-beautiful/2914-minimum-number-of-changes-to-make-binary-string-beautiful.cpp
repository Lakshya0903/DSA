class Solution {
public:
    int minChanges(string s) {
        int settle = 0;
        for(int i = 0 ; i < s.size() ; i = i +2){
            if(i + 1 < s.size()){
                if(s[i] != s[i+1])settle++;
            }
        }
        return settle;
    }
};