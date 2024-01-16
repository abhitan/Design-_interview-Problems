class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        int sz = stones.size();

        for(auto &it:stones)
        {
            pq.push(it);
        }
        while(pq.size() > 1)
        {
            int ele1 = pq.top();
            pq.pop();

            int ele2 = pq.top();
            pq.pop();

            pq.push(ele1-ele2);
        }
        return pq.top();
    }
};