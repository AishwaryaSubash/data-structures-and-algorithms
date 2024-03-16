from typing import List

def isValidSudoku(board: List[List[str]]) -> bool:
    arr = []
    for i in range(9):
        for j in range(9):
            num = board[i][j]
            if num != ".":
                if num not in "123456789":
                    return False
                arr.extend([(i, num), (num, j), (i//3, j//3, num)])
    # print(arr)
    return (len(arr)==len(set(arr)))
            
    

            


board = [["5","3",".",".","7",".",".",".","."]
        ,["6",".",".","1","9","5",".",".","."]
        ,[".","9","8",".",".",".",".","6","."]
        ,["8",".",".",".","6",".",".",".","3"]
        ,["4",".",".","8",".","3",".",".","1"]
        ,["7",".",".",".","2",".",".",".","6"]
        ,[".","6",".",".",".",".","2","8","."]
        ,[".",".",".","4","1","9",".",".","5"]
        ,[".",".",".",".","8",".",".","7","9"]]

print(isValidSudoku(board))