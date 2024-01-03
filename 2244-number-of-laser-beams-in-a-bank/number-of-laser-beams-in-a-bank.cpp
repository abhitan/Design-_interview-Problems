class Solution {
public:

  int countLasers(string s)
  {
      int tot = 0;
      for(int i = 0;i<s.length();i++)
      {
          if(s[i] == '1')
          tot++;
      }
      return tot;
  }


    int numberOfBeams(vector<string>& bank) {
        int total = 0;
        int start = countLasers(bank[0]);
        int  n = bank.size();

        for(int i = 1;i<n;i++)
        {
            int curr = countLasers(bank[i]);

            if(curr != 0)
            {
                total += (start * curr);
                start = curr;
            }
        }
       return total;
    }
};