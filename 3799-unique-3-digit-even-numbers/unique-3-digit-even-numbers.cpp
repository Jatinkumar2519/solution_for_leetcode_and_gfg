class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count = 0;
        int n = digits.size();
        unordered_set<int> unique;

        for(int i = 0;i < n;i++){
            int num1 = digits[i];
            if(num1 == 0) continue;
            
            for(int j = 0;j < n;j++){
                if(i == j) continue;
                int num2 = digits[j];

                for(int k = 0;k < n;k++){
                    if(i == k || j == k) continue;
                    int num3 = digits[k];

                    int num = ((num1 * 10 + num2) * 10) + num3;
                    if(num % 2 == 0 && unique.count(num) == 0){
                        unique.insert(num);
                        count++;
                    } 
                }
            }
        }

        return count;
    }
};