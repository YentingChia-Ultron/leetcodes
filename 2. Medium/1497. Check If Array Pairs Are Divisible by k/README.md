# 1497. Check If Array Pairs Are Divisible by k ( Medium )

+ [Description](#Description)  
+ [Solution](#Solution)  

## Description
Given an array of integers arr of even length n and an integer k.  

We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.  

Return True If you can find a way to do that or False otherwise.  

**Example 1:**  

**Input**: arr = [1,2,3,4,5,10,6,7,8,9], k = 5        
**Output**: true    
**Explanation**: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).    

**Example 2:**  

**Input**: arr = [1,2,3,4,5,6], k = 7        
**Output**: true    
**Explanation**: Pairs are (1,6),(2,5) and(3,4).    

**Example 3:**  

**Input**: arr = [1,2,3,4,5,6], k = 10        
**Output**: false    
**Explanation**: You can try all possible pairs to see that there is no way to divide arr into 3 pairs each with sum divisible by 10.    

**Example 4:**  

**Input**: arr = [-10,10], k = 2        
**Output**: true    

**Example 5:**  

**Input**: arr = [-1,1,-2,2,-3,3,-4,4], k = 3        
**Output**: true       

**Constraints:**  

+ arr.length == n
+ 1 <= n <= 10^5
+ n is even.
+ -10^9 <= arr[i] <= 10^9
+ 1 <= k <= 10^5

## Solution

### 條件
如果想要整除k，配對成一組的兩個數就可以分為兩種：  
1. 兩個數都是k的倍數
2. 兩個數相加為k的倍數

### 解法
所以如果我們想要找到是否全部都可以配對成功，就要看看下面三種情況是不是都符合：
1. 為k的倍數的元素數量，是否能整除2（能成對組合）  _**[條件一]**_  
2.    ```i != j```  
``` a = arr[i] % k```  
```b = arr[j] % k```  
若 ```a + b = k```，a出現的次數和b出現的次數，是否相等   _**[條件二]**_  
3. 若k為偶數，則```arr[i] % k ＝ k / 2```的元素數量，是否能整除2（能成對組合）   
_**因為當k為偶數時，能和餘數為k / 2相加為k的元素，就只有同為餘數為k / 2的元素**_    

---

