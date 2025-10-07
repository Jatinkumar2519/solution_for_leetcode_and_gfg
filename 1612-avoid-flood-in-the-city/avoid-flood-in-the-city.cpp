class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> set;
        map<int,int> map;
        int n = rains.size();
        vector<int> result(n,1);
        for(int i = 0;i < n;i++){
            if(rains[i] == 0){
                set.insert(i);
            }
            else{
                result[i] = -1;
                if(map.count(rains[i])){
                    auto it = set.lower_bound(map[rains[i]]);
                    if(it == set.end()) return {};
                    result[*it] = rains[i];
                    set.erase(it);
                }
                map[rains[i]] = i;
            }
        }
        return result;
    }
};