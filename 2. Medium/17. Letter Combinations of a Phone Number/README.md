# 17. Letter Combinations of a Phone Number ( Medium )

+ [Description](#Description)  
+ [Solution](#Solution)  

## Description
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.  

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.  

<img width="200" height="162" src="https://i.ibb.co/NszCJTg/200px-Telephone-keypad2-svg.png">    

#### Example :
**Input**: "23"  
**Output**: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].  


## Solution
使用DFS的方法：  
<img width="640" height="331" src="https://i.ibb.co/p0CMP8G/dfs.png">    
從頭開始往下，找到底了後再往回，再往下，再往回......  
到底的時候，記得要把舊的清掉（ pop ）  

 

---

