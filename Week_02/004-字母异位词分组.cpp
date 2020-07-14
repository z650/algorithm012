class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> map;
        vector<vector<string>> res;
        for (string one : strs) {
            string unsort_one = one;
            sort(one.begin(), one.end());
            if (map.find(one) != map.end()) {
                map[one].push_back(unsort_one);
            } else {
                map[one] = vector<string>{unsort_one};
            }
        }
        for (auto kv : map) res.push_back(kv.second);
        return res;
    }
};