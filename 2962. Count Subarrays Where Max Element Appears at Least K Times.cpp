class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx  = nums[0];
        for(auto x :nums)mx = max(mx,x);

        int l = 0,r = 0,mxCnt =  (nums[0] == mx ? 1:0),n = nums.size();
        bool rMove = false;
        long long res =0;

        while(r<n){
            if(mxCnt >= k){
                res+=n-r;
                if(nums[l]==mx)mxCnt--;
                l++;
                if(r<l)rMove = true;
            }else rMove = true;

            if(rMove){
                r++;
                if(r<n)
                    if(nums[r]==mx)mxCnt++;
                rMove = false;
            }
        }
        return res;
    }
};