class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.length();
        int mod = 1e9 + 7;
        vector<int> nums(n), sums(n), lengths(n), power(n + 1);

        power[0] = 1;
        for (int i = 1; i <= n; i++) {
            power[i] = (power[i - 1] * 1LL * 10) % mod;
        }

        int num = 0;
        int sum = 0;
        int len = 0;
        
        for(int i = 0;i < n;i++){
            if(s[i] != '0'){
                num = ((num * 1LL * 10) + (s[i] - '0')) % mod;
                sum += (s[i] - '0');
                len++;
            }

            nums[i] = num;
            sums[i] = sum;
            lengths[i] = len;
        }

        vector<int> result;
        for(auto& query : queries){
            int l = query[0];
            int r = query[1];

            int s = sums[r];
            int num = nums[r];
            int p = lengths[r];

            if(l > 0){
                s -= sums[l - 1];
                p -= lengths[l - 1];
                num = (num - (nums[l - 1] * 1LL * power[p]) % mod + mod) % mod;
            }
            
            num = (num * 1LL * s) % mod;
            result.push_back(num);
        }

        return result;
    }
};