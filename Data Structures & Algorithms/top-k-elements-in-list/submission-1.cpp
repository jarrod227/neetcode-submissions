class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        for (int num : nums) {
            count[num]++;
        }

        vector<int> ans;
        while (k > 0) {
            int max_freq = 0;
            int max_id = 0;

            for (auto& pair : count) {
                if (pair.second > max_freq) {
                    max_freq = pair.second;
                    max_id = pair.first;
                }
            }

            ans.push_back(max_id);
            count.erase(max_id);
            k--;
        }

        return ans;
    }
};