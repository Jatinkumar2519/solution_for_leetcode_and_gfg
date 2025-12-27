class Solution {
public:
    int mostBooked(int k, vector<vector<int>>& meetings) {
        using ll = long long;
        int n = meetings.size();
        sort(meetings.begin(),meetings.end());
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> meets;
        priority_queue<int,vector<int>,greater<int>> rooms;
        for(int i = 0;i < k;i++){
            rooms.push(i);
        }
        vector<int> visited(k,0);
        for(auto& meet : meetings){
            int st = meet[0];
            ll ed =  meet[1];
            while(!meets.empty() && meets.top().first <= st){
                rooms.push(meets.top().second);meets.pop();
            }
            if(!rooms.empty()){
                int rm_id = rooms.top();rooms.pop();
                visited[rm_id] ++;
                meets.push({ed,rm_id});
            }
            else{
                int dur = ed - st;
                auto [prev_ed,prev_id] = meets.top();meets.pop();
                visited[prev_id]++;
                meets.push({prev_ed + dur,prev_id});
            }
        }
        int maxv = *max_element(visited.begin(),visited.end());
        for(int i = 0;i < k;i++){
            if(maxv == visited[i]) return  i;
        }
        return -1;
    }
};