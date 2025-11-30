class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int target = 0;
        int n = nums.size();
        for(int& num : nums){
            target = (target + num) % p;
        }
        if(target == 0) return 0;
        int sum = 0;
        int minl = INT_MAX;
        unordered_map<int,int> map;map[0] = -1;
        for(int i = 0;i < n;i++){
            sum = (sum + nums[i]) % p;
            int need = (sum - target + p) % p;
            if(map.find(need) != map.end()){
                minl = min(minl,i - map[need]);
            }
            map[sum] = i;
        }
        return (minl == INT_MAX || minl == n) ? -1 : minl;
    }
};