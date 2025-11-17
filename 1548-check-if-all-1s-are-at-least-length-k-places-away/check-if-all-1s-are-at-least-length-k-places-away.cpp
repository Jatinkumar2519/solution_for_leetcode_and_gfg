class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int len = -1;
        for(int& num : nums){
            if(num == 1){
                if(len != -1 && len < k) return false;
                len = 0;
            }
            else{
                if(len != -1)
                    len++;
            }
        }
        return true;
    }
};