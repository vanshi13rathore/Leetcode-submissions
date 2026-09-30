class Solution {
public:
    vector<vector<int>> ans;

    void solve(int k, int n ,int start, vector<int>& temp, int sum) {


        if(temp.size() == k) {
            if(sum == n) {
                ans.push_back(temp);

            }
            return;
        }

        for(int i = start; i<=9; i++) {

            if(sum+i > n) {
                break;
            }

            temp.push_back(i);

            solve(k, n, i+1, temp, sum+i);

            temp.pop_back();
        }


    }


    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int> temp;
        solve(k, n, 1, temp, 0);
        return ans;

        
    }
};