class Solution {
public:
    int minDeletions(string str) {
        int freq[26] = {0};
    int n = str.size();
    for(char &ch:str)
    {
        freq[ch - 'a']++;
    }

    unordered_set<int>st;
    int ans = 0;
    for(int i = 0;i<26;i++)
    {
        while(freq[i] > 0 && st.find(freq[i]) != st.end())
        {
            freq[i] -= 1;
            ans++;
        }
        st.insert(freq[i]);
    }
    return ans;
    }
};