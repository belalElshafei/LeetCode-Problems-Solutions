class Solution {
public:
    int getMx(map<int,int>&frq){
        auto it = frq.end();
        it--;
        return it->first;
    }
    int getMn(map<int,int>&frq){
        auto it = frq.begin();
        return it->first;
    }
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        vector<vector<int>>ranges;
        vector<int>sub;
        for(auto x:nums){
            if(x >= minK  && x <= maxK)
                sub.push_back(x);
            else if(!sub.empty()){
                ranges.push_back(sub);
                sub.clear();
            }
        }
        if(!sub.empty())
                ranges.push_back(sub);

        long long totRes = 0;
        for(auto sub:ranges){
            int l = 0,r = 0,n = sub.size(),currMn = sub[0] ,currMx = sub[0];
            map<int,int>frq;
            bool rMove = false;
            frq[sub[r]]++;
            long long res = 0;
            while(r<n){
                if(currMn == minK && currMx == maxK){
                    res+=n-r;
                    frq[sub[l]]--;
                    if(frq[sub[l]]==0)frq.erase(sub[l]);
                    l++;
                    if(l>r)rMove = true;
                    else{
                        currMn = getMn(frq);
                        currMx = getMx(frq);
                    }
                }else rMove = true;

                if(rMove){
                    r++;
                    if(r<n){
                        frq[sub[r]]++;
                        currMn = getMn(frq);
                        currMx = getMx(frq);
                    }
                    rMove = false;
                }                
            }
            totRes+=res;
        }
        return totRes;
    }
};