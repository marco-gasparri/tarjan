#include "helper.h"

int * I_alloc (int n)
{
    int *p;

    p=(int *)calloc(n,sizeof(int));
    if (p==NULL)
    {  printf("\nSPAZIO INSUFFICIENTE (I_alloc)"); exit(1); }
    return p;
}


int  **PI_alloc(int length)
{
    int   **i;
    if ( ( i = (int   **) malloc(length*sizeof(int*))) == NULL) {
       printf("\nNot enough memory to allocate an array of %d pointers to int \n", length);
        exit(1);
    }
    return i;
}
