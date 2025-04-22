/**
 * @file 2145. Count the Hidden Sequences.cpp
 * @brief Solution for the problem using prefix sum and binary search.
 * @details To understand the idea , visit the video (https://www.youtube.com/watch?v=3E9m4soD9cE&t=6s) video is the same idea, but we used another approach (binary search).
 */
class Solution {
public:
    int  binarySearchMx(long long mxPrefix,long long mnPrefix,int lower,int upper){
        int l = lower,r = upper,res = INT_MIN;

        while(l<=r){
            int mid = (l+r)/2;
            long long midMn = mid+mnPrefix,midMx = mid+mxPrefix;
            if(midMn >= lower && midMx <= upper){
                res = mid;
                l = mid+1;
            }else if(midMn < lower)
                l = mid+1;
            else if(midMx > upper)
                r = mid-1;
        }
        return res;
    }

    int  binarySearchMn(long long  mxPrefix,long long mnPrefix,int lower,int upper){
        int l = lower,r = upper,res = INT_MIN;

        while(l<=r){
            int mid = (l+r)/2;
            long long midMn = mid+mnPrefix,midMx = mid+mxPrefix;
            if(midMn >= lower && midMx <= upper){
                res = mid;
                r = mid-1;
            }else if(midMn < lower)
                l = mid+1;
            else if(midMx > upper)
                r = mid-1;
        }
        return res;
    }
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
            int n = differences.size();
            vector<long long> prefixSum(n);
            prefixSum[0] = differences[0];
            long long  mxPrefix = prefixSum[0],mnPrefix = prefixSum[0];

            for(int i = 1; i < n; i++){
                prefixSum[i] = prefixSum[i-1] + differences[i];
                mxPrefix = max(mxPrefix,prefixSum[i]);
                mnPrefix = min(mnPrefix,prefixSum[i]);
            }

            int mx = binarySearchMx(mxPrefix,mnPrefix, lower, upper);
            int mn = binarySearchMn(mxPrefix,mnPrefix,lower, upper);
            if(mx == INT_MIN)
                return 0;
            return (mx - mn) + 1;
    }
};