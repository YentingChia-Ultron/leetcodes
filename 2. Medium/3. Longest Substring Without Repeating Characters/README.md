# 3. Longest Substring Without Repeating Characters ( Medium )

+ [Description](#Description)  
+ [Solution](#Solution)  

## Description
Given a string, find the length of the longest substring without repeating characters.   

#### Example 1
**Input**: "abcabcbb"  
**Output**: 3   
**Explanation**: The answer is "abc", with the length of 3.  

#### Example 2
**Input**: "bbbbb"  
**Output**: 1   
**Explanation**:The answer is "b", with the length of 1.  

#### Example 3
**Input**: "pwwkew"  
**Output**: 3   
**Explanation**: The answer is "wke", with the length of 3.  
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.  

## Solution
注意：  
不是求**不同字元的數量**。  
是求**沒有重複字元的一組字串**。    
 

直接用ASCII存取vector（像是hash map），記錄字元上一次出現的位置（若沒出現過則為-1）
```
vector<int> position(128, -1);
```  

遍歷（ for loop ) 字串，更新窗口大小：   
left指向無重複字串的最左邊。  
```
left = max(left, position[s[i]] ); 
```  
result為無重複字串中的最大值，也就是窗口大小。
```
result = max(result, i - left); 
``` 