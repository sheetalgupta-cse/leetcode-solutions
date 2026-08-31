class Solution {
public:

    vector<string> ans;

    void solve(string &s, int index) {

        // Base case
        if (index == s.size()) {
            ans.push_back(s);
            return;
        }

        // If current character is a digit
        if (isdigit(s[index])) {
            solve(s, index + 1);
            return;
        }

        // Case 1: lowercase
        s[index] = tolower(s[index]);
        solve(s, index + 1);

        // Case 2: uppercase
        s[index] = toupper(s[index]);
        solve(s, index + 1);
    }

    vector<string> letterCasePermutation(string s) {
        solve(s, 0);
        return ans;
    }
};