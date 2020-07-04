# 70. Climbing Stairs ( Easy )

+ [Description](#Description)  
+ [Solution](#Solution)  

## Description
You are climbing a stair case. It takes n steps to reach to the top.  

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?  

Note: Given n will be a positive integer.   

**Example 1:**  

**Input**: 2      
**Output**: 2  
**Explanation**: There are two ways to climb to the top.  
1. 1 step + 1 step  
2. 2 steps      


**Example 2:**  

**Input**: 3        
**Output**: 3    
**Explanation**: There are three ways to climb to the top.  
1. 1 step + 1 step + 1 step  
2. 1 step + 2 steps  
3. 2 steps + 1 step  


## Solution

因為一次是爬**一階**或**兩階**，所以當我們要爬 ```i 階```的時候，我們的前一步，一定會先爬到 ```i - 1 階```或 ```i - 2 階```。  
換句話說 :  
 ```i 階``` = ```i - 1 階``` + 1   
 或   
 ```i 階``` = ```i - 2 階``` + 2  
 所以，若要論到達 ```i 階``` 的所有方法，我們就要把到達 ```i - 1 階``` 和 ```i - 2 階``` 的方法加總起來。    

|  n = 1  |  n = 2  |  n = 3  |  n = 4  |  n = i  |
|:-------:|:-------:|:-------:|:-------:|:-------:|
| ans[1] = 1 | ans[2] = 2 | ans[3] = 3 | ans[4] = 5 | ans[i] = ans[i-1] + ans[i-2] |  


---

