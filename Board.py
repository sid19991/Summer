board = [
    [7,8,0,4,0,0,1,2,0],
    [6,0,0,0,7,5,0,0,9],
    [0,0,0,6,0,1,0,7,8],
    [0,0,7,0,4,0,2,6,0],
    [0,0,1,0,5,0,9,3,0],
    [9,0,4,0,6,0,0,0,5],
    [0,7,0,3,0,0,0,1,2],
    [1,2,0,0,0,7,4,0,0],
    [0,4,9,2,0,6,0,0,7]
]

def solve(grid):
    #base case
    find = find_emptyCell(grid)
    if not find:
        return True
    else:
        raw,col=find

    for i in range(1,10):
        if isValid(grid,i,(raw,col)):
            grid[raw][col]=i
            
            if solve(grid):
                return True
            
            grid[raw][col]=0
    return False
    

def isValid(grid,num,pos):

    #check raw
    for i in range(len(grid)):
        if grid[pos[0]][i]==num and pos[1]!=i:
            return False
        
    #check Column
    for i in range(len(grid[0])):
        if grid[i][pos[1]]==num and pos[0]!=i:
            return False
    
    #check box
    box_x = pos[0]//3
    box_y = pos[1]//3

    for i in range(box_x*3,box_x*3+3):
        for j in range(box_y*3,box_y*3+3):
            if grid[i][j]==num and (i,j)!=pos:
                return False
    
    return True


def print_board(grid):
    
    for i in range(len(grid)):
        if i%3==0 and i!=0:
            print("- - - - - - - - - - -")
        for j in range(len(grid[0])):
            if j%3==0 and j!=0:
                print("|",end="")
            if j==8:
                print(grid[i][j])
            else:
                print(str(grid[i][j])+" ", end="")

#print_board(board)

#fun will find empty cell in board and return raw,col.

def find_emptyCell(grid):

    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 0:
                return (i,j) #raw,col.
    return None


print_board(board)
print("\n")
print("After Solving\n")
solve(board)
print_board(board)




