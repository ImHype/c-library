## preorder_inorder_tree_recovery

### 时间复杂度
O(N)

### 空间复杂度
o(N（每层） * LogN（层数）)


## postorder_inorder_tree_recovery

### 时间复杂度
O(N)

### 空间复杂度
o(N（每层） * LogN（层数）)


## 为什么前序和后序不能生成二叉树
```
      1
   1          2
 4    5     6
    7   8
```

前序遍历：1  2  4  5  7  8  3  6   
中序遍历：4  2  7  5  8  1  3  6  
后序遍历：4  7  8  5  2  6  3  1  


前序 和 后序有个特点是容易找 根节点，但左子树与右子树的边界无法确定，故能够生成的树会不唯一