class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int maxv = INT_MIN;
        int n = energy.size();
        vector<int> suff(n);
        for(int i = n - k;i < n;i++){
            suff[i] = energy[i];
            maxv = max(maxv,suff[i]);
        }
        for(int i = n - k - 1;i >= 0;i--){
            suff[i] = suff[i + k] + energy[i];
            maxv = max(maxv,suff[i]);
        }
        return maxv;
    }
};