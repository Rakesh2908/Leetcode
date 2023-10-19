class Solution {
public:
    string f(string s) {
        stack<char> ans;

        for (char c : s) {
            if (c != '#') {
                ans.push(c);
            } else if (!ans.empty()) {
                ans.pop();
            }
        }

        string temp;

        while (!ans.empty()) {
            temp = ans.top() + temp;
            ans.pop();
        }

        return temp;
    }

    bool backspaceCompare(string s, string t) {
        return f(s) == f(t);
    }
};
