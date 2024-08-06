class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int n = nums.size();
       priority_queue<int>pq;
       for(auto it:nums){
           pq.push(it);
       }
       int ele1 = pq.top();
       pq.pop();
       int ele2 = pq.top();
       pq.pop();

       int res = (ele1-1) * (ele2-1);
       return res;
    }
};