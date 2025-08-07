class CombinationIterator {
public:
    int i;
    vector<string> comb;
    void solve(string& s,string curr,int i,int mask,int k){
        if(i == s.length()){
            if(curr.length() == k){
                comb.push_back(curr);
            }
            return;
        }
        solve(s,curr,i + 1,mask,k);
        if((mask & (1 << i)) == 0){
            solve(s,curr + s[i],i + 1,mask | (1 << i),k);
        }
    }
    CombinationIterator(string characters, int combinationLength) {
        i = 0;
        solve(characters,"",0,0,combinationLength);
        sort(comb.begin(),comb.end());
    }
    
    string next() {
        return comb[i++];
    }
    
    bool hasNext() {
        if(i < comb.size()){
            return true;
        }
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */