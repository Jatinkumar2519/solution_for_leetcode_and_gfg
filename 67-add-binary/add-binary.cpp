class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int n = a.length();
        int m = b.length();

        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        while(a.length() > b.length()) b.push_back('0');
        while(a.length() < b.length()) a.push_back('0');

        int carry = 0;
        n = max(n,m);

        for(int i = 0;i < n;i++){
            int b1 = (a[i] - '0');
            int b2 = (b[i] - '0');

            int sum = carry ^ b1 ^ b2;
            carry = (b1 & b2) | (carry & (b1 ^ b2));

            res.push_back(to_string(sum)[0]);
        }
        if(carry){
            res.push_back('1');
        }

        reverse(res.begin(),res.end());
        return res;
    }
};