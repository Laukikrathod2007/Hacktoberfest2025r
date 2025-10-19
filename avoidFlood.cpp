class Solution {
public:
    vector<int> avoidFlood(vector<int>& rain) {
        int n = rain.size();
        vector<int> ans(n, -1);
        set<int> dryDays;
        unordered_map<int, int> full;

        for (int i = 0; i < n; i++) {
            int lake = rain[i];

            if (lake > 0) {
                if (full.count(lake)) {
                    auto it = dryDays.upper_bound(full[lake]);
                    if (it == dryDays.end()) return {};
                    ans[*it] = lake;
                    dryDays.erase(it);
                }
                full[lake] = i;
            } else {
                dryDays.insert(i);
                ans[i] = 1;
            }
        }
        return ans;
    }
};
