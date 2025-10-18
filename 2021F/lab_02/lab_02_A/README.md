 # Problem A (inferred)

## Description

Given a set of integers and several query values, determine for each query whether the value exists in the set.

Output "YES" if it exists, otherwise output "NO".

## Input

- Line 1: integer n, the number of elements in the set.
- Line 2: n integers (space-separated), the elements of the set.
- Next: integer T, the number of queries.
- Next T integers (whitespace separated or one per line): the queries.

## Output

Output T lines. For each query print either:

- `YES` if the queried value is in the set
- `NO` otherwise

## Sample

### Sample Input

```text
4
1 2 3 999999
2
99
3
```

### Sample Output

```text
NO
YES
```

## Implementation notes

- The provided implementation stores elements in an `unordered_set<int32_t>` and answers each query by O(1) average-time hash lookup.

- Current code uses 32-bit signed integers; if input values may exceed int32 range, switch to 64-bit types.

## 复用信息

+ Contest 1162:CS203 2024 Fall Lab 1
+ Contest 1093:CS203 2021 Fall Lab 02 Complexity + Binary Search
+ Contest 1094:CS217 2021 Fall Lab 02 Complexity + Binary Search
+ Contest 1135:CS203 2023 Fall Lab 1 Complexity + Binary Search
+ Contest 1186:CS203 2025 Fall Lab 1 Complexity + Binary Search

# Solution / 思路解析

- 思路概述：把给定集合中的元素放入一个哈希集合（`unordered_set`），对每个查询直接判断是否存在，从而以接近 O(1) 的均摊时间回答。
- 算法要点：读取 n 个元素并插入 `unordered_set`；然后对每个查询，在哈希集合中查找并输出 `YES`/`NO`。
- 复杂度：构建集合 O(n)（均摊），每次查询 O(1)（均摊），总时间 O(n + T)。空间 O(n)。
- 边界与实现注意事项：
  - 输入可能包含重复元素（哈希集合会自动去重），但查询逻辑不受影响。
  - 若数据可能超出 32 位范围，则把 `int32_t` 换成 `int64_t`。
  - 对于极端输入（非常大的 n），确保 reserve 集合以减少 rehash 开销（可选优化）。
