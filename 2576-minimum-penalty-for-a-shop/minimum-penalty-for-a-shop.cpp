class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> prefix1(n,0);
        vector<int> prefix2(n,0);
        prefix1[0] = (customers[0] == 'Y');
        prefix2[0] = (customers[0] == 'N');
        for(int i = 1;i < n;i++){
            prefix1[i] = prefix1[i - 1] + (customers[i] == 'Y');
            prefix2[i] = prefix2[i - 1] + (customers[i] == 'N');
        }
        int mint = 0;
        int loss = INT_MAX;
        for(int i = 0;i < n;i++){
            int left = (i == 0) ? 0 : prefix2[i - 1];
            int right = (i == 0) ? prefix1.back() : prefix1.back() - prefix1[i - 1];
            if(loss > left + right){
                mint = i;
                loss = left + right;
            }
        }
        if(loss > prefix2.back()){
            mint = n;
        }
        return mint;
    }
};