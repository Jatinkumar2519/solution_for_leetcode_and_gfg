class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxv = 0;
        unordered_map<int,int> mapp;
        for(int num : nums){
            mapp[num]++;
            maxv = max(maxv,mapp[num]);
        }
        int num = 0;
        for(auto& [_,freq] : mapp){
            if(freq == maxv){
                num += freq;
            }
        }
        return num;
    }
};