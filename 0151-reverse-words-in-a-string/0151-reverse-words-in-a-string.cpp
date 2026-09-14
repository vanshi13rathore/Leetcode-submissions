class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i = s.size() - 1;

        while(i >= 0) {
            

            // Skip spaces
            while(i >= 0 && s[i] == ' ') {
                i--;
            }

            if(i < 0) {
                break;
            }

            // Find the beginning of the word
            int j = i;

            while(j >= 0 && s[j] != ' ') {
                j--;
            }

            // Add space between words
            if(!ans.empty()) {
                ans += ' ';
            }

            // Add the word
            ans += s.substr(j + 1, i - j);

            // Move to previous word
            i = j - 1;
        }

        return ans;
    }
};