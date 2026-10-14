class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> seen;
        int i = 0;
        int front = 0;
        while (i < nums.size()) {
            if (seen[nums[i]] > 0) {
                return true;
            }
            seen[nums[i]]++;
            if (i-front >= k) {
                seen[nums[front]]--;
                front++;
            }
            i++;
        }
        return false;
    }
};