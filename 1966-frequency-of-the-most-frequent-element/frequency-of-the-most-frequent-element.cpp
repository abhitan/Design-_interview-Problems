class Solution {
public:

  int binarySearch(vector<int>&nums,int target_idx,int k, vector<long long>&prefixSum)
  {
      int target = nums[target_idx];
      int i = 0;
      int j = target_idx;
      int res = target_idx;

      while(i<=j)
      {
          int mid = i + (j-i)/2;

          long long count = (target_idx-mid+1);
          long long window_sum = count * target;
          long long curr_sum = prefixSum[target_idx] - prefixSum[mid] + nums[mid];
          long long ops = window_sum - curr_sum;

          if(ops > k)
          {
              i = mid+1;
          }
          else
         {
             res = mid;
             j = mid-1;
         }
      }
      return target_idx-res+1;
  }
  






    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int res = 0;

        vector<long long>prefixSum(n,0);
        prefixSum[0] = nums[0];
        for(int i = 1;i<n;i++)
        {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        for(int i = 0;i<n;i++)
        {
            int freq = binarySearch(nums,i,k,prefixSum);
            res = max(res,freq);
        }
        return res;
    }
};