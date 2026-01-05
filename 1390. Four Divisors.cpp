class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;
        vector<int>visited(1e5+1,-1);
        for(int i = 0; i < nums.size(); i++){
            if(visited[nums[i]] !=-1){
                totalSum+=visited[nums[i]];
                continue;
            }
            int subSum = 0,cnt = 0;
            for(int j = 1; j*j <= nums[i]; j++){
                int d1 = j;
                if(nums[i]%d1 == 0){
                    cnt++;
                    subSum+=d1;
                    int d2 = (nums[i]/j);
                    if(d1!=d2){
                        cnt++;
                        subSum+=d2;
                    }
                }
            }
            if(cnt==4){
                totalSum+=subSum;
                visited[nums[i]] = subSum;
            }else {
                visited[nums[i]] = 0;
            }
        }
        return totalSum;
    }
};