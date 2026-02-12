class Solution {
public:
    int longestBalanced(string s) {
        int maxlen = 0;
        int n = s.length();
        for(int i = 0;i < n;i++){
            vector<int> freq(26,0);
            for(int j = i;j < n;j++){
                freq[s[j] - 'a']++;
                int check = -1;
                bool flag = true;
                for(int k = 0;k < 26;k++){
                    if(check == -1){
                        if(freq[k] > 0) check = freq[k];
                    }
                    else{
                        if(freq[k] > 0 && check != freq[k]){
                            flag = false;
                            break;
                        }
                    }
                }
                if(flag){
                    maxlen = max(maxlen,j - i + 1);
                }
            }
        }
        return maxlen;
    }
};