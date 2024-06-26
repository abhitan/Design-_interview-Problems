class Solution {
public:
    string decodeString(string s) {
         std::stack<std::string> strStack;
        std::stack<int> numStack;
        std::string curString = "";
        int curNum = 0;

        for (char c : s) {
            if (c == '[') {
                strStack.push(curString);
                numStack.push(curNum);
                curString = "";
                curNum = 0;
            } else if (c == ']') {
                int num = numStack.top();
                numStack.pop();
                std::string prevString = strStack.top();
                strStack.pop();
                for (int i = 0; i < num; ++i) {
                    prevString += curString;
                }
                curString = prevString;
            } else if (isdigit(c)) {
                curNum = curNum * 10 + (c - '0');
            } else {
                curString += c;
            }
        }

        return curString;
    }
};