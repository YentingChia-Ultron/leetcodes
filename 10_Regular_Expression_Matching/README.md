# 5. Longest Palindromic Substring ( Hard )
## Description
Given an input string (s) and a pattern (p), implement regular expression matching with support for ```'.'``` and ```'*'``` .  
```
'.' Matches any single character.
'*' Matches zero or more of the preceding element.
```
The matching should cover the **entire** input string (not partial).  

**Note:**  

+ ```s``` could be empty and contains only lowercase letters ```a-z```.
+ ```p``` could be empty and contains only lowercase letters ```a-z```, and characters like ```.``` or ```*```.  

#### Example 1:
Input:  
s = "aa"  
p = "a"  
Output: false  
Explanation: "a" does not match the entire string "aa".  

#### Example 2:
Input:  
s = "aa"  
p = "a*"  
Output: true  
Explanation: '*' means zero or more of the preceding element, 'a'.  Therefore, by repeating 'a' once, it becomes "aa".  

#### Example 3:
Input:  
s = "ab"  
p = ".*"  
Output: true  
Explanation: ".\*" means "zero or more (*) of any character (.)".   

#### Example 4:
Input:  
s = "aab"  
p = "c\*a*b"  
Output: true  
Explanation: c can be repeated 0 times, a can be repeated 1 time.   Therefore, it matches "aab".  

#### Example 5:
Input:  
s = "mississippi"  
p = "mis\*is\*p*."  
Output: false  

## Solution
如果沒有遇到```*```就直接比對字元是否相符即可。   

這題比較麻煩的情況是遇到```*```，因為它所指的字元，可能會有零個或是很多個  
下面我舉出了三種case：   

| Case 1 | Case 2 | Case 3 |
| -------- | -------- | -------- |
| s = "aaa" | s = "" | s = "aaa" |
| p = "a*" | p = "a*" | p = "a*a" |  

若是不可慮後面（ ```*```之後），則可以將 case 1 的 s 不斷pop，最後就會變成和 case 2 一樣。  
但是，因為後面有可能還有其它字元，若```*```左邊和右邊的字元相等（ case 3 ）， 就不能用上面的方法了。  
遇到```*```要判斷時，應該要把字串打成兩半   
```*```的左邊要判斷：字元是否一樣（ line 23 註解）  
```*```的右邊要判斷：字串是否符合RE （ line 26 註解）

 

---

**總共時間**：O(n^2): O((|s| + |p|) * 2 ^ (|s| + |p|))