| Date     |
| -------- |
| 09-19-22 |

# Modular Exponentiation Examples
## E1
Suppose we want 
$$
2^{23} \text{ mod } 51
$$

Convert to binary $\to 23 = 10111_2$

Start with least significant bit.

| bit | Power $\mod{51}$                                             | Store              |
| --- | ------------------------------------------------------------ | ------------------ |
| 1   | $2^1 \equiv_{51} 2$                                          | $2\times 1=2$      |
| 1   | $2^2 \equiv_{51} 4$                                          | $4\times 2=8$      |
| 1   | $2^4 \equiv_{51} 16$                                         | $8\times 4=32$     |
| 0   | $2^8 \equiv_{51} 16 * 16 \equiv_{51} 1$                      | 32                 |
| 1   | $2^{16} \equiv_{51} 2^{8^{2}} \equiv_{51} 1^2 \equiv_{51} 1$ | $32 \times 1 = 32$ |

$$\implies 2^{23} \equiv_{51} 32$$


## E2
Suppose we want 
$$
5^{23} \text{ mod } 61
$$

| Bit (Least $\to$ Greatest) | Power $\%\ 61$          | Store                        |
| -------------------------- | ----------------------- | ---------------------------- |
| 1                          | $5^1 \equiv_{61} 5$     | $5\times 1 \equiv_{61} 5$    |
| 1                          | $5^2 \equiv_{61} 25$    | $25 \times 5 \equiv_{61} 3$  |
| 1                          | $5^4 \equiv_{61} 15$    | $15 \times 3 \equiv_{61} 45$ |
| 0                          | $5^8 \equiv_{61} 42$    | $45$                         | 
| 1                          | $5^{16} \equiv_{61} 56$ | $56 \times 45 \equiv_{61} 19$                             |

$$
\implies 5^{23} \equiv_{61} 19 
$$

## How Modular Exponentiation Works

Consider the $5^{23}$ example.

Notice that
$$
5^{1} \times 5^{2} \times 5^{4} \times 5^{16} = 5^{1+2+4+16} = 5^{23}
$$

Recall and apply:
$$
ab\text{ mod } c = \biggr[(a\text{ mod } c)\cdot(b\text{ mod } c)\biggr] \text{ mod } c 
$$

This moving result of multiplications is what the *store* keeps track of. 

<!--
% just something i was thinking about
$$
(1+1)^n = \sum_{k=0}^n \binom{n}{k}1^k1^{n-k} = 2^n
$$
-->