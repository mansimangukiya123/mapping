class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         std::unordered_map<int, int> freq;
        
        
        for (int num : nums) {
            freq[num]++;
        }

        
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> minHeap;
        
        for (const auto& [num, count] : freq) {
            minHeap.push({count, num});
            if (minHeap.size() > k) {
                minHeap.pop();  
            }
        }

        
        std::vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
        
    }
};
//https://leetcode.com/problems/top-k-frequent-elements/submissions/1596278382/
