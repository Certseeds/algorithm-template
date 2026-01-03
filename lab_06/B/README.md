# lab_06_B — FSA Transition Function

## Description

As learned in the lecture, FSA can be used to solve string matching problems.

Here you are given a string \(S\), and you are required to output it's transition function according to the FSA algorithm.

## Input

One line, indicating the input string \(S\) \((1\leq |S| \leq 10^5)\).

The string contains only lowercase letters.

## Output

\(|S|\) lines, each containing 26 integers, indicating the transition function.

## Sample Input

```log
aabaaabb
```

## Sample Output

```log
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
2 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
5 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
6 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
2 7 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
4 8 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
```

## HINT

## 复用信息

+ Contest 1101:CS203 2021 Fall Lab 06 String
+ Contest 1102:CS217 2021 Fall Lab 06 String
+ Contest 1122:CS203 2022 Fall Lab 5 String
+ Contest 1123:CS217 2022 Fall Lab 5 String
+ Contest 1144:CS203 2023 Fall Lab 5 String
+ Contest 1170:CS203 2024 Fall Lab 5
