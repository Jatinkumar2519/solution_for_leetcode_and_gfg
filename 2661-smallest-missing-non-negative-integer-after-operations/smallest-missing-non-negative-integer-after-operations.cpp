class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> map;
        for(int i = 0;i < nums.size();i++){
            map[((nums[i] % value) + value) % value]++;
        }
        int prev = 0;
        int num = 0;
        while(true){
            prev = prev % value;
            if(map[prev] <= 0) return num;
            map[prev]--;
            prev += 1;
            num++;
        }
        return num;
    }
};