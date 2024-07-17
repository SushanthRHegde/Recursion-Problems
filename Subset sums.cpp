ass Solution {
  public:
  void func(int ind , int sum , vector<int> & arr , int n , vector<int> &ans ){
      if( ind == n){
          ans.push_back(sum);
          return ;
      }
      //element is picked
      func(ind+1,sum +arr[ind],arr,n,ans );
      //element is not picked
      func(ind+1,sum,arr,n,ans);
  }
    vector<int> subsetSums(vector<int> arr, int n) {
        
        vector<int> ans;
        func(0,0,arr,n,ans);
        return ans;
    }
};
