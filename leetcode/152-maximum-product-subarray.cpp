#include <iostream>
#include <vector>

using namespace std;

int max3(int a, int b, int c)
{
    return max(a, max(b, c));
}

int min3(int a, int b, int c)
{
    return min(a, min(b, c));
}

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int res = -2147483648;
        int maxdp = nums[0];
        int mindp = nums[0];
        res = nums[0];
        for (size_t i = 1; i < nums.size(); i++)
        {
            int maxtmp = (max3(nums[i], nums[i] * mindp, nums[i] * maxdp));
            int mintmp = (min3(nums[i], nums[i] * mindp, nums[i] * maxdp));
            res = max3(maxtmp, mintmp, res);
            maxdp = maxtmp;
            mindp = mintmp;
        }
        return res;
    }
};

/*

给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

 

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/