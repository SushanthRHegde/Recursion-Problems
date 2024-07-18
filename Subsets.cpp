class Solution {
public:
    void func(int ind, vector<int> &ds, vector<vector<int>> &ans , vector<int> &nums){

        ans.push_back(ds);
        for(int i = ind ; i < nums.size() ;i++){
            ds.push_back(nums[i]);
            func(i+1,ds,ans,nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;

        func(0,ds,ans,nums);
        return ans;

    }
};
