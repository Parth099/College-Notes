NEWLINE = "\\\\"
DIFF = "&"
MATRIX_TYPE = "{pmatrix}"

def matToTex(matrix):

    fullMatrix = ""
    currRow = ""
    for row in matrix:
        currRow = f" {DIFF} ".join(list(map(str, row)))
        fullMatrix += "\t" + currRow + NEWLINE + "\n"

    if fullMatrix:
        fullMatrix = fullMatrix[:-3] + "\n" 

    return f'\\begin{MATRIX_TYPE}\n{fullMatrix}\\end{MATRIX_TYPE}'

"""
[
    [0, 1, 0, 0, 0],
    ["1/4", 0, "3/4", 0, 0],
    [0, "1/2", 0, "1/2", 0],
    [0, 0, "1/4", 0, "3/4"],
    [0, 0, 0, 1, 0],
]
"""
mat = [[0, 1, 2, 4], ["1/3", "1/3", "1/6", "1/6"]]
print("p_X = "+matToTex(mat))

