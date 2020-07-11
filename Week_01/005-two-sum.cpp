class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int key = target - nums[i];
            if (map.end() != map.find(key)) {
                res.push_back(map[key]);
                res.push_back(i);
                return res;
            }
            map[nums[i]] = i;
        }
        return res;
    }
};