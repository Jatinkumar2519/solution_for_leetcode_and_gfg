class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int prev = INT_MIN;
        int count = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int& num : nums){
            int curr = min(max(num - k,prev + 1),num + k);
            if(prev < curr){
                count++;
                prev = curr;
            }
        }
        return count;
    }
};