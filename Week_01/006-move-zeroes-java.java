class Solution {
    public void moveZeroes(int[] nums) {
        if (nums == null || nums.length <= 1) return;
        int insertPos = 0;
        for (int n : nums) {
            if (n != 0) nums[insertPos++] = n;
        }
        while (insertPos < nums.length) nums[insertPos++] = 0;
    }
}