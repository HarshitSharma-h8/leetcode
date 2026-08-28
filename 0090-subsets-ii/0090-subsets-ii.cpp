class Solution {
public:
    set<vector<int>> s;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allSubset;
        vector<int> subset;
        generate(allSubset, subset, nums, 0);
        return allSubset;
    }

    void generate(vector<vector<int>>& allSubset, vector<int>& subset,
                  vector<int>& nums, int i) {
        if (i == nums.size()) {
            if (s.find(subset) == s.end()) {
                allSubset.push_back(subset);
                s.insert(subset);
            }
            return;
        }
        // below line include
        subset.push_back(nums[i]);
        generate(allSubset, subset, nums, i + 1);
        subset.pop_back();
        // here we did'nt include
        generate(allSubset, subset, nums, i + 1);
    }
};

