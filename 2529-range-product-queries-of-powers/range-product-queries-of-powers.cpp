class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        vector<long long> arr;
        for(int i = 0;i < 32;i++){
            if(n & (1 << i)){
                arr.push_back(1 << i);
            }
        }
        vector<int> result;
        for(auto& query : queries){
            int mul = 1;
            for(int i = query[0];i <= query[1];i++){
                mul = (mul * arr[i]) % mod;
            }
            result.push_back(mul);
        }
        return result;
    }
};