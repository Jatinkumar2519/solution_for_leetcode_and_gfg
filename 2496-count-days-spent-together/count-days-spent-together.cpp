class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i = 1;i < 13;i++) days[i] += days[i - 1];

        auto getDays = [&](string& str)->int{

            int day = stoi(str.substr(3));
            int month = stoi(str.substr(0,2));

            return days[month - 1] + day;
        };

        pair<int,int> p2 = {getDays(arriveBob), getDays(leaveBob)};
        pair<int,int> p1 = {getDays(arriveAlice), getDays(leaveAlice)};

        if(p1.second < p2.first || p2.second < p1.first) return 0;
        return min(p2.second, p1.second) - max(p2.first, p1.first) + 1;
    }
};