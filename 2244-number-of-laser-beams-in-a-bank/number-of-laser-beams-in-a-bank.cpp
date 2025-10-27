class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int sum = 0;
        int prev = 0;
        int n = bank.size();
        int m = bank[0].size();
        for(int i = 0;i < n;i++){
            int count = 0;
            for(int j = 0;j < m;j++){
                count += (bank[i][j] == '1');
            }
            if(count > 0){
                sum += prev * count;
                prev = count;
            }
        }
        return sum;
    }
};