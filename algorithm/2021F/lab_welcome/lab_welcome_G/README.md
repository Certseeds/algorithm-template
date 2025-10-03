# Problem G (Order 1420)

## Description

In this game, you first choose $n$ integers with values in $[1,13]$.

For these $n$ integers, you can arrange them in arbitrary order, insert the operators $+$, $-$, $\times$, $\div$ and parentheses to obtain an expression. The goal is to make the expression evaluate to $m$.

You may have many valid solutions. For example, if $n=4$ and $m=24$, we have two solutions: $A=(2,2,3,8)$ and $B=(1,5,5,5)$.

A has many expressions such as $3/2\times8\times2$ or $3\times8\times2/2$. The expressions for $B$ include $5\times(5-1/5)$ and $(5-1/5)\times5$.

We say $B$ is a valid solution if in all expressions formed by its multiset of numbers there is at least one non-integer intermediate result (for example $1/5$). A is not valid because expressions like $3\times8\times2/2$ do not require non-integer intermediate values.

Return the number of valid solutions for the given $n$ and $m$. Note permutations such as $(1,5,5,5)$ and $(5,1,5,5)$ are considered the same solution.

## Input

The only line of input contains two integers: $n$ and $m$, where $1 \le n \le 4$ and $1 \le m \le 10^9$.

## Output

The number of valid solutions.

## Sample Input

``` log
4 159
```

## Sample Output

``` log
8
```

## HINT

The correspond solutions to the sample is:

``` log
2,8,12,13
3,12,12,13
3,12,13,13
4,5,12,12
4,9,11,12
4,10,12,13
8,10,12,12
10,13,13,13
```

> GPT-5 Mini 无法解决
>
> GPT-5 可以解决
>
> 真是小众变态题目

## 实现分析

注意事项: 实现包含若干剪枝:

+ 乘积上界剪枝 (若 m 大于元素乘积则跳过), 整数先验检查避免不必要的有理数搜索
+ 有理数表示不做约分以减少开销但每次设置后均调用 `rat_fix_sign` 确保分母正
+ 对于更大的 n 或更宽的元素范围需要额外优化 (如记忆化、子集 DP 或位掩码枚举)

复杂度: 由于 n ≤ 4 且每个元素范围有限, 枚举非降序组合数量受限 (组合计数), 对于每个组合进行的递归搜索代价较高但在限制范围内可行.

总体在最坏情况下为枚举组合数乘以每个组合的表达式枚举复杂度 (指数级但受 n ≤ 4 限制).

- 实现要点: `main.cpp` 在多重集合层面生成所有非降序的长度为 n 的组合 (元素范围 [1,13]), 对每个组合先做快速的整数可达性搜索 (`dfs_int`), 如果存在纯整数表达式可以得到 m 则直接跳过 (因为题目要求所有表达式必须至少出现一次非整数中间结果).

如果整数搜索不成立, 则进行有理数 (分数) 搜索 `dfs_rat` 判断是否存在任意表达式能达到 m (判断基于 a/b == m)

整数搜索的除法仅在整除时允许; 有理数搜索在每次二元运算后用未约分的分子/分母表示并修正符号以避免分母为负.
