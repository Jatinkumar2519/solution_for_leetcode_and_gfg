class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());

        if(hFences[0] != 1) hFences.insert(hFences.begin(),1);
        if(vFences[0] != 1) vFences.insert(vFences.begin(),1);
        if(hFences.back() != m) hFences.push_back(m);
        if(vFences.back() != n) vFences.push_back(n);

        for(auto& num : hFences) cout<< num << ' ';
        cout<< endl;
        for(auto& num : vFences) cout<< num << ' ';

        unordered_map<int,int> diffs;
        for(int i = 0;i < hFences.size();i++){
            for(int j = i + 1;j < hFences.size();j++){
                int diff = hFences[j] - hFences[i];
                if(diffs[diff] == 0) diffs[diff]++;
            }
        }

        for(int i = 0;i < vFences.size();i++){
            for(int j = i + 1;j < vFences.size();j++){
                int diff = vFences[j] - vFences[i];
                if(diffs[diff] == 1) diffs[diff]++;
            }
        }

        long long maxv = 0;
        
        for(auto& [len,cnt] : diffs){
            if(cnt == 2)
                maxv = max(maxv,1LL * len);   
        }

        if(maxv == 0) return -1;
        int mod = 1e9 + 7;

        return (maxv * maxv % mod) % mod;
    }
};