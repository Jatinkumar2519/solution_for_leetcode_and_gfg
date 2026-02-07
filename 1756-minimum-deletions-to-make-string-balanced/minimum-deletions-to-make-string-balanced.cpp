class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> prefix(n,0),suffix(n,0);

        int sum = 0;
        for(int i = 0;i < n;i++){
            sum += (s[i] == 'b');
            prefix[i] = sum;
        }

        sum = 0;
        for(int i = n - 1;i >= 0;i--){
            sum += (s[i] == 'a');
            suffix[i] = sum;
        }

        int minv = 1e5;
        for(int i = 0;i < n;i++){
            int left = (i - 1 >= 0) ? prefix[i - 1] : 0;
            int right = (i + 1 < n) ? suffix[i + 1] : 0;
            minv = min({minv,left + right});
        }

        return minv;
    }
};