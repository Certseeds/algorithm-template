# Problem E (Order 1418)

## Description

Lihua defines a Magic Number as a number that remains the same when rotated 180 degrees. For example, 69, 96, 111, 181 are magic numbers; 87 and 76 are not.

Digits 0, 1, 8 remain the same after rotation; 6 becomes 9 and 9 becomes 6; digits 2 and 5 are invalid for rotation.

Now Lihua wants to find the smallest and largest magic numbers in a given range [L, R].

## Input

Multiple test cases (less than 5).

Each test contains two integers $L$ and $R$. $0 \le L \le R \le 10^{12}$.

It is guaranteed that there is at least one magic number in the interval $[L, R]$.

## Output

For each test case, output two integers on one line: the smallest and largest magic number within [L, R].

## Sample Input

``` log
50 100
150 200
```

## Sample Output

``` log
69 96
181 181
```

## Hint

Use EOF to detect end of input. In C++:

``` cpp
while (cin >> l >> r) {
    ...
}
```

in Java: 

``` java
while (sc.hasNext()) {
    l = sc.nextInt(); r = sc.nextInt();
}
```

On the command line, use Ctrl+D (or possibly Ctrl+Z) to signal EOF.

## 实现分析

- 实现要点: `main.cpp` 使用递归构造回文式的 strobogrammatic 数 (旋转 180° 保持不变或互换的数字对). 对每个长度在 lenL..lenR 之间生成所有候选字符串 (注意首位不能为 '0'), 将其转换为整数并判断是否在 [L,R] 范围内, 维护最小与最大值.
- 复杂度: 生成的字符串数与位数有关. 最坏情况下枚举所有长度为 L..R 的候选值, 时间复杂度近似为枚举这些长度上的组合数 (指数级但受位数上限 log10(R) ≤ 12 限制). 对于本题的上界 10^12, 枚举是可行的.
- 注意事项: 在生成时禁止最高位为 '0', 并在转换为整数时使用 unsigned long long 以避免溢出; 主循环以 EOF 控制读取多个测试用例.
