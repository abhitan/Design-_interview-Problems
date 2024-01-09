class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        int len = s.length();
        for(int i = 0;i<len;i++)
        {
            if(st.empty() || st.top() != s[i])
            {
                st.push(s[i]);
            }
            else if(st.top() == s[i])
            {
                st.pop();
            }
        }

        string res = "";
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(begin(res),end(res));
        return res;
    }
};