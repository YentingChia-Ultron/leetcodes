# 32. Longest Valid Parentheses ( Hard )

+ [Description](#Description)  
+ [Solution](#Solution)  

## Description
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.  

**Example 1:**  

**Input**: "(()"  
**Output**: 2  
**Explanation**: The longest valid parentheses substring is "()"  


**Example 2:**  
 
**Input**: ")()())"  
**Output**: 4  
**Explanation**: The longest valid parentheses substring is "()()"  


## Solution
#### step1 左括號
首先看到這種pair的，就可以先聯想到：或許可以用stack？  
所以這邊當我們一遇到```(```就先把它出現的位置存到stack裡面。  
再來要處理的就是遇到```)```的情況了
#### step2 右括號
這邊分為了三種情況
1. stack是空的  
這很明顯就是不合法的情況，但也代表著之後的合法pair的開始點，必在此位置後，所以要更新start point  

2. stack裡只剩下一個元素（pop之後就沒了的意思）  
首先stack先pop一下
這個時候stack就空了，代表從現在的位置一直往前到start point都會是合法的pair（因為不合法的話start point就會更新）  
所以把結果更新成```max(result, i - start + 1)```  

3. stack裡還有一個以上的元素  
首先stack先pop一下  
這個時候stack還不為空，且stack的top表示這對pair的左括號的前面一個位置（已經先pop過了，pop前的top即pair的左括號）  
所以把結果更新成```max(result, i - mystack.top())```   


Time complexity: O(n)  

---

