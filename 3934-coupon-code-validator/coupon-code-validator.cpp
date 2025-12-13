class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string, string>> filtered; // {code, businessLine}
        unordered_map<string, int> priority;
        priority["electronics"] = 1;
        priority["grocery"] = 2;
        priority["pharmacy"] = 3;
        priority["restaurant"] = 4;

        int n = code.size();
        for (int i = 0; i < n; i++) {
            if (!isActive[i] || code[i].empty()) continue;

            bool valid = true;
            for (char ch : code[i]) {
                if (!isalnum(ch) && ch != '_') {
                    valid = false;
                    break;
                }
            }

            if (valid && priority.count(businessLine[i])) {
                filtered.push_back({code[i], businessLine[i]});
            }
        }

        // Sort by businessLine priority first, then lex order of code
        sort(filtered.begin(), filtered.end(), [&](auto& a, auto& b) {
            if (priority[a.second] == priority[b.second])
                return a.first < b.first;
            return priority[a.second] < priority[b.second];
        });

        vector<string> result;
        for (auto& p : filtered) {
            result.push_back(p.first);
        }
        return result;
    }
};
