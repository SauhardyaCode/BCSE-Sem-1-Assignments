#include<stdio.h>
#include<stdlib.h>

void print_mtx(int**,int,int);
void build_mtx(int**,int,int);
void create_mtx(int***,int*,int*,char);
void free_mtx(int***,int);
void check_conformity(int**,int**,int***,int***,int,int,int,int,int*,int*);
void multiply_mtx(int**,int**,int***,int,int,int);

void main(){
    int **a, **b, **axb, **bxa;
    int rowa,rowb,cola,colb,row_axb,row_bxa;

    create_mtx(&a,&rowa,&cola,'A');
    create_mtx(&b,&rowb,&colb,'B');

    check_conformity(a,b,&axb,&bxa,rowa,rowb,cola,colb,&row_axb,&row_bxa);

    free_mtx(&a,rowa);
    free_mtx(&b,rowb);
    free_mtx(&axb,row_axb);
    free_mtx(&bxa,row_bxa);
}

void create_mtx(int ***ad_mtx, int *row, int *col, char name){
    printf("Create Matrix - %c\n",name);
    printf("Enter number of rows: ");
    scanf("%d",row);
    printf("Enter number of columns: ");
    scanf("%d",col);

    *ad_mtx = (int **)malloc(*row*sizeof(int *));
    for (int i=0; i<*row; i++){
        (*ad_mtx)[i] = (int *)malloc(*col*sizeof(int));
    }

    build_mtx(*ad_mtx,*row,*col);
    print_mtx(*ad_mtx,*row,*col);
}

void build_mtx(int **mtx, int row, int col){
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            printf("Value at [%d][%d]: ",i,j);
            scanf("%d",&mtx[i][j]);
        }
    }
}

void print_mtx(int **mtx, int row, int col){
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            printf("%d ",mtx[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void free_mtx(int ***mtx, int row){
    for (int i=0;i<row;i++){
        free(*mtx[i]);
    }
    free(*mtx);
    mtx=NULL;
}

void check_conformity(int **a, int **b, int ***ad_m1, int ***ad_m2, int r1, int r2, int c1, int c2, int *rmul1, int *rmul2){
    if (c1==r2){
        *rmul1 = r1;
        *ad_m1 = (int **)malloc(r1*sizeof(int *));
        for (int i=0;i<r1;i++){
            (*ad_m1)[i] = (int *)malloc(c2*sizeof(int));
        }
        multiply_mtx(a,b,ad_m1,r1,c2,c1);
        printf("A x B is given by -\n");
        print_mtx(*ad_m1,r1,c2);
    }
    else printf("Matrix Multiplication A x B is not possible!\n\n");

    if (c2==r1){
        *rmul2 = r2;
        *ad_m2 = (int **)malloc(r2*sizeof(int *));
        for (int i=0;i<r2;i++){
            (*ad_m2)[i] = (int *)malloc(c1*sizeof(int));
        }
        multiply_mtx(b,a,ad_m2,r2,c1,c2);
        printf("B x A is given by -\n");
        print_mtx(*ad_m2,r2,c1);
    }
    else printf("Matrix Multiplication B x A is not possible!\n\n");
    
}

void multiply_mtx(int **a, int **b, int ***ad_mul, int row, int col, int match){
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            (*ad_mul)[i][j]=0;
            for (int k=0;k<match;k++){
                (*ad_mul)[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
}