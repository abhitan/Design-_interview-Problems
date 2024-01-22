class Solution {
public:

  void solve(vector<int>&nums,int n,int idx,vector<int>&subset, vector<vector<int>>&subsets)
  {
      if(idx >= n)
      {
          subsets.push_back(subset);
          return;
      }

      subset.push_back(nums[idx]);
      solve(nums,n,idx+1,subset,subsets);

      subset.pop_back();
      while(idx+1<n && nums[idx] == nums[idx+1])
      {
          idx++;
        // continue;

      }
      solve(nums,n,idx+1,subset,subsets);
  }







    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>subsets;
        vector<int>subset;
        solve(nums,n,0,subset,subsets);
        return subsets;
    }
};