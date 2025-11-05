class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        using ll = long long;
        using pii = pair<int,int>;
        ll sum = 0;
        vector<ll> result;
        auto cmp = [](const pii& a, const pii& b){
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        };
        unordered_map<int,int> map;
        multiset<pii,decltype(cmp)> rest,topX;
        auto balance = [&](){
            while((int)topX.size() > x){
                auto it = topX.begin();
                sum -= 1LL * (*it).first * (*it).second;
                rest.insert(*it);
                topX.erase(it);
            }
            while((int)topX.size() < x && !rest.empty()){
                auto it = --rest.end();
                sum += 1LL * (*it).first * (*it).second;
                topX.insert(*it);
                rest.erase(it);
            }
        };
        auto insert = [&](pii a){
            if(topX.empty() || cmp(*topX.begin(),a)){
                sum += 1LL * a.second * a.first;
                topX.insert(a);
            }
            else{
                rest.insert(a); 
            }
            balance();
        };
        auto erase = [&](pii a){
            if(topX.find(a) != topX.end()){
                sum -= 1LL * a.second * a.first;
                topX.erase(topX.find(a));
            }
            else{
                rest.erase(rest.find(a));
            }
            balance();
        };
        for(int i = 0;i < k;i++){
            if(map.find(nums[i]) != map.end()){
                erase({map[nums[i]],nums[i]});
            }
            map[nums[i]]++;
            insert({map[nums[i]],nums[i]});
        }
        result.push_back(sum);
        for(int i = k;i < nums.size();i++){
            if(map.find(nums[i - k]) != map.end()){
                erase({map[nums[i - k]],nums[i - k]});
            }
            if(--map[nums[i - k]] == 0){
                map.erase(nums[i - k]);
            }
            else{
                insert({map[nums[i - k]],nums[i - k]});
            }
            if(map.find(nums[i]) != map.end()){
                erase({map[nums[i]],nums[i]});
            }
            map[nums[i]]++;
            insert({map[nums[i]],nums[i]});
            result.push_back(sum);
        }
        return result;
    }
};