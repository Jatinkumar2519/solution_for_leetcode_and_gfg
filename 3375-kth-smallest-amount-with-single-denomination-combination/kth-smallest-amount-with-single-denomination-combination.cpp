class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {

        int n = coins.size();
        using ll = long long;

        auto getLCM = [&](vector<int>& arr)->ll{

            unordered_map<int,int> map;

            for(int num : arr){

                for(int d = 2;d * d <= num;d++){

                    int p = 0;

                    while(num % d == 0){
                        num /= d;
                        p++;
                    }

                    map[d] = max(map[d],p);
                }

                if(num > 1){
                    map[num] = max(map[num],1);
                }
            }

            ll lcm = 1;
            for(auto [num,p] : map){
                lcm = lcm * pow(num,p);
            }

            return lcm;
        };

        map<vector<int>,ll> map;
        for(int mask = 1;mask < (1 << n);mask++){
            vector<int> nums;

            for(int b = 0;b < n;b++){
                if(mask & (1 << b)){
                    nums.push_back(coins[b]);
                }
            }

            map[nums] = getLCM(nums);
        }
        
        function<bool(ll)> feasible = [&](ll mid)->bool{

            ll count = 0;

            for(int mask = 1;mask < (1 << n);mask++){
                int len = 0;
                vector<int> nums;

                for(int b = 0;b < n;b++){
                    if(mask & (1 << b)){
                        nums.push_back(coins[b]);
                        len++;
                    }
                }

                ll lcm = map[nums];

                if(len % 2){
                    count += mid / lcm;
                }
                else{
                    count -= mid / lcm;
                }
            }

            return count >= k;
        };

        ll left = 1;
        ll right = 1e11;
        ll res = -1;

        while(left <= right){
            ll mid = left + (right - left)/2;

            if(feasible(mid)){
                res = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return res;
    }
};