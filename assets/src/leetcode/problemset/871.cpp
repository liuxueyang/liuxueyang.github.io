class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
	stations.push_back({target, 0});

	int sum = startFuel, res = 0, n = stations.size();
	priority_queue<int> p;
	for (int i = 0; i < n; ++i) {
		while (sum < stations[i][0] && !p.empty()) {
			sum += p.top();
			p.pop();
			++res;
		}

		if (sum < stations[i][0]) return -1;
		p.push(stations[i][1]);
	}

	return res;
    }
};
