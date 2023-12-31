class Solution {
public:

  bool static cmp(int &a,int &b)
  {
      int cA = __builtin_popcount(a);
      int cB = __builtin_popcount(b);

      if(cA == cB)
      {
          return a < b;
      }
      return cA < cB;
  }




    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};