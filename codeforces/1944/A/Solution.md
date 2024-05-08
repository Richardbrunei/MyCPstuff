# A. Destroying Bridges
Since each island is connected to every other island, we have to destroy all the bridges around a island for it to be inaccessable. Therefore, the optimal way to destroy bridges is to try and destroy all the bridges around island 1. As a result, if k>=n-1 then the answer is 1 (since we can destroy all the briges around island 1). Otherwise, the answer is N.
