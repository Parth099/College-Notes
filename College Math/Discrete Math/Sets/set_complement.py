A = set("basic")
B = set("concepts")

U = set([chr(i) for i in range(97, 97 + 26)]) #set all lower alphabet

print("%-10s: "%"union",A.union(B))
print("%-10s: "%"intersect",A.intersection(B))

print("%-10s: "%"A-B",A - B)
print("%-10s: "%"B-A",B - A)

print("%-20s: "%"A^C union B^C",(U-A).union(U-B),"len:",  len((U-A).union(U-B)))
print("%-20s: "%"A^C intersect B^C",(U-A).intersection(U-B),"len:",  len((U-A).intersection(U-B)))

