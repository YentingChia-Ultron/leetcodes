# 5. Longest Palindromic Substring ( Medium )
## Description
Given a string s, find the longest palindromic substring in s.   
You may assume that the maximum length of s is 1000.

#### Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"  

## Solution
#### Palindromic Substring
Palindromic（回文）是指可以投為映射的字串，而 Substring 則是在一串字串中的連續區間（subsequence則為不連續區間）
#### Method1 Brute Force
##### 檢查回文
<img width="300" height="160" src="https://i.ibb.co/n73NHtM/2020-04-19-11-40-49.png">  

由外往內確認對應字符是不是一樣，如果一直到中間都一樣，那就是回文了。  
花費時間：O(n)   
```
def isPalindromic(s, l, r)
    while l < r :
        if s[l] != s[r] : return False
        l += 1
        r -= 1
    return True
```

##### 檢查所有的子字串
<img width="300" height="160" src="https://i.ibb.co/ZBKqrB6/2020-04-19-11-34-57.png">  

檢查所有的子字串，並找出最長的回文。  
花費時間：O(n＾2)   
```
maxPali = ""
for i in range(n):
    for j in range(i, n):
    if j - i + 1 > len(maxPali) && isPalindromic(s, i, j):
        maxPali = s[i:j+1]
return maxPali
```
**總共時間：O(n^3)**

#### Method2
從題目的 **"maximum length of s is 1000"** 這句話來看，我們便不能使用上述算法，因為1000^3=1百萬，是極有可能**run time error** 的，故我們使用下述方法。  
##### 檢查回文長度
<img width="300" height="160" src="https://i.ibb.co/0qGg4F2/2020-04-19-11-37-30.png">  

這邊我們不判斷他是不是回文，而是直接用由內往外的方法，來找出該位置所能，來找出該位置所能擴展出的最長回文。  
花費時間：O(n)   
```
int getPalindromeLen(int l, int r, const string& s)
    {
        while((l>=0) && (r<s.size()) && (s[l]==s[r]))
              {
                  l--;
                  r++;
              }
        return  r-l-1;
    }
```

然後遍尋字串 （ O(n) ）找到最長回文   
**總共時間：O(n^2)**  
 