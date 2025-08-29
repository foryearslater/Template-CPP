/*
 * @lc app=leetcode.cn id=292 lang=cpp
 *
 * [292] Nim 游戏
 */

// @lc code=start
class Solution {
public:
    bool canWinNim(int n) {
        if (n % 4 ==0) 
        {
            return false;
        }
        else 
        {
            return true;
        }
    }
};
// @lc code=end

