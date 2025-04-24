class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size(),distCnt = 0;
        int frq[2001];
        memset(frq,0,sizeof(frq));
        for(int i = 0; i < n; i++){
            frq[nums[i]]++;
            if(frq[nums[i]] == 1)distCnt++;
        }

        int l = 0,r = 0,currDistCnt = 1,res = 0;
        bool rMove = 0;
        memset(frq,0,sizeof(frq));
        frq[nums[0]]++;
        while(r<n){
            if(currDistCnt == distCnt){
                res+=n-r;
                frq[nums[l]]--;
                if(frq[nums[l]] == 0) currDistCnt--;
                l++;
                if(l>r)rMove = 1;

            }else rMove = 1;
            
            if(rMove){
                r++;
                if(r<n){
                    frq[nums[r]]++;
                    if(frq[nums[r]] == 1) currDistCnt++;
                }
                rMove = 0;
            }

        }

        return res;
    }
};