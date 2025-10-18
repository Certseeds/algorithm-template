# Problem C (Order 1423)

## Description

Given $F(x) = x e^{x/20} - b$, $x \in \mathbb{R}$. Here $e$ is Euler's number (approximately $2.718281828459\ldots$), and $b$ is a given integer.

Please find a root of $F(x)$.

## Input

The 1st line is a positive integer $T$ ($1 \le T \le 1000$) which is the number of test cases.

Then $T$ lines follow. Each line has an integer $b$ ($1 \le b \le 10^8$) for a test case.

## Output

Output $T$ lines.

Each line contains a number $ans$ (accurate up to 10 decimal places), representing the approximate zero point of $F(x)$ and $|F(ans)| < 0.01$.

## Sample Input

```text
2
1
20
```

## Sample Output

```text
0.9448242188
11.3433837891
```

## Hint

This problem uses special judge, so the sample output is not the only answer.

## Solution / 思路解析

- 思路概述：要解方程 $F(x)=x e^{x/20}-b=0$，可以对 $x$ 使用二分查找或数值方法（如二分/牛顿法）。题目实现采用对 $x$ 在合理区间做二分搜索，直到函数值接近 0（满足精度要求）。
- 关键细节：给定 $b$ 不同，其对应根 $x$ 在不同范围。实现中选取了固定的左右边界（例如 $[0.9, 258]$ 覆盖题目约束），然后在该区间内通过计算 $f(x)=x e^{x/20}-b$ 并根据符号向左或向右收缩区间，即典型的二分求根法。
- 精度与停止条件：当 $|f(x)| < \varepsilon$（实现中取 pricesion = 1e-4）时返回当前近似值；输出时保留 10 位小数。
- 复杂度：对每个测试用例，二分迭代次数为 O(log((R-L)/eps))，每步计算需要一次指数运算，故时间复杂度可认为是常数乘以二分迭代次数。
- 注意事项：选择区间时要确保包含根；对边界和极端 b 的处理需验证区间是否足够大。
