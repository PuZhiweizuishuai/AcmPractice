# 矩阵

>n行m列的数阵称为矩阵，计作$`n{\times}m`$矩阵。

>$`1`$行或$`1`$列的矩阵称为向量。

>行数和列数相等的$`n{\times}n`$矩阵成为方阵，$`n`$为方阵的阶数。

>主对角线为$`1`$，其他位置为$`0`$的方阵称为单位矩阵，比如三阶单位矩阵：$`\begin{bmatrix}1&0&0\\0&1&0\\0&0&1\end{bmatrix}`$

------

## 矩阵的加法：

```math
\left[
\begin{matrix}
a_{11} & a_{12} & \cdots & a_{1m}\\
a_{21} & a_{22} & \cdots & a_{2m}\\
\vdots & \vdots & \ddots & \vdots\\
a_{n1} & a_{n2} & \cdots & a_{nm}
\end{matrix}
\right]
+
\left[
\begin{matrix}
b_{11} & b_{12} & \cdots & b_{1m}\\
b_{21} & b_{22} & \cdots & b_{2m}\\
\vdots & \vdots & \ddots & \vdots\\
b_{n1} & b_{n2} & \cdots & b_{nm}
\end{matrix}
\right]
=
\left[
\begin{matrix}
a_{11}+b_{11} & a_{12}+b_{12} & \cdots & a_{1m}+b_{1m}  \\
a_{21}+b_{21} & a_{22}+b_{22} & \cdots & a_{2m}+b_{2m}  \\
\vdots        & \vdots        & \ddots & \vdots         \\
a_{n1}+b_{n1} & a_{n2}+b_{n2} & \cdots & a_{nm}+b_{nm}
\end{matrix}
\right]
```

------

## 矩阵的减法：

```math
\left[
\begin{matrix}
a_{11} & a_{12} & \cdots & a_{1m}\\
a_{21} & a_{22} & \cdots & a_{2m}\\
\vdots & \vdots & \ddots & \vdots\\
a_{n1} & a_{n2} & \cdots & a_{nm}
\end{matrix}
\right]
-
\left[
\begin{matrix}
b_{11} & b_{12} & \cdots & b_{1m}\\
b_{21} & b_{22} & \cdots & b_{2m}\\
\vdots & \vdots & \ddots & \vdots\\
b_{n1} & b_{n2} & \cdots & b_{nm}
\end{matrix}
\right]
=
\left[
\begin{matrix}
a_{11}-b_{11} & a_{12}-b_{12} & \cdots & a_{1m}-b_{1m}  \\
a_{21}-b_{21} & a_{22}-b_{22} & \cdots & a_{2m}-b_{2m}  \\
\vdots        & \vdots        & \ddots & \vdots         \\
a_{n1}-b_{n1} & a_{n2}-b_{n2} & \cdots & a_{nm}-b_{nm}
\end{matrix}
\right]
```

------

## 矩阵的乘法

### 数与矩阵相乘：

```math
\left[
\begin{matrix}
a_{11} & a_{12} & \cdots & a_{1m}\\
a_{21} & a_{22} & \cdots & a_{2m}\\
\vdots & \vdots & \ddots & \vdots\\
a_{n1} & a_{n2} & \cdots & a_{nm}
\end{matrix}
\right]
{\times}k
=
\left[
\begin{matrix}
a_{11}k & a_{12}k & \cdots & a_{1m}k\\
a_{21}k & a_{22}k & \cdots & a_{2m}k\\
\vdots & \vdots & \ddots & \vdots\\
a_{n1}k & a_{n2}k & \cdots & a_{nm}k
\end{matrix}
\right]
```

### 矩阵与矩阵相乘

>假设矩阵$`A`$为$`n{\times}p`$矩阵，矩阵$`B`$为$`p{\times}m`$矩阵，得到的结果矩阵$`C`$为$`n{\times}m`$矩阵。计算方法为$`C_{ij}=\sum\limits_{k=1}^{p}A_{ik}{\times}B_{kj}`$

矩阵与矩阵相乘的情况有些特殊，为了方便理解，我们限定矩阵$`A`$为$`p{\times}p`$方阵，矩阵$`B`$为$`p{\times}1`$向量，那么矩阵$`C`$也是$`p{\times}1`$向量，这样我们就得到如下的等式

```math
    \begin{bmatrix}
    y_1     \\
    y_2     \\
    \vdots  \\
    y_p
    \end{bmatrix}
    =
    \begin{bmatrix}
    a_{11}  &   a_{12}  &   \cdots  &   a_{1p}  \\
    a_{21}  &   a_{22}  &   \cdots  &   a_{2p}  \\
    \vdots  &   \vdots  &   \ddots  &   \vdots  \\
    a_{p1}  &   a_{p2}  &   \cdots  &   a_{pp}
    \end{bmatrix}
    *
    \begin{bmatrix}
    x_1     \\
    x_2     \\
    \vdots  \\
    x_p
    \end{bmatrix}
```

按照上面的计算法则，我们可以得到如下的线性方程组

```math
\begin{matrix}
y_1=a_{11}x_1+a_{12}x_2+\cdots+a_{1p}x_p    \\
y_2=a_{21}x_1+a_{22}x_2+\cdots+a_{2p}x_p    \\
\vdots                                      \\
y_p=a_{p1}x_1+a_{p2}x_2+\cdots+a_{pp}x_p
\end{matrix}
```

其实矩阵的就是线性方程组的数学抽象，矩阵乘法表示的就是从一个线性空间到另一个线性空间的线性变换。

------

矩阵乘法的一个比较常见的应用就是求线性齐次递推式$`F_n=a_1F_{n-1}+a_2F_{n-2}+\cdots+a_kF{k}`$。
我们可以将线性齐次递推式表示成一个如下的线性方程组

```math
\begin{matrix}
F_n&=&a_1F{n-1}&+&a_2F{n-2}&+&\cdots&+&a_{k-1}F{n-k+1}&+&a_kF{n-k}  \\
F_{n-1}&=&1F{n-1}&+&0&+&\cdots&+&0&+&0  \\
\vdots&\ &\vdots&\ &\vdots&\ &\ddots&\ &\vdots&\ &\vdots  \\
F_{n-k+1}&=&0&+&0&+&\cdots&+&1F{n-k+1}&+&0    \\
\end{matrix}
```

按照上面的方式转换为矩阵乘法的形式

```math
\begin{bmatrix}
F_n         \\
F_{n-1}     \\
\vdots      \\
F_{n-k+1}   \\
\end{bmatrix}
=
\begin{bmatrix}
a_1 & a_2 & \cdots & a_{k-1} & a_{k} \\
1   & 0   & \cdots & 0       & 0     \\
\vdots    & \vdots & \ddots  & \vdots\\
0   & 0   & \cdots & 1       & 0     \\
\end{bmatrix}
*
\begin{bmatrix}
F_{n-1} \\
F_{n-2} \\
\vdots  \\
F_{n-k}
\end{bmatrix}
```

单纯的一次计算并不能看出矩阵的优点，但是如果将递推式$`F_n=a1F_{n-1}+a2F_{n-2}+\cdots+akF_{n-k}`$展开将得到如下矩阵连乘式：

```math
\begin{bmatrix}
F_n         \\
F_{n-1}     \\
\vdots      \\
F_{n-k+1}   \\
\end{bmatrix}
=
\begin{bmatrix}
a_1 & a_2 & \cdots & a_{k-1} & a_{k} \\
1   & 0   & \cdots & 0       & 0     \\
\vdots    & \vdots & \ddots  & \vdots\\
0   & 0   & \cdots & 1       & 0     \\
\end{bmatrix}
*
\begin{bmatrix}
a_1 & a_2 & \cdots & a_{k-1} & a_{k} \\
1   & 0   & \cdots & 0       & 0     \\
\vdots    & \vdots & \ddots  & \vdots\\
0   & 0   & \cdots & 1       & 0     \\
\end{bmatrix}
*
\cdots
*
\begin{bmatrix}
F_{k-1} \\
F_{k-2} \\
\vdots  \\
F_{0}
\end{bmatrix}
=
\begin{bmatrix}
a_1 & a_2 & \cdots & a_{k-1} & a_{k} \\
1   & 0   & \cdots & 0       & 0     \\
\vdots    & \vdots & \ddots  & \vdots\\
0   & 0   & \cdots & 1       & 0     \\
\end{bmatrix}^{n-k+1}
*
\begin{bmatrix}
F_{k-1} \\
F_{k-2} \\
\vdots  \\
F_{0}
\end{bmatrix}
```

这样我们就转化为矩阵的幂运算，可以使用之前提到的反复平方法来快速求幂。