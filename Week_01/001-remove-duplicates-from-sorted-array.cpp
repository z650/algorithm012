class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int p = 0, q = 1;
        while (q < nums.size()) {
            if (nums[p] == nums[q]) q++;
            else nums[++p] = nums[q++];
        }
        return p + 1;
    }
};