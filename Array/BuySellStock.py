"""
You are given an array prices where prices[i] is the 
price of a given stock on the ith day.

You want to maximize your profit by choosing a single day
to buy one stock and choosing a different day in the future 
to sell that stock.

Return the maximum profit you can achieve from this transaction.
If you cannot achieve any profit, return 0
"""

def maxProfit(prices) -> int:
    max_profit = 0
    min = prices[0]
    max = prices[0]
    for i in range(1,len(prices)):
        if prices[i] < min:
            min = prices[i]
            max = prices[i]
        elif prices[i] > max:
            max = prices[i]
            if max_profit < prices[i] - min:
                max_profit = prices[i] - min
        
    return max_profit

if __name__ == '__main__':
    print(maxProfit([17,11,5,3,2,1]))