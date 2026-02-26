class Solution {
public:
    int numSteps(string s) {
        
        int count = 0;

        while(s.length() > 1){
            if(s.back() == '0'){
                s.pop_back();
            }
            else{
                int n = s.length();

                bool flag = false;
                for(int i = n - 1;i >= 0;i--){
                    if(s[i] == '0'){
                        s[i] = '1';
                        for(int j = i + 1;j < n;j++){
                            s[j] = '0';
                        }
                        flag = true;
                        break;
                    }
                }

                if(!flag){
                    s = '1' + string(s.length(),'0');
                }
            }
            count++;
        }
        return count;
    }
};