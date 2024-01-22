class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
         stack<int>st;
         vector<int>v;
        // step 1:- Put elements into the stack such that satck stores next greater element order.
        
        for(int i = n-2;i>=0;i--)
        {
            while(!st.empty() && st.top() <= nums[i])
            {
                st.pop();
            }
            st.push(nums[i]);
        }

        // step 2:- // next greater element logic

        for(int i = n-1;i>=0;i--)
        {
            while(!st.empty() && st.top() <= nums[i])
            {
                st.pop();
            }
            if(st.empty())
            {
               v.push_back(-1);
            }
            else
            {
                v.push_back(st.top());
            }
            st.push(nums[i]);
        }
        reverse(begin(v),end(v));
        return v;
    }
};