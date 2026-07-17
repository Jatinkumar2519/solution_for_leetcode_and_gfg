class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        using ll = long long;

        int maxv = *max_element(nums.begin(), nums.end()) + 1;

        vector<int> freq(maxv, 0);
        for (int x : nums)
            freq[x]++;

        vector<ll> prefix(maxv, 0);

        for (int g = maxv - 1; g >= 1; g--) {
            ll cnt = 0;

            for (int j = g; j < maxv; j += g)
                cnt += freq[j];

            prefix[g] = cnt * (cnt - 1) / 2;

            for (int j = 2 * g; j < maxv; j += g)
                prefix[g] -= prefix[j];
        }

        for (int i = 1; i < maxv; i++)
            prefix[i] += prefix[i - 1];

        vector<int> ans;

        for (long long q : queries) {
            ans.push_back(lower_bound(prefix.begin(), prefix.end(), q + 1) - prefix.begin());
        }

        return ans;
    }
};