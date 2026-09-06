class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char , int> m;
        for(char i : s) m[i]++;
        priority_queue<pair<int, char>> maxh;
        for(auto &i : m){
            pair< int , char> p = {i.second , i.first};
            maxh.push(p);
        }
        string ans = "";
        while(!maxh.empty()){
            char c = maxh.top().second;
            int n = maxh.top().first;
            for(int i = 0 ; i < n ; i++){
                ans += c;
            }
            maxh.pop();
        }
        return ans;
    }
};