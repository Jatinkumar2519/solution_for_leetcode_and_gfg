class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length() < k) return false;
        
        unordered_set<int> nums;

        int num = 0;
        for(int i = 0;i < k;i++){
            num <<= 1;
            num = (num | (s[i] - '0'));
        }
        nums.insert(num);

        for(int i = k;i < s.length();i++){

            num <<= 1;

            num = (num & (~(1 << k)));
            num = (num | (s[i] - '0'));

            nums.insert(num);
        }

        return nums.size() == pow(2,k);
    }
};