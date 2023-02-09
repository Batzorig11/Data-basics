#include "myinclude.h"

void read(int A[], int n)
{
        int i;
        for (i = 0; i < n; i++)
                scanf("%d", &A[i]);
}

void print(int A[], int n)
{
        int i;
        for (i = 0; i < n; i++)
                printf("%d ", A[i]);
        printf("\n");
}

int max(int A[], int n)
{
        int i, max;
        max=A[0];
        for(i=0; i<n; i++){
                if(max<A[i]){
                        max=A[i];
                }
        }
        return max;
}

int min(int A[], int n)
{  
        int i, min;
        min=A[0];
        for(i=0; i<n; i++){
                if(min>A[i]){
                        min=A[i];
                }
        }
        return min;  
}

void copy(int A[], int n, int B[])
{
        int i;
        for(i=0; i<n; i++){
                B[i]=A[i];
        }                
}

int find(int A[], int n, int x)
{
        int i;
        for(i=0; i<n; i++){
                if(x==A[i]){
                        return i;
                }
        }
        return -1;
}

int make_set(int A[], int n, int B[])
{
        int k, i, j;
        B[0]=A[0];
        k=1;
        for(i=0; i<n; i++){
                for(j=0; j<i; j++){
                        k++;
                        if(B[j]!=A[i]){                             
                             B[i]=A[i];
                             if(B[k]!=B[k-1]){
                                k--;
                             }
                        } else {
                                i++;
                        }
                }
        }
        return k;
}

int union_set(int A[], int n, int B[], int m)
{
        int i, j, k, count;
        k=1;
        count = 0;
        for(i=0; i<m; i++){
                for(j=0; j<n; j++){
                        if(B[i]==A[j]){
                                k++;
                        }
                }
                if(k==0){
                        A[n+count]=B[i];
                        count++;
                }
                k=0;
        }
        return n+count;

}

int intersection_set(int A[], int n, int B[], int m, int C[])
{
        int i, j, k;
        k=0;
        for(i=0; i<m; i++){
                for(j=0; j<n; j++){
                        if(B[i]==A[j]){
                                if(C[k]!=C[k-1]){
                                        C[k]=A[j];
                                        k++;
                                }
                        }
                }
        }
        return k;
}

