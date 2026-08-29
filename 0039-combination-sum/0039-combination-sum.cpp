class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        cs(candidates, 0, comb, ans, target);
        return ans;
    }
    void cs(vector<int>& arr, int i, vector<int>& comb,
            vector<vector<int>>& ans, int target) {
        // base condition
        if (i == arr.size() || target < 0) {
            return;
        }
        if (target == 0) {
            ans.push_back(comb);
            return;
        }

        comb.push_back(arr[i]);
        // singel
        cs(arr, i , comb, ans, target - arr[i]);

        // not include
        comb.pop_back();
        cs(arr, i + 1, comb, ans, target);
    }
};