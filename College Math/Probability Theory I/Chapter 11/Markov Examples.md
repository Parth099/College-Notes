# Markov Examples
## Example 1
Suppose there is a politician. They will agree **yes/no** to running the next year and tell person A. Person A will tell person B and person B will tell C and so on. Let $a$ be the probability of a person flipping the yes to a no and $b$ the probability that a no is flipped to a yes. 

$$
\mathbf{P} = \begin{pmatrix}  
        1-a & a\\
        b & 1-b\\
\end{pmatrix}  
$$

Row 1 is 'Yes' and Row '2' is no.
Col 1 is 'Yes' and Row 2 is no.

## Example 2 - Reading a Transition Matrix
![[reading_a_chain.png]]
Lets look at $P_{11}$ It says that Given event $W$, the event $W$ will happen again next with probability $\frac{1}{2}$. 

Notice that for any event in $\{W, P, S\}$, the next event has the same distribution no matter what happened previously. This an occurrence of an **independent trials process**. 

## Example 3 \& 4
Suppose $80\%$ of the sons of Harvard went to Harvard. The rest went to Yale. 
Of the fathers that went to Yale, $40\%$ of their sons went to Yale. The rest was an even split with Harvard and Dartmouth. 

Of the fathers in Dartmouth. $70\%$ of their sons went to Dartmouth. $20\%$ to Harvard and the rest to Yale.

See that this is the Transition matrix: 
![[markov_ex3.png]]

If sons went to Harvard given their father went there, the first row would be:
$$\begin{pmatrix}    
        1 & 0 & 0\\
\end{pmatrix}$$