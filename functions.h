#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for reading file

#define MEM_ALLOCATE(dataType, length) (dataType *)malloc((length) * sizeof(dataType))

// Matrix
void define_matrix(double ***matrix, int *row, int *column);
void view_matrix(double **matrix, int row, int column);
int select_matrix(double ***matrix, int *row, int *column); // return 2 if user select 'Go Back', 1 if user select invalid choice, else 0
int read_matrix(const char *filename, const char *filename_csv, const char *delimiter, double ***matrix, int *row, int *column); // return 1 if cannot read, else 0
int output_matrix(const char *filename, const char *filename_csv, double **matrix, int row, int column); // return 1 if cannot print, else 0
void free_matrix(double **matrix, int row, int column);

// Program Messages/Errors
void define_matrix_success_msg(char msg);
void invalid_choice_error();
void incompatible_dimension_error();
void unequal_dimension_error();
void det_equal_zero_error();
void cannot_read_error();
void cannot_print_error();

struct Matrix {
    double **value;
    int row, column;
};

struct Matrix matA;
struct Matrix matB;
struct Matrix matC;
struct Matrix matD;
struct Matrix matE;
struct Matrix matF;
struct Matrix matAns;

//--[Matrix]-----------------------------------------------------
//  - Define Matrix
//  - View Matrix
//  - Select Matrix
//  - Read Matrix
//  - Print Matrix
//  - Free Matrix
//---------------------------------------------------------------
// Define Matrix
void define_matrix(double ***matrix, int *row, int *column) {
    printf("\nNumber of Rows: ");
    scanf("%d", row);
    printf("Number of Columns: ");
    scanf("%d", column);
    printf("Enter value: \n");
    double **tempAns;
    tempAns = MEM_ALLOCATE(double *, *row);
    for (int i = 0; i < *row; i++)
        tempAns[i] = MEM_ALLOCATE(double, *column);
    for (int i = 0; i < *row; i++)
        for (int j = 0; j < *column; j++)
            scanf("%lf", &tempAns[i][j]);
    *matrix = tempAns;
}

// View Matrix
void view_matrix(double **matrix, int row, int column) {
    if (row != 0 && column != 0)
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++)
                (matrix[i][j] == 0) ? printf("%.2lf\t", 0) : printf("%.2lf\t", matrix[i][j]); // Prevent displaying -0 instead of 0
            printf("\n");
        }
    else
        printf("[Empty]\n");
    printf("\n");
}

// Select Matrix
int select_matrix(double ***matrix, int *row, int *column) {
    int choice;
    for (int i = 0; i < 6; i++)
        printf("[%d] Matrix %c\n", i + 1, 'A' + i);
    printf("[7] Matrix Answer\n");
    printf("[8] Go back\n");
    printf("\nChoice--> ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        *matrix = matA.value, *row = matA.row, *column = matA.column;
        break;
    case 2:
        *matrix = matB.value, *row = matB.row, *column = matB.column;
        break;
    case 3:
        *matrix = matC.value, *row = matC.row, *column = matC.column;
        break;
    case 4:
        *matrix = matD.value, *row = matD.row, *column = matD.column;
        break;
    case 5:
        *matrix = matE.value, *row = matE.row, *column = matE.column;
        break;
    case 6:
        *matrix = matF.value, *row = matF.row, *column = matF.column;
        break;
    case 7:
        *matrix = matAns.value, *row = matAns.row, *column = matAns.column;
        break;
    case 8:
        return 2;
    default:
        invalid_choice_error();
        system("pause");
        return 1;
    }
    return 0;
}

// Read Matrix
int read_matrix(const char *filename, const char *filename_csv, const char *delimiter, double ***matrix, int *row, int *column) {
    FILE *file, *file_csv, *in_file;
    file = fopen(filename, "r");
    file_csv = fopen(filename_csv, "r");
    if (file == NULL)
        if (file_csv == NULL)
            return 1;
        else
            in_file = file_csv;
    else
        in_file = file;
    char buffer[1024];
    char *readValue, *line;
    int readRow = 0, readElementCount = 0;
    double readMatrix[100][100];
    while ((line = fgets(buffer, sizeof(buffer), in_file)) != NULL) {
        readValue = strtok(line, delimiter);
        while (readValue != NULL) {
            readMatrix[readRow][readElementCount++] = atof(readValue) ;
            readValue = strtok(NULL, delimiter);
        }
        readRow++;
    }
    int tempRow = 0, index = 0;
    int tempColumn = readElementCount / readRow;
    double **tempMatrix;
    tempMatrix = MEM_ALLOCATE(double *, readRow);
    for (int i = 0; i < readRow; i++)
        tempMatrix[i] = MEM_ALLOCATE(double, tempColumn);
    for (int i = 0; i < readRow; i++) {
        for (int j = 0; j < tempColumn; j++)
            tempMatrix[i][j] = readMatrix[tempRow][index++];
        tempRow++;
    }
    *matrix = tempMatrix;
    *row = tempRow;
    *column = tempColumn;
    fclose(file);
    fclose(file_csv);
    return 0;
}

// Print Matrix
int output_matrix(const char *filename, const char *filename_csv, double **matrix, int row, int column) {
    FILE *out_file = fopen(filename, "w");
    FILE *out_csv_file = fopen(filename_csv, "w");
    if (out_file == NULL)
        return 1;
    else {
        if (row <= 0 && column <= 0) {
            fclose(out_file);
            return 0;
        }
        else if (row == 1 && column == 1)
            fprintf(out_file, "Answer:\n[\t%.2lf\t]\n", matrix[0][0]);
        else if (row == 1 &&  column >= 1)
            for (int i = 0; i < column; i++)
                if (i == 0)
                    fprintf(out_file, "Answer:\n[\t%.2lf\t", matrix[0][i]);
                else if (i == column - 1)
                    fprintf(out_file, "%.2lf\t]\n", matrix[0][i]);
                else
                    fprintf(out_file, "%.2lf\t", matrix[0][i]);
        else if (row >= 1 && column == 1)
            for (int i = 0; i < row; i++)
                if (i == 0)
                    fprintf(out_file, "Answer:\n⎡\t%.2lf\t⎤\n", matrix[i][0]);
                else if (i == row - 1)
                    fprintf(out_file, "⎣\t%.2lf\t⎦\n", matrix[i][0]);
                else
                    fprintf(out_file, "⎢\t%.2lf\t⎥\n", matrix[i][0]);
        else {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < column; j++) {
                    if (i == 0 && j == 0) {
                        fprintf(out_file, "Answer:\n⎡\t");
                        fprintf(out_file, "%.2lf\t", matrix[i][j]);
                    }
                    else if (i == 0 && j == column - 1) {
                        fprintf(out_file, "%.2lf\t", matrix[i][j]);
                        fprintf(out_file, "⎤");
                    }
                    else if (i > 0 && i < row - 1 && j == 0) {
                        fprintf(out_file, "⎢\t");
                        fprintf(out_file, "%.2lf\t", matrix[i][j]);
                    }
                    else if (i > 0 && i < row - 1 && j == column - 1) {
                        fprintf(out_file, "%.2lf\t", matrix[i][j]);
                        fprintf(out_file, "⎥");  
                    }
                    else if (i == row - 1 && j == 0) {
                        fprintf(out_file, "⎣\t");
                        fprintf(out_file, "%.2lf\t", matrix[i][j]);
                    }
                    else if (i == row - 1 && j == column - 1) {
                        fprintf(out_file, "%.2lf\t", matrix[i][j]);
                        fprintf(out_file, "⎦");
                    }
                    else
                        fprintf(out_file, "%.2lf\t", matrix[i][j]);
                }
                fprintf(out_file, "\n");
                if (i != row - 1) {
                    fprintf(out_file, "⎢");
                    for (int j = 0; j < column + 1; j++)
                        fprintf(out_file, "\t");
                    fprintf(out_file, "⎥\n");
                }    
            }
        }
        fprintf(out_file, "\nLaTeX:\n\\left[\\begin{matrix}");
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++)
                (j != column - 1) ? fprintf(out_file, "%.2lf&", matrix[i][j]) : fprintf(out_file, "%.2lf", matrix[i][j]);
            fprintf(out_file, "\\\\");
        }
        fprintf(out_file, "\\end{matrix}\\right]\n");
    }
    if (out_csv_file == NULL)
        return 1;
    else {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++)
                (j != column - 1) ? fprintf(out_csv_file, "%.2lf,", matrix[i][j]) : fprintf(out_csv_file, "%.2lf", matrix[i][j]);
            fprintf(out_csv_file, "\n");
        }
    }
    fclose(out_file);
    fclose(out_csv_file);
    return 0;
}

// Free Matrix
void free_matrix(double **matrix, int row, int column) {
    for (int i = 0; i < row; i++) {
        double *ptr = matrix[i];
        free(ptr);
    }
    row = 0, column = 0;
}

//--[Program Messages/Errors]------------------------------------
// Define Matrix Success
void define_matrix_success_msg(char msg) {
    printf("\nMatrix %c successfully defined!\n\n", msg);
}

// Invalid Choice Error
void invalid_choice_error() {
    printf("\nPlease select a valid choice!\n\n");
}

// Incompatible Dimension Error
void incompatible_dimension_error() {
    printf("\nIncompatible matrix dimension!\n\n");
}

// Unequal Dimension Error
void unequal_dimension_error() {
    printf("\nMatrix dimension must be equal!\n\n");
}

// Unequal Dimension Error
void det_equal_zero_error() {
    printf("\nCannot find inverse of singular matrix!\n\n");
}

// Cannot Read Error
void cannot_read_error() {
    printf("\nError accessing input file!\n\n");
}

// Cannot Print Error
void cannot_print_error() {
    printf("\nError accessing output file!\n\n");
}