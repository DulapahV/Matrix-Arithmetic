
# Matrix-Arithmetic
An individual project for C Programing Lecture, KMITL Software Engineering, Year 1, Semester 1

> Created by **Dulapah Vibulsanti (64011388)**

This README is separated into 3 parts:
 - [Project Description](#project-description)
 - [Demo](#demo)
	 - [Defining matrix through terminal/command line and through file (*input.txt* or *input.csv*)](#defining-matrix-through-terminalcommand-line-and-through-file-inputtxt-or-inputcsv)
	 - [Viewing stored matrix](#viewing-stored-matrix)
	 - [Performing arithmetic](#performing-arithmetic)
	 - [Looking at output files (*output.txt* and *output.csv*)](#looking-at-output-files)
 - [Testing Scheme](#testing-scheme)
	 - [First Test (Adding and Subtracting)](#first-test-adding-and-subtracting)
	 - [Second Test (Multiplying and Inverse)](#second-test-multiplying-and-inverse)
	 - [Third Test (Determinant and Adjoint)](#third-test-determinant-and-adjoint)
	 - [Fourth Test (Error Messages)](#fourth-test-error-messages)

# Project Description
This project aims to create a matrix computing program that runs in the terminal. The key features are:
 1. Wide variety of operations
	 - Addition
	 - Subtraction
	 - Multiplication
	 - Scalar Multiplication
	 - Exponentiation
	 - Determinant
	 - Transposition
	 - Inverse
	 - Adjoint

	*Program will also automatically detect matrix compatibility when performing certain operations.

2. User can choose to input matrix through terminal/command line or from an `input.txt` and `input.csv` file with a user-specifiable delimiter.

3. Answer is automatically output in the `output.txt` file with proper matrix brackets and also generates LaTeX code for the user. The program also outputs answers in the `output.csv` file as a comma-separated value.

4. Answer is automatically stored in 'Matrix Answer' so that it can be used to compute or perform further operations later on.

5. User can view each stored matrix value (max 7)


# Demo
### Defining matrix through terminal/command line and through file (*input.txt* or *input.csv*)
1. Select `Define Matrix`

![image](https://user-images.githubusercontent.com/71577909/137516772-a74e5b9a-f544-404f-a5c9-f946e4dd8da4.png)

2. Select a matrix to define.

![image](https://user-images.githubusercontent.com/71577909/137517087-dfb09958-4781-4666-8b7a-c0cdcb9c9e91.png)

To input through the terminal/command line, select the first option. Then specify `rows` and `columns` and `value` of your matrix.

![image](https://user-images.githubusercontent.com/71577909/137517291-7037b65e-a25e-4663-b635-dca2372f8318.png)

To input through a file, select the second option. Make sure there is only 1 input file named `input.txt` or `input.csv` in the program's directory. Then specify the delimiter and the program will automatically preview the matrix it reads from as well as defining it.

**Maximum dimensions for reading matrix from a file is 100 x 100 with a maximum of 255 characters per delimiter (delimiter cannot contain `.` character as it will be determined as a decimal point instead)*

Suppose we have a file containing comma-separated values

![image](https://user-images.githubusercontent.com/71577909/137518709-9312f2ee-2540-4056-a50b-dc26431b66e4.png)

We just specify the delimiter as a `,` and simply press enter.

![image](https://user-images.githubusercontent.com/71577909/137518814-3051b28a-15cc-41d9-851a-b9f5868095df.png)


### Viewing stored matrix
1. Select `View Matrix`

![image](https://user-images.githubusercontent.com/71577909/137516772-a74e5b9a-f544-404f-a5c9-f946e4dd8da4.png)

2. Select a matrix to view and the value of that matrix will appear.

![image](https://user-images.githubusercontent.com/71577909/137520627-5dbf0bcd-f113-4a5d-aecb-ef159dce897e.png)


### Performing arithmetic
1. Select `Compute Matrix`

![image](https://user-images.githubusercontent.com/71577909/137516772-a74e5b9a-f544-404f-a5c9-f946e4dd8da4.png)

2. Select an operation you would like to perform.

![image](https://user-images.githubusercontent.com/71577909/137521025-e821b81d-6276-4da2-84fd-266551231709.png)

3. Suppose we select `Addition`, then we just select 2 matrixes to be added together and the result will appear. After pressing any key to continue, the result will be outputted into `output.txt` and `output.csv` which we will take a look [here](#looking-at-output-files).

![image](https://user-images.githubusercontent.com/71577909/137521209-aabd5fe7-b44e-4891-9562-a4487c46b74c.png)


### Looking at output files
In the `output.txt`, there will be an answer with proper matrix brackets and a generated LaTeX code for the answer.

![image](https://user-images.githubusercontent.com/71577909/137522513-86dfe040-dbd7-4590-b420-6d5088fa8e94.png)

In the `output.csv`, there will be a comma-separated answer. The `output.csv` file is separated so that it can be imported into other programs right away.

![image](https://user-images.githubusercontent.com/71577909/137522612-0b0b6dcd-2a3c-49f1-8133-d625f9393e5b.png)


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

### Fourth Test (Error Messages)
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

Deleting `input.txt` or `input.csv` and reading matrix from it must give out *error accessing input file error*

	Error accessing input file!

Setting `output.txt` or `output.csv` to *read-only* and outputting matrix to it must give out *error accessing output file error*

	Error accessing output file!