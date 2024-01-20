class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int n = nums.size();
        int cnt = 0;
        int sum = 0;
        int i = 0;
        int j = 0;
        while(j<n)
        {
            sum += nums[j];
            
            // when window size gets hit perform necessary operation
            if(j-i+1 == k)
            {
                cnt = ((sum/k >= threshold)? cnt+1:cnt);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return cnt;
    }
};