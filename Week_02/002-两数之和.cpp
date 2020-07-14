class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> dict;
        if (nums.size() < 2) return res;
        for(int i = 0; i < nums.size(); i++) {
            int key = target - nums[i];
            if (dict.find(key) != dict.end()) return vector<int>{i, dict[key]};
            else dict[nums[i]] = i;
        }
        return res;
    }
};