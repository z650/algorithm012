class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int bucket[26] = {0};
        for (char c : s) bucket[c - 'a']++;
        for (char c : t) bucket[c - 'a']--;
        for (int i : bucket) {
            if (i != 0) return false;
        }
        return true;
    }
};