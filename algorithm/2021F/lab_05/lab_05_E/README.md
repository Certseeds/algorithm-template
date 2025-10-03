# lab_05_E — Deque Operations

## Description

In the library, LowbieH is learning the double-ended queue, which is also called deque.

He thinks that it is very interesting and invites you to join him.

Now there are `n` empty deques numbered from `1` to `n`, you need to implement three types of operations that LowbieH asks you.

Type-1: `1 u w val`. Insert `val` to the deque numbered by `u`. (`w=0` means that the insertion is done in the front, `w=1` means that the insertion is done in the rear)

Type-2: `2 u w`. Query the front or the rear element in the deque numbered by `u` and pop it out. (`w=0` means the front, `w=1` means the rear)

Type-3: `3 u v w`. Connect the deque numbered by `v` to the rear of the deque numbered by `u(u != v)`. (`w=0` means a direct connection, `w=1` means a reversed connection, that is to say you need to first reverse the deque numbered by `v` and then connect them)

The deque numbered by `v` will be cleared after the connection.

## Input

Multiple test cases .

Please process to the end of file .

For each test case, the first line contains two integers `n(1<= n <= 10^5)` and `q(1<= q <= 10^5)`, denoting the number of the deques and the number of the operations.

The following `q` lines will be the three types of operations that have been explained.

`1<= u,v <= n`, `0<= w <= 1`, `1<= val <= 10^5`.

It is guaranteed that the total number of operations will not exceed `3*10^5`.

## Output

Print one line an integer denoting the answer for each type-2 operation.

If the deque is empty, then print `-1` instead.

## Sample Input

```log
2 10
1 1 1 23
1 1 0 233
2 1 1
1 2 1 2333
1 2 1 23333
3 1 2 1
2 2 0
2 1 1
2 1 0
2 1 1
2 10
1 1 1 23
1 1 0 233
2 1 1
1 2 1 2333
1 2 1 23333
3 1 2 1
2 2 0
2 1 1
2 1 0
2 1 1
```

## Sample Output

```log
23
-1
2333
233
23333
23
-1
2333
233
23333
```

## HINT

The data is randomly generated , so you can assume that the expected length of each deque is very small.

You are encouraged to self-study the implementation of deque

## 复用信息

+ Contest 1083:2020 Fall Lab05 Stack + Queue
+ Contest 1168:CS203 2024 Fall Lab 4
+ Contest 1099:CS203 2021 Fall Lab 05 Stack + Queue
+ Contest 1100:CS217 2021 Fall Lab 05 Stack + Queue
