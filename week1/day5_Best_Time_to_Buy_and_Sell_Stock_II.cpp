class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if( !prices.size() ) return 0;//empty vector
        int i = 1;
        int maxProfit = 0;
        int sPrice, bPrice, curProfit = 0;
        int lowBPrice = prices[0];
        while(i<prices.size()){
            //find lowest price to buy
            while( i < prices.size() && prices[i] <= prices[i-1]) i++;
            if(i==prices.size()) break;//if reach the end, stop...
            bPrice =prices[i-1];
            if(bPrice < lowBPrice){//if price to buy lower than our previous lowest then...
                lowBPrice = bPrice;//our profit CAN'T be greater with any previous price,so...
                maxProfit += curProfit;//add current to max profit
                curProfit = 0;//and start current from zero
            }
            //find max price to sell
            while( i < prices.size() && prices[i] >= prices[i-1] ) i++;
            //we are ok if we reach the last price here
            sPrice =prices[i-1];
            if( curProfit + (sPrice - bPrice) > (sPrice - lowBPrice) ) curProfit += sPrice - bPrice;
            else curProfit = sPrice - lowBPrice;
        }
        return maxProfit + curProfit;
    }
};
