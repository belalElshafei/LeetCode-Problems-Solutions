class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zero1 = 0,zero2 = 0;
        long long sum1 = 0,sum2 = 0;
        for(auto x:nums1){
            sum1+=(x?x:1);
            if(!x)zero1++;
        }
        for(auto x:nums2){
            sum2+=(x?x:1);
            if(!x)zero2++;
        }
        if(sum2>sum1)
        {
            swap(sum1,sum2);
            swap(zero1,zero2);
        }
        if(sum1!=sum2 && !zero2)return -1;
        return sum1;
    }
};
