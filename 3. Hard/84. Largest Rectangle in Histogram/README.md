# 84. Largest Rectangle in Histogram ( Hard )

+ [Description](#Description)  
+ [Solution](#Solution)  

## Description
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.    

<img width="271" height="271" src="https://i.ibb.co/tZJ2Hzv/2020-07-17-15-55-19.png">      

**Example :**  

```
Example:

Input: [2,1,5,6,2,3]
Output: 10
``` 

## Solution
這題除了用暴力法外，還有可以在O(N)內解決的方法，下面將會細述解題思路。   
另外，若寫完這題，可以試者寫寫看 [85. Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/) 你可以把85題當作這題的進階題。    

### idea 1
我們試著分出兩種簡單的case：  

1. heights[i] >= heights[i - 1]  
當這種情況時，對於 ```heights[i - 1]``` 而言，與他關聯的面積延伸方向有兩種 :  
第一種是以自己的高度來算面積（下圖左）;  
第二種是延伸到右邊，用延伸的寬和自己的高來計算面積（下圖右）。    

<img width="271" height="171" src="https://i.ibb.co/DkJx9Yc/2020-07-17-16-22-23.png">      


2. heights[i] < heights[i - 1]  
當這種情況時，對於 ```heights[i - 1]``` 而言，與他關聯的面積延伸方向只有一種 :
以自己的高度來算面積(因為他比較高，所以無法往右延伸)。    

<img width="111" height="171" src="https://i.ibb.co/xftgm0G/2020-07-17-16-26-34.png">   

### idea 2
所以當```heights[i] < heights[i - 1]``` 時，我們要計算```i - 1```之前，和高度小於等於```heights[i - 1]```的高度們的各自的延伸到```i - 1```的面積（上面case1的第二項，不用算第一項，因為第二項的面積一定大於第一項)。   


---

