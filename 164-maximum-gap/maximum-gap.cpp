class Solution {
public:
    int maximumGap(vector<int>& nums) {
        map<int,int> map;
        for(int num : nums){
            map[num]++;
        }
        int maxv = 0;
        int prev = -1;
        for(auto& [num,_] : map){
            if(prev != -1){
                maxv = max(maxv,num - prev);
            }
            prev = num;
        }
        return maxv;
    }
};