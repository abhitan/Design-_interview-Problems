class Solution {
public:

   bool allZero(vector<int>&freq)
   {
       for(auto itr:freq)
       {
           if(itr != 0)
           return false;
       }
       return true;
   }





    bool checkInclusion(string pat, string text) {
        int k = pat.length();
        int n = text.size();
        vector<int>freq(26,0);
        for(int i = 0;i<k;i++)
        {
            freq[pat[i] - 'a']++;
        }

        int i = 0;
        int j = 0;
        while(j<n)
        {
            freq[text[j]-'a']--;
            if(j-i+1 == k)
            {
                if(allZero(freq))
                {
                    return true;
                }
                freq[text[i] - 'a']++;
                i++;
            }
            j++;
        }
        return false;
    }
};