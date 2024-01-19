class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        double avg_ans = 0;
        int n = salary.size();
        for(int i = 1;i<=n-2;i++)
        {
           avg_ans += salary[i];
        }
        return double(avg_ans/(n-2));
    }
};