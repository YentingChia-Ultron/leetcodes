# 48. Rotate Image ( Medium )

+ [Description](#Description)  
+ [Solution](#Solution)  

## Description
You are given an n x n 2D matrix representing an image.  

Rotate the image by 90 degrees (clockwise).  

Note:  

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. **DO NOT** allocate another 2D matrix and do the rotation.  

**Example 1:**  

```
Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
```     

**Example 2:**  

```
Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
```  


## Solution

因為有說一定要在原本的matrix上面動作，所以我們要勁量想如何用swap的方法。  

### idea
下圖為旋轉90度的規律：    

<img width="421" height="270" src="https://i.ibb.co/HPQPfwt/2020-06-28-22-13-40.png">    

要做到這樣，有兩種方法：

### method 1
以左上到右下的對角線為軸翻轉，然後再將每個**row裡的元素**做reverse。   

<img width="521" height="270" src="https://i.ibb.co/WKkgww1/00001.png">    

### method 2
以右上到左下的對角線為軸翻轉，然後再將**每個row**做reverse。   

<img width="521" height="270" src="https://i.ibb.co/86fN1cq/00001.png">    





---

