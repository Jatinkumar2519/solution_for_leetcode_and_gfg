class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        const int mod = 1e9 + 7;
        int x = 0;
        for(auto& ch : corridor) x += (ch == 'S');
        vector<bool> suffix(n,false);
        suffix[n - 1] = (corridor[n - 1] == 'S');
        for(int i = n - 2;i >= 0;i--){
            suffix[i] = (corridor[i] == 'S') || suffix[i + 1];
        }
        if(x == 0 || x % 2 != 0) return 0;
        int count = 1;
        bool flag = false;
        for(int i = 0;i < n;){
            if(i + 1 < n && !suffix[i + 1]) break;
            if(corridor[i] == 'S'){
                if(!flag){
                    i++;
                    flag = true;
                }
                else{
                    int p = 1;i++;
                    while(i < n && corridor[i] == 'P'){
                        p++;i++;
                    }
                    count = (count * 1LL * p) % mod;
                    flag = false;
                }
            }
            else{
                i++;
            }
        }
        return count;
    }
};