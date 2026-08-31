class Solution {
public:
    int minBitFlips(int start, int goal) {
        start = start^goal;
        if(start == 0) return 0;
        int cnt = 0;
        while(start != 1){
            cnt += start&1;
            start = start >> 1;
        }
        if(start == 1){
            cnt += 1;
        }
        return cnt;
    }
};