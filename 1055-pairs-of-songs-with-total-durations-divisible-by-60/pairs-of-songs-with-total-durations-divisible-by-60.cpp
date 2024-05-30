class Solution {
public:

int sumOfN(int n)
{
    return (long)n*(n+1)/2;
}
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        vector<int>count(60,0);

        for(auto i:time)
        {
            count[i%60]++;
        }

        int pairs = 0;
        for(int i = 1;i<30;i++)
        {
            pairs += count[i]*count[60-i];
        }

        pairs += sumOfN(count[0]-1) + sumOfN(count[30]-1);

        return pairs;
    }
};