class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();
        vector<int> prefix(n,INT_MAX),suffix(n,INT_MAX);

        unordered_map<int,int> map1, map2;

        map1[0] = -1;
        int sum = 0;

        for(int i = 0;i < n;i++){

            sum += arr[i];
            int x = sum - target;

            if(map1.find(x) != map1.end()){
                prefix[i] = i - map1[x];
            }

            if(i > 0){
                prefix[i] = min(prefix[i - 1], prefix[i]);
            }
            map1[sum] = i;
        }

        map2[0] = n;
        sum = 0;

        for(int i = n - 1;i >= 0;i--){

            sum += arr[i];
            int x = sum - target;

            if(map2.find(x) != map2.end()){
                suffix[i] = map2[x] - i;
            }

            if(i < n - 1){
                suffix[i] = min(suffix[i], suffix[i + 1]);
            }
            map2[sum] = i;
        }

        int minv = INT_MAX;
        for(int i = 0;i + 1 < n;i++){

            if(prefix[i] == INT_MAX || suffix[i + 1] == INT_MAX) continue;
            minv = min(minv, prefix[i] + suffix[i + 1]);
        }

        return (minv == INT_MAX) ? -1 : minv;
    }
};