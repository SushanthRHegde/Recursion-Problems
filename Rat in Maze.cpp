

class Solution {
  public:
    vector<string> result;
    void solve(int i, int j,vector<vector<int>> &m,int n,string& temp){
        if(i < 0 || i >=n || j < 0 || j >=n || m[i][j] == 0) return;
        
        if((i == n - 1) && (j == n - 1)){
            result.push_back(temp);
            return;
        }
        m[i][j] = 0;
        
        //Going down 
        temp.push_back('D');
        solve(i+1,j,m,n,temp);
        temp.pop_back();
        
        //going right
        temp.push_back('R');
        solve(i,j+1,m,n,temp);
        temp.pop_back();
        
        //going left
        temp.push_back('L');
        solve(i,j-1,m,n,temp);
        temp.pop_back();
        
        //going up
        temp.push_back('U');
        solve(i-1,j,m,n,temp);
        temp.pop_back();
        
        m[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        string temp = "";
        int n = mat.size();
        solve(0,0,mat,n,temp);
        return result;
    }
};






//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
