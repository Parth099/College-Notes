# Week 3 - 01 31 23

Cont: [[Week 2 - 01 26 23 - Exploratory Data Analysis]] (Exploratory Data Analysis)

## Categorical Features
+ Visualization of categorical features
	+ We can explore the counts of categorical features via data visualizations too.
		+ Bar Charts, Pie Charts, ...
		+ 

## Correlation Between Features
+ Scatter Plots
+ Exploring pairs of features via `df.corr()`[^1]
	+ generates a table that explores the $r^2$ against each feature. It compares each feature to all other features. 

## Graph Data

> Dataset is represented as a graph, where nodes and edges can have their own properties and values

We can use the `networkx` package to view and CRUD graphs - [Docs](https://networkx.org/).

[^1]: `df` - DataFrame from `pandas`