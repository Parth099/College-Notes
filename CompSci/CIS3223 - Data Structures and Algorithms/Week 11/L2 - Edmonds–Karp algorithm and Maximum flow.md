# Edmonds–Karp algorithm and Maximum flow

> maximum flow problems involve finding a feasible flow through a flow network that obtains the maximum possible flow rate.

## Flow Networks
A flow network $X$ consists asymmetric directed graph $G= (V,\ E)$ and two special edges:

+ $s$ - Source: All edges are outgoing
+ $t$ - Sink: All edges are incoming

![flow_network](/img/flow_network.png)

The weight on each edge is the flow capacities through that connection. 

## Flow
A **flow** in the network consists of a variable $f_e$ for each edge $e \in E$ which satisfies the following for all edges:
+ $0\leq f_e \leq c_e$ (does not exceed defined capacities)
+ $\sum_{(w, u)\in E} f_{wu} = \sum_{(uz)\in E} f_{uz}$ 
	+ This says "flow in" = "flow out"