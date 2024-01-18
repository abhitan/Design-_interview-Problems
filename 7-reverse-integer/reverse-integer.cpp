class Solution {
public:
    int reverse(int x) {
        long rev_num = 0;
        while(x != 0)
        {
            int digit = x % 10;
            rev_num = (rev_num * 10) + digit;
            x /= 10;
        }
        return (rev_num > INT_MAX || rev_num < INT_MIN) ? 0 : rev_num;
    }
};