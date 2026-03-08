class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> set;

        auto getNum = [&](string& bin){
            int num = 0;
            int n = bin.length();

            for(int i = n - 1;i >= 0;i--){
                if(bin[i] == '1')
                    num = (num | (1 << (n - i - 1)));
            }

            return num;
        };

        for(auto& bin : nums){
            int num = getNum(bin);
            set.insert(num);
        }

        int start = 0;
        while(set.count(start)) start++;

        string bin;
        int n = nums[0].length();

        for(int i = 0;i < n;i++){
            if(start & (1 << i)){
                bin.push_back('1');
            }
            else{
                bin.push_back('0');
            }
        }
        
        reverse(bin.begin(),bin.end());
        return bin;
    }
};