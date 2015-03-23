#include <vector>
using namespace std;
class BestTimeToBuyAndSellStock2 {
public:
	int maxProfit(vector<int> &prices) {
		int totalDays = prices.size();
		if (totalDays <= 1)
			return 0;
		int curDay = 1, buyInPrice, profit = 0;
		bool isHold = false;
		while (curDay < totalDays)
		{
			if (!isHold)     //waiting for price increase to buy in
			{
				if (prices[curDay] > prices[curDay - 1])
				{
					//buy in
					buyInPrice = prices[curDay - 1];
					isHold = true;
				}
			}
			else            //waiting for price decrease to sell out
			{
				if (prices[curDay] < prices[curDay - 1])
				{
					//sell out
					profit += prices[curDay - 1] - buyInPrice;
					isHold = false;
				}
			}
			++curDay;
		}
		if (isHold)
		{
			profit += prices[totalDays - 1] - buyInPrice;
		}
		return profit;
	}
};