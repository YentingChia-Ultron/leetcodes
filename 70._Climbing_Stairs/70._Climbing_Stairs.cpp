class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        //前面兩個case相加
        int last = 1, cur = 2;
        for(int i = 3; i <= n; i++)
        {
            int tmp = last + cur;
            last = cur;
            cur = tmp;
        }
        return cur;
    }
};
