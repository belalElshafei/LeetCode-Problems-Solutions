class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        int prefixSum[n+1];
        prefixSum[0] = 0;
        unordered_map<int,int>mp;
        mp[(prefixSum[0] +modulo-k)%modulo]++;

        for(int i = 1;i <= n; i++){
            prefixSum[i] = prefixSum[i-1] +((nums[i-1]%modulo == k) ? 1 : 0);
            mp[(prefixSum[i] +modulo-k)%modulo]++;
        }
        long long res = 0;
        for(int i = 0;i <= n; i++){
            mp[(prefixSum[i] +modulo-k)%modulo]--;
            res+=mp[prefixSum[i]%modulo];
        }
        
        return res;
    }
};