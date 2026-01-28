class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> arr(256,0);
        for(auto& ch : t){
            arr[ch]++;
        }

        auto feasible = [&](int len){
            vector<int> freq(256,0);

            auto check = [&](){
                for(int i = 0;i < 256;i++){
                    if(arr[i] > freq[i]) return false;
                }
                return true;
            };

            for(int i = 0;i < len;i++){
                freq[s[i]]++;
            }
            if(check()) return 0;

            for(int i = len;i < s.length();i++){
                freq[s[i - len]]--;
                freq[s[i]]++;
                if(check()) return i - len + 1;
            }
            return -1;
        };

        int len = -1;
        int start = -1;
        int left = t.length();
        int right = s.length();

        while(left <= right){
            int mid = (left + right)/2;
            
            int ans = feasible(mid);
            if(ans != -1){
                len = mid;
                start = ans;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        if(start == -1) return "";
        return s.substr(start,len);
    }
};