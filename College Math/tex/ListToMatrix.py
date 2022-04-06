NEWLINE = "\\\\"
DIFF = "&"
MATRIX_TYPE = "{pmatrix}"

def matToTex(matrix):

    fullMatrix = ""
    currRow = ""
    for row in matrix:
        currRow = f" {DIFF} ".join(list(map(str, row)))
        fullMatrix += "\t" + currRow + NEWLINE + "\n"

    return f'\\begin{MATRIX_TYPE}\n{fullMatrix}\\end{MATRIX_TYPE}'

mat = [ [1, 2, 3]
]

print(matToTex(mat))