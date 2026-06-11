class Solution {
public:
    vector<int> maxNumber(vector<int>& arr1, vector<int>& arr2, int k) {
        int n = arr1.size();
        int m = arr2.size();

        vector<int> maxv;
        for (int len = 0; len <= k; len++) {
            if (len > n || k - len > m)
                continue;

            stack<int> s;

            int del = n - len;
            for (int i = 0; i < n; i++) {
                while (!s.empty() && del > 0 && s.top() < arr1[i]) {
                    s.pop();
                    del--;
                }
                s.push(arr1[i]);
            }

            vector<int> temp1;

            while (!s.empty() && del > 0) {
                s.pop();
                del--;
            }
            while (!s.empty()) {
                temp1.push_back(s.top());
                s.pop();
            }

            reverse(temp1.begin(), temp1.end());

            del = m - (k - len);
            for (int i = 0; i < m; i++) {
                while (!s.empty() && del > 0 && s.top() < arr2[i]) {
                    s.pop();
                    del--;
                }
                s.push(arr2[i]);
            }

            vector<int> temp2;

            while (!s.empty() && del > 0) {
                s.pop();
                del--;
            }
            while (!s.empty()) {
                temp2.push_back(s.top());
                s.pop();
            }

            reverse(temp2.begin(), temp2.end());

            auto compareRest = [&](int i, int j) -> bool {
                while (i < len && j < (k - len)) {
                    if (temp1[i] > temp2[j]) {
                        return true;
                    } else if (temp1[i] < temp2[j]) {
                        return false;
                    }
                    i++;
                    j++;
                }

                return j == (k - len);
            };

            vector<int> temp;
            int i = 0, j = 0;

            while (i < len && j < (k - len)) {
                if (temp1[i] > temp2[j]) {
                    temp.push_back(temp1[i++]);
                } else if (temp1[i] < temp2[j]) {
                    temp.push_back(temp2[j++]);
                } else {
                    if (compareRest(i, j)) {
                        temp.push_back(temp1[i++]);
                    } else {
                        temp.push_back(temp2[j++]);
                    }
                }
            }

            while (i < len) {
                temp.push_back(temp1[i++]);
            }

            while (j < (k - len)) {
                temp.push_back(temp2[j++]);
            }

            maxv = max(maxv, temp);
        }

        return maxv;
    }
};