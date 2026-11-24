class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();

        int maxl = 0;
        int maxE = *max_element(nums.begin(), nums.end()) + 1;

        for (int i = 0; i + 1 < n; i++) {

            vector<int> ForLCM(maxE, 0), ForGCD(maxE, INT_MAX), total(maxE, 0);

            for (int j = i; j < n; j++) {

                vector<int> temp(maxE,0);
                int num = nums[j];

                for (int d = 2; d <= num; d++) {

                    int f = 0;
                    while (num % d == 0) {

                        f++; num /= d;
                    }

                    temp[d] = f;
                    total[d] += f;
                }

                if(num > 1){

                    temp[num] = 1;
                    total[num] += 1;
                }

                for (int i = 2; i < maxE; i++) {
                    ForGCD[i] = min(ForGCD[i], temp[i]);
                    ForLCM[i] = max(ForLCM[i], temp[i]);
                }

                bool flag = true;
                for (int i = 2; i < maxE; i++) {

                    if(total[i] != ForGCD[i] + ForLCM[i]){
                        flag = false;
                        break;
                    }
                }

                int len = j - i + 1;
                if(flag){
                    maxl = max(maxl, len);
                }
            }
        }

        return maxl;
    }
};