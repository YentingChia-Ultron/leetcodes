# 64. Minimum Path Sum ( Medium )

+ [Description](#Description)  
+ [Solution](#Solution)  

## Description
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.  

Note: You can only move either down or right at any point in time.  

**Example :**  

```
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
```  

## Solution

這題跟 [62. Unique Paths](https://github.com/fhsi5794/leetcodes/tree/master/2.%20Medium/62.%20Unique%20Paths) 很像，若是論不繞遠路的走法，那每一步一定是往右或往下走，所以走到目的地的前一步，就會在目的地的上方或是左方。  
故，目的地的最小加總值，就會是```目的地原本值```，加上它的```上方最小總值```或```左方最小總值```比較小的那一個。  
以此類推，直到第一行或第一列，他們的(最小）總值為前一相加總值。   

範例：  
|   | 0 | 1 | 2 |
|:-:|:-:|:-:|:-:|
| **0** | 1 | 3 | 1 |
| **1** | 1 | 5 | 1 |
| **2** | 4 | 2 | 1 |  

各位置之最小總值：  
|   | 0 | 1 | 2 |
|:-:|:-:|:-:|:-:|
| **0** | 1 | 1 + 3 = 4 | 4 + 1 = 5 |
| **1** | 1 + 1 = 2 | min(4, 2) + 5 = 7 | min(5, 7) + 1 = 6 |
| **2** | 2 + 4 = 6 | min(7, 6) + 2 = 8 | min(6, 8) + 1 = 7 |    




---

