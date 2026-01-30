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

int zsn(float *mat,float *zsn_mat, int n){
    float *mean_array, *sd_array;
    int index, curr_time,final_time;
    float t,a_j = 0, d_j = 0;
    

    // Create and calculate arrays for sd and mean
    mean_array = (float*)malloc(sizeof(float)*n);
    sd_array = (float*)malloc(sizeof(float)*n);

    for (int i = 0; i<n ; i++){
        a_j = 0;
        d_j = 0;

        //calculates mean
        for(int j =0; j<n; j++){
            index = (j*n)+i; // convert coorinates to index see [1] modified to go through column
            a_j += mat[index];
        }
        a_j = a_j/n;
        mean_array[i] = a_j;

        // calculates sd
        for (int j = 0; j<n ; j++){
            index = (j*n)+i;
            d_j += (mat[index] - a_j) * (mat[index] - a_j);
        }
        d_j = sqrt(d_j/n);
        sd_array[i] = d_j;
    }
    
    // printf("means: ");
    // for(int i =0; i<n ;i++){
    //     printf("%f ",mean_array[i]);
    // }
    // printf("\nsd: ");
    // for(int i =0; i<n ;i++){
    //     printf("%f ",sd_array[i]);
    // }
    
    // calculate z-score
    for (int i = 0; i<n ; i++){
        for (int j = 0; j<n ; j++){
            index = (i*n)+j;
            t = (mat[index] - mean_array[j])/sd_array[j];
            zsn_mat[index] = t;
        }
    }

    free(mean_array);
    free(sd_array);
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
            printf("\nFinished filling matrix\n");
            // fill zsn matrix
            clock_t t; // init timer [2]
            t = clock();
            zsn(mat,zsn_mat,n);
            t = clock() - t;
            double time_elapsed = (double)t/CLOCKS_PER_SEC;
            printf("Finished computing z scores with time elapsed %f \n",time_elapsed);
            // Print matrices
            // printf("Before");
            // print_mat(mat,n);
            // printf("\nAfter");
            // print_mat(zsn_mat,n);
            
            break;
            
            default:
            printf("invalid input");
    }
    free(mat);
    free(zsn_mat);
    return 0;
} 


/*

References:
[1] https://stackoverflow.com/questions/1730961/convert-a-2d-array-index-into-a-1d-index
[2] https://www.geeksforgeeks.org/cpp/how-to-measure-time-taken-by-a-program-in-c/
*/