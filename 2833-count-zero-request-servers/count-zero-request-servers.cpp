class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();
        sort(logs.begin(),logs.end(),[&](auto& a,auto& b){
            return a[1] < b[1];
        });

        int l = queries.size();
        vector<pair<int,int>> temp(l);
        for(int i = 0;i < l;i++){
            temp[i] = {queries[i], i};
        }

        sort(temp.begin(), temp.end());

        int left = 0;
        int right = 0;
        int count = 0;

        vector<int> freq(n + 1);
        vector<int> result(l);

        for(auto [q, idx] : temp){

            while(right < m && logs[right][1] <= q){
                
                count += (freq[logs[right][0]]++ == 0);
                right++;
            }
            while(left < m && logs[left][1] < q - x){
                
                count -= (--freq[logs[left][0]] == 0);
                left++;
            }

            result[idx] = n - count;
        }

        return result;
    }
};