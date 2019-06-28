class Solution(object):
    def gardenNoAdj(self, N, paths):
        """
        :type N: int
        :type paths: List[List[int]]
        :rtype: List[int]
        """
        res = [0] * N
        G = [[] for i in range(N)]
        for x, y in paths:
            G[x - 1].append(y - 1)
            G[y - 1].append(x - 1)
        for i in range(N):
            s = {1, 2, 3, 4} - {res[j] for j in G[i]}
            print "s =", s, "i =", i
            res[i] = s.pop()
        return res


if __name__ == '__main__':
    a = Solution()
    print a.gardenNoAdj(4, [[1,2],[2,3],[3,4],[1,3],[2,4]])
