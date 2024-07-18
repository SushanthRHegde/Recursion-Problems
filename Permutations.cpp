class Solution {
public:
    void permuteFunc(vector<int>& ds,vector<vector<int>>& ans,vector<int>& nums,int freq[]){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return ;
        }
        for(int i = 0; i < nums.size();i++){
            if(!freq[i]){ //un marked 

            // Now mark it --> element is picked
                freq[i] = 1;
                ds.push_back(nums[i]);
                permuteFunc(ds,ans,nums,freq);
            // After recusrion -> unmark it and remove element
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        //to keep track of ele is marked or not
        int freq[nums.size()] ;
        for(int i = 0; i < nums.size();i++ ){
            freq[i] = 0;
        }
        permuteFunc(ds,ans,nums,freq);
        return ans;
    }
};
