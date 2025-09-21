class MovieRentingSystem {
public:
    map<pair<int,int>,int> prices;
    map<int,set<pair<int,int>>> available;
    set<tuple<int,int,int>> rented;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (int i = 0; i < entries.size(); i++) {    // FIXED loop
            int shop = entries[i][0];
            int movie = entries[i][1];
            int price = entries[i][2];
            prices[{shop, movie}] = price;
            available[movie].insert({price, shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        if (available.count(movie)) {
            int count = 0;
            for (auto& it : available[movie]) {
                res.push_back(it.second);
                if (++count == 5) break;
            }
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int price = prices[{shop, movie}];
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = prices[{shop, movie}];
        rented.erase({price, shop, movie});
        available[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int count = 0;
        for (auto& it : rented) {
            auto [price, shop, movie] = it;
            res.push_back({shop, movie});
            if (++count == 5) break;
        }
        return res;
    }
};
