class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        cs(candidates, 0, comb, ans, target);
        return ans;
    }
    void cs(vector<int>& arr, int i, vector<int>& comb,
            vector<vector<int>>& ans, int target) {
        // base condition
        if (target == 0) {
            ans.push_back(comb);
            return;
        }
        if (i == arr.size() || target < 0) {
            return;
        }
        

        comb.push_back(arr[i]);
        // singel
        cs(arr, i+1 , comb, ans, target - arr[i]);

        comb.pop_back();
        while(i+1 < arr.size() && arr[i] == arr[i+1]){
            i++;
        }
        // not include
        cs(arr, i + 1, comb, ans, target);
    }
};