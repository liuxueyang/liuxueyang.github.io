//给你一个points 数组，表示 2D 平面上的一些点，其中 points[i] = [xi, yi] 。 
//
// 连接点 [xi, yi] 和点 [xj, yj] 的费用为它们之间的 曼哈顿距离 ：|xi - xj| + |yi - yj| ，其中 |val| 表示 
//val 的绝对值。 
//
// 请你返回将所有点连接的最小总费用。只有任意两点之间 有且仅有 一条简单路径时，才认为所有点都已连接。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
//输出：20
//解释：
//
//我们可以按照上图所示连接所有点得到最小总费用，总费用为 20 。
//注意到任意两个点之间只有唯一一条路径互相到达。
// 
//
// 示例 2： 
//
// 
//输入：points = [[3,12],[-2,5],[-4,1]]
//输出：18
// 
//
// 示例 3： 
//
// 
//输入：points = [[0,0],[1,1],[1,0],[-1,1]]
//输出：4
// 
//
// 示例 4： 
//
// 
//输入：points = [[-1000000,-1000000],[1000000,1000000]]
//输出：4000000
// 
//
// 示例 5： 
//
// 
//输入：points = [[0,0]]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= points.length <= 1000 
// -106 <= xi, yi <= 106 
// 所有点 (xi, yi) 两两不同。 
// 
// Related Topics 并查集 
// 👍 60 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;
using VI = vector<int>;
using VS = vector<string>;
using LL = long long;

int fa[1009], sz[1009];

int Find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = Find(fa[x]);
}


class Solution {
public:
    LL res;
    vector <VI> v;

    LL dis(VI &a, VI &b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    void Union(int x, int y) {
        int rx = Find(x), ry = Find(y);
        if (rx == ry) return;
        if (sz[rx] < sz[ry]) swap(rx, ry);
        fa[ry] = rx;
        sz[rx] += sz[ry];
    }

    int minCostConnectPoints(vector <vector<int>> &a) {
        int n = a.size();
        v = a;
        for (int i = 0; i < n; ++i) {
            sz[i] = 1;
            fa[i] = i;
        }
        res = 0;
        for (int i = 0; i < n; ++i) {
            LL mi = 1e12 + 10, k = -1;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int tmp = dis(a[i], a[j]);
                if (tmp < mi) {
                    mi = tmp;
                    k = j;
                }
            }
            if (k == -1) {
                continue;
            }
            int ri = Find(i), rk = Find(k);
            if (ri != rk) {
                Union(i, k);
                printf("i=%d, k=%d, mi=%d\n", i, k, mi);
                res += mi;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
