def rotate(matrix):
  n = len(matrix)-1
  for layer in range(0, n//2+1):
    for i in range (0, n-2*layer):
      #at starting point: i = 0
      #firstRow starting point: [layer][layer+i]
      #lastCol starting point: [layer+i][n-layer]
      #lastRow starting point: [n - layer][n-layer-i]
      #firstCol starting point: [n-layer-i][layer]
      #print(matrix[layer][layer+i],matrix[layer+i][n-layer],matrix[n - layer][n-layer-i],matrix[n-layer-i][layer])
      

      
      firstRow = matrix[layer][layer+i]
      lastCol = matrix[layer+i][n-layer]
      lastRow = matrix[n - layer][n-layer-i]
      firstCol = matrix[n-layer-i][layer]
      
      
      firstRow,lastCol,lastRow,firstCol= firstCol,firstRow,lastCol,lastRow

      
      matrix[layer][layer+i] = firstRow
      matrix[layer+i][n-layer] = lastCol
      matrix[n - layer][n-layer-i] = lastRow
      matrix[n-layer-i][layer] = firstCol
  return matrix
      
      
      

        #matrix[i][i+j],matrix[i][len(matrix)-1-i],matrix[len(matrix)-1-i][len(matrix)-1-i],matrix[len(matrix)-1-i][i]=\
        #matrix[len(matrix)-1-i][i],matrix[i][i],matrix[i][len(matrix)-1-i],matrix[len(matrix)-1-i][len(matrix)-1-i]

'''
('first', 0, 0, 5 'second', 0, 3, 11 'third', 3, 3, 16, 'fourth', 3, 0)
('first', 0, 1, 'second', 1, 3, 'third', 3, 2, 'fourth', 2, 1)
('first', 0, 2, 'second', 2, 3, 'third', 3, 1, 'fourth', 1, 2)
('first', 0, 3, 'second', 3, 3, 'third', 3, 0, 'fourth', 0, 3)
('first', 1, 0, 'second', 1, 2, 'third', 2, 2, 'fourth', 2, 0)
'''

matrix =     [[5,  1,9,11,   18],

              [2,  4,8,10,   22],

              [13, 3,6,7,   24],

              [15, 14,12,16, 31],

              [12, 25,64,32, 23]] 

matrix2 = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]

#print(recursiveRotate(matrix, 0))

'''
firstRow=1
lastCol=2
lastRow=3
firstCol=4

firstRow,lastCol,lastRow,firstCol= firstCol,firstRow,lastCol,lastRow
print(firstRow,lastCol,lastRow,firstCol)
'''
print(rotate(matrix))

