# 85. Maximal Rectangle ( Hard )

+ [Description](#Description)  
+ [Solution](#Solution)  

## Description
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.     

**Example :**  

```
Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
``` 

## Solution
這題其實可以當作[84. Largest Rectangle in Histogram]（https://leetcode.com/problems/largest-rectangle-in-histogram/） 的進階題，所以如果沒有做過84題，建議可以先挑戰看看。  

用84題的方法來看的話，其實這題可以直接把每一個row就當作一組```heights```，而他的高度就根據他的上面（前面的row、同一colum)所連續堆疊的```'1'```的高度。  
以範例來講的，前兩組```heights```就會等於：  
```
1  0  1  0  0
2  0  2  1  1
```
然後套用算最大矩形面積的方法，每行每行的來找出的高度裡面的最大面積。  


---

