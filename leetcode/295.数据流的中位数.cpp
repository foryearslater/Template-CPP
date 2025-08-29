/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
class MedianFinder
{
public:
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int>> mi;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (mx.empty() || mx.top() > num)
        {
            mx.push(num);
        }
        else
        {
            mi.push(num);
        }
        if (mx.size() > mi.size() + 1)
        {
            mi.push(mx.top());
            mx.pop();
        }
        else if (mi.size() > mx.size() + 1)
        {
            mx.push(mi.top());
            mi.pop();
        }
    }

    double findMedian()
    {
        if (mx.size() == mi.size())
        {
            if (mx.size() == 0)
            {
                return 0;
            }
            return (mx.top() + mi.top()) / 2.0;
        }
        else
        {
            return mx.size() > mi.size() ? mx.top() : mi.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
