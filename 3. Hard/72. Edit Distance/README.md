# 72. Edit Distance ( Hard )

+ [Description](#Description)  
+ [Solution](#Solution)  

## Description
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.  

You have the following 3 operations permitted on a word:  

Insert a character  
Delete a character  
Replace a character  

**Example 2:**  

```
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
``` 


## Solution

### idea 1
讓我們先用最簡單的case，來檢視上面的三種 operations 會出現的情況：  
+ Insert：```word1 = ""```, ```word2 = "b"```          
+ Delete：```word1 = "a"```, ```word2 = ""```     
+ Replace：```word1 = "a"```, ```word2 = "b"```  

### idea 2 
我們設一個 m * n 矩陣  
其中 m(i ,j)代表： 將 ```word1[0:i]``` 轉換成 ```word2[0:j]```   
（ ```word1``` 的前 ```i``` 個字符和 ```word2``` 的前 ```j``` 個字符）  
所需要的**最小編輯距離**    

如果今天 ```word1 = "a"```, ```word2 = "b"```    
矩陣將會如下：    

|   **0**   |   **1**   |
|:---------:|:---------:|
|   **1**   |   **1**   |    

### idea 3
這邊詳細說明如何擴充矩陣  

#### step 0
因為很重要，這邊再說一次矩陣代表的意義：  
m(i ,j)代表： 將 ```word1[0...i-1]``` 轉換成 ```word2[0...j-1]```   
（ ```word1``` 的前 ```i``` 個字符和 ```word2``` 的前 ```j``` 個字符）  

#### step 1
先設好邊界：  
因為很明顯的，將```"123" -> ""```或```""- > "123"```的距離，就是不為空的字串的長度  
所以```m[i][0] = i```、```m[0][j]=j```  

#### step 2
如果我們要到達```m[i][j]```，就代表我們會對```word1```做下面三種的其中一種動作，使 ```word1[0...i-1]``` = ```word2[0...j-1]```：  

+ **Insert**：
```word2[j-1]```會加到```word1[0...i-1]```後面 = ````word2[0...j-1]````
所以此時是 ```m[i][j]``` = ```m[i][j-1] + 1```   

+ **Delete**：
```word1```變成```word1[0...i-2]``` = ```word2[0...j-1]```
所以此時是 ```m[i][j]``` = ```m[i-1][j] + 1  ``` 

+ **Replace**：
直接把```word1[i-1]```換成```word2[j-1]``` = ```word2[0...j-1]```
所以此時是 ```m[i][j]``` = ```m[i-1][j-1] + 1```
（當 ```word1[i-1] == word2[j-1]``` 的時候不用加 ```1```，因為替換成同一個字母不算一次步驟）

#### step 3
因為我們只能做三個動作，所以要到我們的最終目標，將 ```word1``` 轉換成 ```word2``` ，也就是矩陣的```[m-1][n-1]``` 位置，一定是從這三個動作來的，所以:  

```c
if(word1[i-1] == word2[j-1])
    m[i][j] = m[i-1][j-1]
else
    m[i][j] = min(Insert, Delete, Replace) = min(m[i][j-1], m[i-1][j] , m[i-1][j-1]) + 1  
``` 


### example
如果今天 ```word1``` = "ab", ```word2``` = "c"      
我們設一個 m * n 矩陣    
 
矩陣將會如下：      

|   **0**   |   **1**   |
|:---------:|:---------:|
|   **1**   |   **min(0, 1, 1) + 1 = 1**   |
| **2** |  **min(1, 1, 2) + 1= 3** |  


---

