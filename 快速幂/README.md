# 快速幂

    快速幂还有其他的名称如反复平方法。

数论计算中经常出现的一种运算就是求一个数的幂对另一个数的模运算(余数)，也称为模取幂。更加明确的说，这种算法的任务就是快速高效的计算$`a^b\ mod\ n`$的值，其中$`a,b`$是非负整数，$`n`$是正整数。

>幂运算的乘法法则：$`a^i*a^j=a^{i+j}`$，特别地，当$`i=j`$ 时，$`a^i*a^i=a^{2i}`$。

由此我们可以得到这样的递归式

```math
a^b=
\begin{cases}
1& b=0\\
a^{\frac{b}{2}}*a^{\frac{b}{2}}& b=2k\\
a^{\frac{b}{2}}*a^{\frac{b}{2}}*a& b=2k+1
\end{cases}
```

>模运算的乘法法则：$`a*b\ mod\ n=((a\ mod\ n)*(b\ mod\ n))\ mod\ n`$

上面的递归式修改一下

```math
a^b=
\begin{cases}
1 mod n& b=0\\
(a^{\frac{b}{2}}\ mod\ n)*(a^{\frac{b}{2}}\ mod\ n)\  mod\ n& b=2k\\
(a^{\frac{b}{2}}\ mod\ n)*(a^{\frac{b}{2}}\ mod\ n)*(a\ mod\ n)\ mod\ n& b=2k+1
\end{cases}
```

这样我们就可以在$`O(log_2b)`$的时间内得到$`a^b\ mod\ n`$的值。

------

除了递归式的形式外，我们还有另一种形式。

>任意一个正整数数都可以表示为有限个$`2^i`$和的形式，即$`n={\alpha_1}2^1+{\alpha_2}2^2+...{\alpha_k}2^k`$，将$`\alpha_k`$提出出来之后的有序序列$`{\alpha_k}...{\alpha_2}{\alpha_1}`$即为n的二进制位表示形式，$`{\alpha_i}`$即为$`n`$在第$`i`$位上的二进制数。

这样$`a^b`$就可以表示成$`a^{{\alpha_1}2^1+{\alpha_2}2^2+...{\alpha_k}2^k}=a^{{\alpha_1}2^1}a^{{\alpha_2}2^2}...a^{{\alpha_k}2^k}`$。

```math
a^{{\alpha_k}2^k}=
\begin{cases}
1& {\alpha_k=0}\\
a^{2^k}& {\alpha_k=1}
\end{cases}
```

而$`a^{2^k}=a^{2^{k-1}}*a^{2^{k-1}}`$，这样从1到k对$`a`$进行反复平方就可以依次求的$`a^{2^i}`$