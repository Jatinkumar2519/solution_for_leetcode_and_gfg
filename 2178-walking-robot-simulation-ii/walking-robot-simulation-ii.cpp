class Robot {
public:
    int idx;
    vector<pair<int,int>> points;

    int x,y;
    bool travelled;
    Robot(int width, int height){
        idx = 0;
        x = width;
        y = height;
        travelled = false;

        for(int i = 0;i < width;i++){
            points.push_back({i,0});
        }
        for(int i = 1;i < height - 1;i++){
            points.push_back({width - 1,i});
        }
        for(int i = width - 1;i >= 0;i--){
            points.push_back({i,height - 1});
        }
        for(int i = height - 2;i > 0;i--){
            points.push_back({0,i});
        }
    }
    
    void step(int num) {
        travelled = travelled || (num > 0);
        int n = points.size();

        idx = (idx + num) % n;
    }
    
    vector<int> getPos() {
        return {points[idx].first,points[idx].second};
    }
    
    string getDir() {
        auto point = points[idx];

        if(point.second == 0){
            if(point.first == 0 && travelled) return "South";
            else return "East";
        }
        else if(point.first == x - 1){
            return "North";
        }
        else if(point.second == y - 1){
            return "West";
        }
        else{
            return "South";
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */