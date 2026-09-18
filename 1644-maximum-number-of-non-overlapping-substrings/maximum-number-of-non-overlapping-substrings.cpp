class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> last(26,-1),first(26,-1);

        for(int i = 0;i < n;i++) last[s[i] - 'a'] = i;
        for(int i = n - 1;i >= 0;i--) first[s[i] - 'a'] = i;

        for(int ch = 0;ch < 26;ch++){
            if(last[ch] == -1) continue;

            for(int i = first[ch];i <= last[ch];i++){
                
                if(first[ch] <= first[s[i] - 'a'] && 
                    last[s[i] - 'a'] <= last[ch]) continue;

                first[ch] = min(first[ch], first[s[i] - 'a']);
                last[ch] = max(last[ch], last[s[i] - 'a']);

                i = first[ch];
            }
        }

        vector<pair<int,int>> arr;
        for(int i = 0;i < 26;i++){
            if(last[i] == -1) continue;

            arr.push_back({first[i],last[i]});
        }

        sort(arr.begin(),arr.end(),[&](auto& a,auto& b){
            if(a.second == b.second) return a.first > b.first;
            return a.second < b.second;
        });

        vector<string> result;
        int end = -1;

        for(auto& [x,y] : arr){
            if(end == -1 || end < x){
                result.push_back(s.substr(x,y - x + 1));
                end = y;
            }
        }

        return result;
    }
};