class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>st;
        int i = 0;
        int j = 0;
        int n = nums.size();
        while(j<n)
        {
            // Condition 1:
            if(abs(i - j) > k)
            {
                st.erase(nums[i]);
                i++;
            }

            // condition 2:
            if(st.find(nums[j]) != st.end())
            {
                return true;
            }
            st.insert(nums[j]);
            j++;
        }
        return false;
    }
};