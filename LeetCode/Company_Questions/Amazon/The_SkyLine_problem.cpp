class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multimap<int, int> coords;
		for (const vector<int> & building : buildings) {
			coords.emplace(building[0], building[2]);
			coords.emplace(building[1], -building[2]);
		}

		multiset<int> heights = { 0 };
		vector<vector<int>> corners;
		int x = -1;
		int y = 0;
		for (const pair<int, int> & p : coords) {
			if ((x >= 0) && (p.first != x) && (corners.empty() || (corners[corners.size()-1][1] != y))) {
				corners.push_back({x, y});
			}

			if (p.second >= 0) {
				heights.insert(p.second);
			}
			else {
				heights.erase(heights.find(-p.second));
			}

			x = p.first;
			y = *heights.rbegin();
		}
		
		if (!corners.empty()) {
			corners.push_back({x, 0});
		}
		
		return corners;
    }
};