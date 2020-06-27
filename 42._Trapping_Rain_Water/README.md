# 42. Trapping Rain Water ( Hard )

+ [Description](#Description)  
+ [Solution](#Solution)  

## Description
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.    

<img width="321" height="151" src="https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png">    
The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!     

**Example 1:**  
**Input**: [0,1,0,2,1,0,1,3,2,1,2,1]      
**Output**: 6     

## Solution
_大家可以先參考第一個程式，會比較好懂，因為第二個程式是合併修飾過的版本。_    

### step 1
首先，我們如果需要蓄水，那該處兩側就必續要有「牆」才行，如下圖：  

<img width="321" height="151" src="https://i.ibb.co/SKJ5T5s/rainwatertrap.png">     

對於位置6而言，它的「牆」就是箭頭所指的兩個地方。  
也就是其位置往左、往右的最高處。  
所以位置6的「左牆」和「右牆」之高度分別為```2```和```3```。  

### step 2
而水會累積的「高度」，則是兩面「牆」中比較低的牆的高度；  
並且，我們最終要求的水累積的「深度」，則要將「水高」扣除掉它「地板」（```height[i]```）的高度才行。  
所以可知，位置6的「深度」 = ```「左牆高」 - 「地板高」``` = ```2 - 0``` = ```2```  


---

