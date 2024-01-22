class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int>v(n);
        stack<int>st;
        for(int i = n-1;i>=0;i--)
        {
            if(st.empty())
            {
                v.push_back(-1);
            }
            else if(!st.empty() and st.top() > nums2[i])
            {
                v.push_back(st.top());
            }
            else if(!st.empty() and st.top() <= nums2[i])
            {
                while(!st.empty() and st.top() <= nums2[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    v.push_back(-1);
                }
                else{
                    v.push_back(st.top());
                }
            }
            st.push(nums2[i]);
        }
        reverse(v.begin(),v.end());

        unordered_map<int,int>mp;
        for(int i = 0;i<n;i++)
        {
            mp[nums2[i]] = v[i];
        }

        vector<int>ans(nums1.size());
        for(int i = 0;i<nums1.size();i++)
        {
            ans[i] = mp[nums1[i]];
        }
       return ans;
    }
};