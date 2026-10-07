class Solution {
public:
    bool isValid(string s) {

        int balance = 0;

        for(char ch : s) { 

            if(ch == '(') {
                balance++;
            }
            else if(ch == ')') {
                balance--;

                if(balance < 0) {
                    return false;
                }
            }

        }
        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;

        queue<string> q;
        unordered_set<string> visited;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while(!q.empty() && !found) {
            int size = q.size();

            while(size--) {

                string current = q.front();
                q.pop();

                if(isValid(current)) {
                    ans.push_back(current);
                    found = true;
                }

                if(found) {
                    continue;
                }

                for(int i=0; i<current.size(); i++) {

                    if(current[i] != '(' && current[i] != ')') {
                        continue;
                    }

                    string next = current.substr(0, i)
                                    + current.substr(i+1);

                
                    if(!visited.count(next)) {

                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
        }
        return ans;
    }
};