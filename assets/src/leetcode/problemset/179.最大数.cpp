/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> nums1;
        for (auto const &x : nums)
        {
            nums1.push_back(to_string(x));
        }
        sort(
            nums1.begin(),
            nums1.end(),
            [&](const string a, const string b) {
                return compareString(a, b);
            });
        
        string res;
        for (auto const &x : nums1)
        {
            res = res + x;
        }

        string res1;
        for (size_t i = 0; i < res.size(); i++)
        {
            if (res[i] != '0')
            {
                res1 = res.substr(i);
                break;
            }
        }

        if (res1 == "")
            res1 = "0";
        return res1;
    }

    bool compareString(string a, string b)
    {
        string c1 = a + b, c2 = b + a;
        if (c1 > c2) return true;
        else return false;
    }
};
// @lc code=end

int main()
{
    Solution a;
    using VI = vector<int>;

    vector<int> a1{10, 2};
    cout << a.largestNumber(a1) << endl;

    a1 = vector<int>{824, 8247};
    cout << a.largestNumber(a1) << endl;

    a1 = VI{0, 0, 1};
    cout << a.largestNumber(a1) << endl;

    a1 = VI{0, 0, 0};
    cout << a.largestNumber(a1) << endl;

    a1 = VI{3, 30, 34};
    cout << a.largestNumber(a1) << endl;

    a1 = VI{
        9051,5526,2264,5041,1630,5906,6787,8382,4662,4532,6804,4710,4542,2116,7219,8701,8308,957,8775,4822,396,8995,8597,2304,8902,830,8591,5828,9642,7100,3976,5565,5490,1613,5731,8052,8985,2623,6325,3723,5224,8274,4787,6310,3393,78,3288,7584,7440,5752,351,4555,7265,9959,3866,9854,2709,5817,7272,43,1014,7527,3946,4289,1272,5213,710,1603,2436,8823,5228,2581,771,3700,2109,5638,3402,3910,871,5441,6861,9556,1089,4088,2788,9632,6822,6145,5137,236,683,2869,9525,8161,8374,2439,6028,7813,6406,7519
    };
    
    string res = "995998549642963295795569525905189958985890288238775871870185978591838283748308830827481618052787813771758475277519744072727265721971071006861683682268046787640663256310614560285906582858175752573156385565552654905441522852245213513750414822478747104662455545424532434289408839763963946391038663723370035134023393328828692788270926232581243924362362304226421162109163016131603127210891014";
    cout << (res == a.largestNumber(a1)) << endl;

    return 0;
}
