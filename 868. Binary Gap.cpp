class Solution {
public:
    int binaryGap(int n) {
        int i = 1,indx = 1, lsPos = -1,res = 0;
        while(i <= n){
            if((i & n) == i){
                if(lsPos == -1){
                    lsPos = indx;
                }else{
                    res = max(res,indx-lsPos);
                    lsPos = indx;
                }
            }
            i<<=1;
            indx++;
        }

        return res;
    }
};