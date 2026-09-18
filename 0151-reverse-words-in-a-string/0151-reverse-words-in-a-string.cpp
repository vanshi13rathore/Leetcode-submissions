class Solution {
public:
    string reverseWords(string s) {

        vector<string> words;

        int i=0;

        while(i<s.size()) {

            while(i<s.size() && s[i] == ' ') {
                i++;
            }

            if(i>=s.size()) {
                break;
            }

            int start = i;

            while(i<s.size() && s[i] != ' ' ) {
                i++;
            }

            words.push_back(s.substr(start, i-start)) ;
        }

        string ans = "";

        for(int i=words.size()-1; i>=0; i--) {

            ans += words[i];

            if(i != 0) {
                ans += " ";
            }

        }
        return ans;
    }
};