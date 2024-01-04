class Solution {
public:

  bool allZeros(vector<int>&freq)
   {
       for(auto it:freq)
       {
           if(it != 0)
           {
               return false;
           }
       }
       return true;
   }


    bool checkInclusion(string p, string s) {
        vector<int>ans;
        vector<int>freq(26,0);
        int n = s.size();
        int k = p.size();

        for(int i = 0;i<k;i++)
        {
            freq[p[i]-'a']++;
        }
    
        int i = 0;
        int j = 0;
        while(j<n)
        {
            freq[s[j]-'a']--;
            if(j-i+1 == k)
            {
                if(allZeros(freq))
                {
                   return true;
                }

                freq[s[i] - 'a']++;
                i++;
            }
            j++;
        }
        return false;
    }
};