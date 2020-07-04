# 23. Merge k Sorted Lists ( Hard )

+ [Description](#Description)  
+ [Solution1](#Solution1)  
+ [Solution2](#Solution2)  

## Description
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.  

**Example**:  
```
**Input**:
[
  1->4->5,
  1->3->4,
  2->6
]
**Output**: 1->1->2->3->4->4->5->6
```

## Solution1
先從第 1 個、第 2 個合併排序成新的list  
然後這個list再接續和第 3 、 4 、 5 ...... n 個合併排序     

<img width="421" height="271" src="https://i.ibb.co/JQHPqw3/merge0.png">      

Runtime：176 ms  

## Solution2
為了使上面的解法可以更有效率，我們這邊要用 **divide and conquer** 的方法  
將list分為左右兩半，使兩邊都先行排序，然後再合併彼此。  

<img width="600" height="340" src="https://i.ibb.co/kMSScJ9/merge2.png">      

Runtime：24 ms  

---

