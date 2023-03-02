# Lab0 : SparseMatrix
## 数据结构设计以及实现思路
节点类，ij表示位置，v表示值
```cpp
struct SPNode{
    int i, j;
    int v;
};

```
矩阵类，mu，nu表示位置，tu表示非零元素个数，data表示非零界点集
```cpp
class SparseMatrix {
private:
    int mu, nu, tu;
    SPNode data[MAX_SIZE];
public:
    ...
};
```

## 对比分析两种矩阵乘法

### 时间复杂度：
假设有两个矩阵 ： L_mn, R_nq

|    算法    | 时间复杂度  |                分析                 |
|:--------:|:--------:|:---------------------------------:|
|   矩阵乘法   | O(n^3) | 前提是左侧矩阵列数等于右侧矩阵行数，运算次数等于N * M * Q |
|  稀疏矩阵乘法  | O(n^2) |               N * Q               |

### 空间复杂度
假设有两个矩阵 ： L_mn, R_nq

|    算法    | 时间复杂度  |                  分析                   |
|:--------:|:------:|:-------------------------------------:|
|   矩阵乘法   | O(n^2) |   R : m * n ; L : n * q 每个元素占据一个空间    |
|  稀疏矩阵乘法  |  O(n)  | 完全取决于矩阵内非零元素数量，最坏可能为nm，如果这样也不必用稀疏矩阵运算 |

