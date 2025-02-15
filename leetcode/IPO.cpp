class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<array<int, 2>> projects(profits.size());
        priority_queue<int> available;
        for (int i = 0; i < profits.size(); i++) {
            projects[i] = {capital[i], profits[i]};
        }
        sort(projects.begin(), projects.end());
        auto itr = projects.begin();
        while (k--) {
            while (itr != projects.end() && (*itr)[0] <= w) {
                available.push((*(itr++))[1]);
            }
            if (available.empty()) {
                return w;
            }
            int p = available.top();
            available.pop();
            w += p;
        }
        return w;
    }
};
