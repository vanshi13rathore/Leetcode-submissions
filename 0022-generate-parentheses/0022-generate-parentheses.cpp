class Solution {
public:
    vector<string> ans;

    void solve(string temp, int open, int close, int n) {

        if(temp.size() == 2*n) {
            ans.push_back(temp);
            return;
        }

        if(open < n) {
            solve(temp + "(", open+1, close, n);
        }

        if(close < open) {
            solve(temp + ")", open, close+1, n);
        }
    }
    


    vector<string> generateParenthesis(int n) {

        solve("", 0, 0, n);
        return ans;
        
        
    }
};