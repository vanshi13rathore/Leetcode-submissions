class Solution {
public:
    vector<string> ans;

    void solve(string& num, long long target, int index, string path, long long value, long long prev) {

        if(index == num.size()) {
            if(value == target) {
                ans.push_back(path);
            }
            return ;

        }

        for(int i=index; i<num.size(); i++) {

            if(i>index && num[index] == '0') {
                break;
            }

            string currentStr = num.substr(index, i-index+1);
            long long current = stoll(currentStr);

            if(index == 0) {

                solve(num, target, i+1, currentStr, current, current);
            }
            else{
                solve(num, target, i+1, path +"+"+ currentStr, value+current, current);

                solve(num, target, i+1, path + "-" + currentStr, value-current, -current);

                solve(num, target, i+1, path + "*" + currentStr, value-prev+ prev*current, prev*current );
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        solve(num, target, 0, "", 0, 0);
        return ans;
        
    }
};