class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for (int i = 0;i < 12; i++) {
            for (int j = 0;j < 60; j++) {
                int len = __builtin_popcount(j) + __builtin_popcount(i);
                
                if (len == turnedOn) {
                    string hrs = to_string(i);
                    string mint = to_string(j);

                    if (j < 10) {
                        mint = '0' + mint;
                    }

                    string time = hrs + ":" + mint;
                    result.push_back(time);
                }
            }
        }
        return result;
    }
};