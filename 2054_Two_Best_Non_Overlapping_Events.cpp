class Solution {
public:
    int binarySearch(int s,vector<pair<int,int>>&end){
        int l = 0,r = end.size()-1,res = 0;
        while(l<=r){
            int mid = (l+r)/2;
            if(end[mid].first < s){
                res = end[mid].second;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return res;
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<pair<int,int>>end;
        vector<pair<int,int>>start;
        for(int i = 0; i< events.size(); i++){
            end.push_back({events[i][1],events[i][2]});
            start.push_back({events[i][0],events[i][2]});
        }

        sort(end.begin(),end.end());
        sort(start.begin(),start.end());
        for(int i = 1; i < end.size() ; i++){
            end[i].second = max(end[i].second,end[i-1].second);
        }
        int res = 0;
        for(int i = start.size()-1; i>=0 ;i--){
            int s = start[i].first,val = start[i].second;
            res = max(res,val+binarySearch(s,end));
        }
        return res;
    }
};