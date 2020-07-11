class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insertPos = 0;
        for (int n : nums) {
            if (n != 0) nums[insertPos++] = n;
        }
        while (insertPos < nums.size()) nums[insertPos++] = 0;
    }      
};