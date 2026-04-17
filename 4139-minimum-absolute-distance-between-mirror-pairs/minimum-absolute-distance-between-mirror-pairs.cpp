class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();

        auto rev = [](int num){
            int res = 0;
            while(num > 0){
                res = res * 10 + num % 10;
                num = num / 10;
            }

            return res;
        };

        int minv = INT_MAX;

        unordered_map<int,int> map;
        for(int i = 0;i < n;i++){
            int num = nums[i];
            

            if(map.find(num) != map.end()){
                minv = min(minv,i - map[num]);
            }

            // while(nums[i] % 10 == 0) nums[i] /= 10;
            map[rev(nums[i])] = i;
        }

        return (minv == INT_MAX ? -1 : minv);
    }
};