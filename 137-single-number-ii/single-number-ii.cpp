class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0;i<32;i++)
        {
            int count1 = 0;
            for(int j = 0;j<nums.size();j++)
            {
                if(nums[j] & (1<<i))
                {
                    count1++;
                }
            }

            if(count1 % 3)
            {
                ans |= (1<<i);
            }
        }
        return ans;
    }
};