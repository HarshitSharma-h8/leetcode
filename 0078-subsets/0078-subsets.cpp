class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubset;
        vector<int> subset;
        generate(allSubset, subset, nums, 0);
        return allSubset;
    }

private :
    void generate(vector<vector<int>>& allSubset, vector<int>& subset, vector<int>& nums, int i){
        if(i == nums.size()){
            allSubset.push_back(subset);
            return;
        }
        // below line include
        subset.push_back(nums[i]);
        generate(allSubset, subset, nums, i+1);
        subset.pop_back();
        // here we did'nt include
        generate(allSubset, subset, nums, i+1);
    }    
};