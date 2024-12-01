# C. Gerrymandering
Dynamic programming time. We can either add a line or a L shape. Let `dp[i][j]` be the number of votes in the `i`th column and `j` be the current configuration. If j==0 then the end is flat. If j==1 then the end is a L. if j==1 then the end is a reverse L.
