#include<stdio.h>
#include<stdlib.h>

void allocate_matrix(int***,int,int);
void build_matrix(int**,int,int);
void print_matrix(int**,int,int);
int **multiply_matrix(int**,int**,int,int,int);
void free_matrix(int***,int);

void main(){
    int **matx1,**matx2;
    int ***matxs[] = {&matx1,&matx2};
    int rows[2],cols[2];
    for (int i=0;i<2;i++){
        printf("Matrix - %d\n",i+1);
        printf("Enter no. of rows: ");
        scanf("%d",&rows[i]);
        printf("Enter no. of columns: ");
        scanf("%d",&cols[i]);
        allocate_matrix(matxs[i],rows[i],cols[i]);
        build_matrix(*matxs[i],rows[i],cols[i]);
        printf("The matrix %d is:\n",i+1);
        print_matrix(*matxs[i],rows[0],cols[0]);
    }

    if (cols[0]!=rows[1]) printf("A x B is not possible!\n");
    else{
        printf("The result of A x B is:\n");
        print_matrix(multiply_matrix(matx1,matx2,rows[0],cols[1],rows[1]),rows[0],cols[1]);
    }
    if (cols[1]!=rows[0]) printf("B x A is not possible!\n");
    else{
        printf("The result of B x A is:\n");
        print_matrix(multiply_matrix(matx2,matx1,rows[1],cols[0],rows[0]),rows[1],cols[0]);
    }
    for (int i=0;i<2;i++){
        free_matrix(matxs[i],rows[i]);
    }
}

void allocate_matrix(int ***ad_matx, int row, int col){
    *ad_matx = (int **)malloc(row*sizeof(int *));
    for (int i=0;i<row;i++){
        (*ad_matx)[i] = (int *)malloc(col*sizeof(int));
    }
}

void build_matrix(int **matx, int row, int col){
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            printf("Value for element [%d][%d]: ",i,j);
            scanf("%d",&matx[i][j]);
        }
    }
}

void print_matrix(int **matx, int row, int col){
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            printf("%d ",matx[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(int ***mtx, int row){
    for (int i=0;i<row;i++){
        free(*mtx[i]);
    }
    free(*mtx);
}

int **multiply_matrix(int **A, int **B, int rowA, int colB, int same){
    int **X;
    allocate_matrix(&X,rowA,colB);
    for (int i=0;i<rowA;i++){
        for (int j=0;j<colB;j++){
            int val=0;
            for (int k=0;k<same;k++){
                val+=A[i][k]*B[k][j];
            }
            X[i][j]=val;
        }
    }
    return X;
}