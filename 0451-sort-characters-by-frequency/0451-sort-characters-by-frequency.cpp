class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mp;

        for(char ch : s) {
            mp[ch]++;
        }

        vector<pair<char, int>> freq;

        for(auto it : mp) {
            freq.push_back({it.first, it.second});
        }

        sort(freq.begin(), freq.end(),[](auto &a, auto &b) {
            return a.second > b.second;
        });

        string ans = "";

        for(auto it : freq) {
            ans.append(it.second, it.first);
        }
        return ans;
    }
};