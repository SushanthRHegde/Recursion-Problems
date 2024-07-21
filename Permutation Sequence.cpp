//Using Recursion --> but time limit exceeded

class Solution {
public:
    void solve(string s, int ind, vector<string>& res) {
        if (ind == s.size()) {
            res.push_back(s);
            return;
        }
        for (int i = ind; i < s.size(); i++) {
            swap(s[i], s[ind]);
            solve(s, ind + 1, res);
            swap(s[i], s[ind]);
        }
    }
    
    string getPermutation(int n, int k) {
        string s;
        vector<string> res;
        for (int i = 1; i <= n; i++) {
            s.push_back(i + '0');
        }
        solve(s, 0, res);
        sort(res.begin(), res.end());
        return res[k - 1];
    }
};

//Using the Iterative method
class Solution {
public:
    string getPermutation(int n, int k) {
        // Create a list of numbers to get permutations of
        string numbers;
        for(int i = 1; i <= n; i++){
            numbers += to_string(i);
        }
        
        // Precompute factorials
        vector<int> factorial(n);
        factorial[0] = 1;
        for(int i = 1; i < n; i++){
            factorial[i] = factorial[i - 1] * i;
        }
        
        // Adjust k to be zero-indexed
        k--;
        
        string result;
        for(int i = n; i > 0; i--){
            int idx = k / factorial[i - 1];
            k %= factorial[i - 1];
            
            result += numbers[idx];
            numbers.erase(numbers.begin() + idx);
        }
        
        return result;
    }
};
