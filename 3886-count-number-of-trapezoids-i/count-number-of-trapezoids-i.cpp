class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int mod = 1'000'000'007;
        unordered_map<int,int> map;
        for(auto& point : points){
            map[point[1]]++;
        }
        vector<int> segment;
        for(auto& [_,count] : map){
            int comb = ((count * 1LL * (count - 1) ) / 2) % mod;
            segment.push_back(comb);
        }
        int n = segment.size();
        long long sum = 0;
        long long result = 0;
        vector<long long> prefsum(n);
        for(int i = n - 1;i >= 0;i--){
            sum = (sum + segment[i]) % mod;
            prefsum[i] = sum;
        }
        for(int i = 0;i < n - 1;i++){
            result = (result + (segment[i] * prefsum[i + 1]) % mod) % mod;
        }
        return result;
    }
};