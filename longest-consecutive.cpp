class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         if (nums.empty()) return 0; 
        
       
        unordered_set<int> num_set(nums.begin(), nums.end());
        int longest = 0;

        for (int num : num_set) {
            
            if (num_set.find(num - 1) == num_set.end()) {
                int current_num = num;
                int current_streak = 1;

                
                while (num_set.find(current_num + 1) != num_set.end()) {
                    current_num++;
                    current_streak++;
                }

                
                longest = max(longest, current_streak);
            }
        }

        return longest;
}
};
//https://leetcode.com/problems/longest-consecutive-sequence/submissions/1596273080/
