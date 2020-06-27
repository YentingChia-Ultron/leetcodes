# 41. First Missing Positive ( Hard )

+ [Description](#Description)  
+ [Solution](#Solution)  

## Description
Given an unsorted integer array, find the smallest missing positive integer.  

**Example 1:**  

**Input**: [1,2,0]        
**Output**: 3  
 
 
**Example 2:**  

**Input**: [3,4,-1,1]          
**Output**: 2   
 
**Example 3:**  

**Input**: [7,8,9,11,12]           
**Output**: 1      


## Solution
題目要求時間複雜度不能超過O(n)，所以這題我們勢必不能先sort過，再去尋找答案，所以我們需要換一個思路。  


這題可能答案的**最小值**為：1 、 **最大值**為：n + 1（假設size = n)    
下面有幾個例子來解釋？   
1.  
假設今天這組數列是從1開始的連續數列```[1,2,…,n-1,n]```，如下圖：
<img width="321" height="71" src="https://i.ibb.co/nkmGJVJ/2020-06-27-18-23-27.png">   

那我們找到的答案就會是 5 ，也就是 ```n + 1```。    

2.  
那假如是不連續區間呢？
<img width="321" height="71" src="https://i.ibb.co/zNf1Tp6/2020-06-27-18-29-06.png">    

如這題的答案為 3，我們可以發現到，答案便是```[1,2,…,n-1,n]```區間的**缺失值**。  

那我們再進一步想想，如果我們將數列整理一下，使元素 i 剛好在i - 1的位置上，也就是```nums[i - 1] == i```=>```nums[i] == i + 1```  
要做到上面這點，元素i的值就必須介於1~n，也就是```1 >= nums[i] && nums[i] <= n```  
所以，我們下面只會整理符合條件的元素，若元素不符合條件我們就不理他。  

下面是程式：  
我們現進行整理    
```c
for(int i = 0; i < n; i++)
    while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
        swap(nums[i], nums[nums[i] - 1]);
```  

若發現對應的位置上出現不對應的值，就帶表它（這個位置的index）就是我們要找的**區間缺失值**  
```c
for(int i = 0; i < n; i++)
            if(nums[i] != i + 1)
                return i + 1;
```  

這樣時間複雜度為 O(2n) == O(n) ，符合題目要求  


---

