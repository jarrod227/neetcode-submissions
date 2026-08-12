class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        for (int num = 0; num < nums.size(); num++){
            count[nums[num]]++;
        }

        vector<int> ans;
        
        while (k > 0){
            int max = -2000;
            int max_id = 0;
            for (auto& pair : count){
                if (pair.second > max){
                    max = pair.second;
                    max_id = pair.first;
                }
            }
            k--;
            count.erase(max_id);
            ans.push_back(max_id);
        };
        
        return ans;
    }
};
