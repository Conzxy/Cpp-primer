Taylor Formula
===

多项式的泰勒公式
--
若p(x)为n次整多项式:
$$
p(x)=a_0+a_1x+a_2x^2+a_3x^3+...+a_nx^n,     (1)
$$

则逐次将它微分n次:
$$p'(x)=a_1+2\cdot a_2x+3\cdot a_3x^2+...+n\cdot a_nx^{n-1},$$
$$p''(x)=1\cdot 2\cdot a_2+2\cdot 3\cdot a_3x+...+(n-1)n\cdot a_nx^{n-2},$$
$$p'''(x)=1\cdot 2\cdot 3\cdot a_3+...+(n-2)(n-1)n\cdot a_nx^{n-3},$$
$$...........................................$$
$$p^(n)(x)=1\cdot 2\cdot 3\cdot \cdot \cdot n\cdot a_n$$

令以上所有式子x的x=0，可得:
$$a_0=p(0)/0!,a_1=p'(0)/1!,a_2=p''(0)/2!,$$
$$a_3=p'''(0)/3!,\cdot \cdot \cdot,a_n=p^(n)(0)/n!.$$

将这些系数代入(1)中:
$$p(x)=p(0)+p'(0)/1!x+p''(0)/2!x^2+p'''(0)/3!x^3+\cdot \cdot \cdot+p^(n)(0)/n!x^n.    (2)
