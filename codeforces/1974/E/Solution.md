# E. Money Buys Happiness
This is like a 0-1 knapsack problem. We let dp[i] be the amount of money we will have left after getting i happiness. dp[j]=max(dp[j-h[i]]+x-c[i],dp[j]+x) if we can afford h[i] happiness. Otherwise, we have dp[j]+=x. We find the highest value of i which dp[i]>=0.
