class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());

        int n = asteroids.size();
        for(int i = 0;i < n;i++){
            if(mass < asteroids[i]) return false;

            mass += asteroids[i];
        }

        return true;
    }
};