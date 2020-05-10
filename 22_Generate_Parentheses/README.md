# 22. Generate Parentheses ( Medium )

+ [Description](#Description)  
+ [Solution](#Solution)  

## Description
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.  

For example, given n = 3, a solution set is:  
```
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
] 
```

## Solution
與17題類似，先使用DFS的方法，找出所有可能性：  
因為左右括弧必成對出現，所以當有一方等於0，另一方大於0時，則沒必要繼續往下找。  
最終將停在雙方都等於0。  
<img width="1368" height="503" src="https://i.ibb.co/qpdf58S/DFS2.png">      
**左邊是' ( '  ,  右邊是' ) '**  

由上圖可以看出來，但凡遇到**L > R**的情況，括號的 format 就會不合法。  
所以一旦遇到**L > R**，就直接跳出，則可以使最後得到的都是合法解，並減少運算時間。  

當然，如果覺得這樣太複雜，也不是不行列出全部的結果之後，最後再一併判斷合法性。  
 

---

