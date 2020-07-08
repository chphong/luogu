#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 1)
        {
            return 0;
        }

        int left = 0, right = 0;
        int prod = 1, res = 0;
        while (right < nums.size())
        {
            prod *= nums[right];
            while (prod >= k)
            {
                prod /= nums[left];
                left++;
            }
            res += right - left + 1;
            right++;
        }
        return res;
    }

    // int numSubarrayProductLessThanK(vector<int> &nums, int k)
    // {
    //     int *dp = new int[nums.size()];
    //     int res = 0;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         for (int j = 0; j < i; j++)
    //         {
    //             dp[j] *= nums[i];
    //             if (dp[j] < k)
    //             {
    //                 res++;
    //             }
    //             else
    //             {
    //                 dp[j] = k;
    //             }
    //         }
    //         if (nums[i] < k)
    //         {
    //             res++;
    //         }
    //         dp[i] = nums[i];
    //     }
    //     return res;
    // }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums;
    nums.push_back(10);
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(6);
    // nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(3);
    cout << s.numSubarrayProductLessThanK(nums, 100) << endl;
    return 0;
}

/*

给定一个正整数数组 nums。

找出该数组内乘积小于 k 的连续的子数组的个数。

示例 1:

输入: nums = [10,5,2,6], k = 100
输出: 8
解释: 8个乘积小于100的子数组分别为: [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]。
需要注意的是 [10,5,2] 并不是乘积小于100的子数组。
说明:

0 < nums.length <= 50000
0 < nums[i] < 1000
0 <= k < 10^6


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarray-product-less-than-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/