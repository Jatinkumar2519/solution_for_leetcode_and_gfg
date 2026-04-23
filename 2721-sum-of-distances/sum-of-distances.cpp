class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        using ll = long long;

        unordered_map<int,vector<ll>> map1,map2;
        int n = nums.size();

        for(int i = 0;i < n;i++){
            map1[nums[i]].push_back(i);

            if(map2[nums[i]].empty()){
                map2[nums[i]].push_back(i);
            }
            else{
                map2[nums[i]].push_back(map2[nums[i]].back() + i);
            }
        }
        
        vector<ll> result(n,0);
        for(int i = 0;i < n;i++){

            int num = nums[i];
            int m = map1[num].size();

            int indx = 0;
            int left = 0;
            int right = m - 1;

            while(left <= right){
                int mid = (left + right)/2;

                if(map1[num][mid] == i){
                    indx = mid;
                    break;
                }
                if(map1[num][mid] < i){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }

            result[i] += (indx * 1LL * i) * 1LL - ((indx - 1) >= 0 ? map2[num][indx - 1] : 0);
            result[i] += (map2[num][m - 1] - map2[num][indx]) - ((m - indx - 1) * 1LL * i);
            
        }

        return result;
    }
};