# Matrix-Arithmetic
An individual project for C Programing Lecture, KMITL Software Engineering, Year 1, Semester 1

Created by **Dulapah Vibulsanti (64011388)**

This README is separated into 4 parts:
 - Project Description
 - To Do List
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

	*Program will also automatically detect matrix compatibility when performing certain operations.
	
2. Answer is automatically stored in 'Matrix Answer' so that it can be used to compute or perform further operations later on.

3. User can view each stored matrix value (max 7)

4. Answer is automatically output in the 'output.txt' with proper matrix brackets. The program will also generate LaTeX code for user.

6. User has an option to clear selected/all matrix values (coming soon)

# To do list
 - [x] Design UI and program flow 
 - [x] Implement arithmetics (add, subtract, multiply)
 - [x] Implement additional features (determinant, transpose, inverse, adjoint)
 - [x] Implement outputting result to a file
 - [ ] Implement option for user to clear selected/all matrix values
 - [ ] Add proper comments in the code
 - [ ] Make code easier to read and maintain
 - [ ] Create documentation

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

    4	7
    2	6

### First Test (Adding and Subtracting)
Adding *matrix A* together must give out

    8	14
    4	12

And subtracting the *sum of matrix A* with *matrix A* must give out the original value of *matrix A*

    4	7
    2	6

### Second Test (Multiplying and Inverse)
Finding the *inverse of matrix A* must give out

    0.60    -0.70
    -0.20   0.40

And multiplying the the *inverse of matrix A* with *matrix A* must give out *identity matrix*

    1	0
    0	1
    
### Third Test (Determinant and Adjoint)
Finding the determinant of *matrix A* must give out

    10

Finding adjoint of *matrix A* must give out

    6	-7
    -2	4

Multiplying *1/det(A)* with the adjoint of *matrix A* must give out the inverse of *matrix A*

    0.60    -0.70
    -0.20   0.40

### Fourth Test (Testing Incompatible Matrix)
Suppose *matrix B* is

    1	2	3
    4	5	6
    7	8	9

Adding/subtracting/multiplying *matrix A* with *matrix B* must give out *incompatible matrix dimension error*

    Incompatible matrix dimension!

Finding determinant/inverse of a matrix with unequal row and column must give out *unequal matrix dimension error*

    Matrix dimension must be equal!

Finding the inverse of *matrix B* must give out *det equal 0 error* because an inverse of a matrix with *det = 0* does not exist (*singular matrix*)

    Cannot find inverse of singular matrix!