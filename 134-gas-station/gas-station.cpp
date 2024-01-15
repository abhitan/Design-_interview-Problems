class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gs = gas.size();
        int cs = cost.size();

        int gasSum = 0;
        int costSum = 0;

        int start = 0;
        int currGas = 0;

        for(int i = 0;i<gs;i++)
        {
            gasSum += gas[i];
        }

        for(int i = 0;i<cs;i++)
        {
            costSum += cost[i];
        }

        if(gasSum < costSum)
        return -1;

        for(int i = 0;i<gs;i++)
        {
            currGas += (gas[i] - cost[i]);

            if(currGas < 0)
            {
                start = i+1;
                currGas = 0;
            }
        }
        return start;
    }
};