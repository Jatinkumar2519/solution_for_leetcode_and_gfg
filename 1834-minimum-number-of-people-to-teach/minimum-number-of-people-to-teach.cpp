class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        set<int> set;
        for(auto& temp : friendships){
            map<int,int> map;
            bool flag = false;
            for(int& l : languages[temp[0] - 1]){
                map[l] = 1;
            }
            for(int& l : languages[temp[1] - 1]){
                if(map[l]){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                set.insert(temp[0]-1);
                set.insert(temp[1]-1);
            }
        }
        int maxv = 0;
        vector<int> cnt(n + 1,0);
        for(auto f : set){
            for(int& l : languages[f]){
                cnt[l]++;
                maxv = max(maxv,cnt[l]);
            }
        }
        return set.size() - maxv;
    }
};