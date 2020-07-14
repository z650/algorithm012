class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       map<int, int> map;
       for (int n : nums) map[n]++;
       priority_queue<pair<int, int>> heap;
       for (auto kv : map) heap.push(make_pair(kv.second, kv.first));
       vector<int> res;
       for (int i = 0; i < k; i++) {
           res.push_back(heap.top().second);
           heap.pop();
       }
       return res;
    }
};