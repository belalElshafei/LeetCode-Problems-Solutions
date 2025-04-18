class Solution {
public:
    string countAndSay(int n) {
        deque<char> res;
        res.push_front('1');
        for(int i = 2;i <= n; i++){
           deque<char>curr;
            for(int j = res.size()- 1; j>=0; j--){
                char c = res[j];
                curr.push_front( c);
                int cnt = 1;
                while(j >0){
                    j--;
                    if(c!=res[j]){
                        j++;
                        break;
                    }
                    cnt++;
                }
                curr.push_front('0'+cnt);
            }
            res = curr;
        }
        return string(res.begin(),res.end());
    }
};
