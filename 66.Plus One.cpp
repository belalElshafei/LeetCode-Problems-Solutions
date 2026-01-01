class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int needOne = 1;
        for(int i = digits.size()-1; i>= 0; i--){
            if(digits[i]<9){
                digits[i]++;
                needOne = 0;
                break;
            }else{
                digits[i] = 0;
            }
        }

        vector<int>res;
        if(needOne){
            res.push_back(1);
        }
        res.insert(res.end(),digits.begin(),digits.end());
        return res;
    }
};