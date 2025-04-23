class Solution {
public:
    int countLargestGroup(int n) {
        int currMxGroupSize = 0,numberOfGroups = 0;
        int frq[n+1];
        memset(frq,0,sizeof(frq));

        for(int i = 1; i<=n;i++){
            int val = i,sum  = 0;
            while(val){
                sum+=val%10;
                val/=10;
            }
            frq[sum]++;
            if(frq[sum]==currMxGroupSize)numberOfGroups++;
            else if(frq[sum]>currMxGroupSize){
                currMxGroupSize = frq[sum];
                numberOfGroups = 1;
            }
        } 
        return numberOfGroups;
    }
};