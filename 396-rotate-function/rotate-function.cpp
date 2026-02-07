class Solution {
public:
    int maxRotateFunction(vector<int>& arr) {
        int n = arr.size();
        int total = accumulate(arr.begin(),arr.end(),0);
        
        for(int i = 0;i < n;i++){
            arr.push_back(arr[i]);
        }
        
        int sum = 0;
        for(int i = 0;i < n;i++){
            sum += arr[i] * i;
        }
        
        int maxv = sum;
        
        for(int i = n;i < 2*n;i++){
            int rest = total - arr[i - n];
            
            sum = sum - rest + (n - 1) * arr[i];
            
            maxv = max(maxv,sum);
        }
        
        return maxv;
    }
};