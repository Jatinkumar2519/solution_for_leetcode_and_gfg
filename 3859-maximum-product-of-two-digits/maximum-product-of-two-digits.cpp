class Solution {
public:
    int maxProduct(int n) {
        string num = to_string(n);
        sort(num.begin(),num.end());
        int res = (num[num.length() - 2] - '0') * (num[num.length() - 1] - '0');
        return res;
    }
};