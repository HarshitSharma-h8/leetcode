class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int,int> mp;
        vector<int> ans;
        for(int elm : nums){
            mp[elm]++;
        }

        for(auto elm : mp){
            if(elm.second == 1){
                ans.push_back(elm.first);
            }
        }
        return ans;
    }
};