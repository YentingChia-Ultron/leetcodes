# 76. Minimum Window Substring ( Hard )

+ [Description](#Description)  
+ [Solution](#Solution)  

## Description
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

**Example :**  

```
Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
``` 
**Note :**   
+ If there is no such window in S that covers all characters in T, return the empty string ```""```.
+ If there is such window, you are guaranteed that there will always be only one unique minimum window in S.

## Solution
這題限制了O(N)，所以我們不能用暴力破解，因為那會至少是O(n^2)。    
但是要怎麼做到O(N)呢？我們先用一個簡單點的例子來想想好了！  

### idea 1
假設 ```S = "AAKB"```  ```T = "BA"```    
如果我們用肉眼來判斷，大概是這樣的步驟：  
1. 第一個字是```A```......所以我們只剩下```B```要找了！
2. 第二個還是```A```......先不管，我們先找```B```  
3. 第三個是```K```，一樣先略過
4. 第四個......找到```B```了！
5. 剛剛好像有看到一個離比較近的```A```？......有了，第二個的```A```！
6. 所以答案是```AKB```！！  

### idea 2
所以上面的行為，可以說是一連串「找齊全```T```」、「縮小範圍」的重複行為。  
那程式的實作似乎就變得容易了！  

#### step 1
我們首先要記錄T中每個字元出現過的次數，代表程式是這段：  
```c
for(char c : t) ++latterCount[c];
```   

#### step 2
遍歷S  
如果遇到T中出現過的字元，便將剛剛紀錄過的次數-1，代表已經遇到過了  
代表程式是這段：  
```c
for(int i = 0; i < s.size(); i++)
    if(--latterCount[s[i]] >= 0) count++;
```  

若是所有的T裡的字元都已經遇到至少一次，那就代表我們已經找到了一個大範圍，現在要做的就是縮減範圍，把left往右推   
代表程式是這段：  
```c
    while(count == t.size())
    {
        ...
        left++;
    }
```    




---

