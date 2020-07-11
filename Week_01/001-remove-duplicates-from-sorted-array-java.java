class Solution {
    public int removeDuplicates(int[] nums) {
        int p = 0, q = 1;
        while (q < nums.length) {
            if (nums[p] == nums[q]) q++;
            else nums[++p] = nums[q++];
        } 
        return p + 1;
    }
}