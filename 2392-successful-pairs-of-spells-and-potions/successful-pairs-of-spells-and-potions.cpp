class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> result(n);
        sort(potions.begin(),potions.end());
        for(int i = 0;i < n;i++){
            int res = m;
            int left = 0;
            int right = m - 1;
            while(left <= right){
                int mid = (left + right)/2;
                if((long)potions[mid] * (long)spells[i] >= success){
                    res = mid;
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            result[i] = m - res;
        }
        return result;
    }
};