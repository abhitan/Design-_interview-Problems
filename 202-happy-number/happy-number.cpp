class Solution {
public:

   int nextNumber(int n)
   {
       int res = 0;
       while(n > 0)
       {
           int mod = n % 10;
           res += mod*mod;
           n /= 10;
       }
      return res;
   }




    bool isHappy(int n) {
        unordered_set<int>st;
        while(n != 1 && st.find(n) == st.end())
        {
            st.insert(n);
            n = nextNumber(n);
        }
        return n == 1;
    }
};