class Solution {
public:
    int binarySearch(vector<int>& nums,int i,int k){
        int l = 0 ,r = i,mid,res = nums.size();
        while(l<=r){
            mid = (l+r)/2;
            if(nums[i] <= (long long)nums[mid]*k){
                r = mid-1;
                res = mid;
            }else{
                l = mid+1;
            }
        }
        return res;
    }
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int res = n;
        for(int i = n-1; i>=0; i--){
            int mn = binarySearch(nums,i,k);
            res = min(res,(n - (i+1))+ mn);
        }

        return res;
    }
};