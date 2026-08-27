class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();

        int freq[26] = {0};
        for(auto& ch : s) freq[ch - 'a']++;
        
        string curr;
        function<bool(int,bool)> solve = [&](int idx,bool tight){
            if(idx == n) return !tight;

            char ch = target[idx];

            if(tight){
                for(char ch = target[idx]; ch <= 'z'; ch++){

                    if(!freq[ch - 'a']) continue;

                    freq[ch - 'a']--;
                    curr.push_back(ch);

                    if(solve(idx + 1,tight && (target[idx] == ch))) return true;

                    freq[ch - 'a']++;
                    curr.pop_back();
                }
            }
            else{
                char ch = '?';
                for(ch = 'a';ch <= 'z';ch++){
                    if(freq[ch - 'a']){
                        break;
                    }
                }

                if(ch != '?'){

                    freq[ch - 'a']--;
                    curr.push_back(ch);

                    if(solve(idx + 1,false)) return true;

                    freq[ch - 'a']--;
                    curr.pop_back();
                }
            }

            return false;
        };

        if(!solve(0,true)) return "";
        return curr;
    }
};