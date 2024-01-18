class Solution {
public:

    int countLaser(string s)
    {
        int tot = 0;
        for(int i = 0;i<s.length();i++)
        {
            if(s[i] == '1')
            {
                tot++;
            }
        }
        return tot;
    }



    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int start = countLaser(bank[0]);
        int res = 0;

        for(int i = 1;i<n;i++)
        {
            int curr = countLaser(bank[i]);

            if(curr != 0)
            {
                res += (curr * start);
                start = curr;
            }
        }
        return res;

    }
};