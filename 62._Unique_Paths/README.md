# 62. Unique Paths ( Medium )

+ [Description](#Description)  
+ [Solution](#Solution)  

## Description
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).  

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).  

How many possible unique paths are there?  

**Example 1:**  

```
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
```


**Example 2:**  

```
Input: m = 7, n = 3
Output: 28
```

**Constraints:**  
+ 1 <= m, n <= 100
+ It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.

## Solution

這題跟爬梯子那（[70. Climbing Stairs](https://github.com/fhsi5794/leetcodes/tree/master/70._Climbing_Stairs)  ）題很像，因為你只能往右或是往左走，所以你到達目的地的前面一步，一定會是在目的地的上方或是下方。  
所以，如果我們要找到到達目的地的走法，就必須把目的地上方和下方位置的走法總和起來。  
以此類推，不斷往前找到其上方和下方的總和，一直到第一列或是第一行，因為他們的走法必定為 1 。   

|   |    0   |           1           |           2           |
|:-:|:------:|:---------------------:|:---------------------:|
| 0 | 1 step |         1 step        |         1 step        |
| 1 | 1 step | 1（Left）+ 1（Up）= 2 | 2（Left）+ 1（Up）= 3 |
| 2 | 1 step | 1（Left）+ 2（Up）= 3 | 1（Left）+ 2（Up）= 3 |     


_範例程式一為比較好理解的空間為（m * n）的解法，程式二則是將其精簡，將空間降成（n）。_   


---

