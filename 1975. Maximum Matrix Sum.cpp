class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long tot  = 0;
        int negCount = 0,mnNum = 1e5;
        for(int i = 0;i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                tot+=abs(matrix[i][j]);
                mnNum = min(mnNum,abs(matrix[i][j]));
                if(matrix[i][j] <= 0){
                    negCount++;
                }
            }
        }
        if(negCount%2 !=0){
            tot-=(2*mnNum);
        }
        return tot;
    }
};