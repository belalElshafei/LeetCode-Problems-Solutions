class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size(); 
        int rightSideY = 0,leftSideN = 0;
        for(int i = 0; i < n; i++){
            if(customers[i] == 'Y'){
                rightSideY++;
            }
        }

        int minPenalty = n+1,earliestHour = 0;
        for(int i = 0 ; i <= n; i++){
            int penalty = leftSideN + rightSideY;
            if(penalty < minPenalty){
                minPenalty = penalty;
                earliestHour = i;
            }
            if(i < n){
                if(customers[i] == 'N'){
                    leftSideN++;
                }else{
                    rightSideY--;
                }
            }
        }
        return earliestHour;
    }
};