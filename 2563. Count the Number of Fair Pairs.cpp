class Solution {
public:
    int BinarySerchMax(int i,vector<int>& nums,int lower,int upper){
        int  l = i+1,r = nums.size()-1,mid,res = -1;

        while(l<=r){
            mid = (l+r)/2;
            int val = nums[i] + nums[mid];
            if(val <= upper && val >= lower ){
                res = mid;
                l = mid+1;
            }else if(val < lower)
                l = mid+1;
            else r = mid -1;
        }   
        return res;
    }
    int BinarySerchMin(int i,vector<int>& nums,int lower,int upper){
        int  l = i+1,r = nums.size()-1,mid,res = -1;

        while(l<=r){
            mid = (l+r)/2;
            int val = nums[i] + nums[mid];
            if(val <= upper && val >= lower ){
                res = mid;
                r = mid - 1;
            }else if( val < lower)
                l = mid+1;
            else r = mid -1;
            
        }   
        return res;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long res = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++){
            int valMx = BinarySerchMax(i,nums,lower,upper),valMn = BinarySerchMin(i,nums,lower,upper);
            if(valMx!=-1)
                res+=(valMx - valMn) +1;
        }
        return res;
    }
};