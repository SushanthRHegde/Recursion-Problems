class Solution {
public:
    // Function to check if a substring s[start..end] is a palindrome
    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }


    void solve(int ind, string s, vector<string>& temp, vector<vector<string>>& res) {

        if (ind == s.size()) {
            res.push_back(temp);
            return;
        }

        for (int i = ind; i < s.size(); i++) {
            // If the current substring is a palindrome, include it in the current partition
            if (isPalindrome(s, ind, i)) {
                temp.push_back(s.substr(ind, i - ind + 1));
                // Recur for the remaining substring
                solve(i + 1, s, temp, res);
                // Backtrack and remove the current substring from the current partition
                temp.pop_back();
            }
        }
    }

    // Main function to return all possible palindrome partitioning of s
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> result;
        solve(0, s, temp, result);
        return result;
    }
};
