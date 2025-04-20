class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int>frq;
        for(auto x:answers)
            frq[x]++;
        int res = 0;
        for(auto p:frq){
            int f = p.first + 1;
            res+=((p.second + f - 1) /f) * f; // This equation is equivalent to  res+=ceil((double)p.second/f)*f  but the first equation (we used) is more efficient.
        }
        return res;
    }
};