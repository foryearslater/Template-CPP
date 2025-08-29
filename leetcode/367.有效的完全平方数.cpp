/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
       int l = 0,r = num;
       while(l<=r)
       {
         long mid = (l+r)/2;
         long sqr = mid*mid;
         if(sqr == num)
         {
            return true;
         }
         else if(sqr < num)
         {
            l = mid+1;
         }
         else
         {
            r=mid-1;
         }
       }
       return false;
    }
};
// @lc code=end

