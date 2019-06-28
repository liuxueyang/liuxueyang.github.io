class Solution {
public:
  int lastStoneWeight(vector<int>& stones) {
    
    if (stones.size() == 1) return stones[0];
    while (stones.size() >= 2) {
      sort(stones.begin(), stones.end());
      int len=stones.size();
      int r = stones[len-1] - stones[len-2];
      stones.pop_back();
      stones.pop_back();
      if (r) stones.push_back(r);
    }
    if (stones.size() == 1) return stones[0];
    return 0;
  }
};
