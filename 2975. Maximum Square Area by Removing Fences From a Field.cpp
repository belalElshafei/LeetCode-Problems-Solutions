class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        long long maxSide = -1;
        int N = 1e9+7;
        if(n == m){
           return ((n-1)*(m-1))%N;
        }
        unordered_set<int>setH;
        for(int i = 0;i <hFences.size();i++){
            for(int j = i+1 ; j < hFences.size(); j++){
                int diff = abs(hFences[j]-hFences[i]);
                setH.insert(diff);
            }
        }
        for(int i = 0;i <vFences.size();i++){
            for(int j = i+1 ; j < vFences.size(); j++){
                int diff = abs(vFences[j]-vFences[i]);
                if(setH.count(diff)){
                    maxSide = max(maxSide,(long long)diff);
                }
            }
        }
        if(maxSide == -1) return maxSide;
        return (maxSide*maxSide)%N;
    }
};