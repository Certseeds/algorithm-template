# Problem G

## Description

Van is a boss of SF Express in Shenzhen.

He has $n$ SF Express sites, these sites are connected by $m$ streets and the i-th site has $w_i$ staffs.

To save the cost, Van wants to remove several staffs from them.

However, there is a minimum number of staff requirement in each street, i.e., the j-th street should has at least $c_j$ staffs.

The number of staffs in the j-th street is the sum of staffs in the two sites which are connected by j-th street.

Now, please tell Van what is the minimum and maximum number of staffs you can remove such that the requirement of each street is exactly satisfied.

"exactly" means the sum of the staffs in the two sides connected by j-th street is equal to the minimum number of staff requirement in it.

If you cannot find a feasible solution, print "impossible".

### Input

The first line contains two integers the number of SF Express sites $n(1\leq n\leq 500000)$ and the number of streets $m(1\leq m\leq 3000000)$.

The second line is divided by a space to give $n$ integers, the i-th integer $w(0\leq w\leq 10^6)$ representing the number of staves at the i-th site.

The next $m$ rows each contain three integers $u,v(1\leq u,v\leq n)$, $c(0\leq c\leq 10^6)$, representing the number of staves needed to connect the u-th site and the v-th site in a street of c.

### Output

If a solution exists, output the minimum and maximum values separated by spaces.

Otherwise print "impossible".

### Sample Input

``` log
3 2
5 10 5
1 2 5
2 3 3
```

### Sample Output

``` log
12 15
```

### HINT

Due to the sheer volume of data, even C++ is recommended to use read-in optimisation, , something like:

``` cpp
char BB[1<<15],*K=BB,*T=BB;
#define getc() (K==T&&(T=(K=BB)+fread(BB,1,1<<15,stdin),K==T)?0:*K())
inline long long read() {
    long long x=0;char ch=getc();
    while(ch<'0'||ch>'9') ch=getc();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getc();
    return x;
}
```

Using scanf to read in may result in RE.

### 题目分析

问题：给定无向图顶点初始权重 w_i 和每条边的要求 c_j（要求边两端权重之和等于 c_j），求能删除的员工数的最小与最大值，或判断不可能。

思路：将每个节点的最终值表示为 x_i。每条边 u-v 给出方程 x_u + x_v = c。把图分成连通块，对每个连通块把 x 表示成 x_i = alpha_i * t + beta_i（alpha_i ∈ {1,-1}）。

通过 BFS 给出 alpha/beta；若遇到确定 t 的方程则固定 t。

对每个连通块在允许区间内选择使得整体 x 非负且不超过原有 w_i，从而得到该连通块在所有合法解下的 x_i 总和的最小值和最大值，最终转换为被删除人数的最小/最大值 = 总初始员工 - 总最终员工。

复杂度：O(n + m) （对每条边只访问常数次），需要注意数值边界与连通块内 t 的可行区间求交。

要点：在构造 alpha/beta 时要照顾无向边在链式前向星中出现两次的事实；连通分量中若出现矛盾或区间无解则无解。
