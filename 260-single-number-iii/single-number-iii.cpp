class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        unsigned int XOR = 0;
        for(auto it:nums)
        {
            XOR ^= it;
        }

        long long unsigned rmsb = XOR & -(XOR);
        int x,y;
        x = 0;
        y = 0;

        for(int i = 0;i<n;i++)
        {
            if(nums[i] & rmsb)
            {
                x ^= nums[i];
            }
            else
            {
                y ^= nums[i];
            }
        }
        ans.push_back(x);
        ans.push_back(y);
        sort(ans.begin(),ans.end());
        return ans;


    }
};