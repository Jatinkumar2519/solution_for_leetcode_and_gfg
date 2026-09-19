class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                      int x2, int y2) {
        
        // square inside the circle
        for(int x = x1;x <= x2;x++){
            int r = pow(x - xCenter,2) + pow(y1 - yCenter,2);
            if(r <= radius * radius) return true;
        }
        for(int x = x1;x <= x2;x++){
            int r = pow(x - xCenter,2) + pow(y2 - yCenter,2);
            if(r <= radius * radius) return true;
        }
        for(int y = y1;y <= y2;y++){
            int r = pow(x1 - xCenter,2) + pow(y - yCenter,2);
            if(r <= radius * radius) return true;
        }
        for(int y = y1;y <= y2;y++){
            int r = pow(x2 - xCenter,2) + pow(y - yCenter,2);
            if(r <= radius * radius) return true;
        }
        
        // circle inside the square
        int x = xCenter;
        int y = yCenter;

        return ((x1 <= x && x <= x2) &&
                (y1 <= y && y <= y2));
    }
};