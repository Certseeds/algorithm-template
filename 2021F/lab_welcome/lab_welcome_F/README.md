# Problem F (Order 1419)

## Description

Let $S(X)=\sum_{j=1}^X f(j)$, where $f(x)$ is a sum of one or more functions chosen from

$$
F=\{C,\; C/x,\; C\sin x,\; C\cos x,\; C/\sin x,\; C/\cos x,\; C^x,\; Cx\}
$$

where $C$ is an integer constant in $[0,10^{9}]$.

## Input

The first line contains an integer $t$ $(1\le t\le 10^4)$, the number of test cases.

Each of the next $t$ lines contains a string $s$ $(1\le |s| \le 100)$ describing the formula of $f(x)$.

Fractions are written as $a/b$. Exponential $C^x$ is written as $C^x$. The constant $C$ is always present even when $C=1$. Adjacent functions in $f(x)$ are connected by $+$.

## Output

For each test case, output "yes" if $S(X)$ is convergent; otherwise output "no".

## Sample Input

``` log
2
2sinx+0cosx+4x+1/sinx+0
0
```

## Sample Output

``` log
no
yes
```

## Hint

We say $S(X)$ is convergent if $\lim_{X\to\infty} S(X)=A$ for some finite $A$.

## 实现分析

- 实现要点: `main.cpp` 将每个输入表达式按 '+' 分割为若干项, 解析每一项的前导常数 C (整数). 题目给定的原函数集合中, 只有当所有项的系数 C 等于 0 时, 累加和 S(X) 才可能收敛 (因为含有 x、C^x、C*x、1/sin x 等项都会导致不收敛, 除非对应常数为 0). 因此实现简单地检查所有项的 C 是否为 0.
- 复杂度: 对每个公式字符串, 按 '+' 切分并解析前缀数字, 时间复杂度为 O(len(s)). 总体线性复杂度, 空间复杂度 O(1) 额外开销.
- 注意事项: 实现假设输入格式规范, 常数 C 紧跟在项首部 (例如 "2sinx" 或 "0"), 并且使用 stoull 解析数字; 遇到字符串为 "0" 的特殊情况直接返回 yes.
