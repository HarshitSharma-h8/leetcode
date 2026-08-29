class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> ans;
        int i = 1;
        gc(res, ans, 1, n, k);
        return res;
    }
    void gc(vector<vector<int>>& res, vector<int>& ans, int i, int target,
            int k) {
        if (target == 0) {
            if (ans.size() == k) {
                res.push_back(ans);
                return;
            }
        }
        if (i > 9 || ans.size() > k) {
            return;
        }

        ans.push_back(i);
        gc(res, ans, i + 1, target - i, k);

        ans.pop_back();
        gc(res, ans, i + 1, target, k);
    }
};