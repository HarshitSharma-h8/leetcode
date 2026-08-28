class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> ans;

        generate(candidates, 0, target, ans, res);

        return res;
    }

    void generate(vector<int>& candidates, int ind, int target,
                  vector<int>& ans, vector<vector<int>>& res) {

        if (target == 0) {
            res.push_back(ans);
            return;
        }

        if (target < 0 || ind == candidates.size()) {
            return;
        }

        for (int i = ind; i < candidates.size(); i++) {

            // Skip duplicate values at the same recursion level
            if (i > ind && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted, no later value can work
            if (candidates[i] > target)
                break;

            ans.push_back(candidates[i]);

            // i + 1 -> each element can be used only once
            generate(candidates, i + 1, target - candidates[i],
                     ans, res);

            ans.pop_back();
        }
    }
};