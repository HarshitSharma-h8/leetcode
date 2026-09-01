class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < 32; i++){
            int cnt =0;
            for(int elm : nums){
                if(elm &(1<<i)){
                    cnt++;
                }
            }

            if(cnt % 3){
                res = res|(1<<i);
            }
        }
        return res;
    }
};