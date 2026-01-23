#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void print_mat(float* mat,int n){
	//Printing Matrix
    int count = 0;
    for(int l =0; l<(n*n); l++){
        if(count++ % n == 0) printf("\n");
        printf("%f ",mat[l]);
    }
}

int convertToIndex(int row,int col, int width){ 
    // Function converts coordinates to index ref [1]
    return (row*width)+col;
}

float calculate_zsn(float *mat, int n, int j, float x){
    int index;
    float a_j = 0, d_j = 0, val = 0;
    
    // calculates avarage of column a_j
    for (int row = 0; row<n ; row++){
        index = convertToIndex(row,j,n);
        a_j += mat[index];
    }
    a_j = a_j/n;
    
    // calculates standard dev of column d_j
    for (int row = 0; row<n ; row++){
        index = convertToIndex(row,j,n);
        d_j += pow(mat[index] - a_j,2);
    }
    d_j = sqrt(d_j/n);
    
    // calculates z score
    val = (x-a_j)/d_j;
    // printf("avarage is %f standard dev is %f z score is %f \n", a_j,d_j,val);
    
    return val;
}

void zsn(float *mat,float *zsn_mat, int n){
    
    int index;
    float t;
    
    for (int i = 0; i<(n) ; i++){
        for (int j = 0; j<(n) ; j++){
            index = convertToIndex(i,j,n);
            t = calculate_zsn(mat,n,j,mat[index]);
            zsn_mat[index] = t;
        }
    }
}

int main() {
    
    srand(time(NULL)); // Seed random using time
    float *mat, *zsn_mat;
    int user_input,n,mat_size;
    float val;

    
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
            mat = (float*)malloc(sizeof(float)*mat_size);
            zsn_mat = (float*)malloc(sizeof(float)*mat_size);

            // filling mat with randomZ
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