class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res;
        for(auto& str : words){
            int sum = 0;
            for(auto& ch : str){
                sum += weights[ch - 'a'];
            }
            sum %= 26;
            
            res.push_back((char)('a' + (25 - sum)));
        }

        return res;
    }
};