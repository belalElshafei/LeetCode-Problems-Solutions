class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size(),res = 1;
        for(int i = 0; i < n; i++){
            unordered_map<char,int>mp;
            mp[s[i]]++;
            for(int j = i+1; j < n; j++){
                mp[s[j]]++;
                int pre = mp.begin()->second,ok = 1;
                for(auto x:mp){
                    if(x.second!=pre){
                        ok = 0;
                        break;
                    }
                    pre = x.second;
                }

                int len = ((j - i) + 1); 
                if(ok && len > res){
                    res = len;
                }
            }
        }
        return res;
    }
};