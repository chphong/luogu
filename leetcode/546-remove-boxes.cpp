#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

class Solution
{
public:
    int removeBoxes(vector<int> &boxes)
    {
        int dp[100][100][100];
        memset(dp, 0, 100 * 100 * 100);
        return calculatePoints(boxes, dp, 0, boxes.size() - 1, 0);
    }

    int calculatePoints(vector<int> &boxes, int dp[][100][100], int l, int r, int k)
    {
        if (l > r)
            return 0;
        if (dp[l][r][k] != 0) // 防止重复计算
            return dp[l][r][k];
        while (r > l && boxes[r] == boxes[r - 1])
        {
            r--;
            k++;
        }
        dp[l][r][k] = calculatePoints(boxes, dp, l, r - 1, 0) + (k + 1) * (k + 1);
        for (size_t i = l; i < r; i++)
        {
            if (boxes[i] == boxes[r])
            {
                dp[l][r][k] = max(dp[l][r][k], calculatePoints(boxes, dp, l, i, k + 1) + calculatePoints(boxes, dp, i + 1, r - 1, 0));
            }
        }
        return dp[l][r][k];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> boxes;
    boxes.push_back(1);
    boxes.push_back(3);
    boxes.push_back(2);
    // boxes.push_back(2);
    // boxes.push_back(2);
    // boxes.push_back(3);
    // boxes.push_back(4);
    // boxes.push_back(3);
    // boxes.push_back(1);
    cout << s.removeBoxes(boxes) << endl;
    return 0;
}
