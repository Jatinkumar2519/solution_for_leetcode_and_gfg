class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> map;

        int left = 0;
        int maxL = 0;
        for(int i = 0;i < n;i++){

            map[nums[i]]++;
            while(map[nums[i]] > k){
                map[nums[left]]--;
                left++;
            }

            maxL = max(maxL,i - left + 1);
        }

        return maxL;
    }
};