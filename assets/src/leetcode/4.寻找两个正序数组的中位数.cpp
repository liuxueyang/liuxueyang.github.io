/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = int(nums1.size()),
            m = int(nums2.size());
        if (n > m) {
            vector<int>& tmp = nums1; nums1 = nums2; nums2 = tmp;
            int len = n; n = m; m = len;
        }
        int lowi = 0, highi = n, lowj = 0, highj = m;
        int i, j;
        double res;
        while (true) {
            i = (lowi + highi) / 2, j = (m + n) / 2 - i;
            if ((i == 0 || j == m || nums1[i-1] <= nums2[j]) &&
                (i == n || j == 0 || nums2[j-1] <= nums1[i])) {
                    int fst, snd;

                    if (i == n) fst = nums2[j];
                    else if (j == m) fst = nums1[i];
                    else fst = min(nums1[i], nums2[j]);

                    if ((m + n) & 1) {
                        // odd
                        snd = fst;
                    } else {
                        // even
                        if (i == 0) snd = nums2[j-1];
                        else if (j == 0) snd = nums1[i-1];
                        else snd = max(nums1[i-1], nums2[j-1]);
                    }

                    res = (fst + snd) / 2.;
                    break;
                }
            else if (i > 0 && nums1[i-1] > nums2[j]) {
                highi = i - 1;
            } else if (j > 0 && nums2[j-1] > nums1[j]) {
                lowi = i + 1;
            }
        }
        return res;
    }
};
// @lc code=end
