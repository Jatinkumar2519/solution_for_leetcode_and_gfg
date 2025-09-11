class Solution {
public:
    string sortVowels(string s) {
        int n = s.length();
        vector<char> chars;
        vector<int> indices;
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        for(int i = 0;i < n;i++){
            if(vowels.count(s[i])){
                indices.push_back(i);
                chars.push_back(s[i]);
            }
        }
        sort(chars.begin(),chars.end());
        for(int i = 0;i < indices.size();i++){
            s[indices[i]] = chars[i];
        }
        return s;
    }
};