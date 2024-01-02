class Solution {
public:

  int calc(int n)
  {
      int sum = 0;
      while(n != 0)
      {
         sum += n % 10;
         n /= 10;
      }
      return sum;
  }




    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>>mp;
        for(auto i:nums)
        {
            mp[calc(i)].push_back(i);
        }

        int maxi = -1;
        for(auto &it:mp)
        {
            auto l = it.second;
            int k = l.size();
            if(k >= 2)
            {
                sort(l.begin(),l.end());
                maxi = max(maxi,l[k-1] +l[k-2]);
            }
        }
       return maxi;
    }
};