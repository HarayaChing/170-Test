#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_mat(int* mat,int n){
	//Printing Matrix
    int count = 0;
    for(int l =0; l<(n*n); l++){
        if(count++ % n == 0) printf("\n");
        printf("%d ",mat[l]);
    }
}

int convertToIndex(int row,int col, int width){ 
    //Function converts coordinates to index ref [1]
    return (row*width)+col;
}

int calculate_zsn(){
    int val = 0;

    return val;
}

void zsn(int *mat,int *zsn_mat, int n){
    
    int index;
    int t;
    
    for (int i = 0; i<(n*n) ; i++){
        for (int j = 0; j<(n*n) ; j++){
            t = 0;
            index = convertToIndex(i,j,n);
            zsn_mat[index] = t;
        }
    }
}

int main() {
    srand(time(NULL)); // Seed random using time
    int *mat, *zsn_mat;
    int user_input,n,mat_size,val;

    
    printf("[1] pre made aray \n[2] generate array \ninput choice: ");
    
    scanf("%d",&user_input);
    
    switch(user_input){
        // -- For Checking --
        case 1:
            break;
        
        // -- Actual Use --
        case 2:
            
            printf("Input matrix size n: ");
            scanf("%d",&n);
            
            mat_size = n*n;

            // malloc matrix
            mat = (int*)malloc(sizeof(int)*mat_size);
            zsn_mat = (int*)malloc(sizeof(int)*mat_size);

            // filling mat with random
            for (int i=0 ; i<mat_size ; i++){
                val = rand() % 10+1;
                mat[i] = val;
            }
            // fill zsn matrix
            zsn(mat,zsn_mat,n);
            
            // Print matrices
            printf("Before");
            print_mat(mat,n);
            printf("\nAfter");
            print_mat(zsn_mat,n);

            break;
        
            default:
            printf("invalid input");
    }
    return 0;
} 


/*

References:
[1] https://stackoverflow.com/questions/1730961/convert-a-2d-array-index-into-a-1d-index

*/