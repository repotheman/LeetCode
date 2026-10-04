class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        //unordered map bana rahe hai sabki frequency dekh lenge

        int result = 0;
        //isme ans store karenge itna dumb toh hai nahi
        for(int &num : nums){
            mp[num]++;
        }
        // map mai daalte huew hai
        for(int &num : nums){
            // ek ek karke iterate karenge
            int minNum = num;
            // number ko minimum maan liya
            int maxNum = num +1;
            // ab max number usse ek bada lelenge
            //kyunki hume aisa number chahiye or subarray chahiye jiska max - min = 1 ho

            if(mp.count(maxNum)){
                result = max(result, mp[minNum] + mp[maxNum]);
            }
        }
        return result;
    }
};