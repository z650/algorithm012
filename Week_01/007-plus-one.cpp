class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >=0 ; i--) {
            digits[i] = (digits[i] + 1) % 10;
            if (digits[i] != 0) return digits;
        }
        digits = vector<int>(digits.size() + 1, 0);
        digits[0] = 1;
        return digits;
    }
};