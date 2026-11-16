class Solution {
public:
    string digitSum(string& s, int k) {
        int n = s.length();
        if(n <= k) return s;

        string str;
        int sum = 0;

        for(int i = 0;i < n;i++){
            if(i % k == 0 && i > 0){
                str += to_string(sum);
                sum = 0;
            }
            sum += (s[i] - '0');
        }
        str += to_string(sum);

        return digitSum(str, k);
    }
};