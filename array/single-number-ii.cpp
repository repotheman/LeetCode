class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for(int i =0 ; i<=31; i++){

            int countOnes = 0;
            int temp = (1 << i);
            for(int &num : nums){
                if((num & temp) == 0){
                }else{
                    countOnes++;
                }
            }

            if(countOnes % 3 == 1){
                result = (result | temp);
            }
        }
        return result;
    }
};