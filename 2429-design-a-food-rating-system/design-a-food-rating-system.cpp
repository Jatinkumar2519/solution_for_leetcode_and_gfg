class FoodRatings {
public:
    unordered_map<string,string> food_to_cuisine;
    unordered_map<string,pair<map<string,int>,map<int,set<string>>>> map;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0;i < n;i++){
            food_to_cuisine[foods[i]] = cuisines[i];
            auto& food_to_rating = map[cuisines[i]].first;
            auto& rating_to_food = map[cuisines[i]].second;
            food_to_rating[foods[i]] = ratings[i];
            rating_to_food[ratings[i]].insert(foods[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine_domain = food_to_cuisine[food];
        auto& food_to_rating = map[cuisine_domain].first;
        auto& rating_to_food = map[cuisine_domain].second;
        int prev_rating = food_to_rating[food];
        rating_to_food[prev_rating].erase(food);
        if(rating_to_food[prev_rating].empty()){
            rating_to_food.erase(prev_rating);
        }
        food_to_rating[food] = newRating;
        rating_to_food[newRating].insert(food);
    }
    
    string highestRated(string cuisine) {
        return *map[cuisine].second.rbegin()->second.begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */