class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = bank.size();
        map<string,int> map;
        queue<pair<string,string>> q{{{startGene,""}}};
        int time = 0;
        while(!q.empty()){
            int len = q.size();
            while(len--){
                auto [curr,prev] = q.front();q.pop();
                if(curr == endGene) return time;
                if(++map[curr] > bank.size()) return -1;
                for(auto& gene : bank){
                    int change = 0;
                    if(prev == gene) continue;
                    for(int i = 0;i < 8;i++){
                        if(curr[i] != gene[i]) change++;
                    }
                    if(change == 1){
                        q.push({gene,curr});
                    }
                }
            }
            time++;
        }
        return -1;
    }
};