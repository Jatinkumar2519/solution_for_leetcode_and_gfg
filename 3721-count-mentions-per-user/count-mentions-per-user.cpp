class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        vector<int> mentions(n,0);
        unordered_map<int,int> offline;
        sort(events.begin(),events.end(),[](vector<string>& a,vector<string>& b){
            if(stoi(a[1]) == stoi(b[1])){
                if(a[0] == "MESSAGE") return false;
                return true;
            }
            return stoi(a[1]) < stoi(b[1]);
        });
        for(auto& msg : events){
            string type = msg[0];
            int time = stoi(msg[1]);

            for (auto it = offline.begin(); it != offline.end(); ) {
                if (it->second <= time) {
                    it = offline.erase(it);
                } else {
                    ++it;
                }
            }

            if(type == "MESSAGE"){
                string who = msg[2];
                if(who == "ALL"){
                    for(int i = 0;i < n;i++) mentions[i]++;
                }
                else if(who == "HERE"){
                    for(int i = 0;i < n;i++){
                        if(offline.count(i) == 0){
                            mentions[i]++;
                        }
                    }
                }
                else{
                    int id;
                    string ids;
                    unordered_set<int> seen;
                    for(auto& ch : who){
                        if(ch == ' '){
                            id = stoi(ids.substr(2,ids.length() - 2));
                            // if(seen.find(id) == seen.end()){
                                mentions[id]++;
                            //     seen.insert(id);
                            // }
                            ids = "";
                        }
                        else{
                            ids.push_back(ch);
                        }
                    }
                    id = stoi(ids.substr(2,ids.length() - 2));
                    // if(seen.find(id) == seen.end()){
                        mentions[id]++;
                    // }
                }
            }
            else{
                int id = stoi(msg[2]);
                offline[id] = time + 60;
            }
            // for(string x : msg) cout<< x << ' ';
            // cout<< " : ";
            // for(int x : mentions) cout<< x << ' ';
            // cout<< endl;
        }
        return mentions;
    }
};