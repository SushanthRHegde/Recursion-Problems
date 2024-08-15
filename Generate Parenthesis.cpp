class Solution {
public:
    bool isValid(string& str){
        int count = 0;
        for(char ch :str){
            if(ch == '(')count++;
            else count--;
            //if close bracket comes before  --> NOT VALID
            if(count < 0) return false;
        }
        // equal no of open and close --> VALID
        return count == 0;
    }
    void solve(int n,string& curr,vector<string>& ans){

        if(curr.size() == 2*n){
            if(isValid(curr)) ans.push_back(curr);
            return ;
        }
        //TRUST THE RECURSION
        curr.push_back('(');
        solve(n,curr,ans);
        curr.pop_back();

        curr.push_back(')');
        solve(n,curr,ans);
        curr.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        solve(n,curr,ans);
        return ans;
    }
};
