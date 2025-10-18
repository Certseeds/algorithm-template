# lab_06_C — KMP Next Array

## Description

Given a string `S` with length `n`, you are required to calculate its next array of the KMP algorithm.

## Input

One line containing `S` `(1<= |S| <= 10^6)`

## Output

`n` lines, each containing a integer, indicating the next array value of `S[i]` for `0 <= i <= len(s)-1`

## Sample Input

```log
ababc
```

## Sample Output

```log
0
0
1
2
0
```

## HINT

`next[0] = 0`
