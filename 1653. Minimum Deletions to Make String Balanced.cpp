class Solution {
public:
    int solve(int i,int oneDone,vector<vector<int>>&dp,string &s,int n){
        if(i == n){
            return 0;
        }

        if(dp[i][oneDone]!=-1){
            return dp[i][oneDone];
        }
        
        int res;
        if(oneDone){
            if(s[i] == 'b'){
                res = solve(i+1,oneDone,dp,s,n);
            }else{
                res = 1 + solve(i+1,oneDone,dp,s,n);
            }
        }else{
            if(s[i] == 'a'){
                res = solve(i+1,oneDone,dp,s,n);
            }else{
                int sol1 = 1+ solve(i+1,oneDone,dp,s,n),sol2 = solve(i+1,1,dp,s,n);
                res = min(sol1,sol2);
            }
        }

        return dp[i][oneDone] = res;
    }
    int minimumDeletions(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,0,dp,s,n);
    }
};