# 49. Group Anagrams( Medium )

+ [Description](#Description)  
+ [Solution](#Solution)  

## Description
Given an array of strings, group anagrams together.  

**Example :**  

```
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
```

**Note:**   
+ All inputs will be in lowercase.  
+ The order of your output does not matter.   


## Solution
不同排列方法，但相同字元組成的字串，經過排序後，必定會相同。  

若直接用排列過的字串當作 key 存入 map 中，便可以很快速的存取。      

---

