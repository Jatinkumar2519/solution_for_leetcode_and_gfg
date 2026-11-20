class Solution {
public:
    string multiply(string a, string b) {
        int n = a.length();
        int m = b.length();

        vector<vector<int>> mat(m, vector<int>(n + m));

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        for (int i = 0; i < m; i++) {

            int carry = 0;
            int x = b[i] - '0';
            for (int j = 0; j < n; j++) {

                int y = a[j] - '0';
                int p = x * y + carry;

                mat[i][j + i] = p % 10;
                carry = p / 10;
            }

            if (carry) {
                mat[i][n + i] = carry;
            }
        }

        string res;
        int carry = 0;

        for (int j = 0; j < m + n; j++) {
            
            int sum = carry;
            for (int i = 0; i < m; i++) {
                sum += mat[i][j];
            }

            res.push_back(to_string(sum % 10)[0]);
            carry = sum / 10;
        }

        // reverse(res.begin(), res.end());
        while (!res.empty() && res.back() == '0')
            res.pop_back();
        reverse(res.begin(), res.end());

        return res.empty() ? "0" : res;
    }
};