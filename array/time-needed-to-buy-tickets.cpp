class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int i = -1;
        int n = tickets.size();
        int time = 0;
        while(tickets[k] != 0){
            i++;
            if(i==n) i=0;
            if(tickets[i]>0) tickets[i]--;
            else continue;
            time++;
        }
        return time;
    }
};