class Solution {
public:
    string removeDuplicates(string S) {
    string sRes = "";
	for (const auto& c : S) {
		if (!sRes.empty() && sRes.back() == c)
			sRes.pop_back();
		else
			sRes.push_back(c);
	}
	return sRes;
    }
};