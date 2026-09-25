class Solution {
public:
    string s;
    int pos;

    set<string> parseExpression() {
        set<string> res = parseTerm();

        while (pos < s.size() && s[pos] == ',') {
            pos++;
            set<string> next = parseTerm();
            res.insert(next.begin(), next.end());
        }

        return res;
    }

    set<string> parseTerm() {
        set<string> res;
        res.insert("");

        while (pos < s.size() && s[pos] != '}' && s[pos] != ',') {
            set<string> cur;

            if (s[pos] == '{') {
                pos++;
                cur = parseExpression();
                pos++; // skip '}'
            } else {
                cur.insert(string(1, s[pos]));
                pos++;
            }

            set<string> temp;

            for (auto &a : res)
                for (auto &b : cur)
                    temp.insert(a + b);

            res = temp;
        }

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;

        set<string> result = parseExpression();

        return vector<string>(result.begin(), result.end());
    }
};