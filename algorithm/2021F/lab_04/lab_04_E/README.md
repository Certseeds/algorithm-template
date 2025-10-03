# lab_04_E — Delete Decreasing Numbers

## Description

Given a sequence `{a[i]}` of length `n`, we define `a[i]` as a decreasing number if `a[i-1] > a[i]` (when `i-1 >= 1`) or `a[i] > a[i+1]` (when `i+1 <= n`).

Please process the given sequence by deleting the decreasing numbers in it. In each turn you should delete all the decreasing numbers in the sequence at the same time. Repeat the procedure until the sequence has no decreasing numbers.

### Input

The first line of input contains an integer `T` (1 <= `T` <= 10) which is the number of test cases.

For each test case, there are two lines. The first line contains an integer `n` (n <= 100000).

The second line contains `n` integers representing the sequence `{a[i]}` (1 <= `a[i]` <= 100000).

### Output

One line per test case representing the final result sequence.

### Sample Input

```log
2
10
1 4 4 3 2 8 9 4 5 7
5
1 8 6 2 4
```

### Sample Output

```log
1 4 7
1 4
```

## 复用信息

+ Contest 1097:CS203 2021 Fall Lab 04 LinkedList
+ Contest 1098:CS217 2021 Fall Lab 04 LinkedList
+ Contest 1141:CS203 2023 Fall Lab 3 LinkedList
