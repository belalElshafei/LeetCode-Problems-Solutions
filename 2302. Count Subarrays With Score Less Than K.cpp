class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int l = 0,r = 0,rMove = 0;
        long long res = 0,currSum = nums[0],score;

        while(r<n){
            score = currSum  * (r-l+1);    
            if(score>=k){
                currSum-=nums[l];
                l++;
                if(l>r)rMove = 2;
            }else rMove = 1;

            if(rMove){
                if(rMove==1)res+=(r-l+1);
                r++;
                if(r<n)currSum+=nums[r]; 
                rMove = 0;
            }
        }
        return res;
    }
};