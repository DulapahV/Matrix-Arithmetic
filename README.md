# Matrix-Arithmetic
An individual project for KMITL Software Engineering, Year 1, Semester 1

Created by **Dulapah Vibulsanti (64011388)**

The README will be separated into 3 parts:
 - Project Description
 - Program Flow
 - Testing Scheme

# Project Description
This project aims to create a matrix computing program that runs in the terminal. The key features are:
 1. Wide variety of operations
	 - Addition
	 - Subtraction
	 - Multiplication
	 - Determinant
	 - Transposition
	 - Inverse
	 - Adjoint
	 - Solving simultaneous equations using Cramer's rule(coming soon)

	*Program will also automatically detect matrix compatibility when performing certain operations.
	
2. Answer is automatically stored in 'Matrix Answer' so that it can be used to compute or perform further operations later on.

3. User can view each stored matrix value (max 7)

4. Answer is automatically output in the 'output.txt' with proper formatting (coming soon)

5. User has an option to clear selected/all matrix values (coming soon)

# Program Flow
    > What would you like to do
    [1] Define Matrix
        > Select a matrix to define
        [1] Matrix A
    
            Number of Rows: 2 
            Number of Columns: 2
            Enter value:
                1 2 3
                4 5 6
                7 8 9
    
            Matrix [selected matrix] successfully defined
    
            Press any key to continue...
    
        [2] Matrix B
        [3] Matrix C
        [4] Matrix D
        [5] Matrix E
        [6] Matrix F
        [7] Go back
    
    
    [2] View Matrix
        > Select a matrix to view
        [1] Matrix A
        [2] Matrix B
        [3] Matrix C
        [4] Matrix D
        [5] Matrix E
        [6] Matrix F
        [7] Matrix Answer
        [8] Go back
    
            (If selected matrix is not empty)
            Value:
            1.00    2.00    3.00
            4.00    5.00    6.00
            7.00    8.00    9.00
            
            Press any key to continue...
    
            (If selected matrix is empty)
            Value:
            [Empty]
            
            Press any key to continue...
    
    
    [3] Compute Matrix
    
            > What operation would you like to perform
            [1] Addition
                > Select matrixes to add
                [1] Matrix A
                [2] Matrix B
                [3] Matrix C
                [4] Matrix D
                [5] Matrix E
                [6] Matrix F
                [7] Matrix Answer
                [8] Go back
        
                Choice--> 1
        
                [1] Matrix A
                [2] Matrix B
                [3] Matrix C
                [4] Matrix D
                [5] Matrix E
                [6] Matrix F
                [7] Matrix Answer
                [8] Go back
        
                Choice--> 1
        
                    (If matrixes are compatible)
                    > The sum is
                    2.00    4.00    6.00
                    8.00    10.00   12.00
                    14.00   16.00   18.00
        
                    Press any key to continue...
        
                    (If matrixes are incompatible)
                    Incompatible matrixes!
        
                    Press any key to continue...
        
            [2] Subtraction
            [3] Multiplication
            [4] Determinant
            [5] Transposition
            [6] Inverse
            [7] Adjoint
            [8] Go back
        
    [4] Solve simultaneous equations (coming soon)
        
    [5] Exit
        
    Choice-->
   
# Testing Scheme
Suppose *matrix A* is

    4	6
    2	7

### First Test (Adding and Subtracting)
Adding *matrix A* together must give out

    8	12
    4	14

And subtracting the result with *matrix A* must give out the original value of *matrix A*

    4	6
    2	7

### Second Test (Multiplying and Inverse)
Multiplying *matrix A* together must give out

    28	66
    22	61
Finding the inverse of *matrix A* must give out

    0.44    -0.38
    -0.13   0.25
And multiplying the product of matrix A and the inverse of the matrix must give out *identity matrix*

    1	0
    0	1
    
### Third Test (Determinant and Adjoint)
Finding the determinant of *matrix A* must give out

    16

Finding adjoint of *matrix A* must give out

    4	2
    6	7

Multiplying *1/det(A)* with the adjoint of *matrix A* must give out the inverse of *matrix A*

    0.44    -0.38
    -0.13   0.25

### Fourth Test (Testing Incompatible Matrix)
Suppose *matrix B* is

    1	2	3
    4	5	6
    7	8	9

Adding/subtracting/multiplying *matrix A* with *matrix B* must give out *incompatible matrix dimension error*

    Incompatible matrix dimension!

FInding determinant/inverse of a matrix with unequal row and column must give out *unequal matrix dimension error*

    Matrix dimension must be equal!

Finding the inverse of *matrix B* must give out *det equal 0 error* because an inverse of a matrix with *det = 0* does not exist (*singular matrix*)

    Cannot find inverse of singular matrix!