#include "tarjan.h"

//Push sullo stack
void push(int i, int *stack){

    stack[0] = stack[0] + 1;
    stack[stack[0]] = i;

}

//Pop dallo stack
int pop(int *stack){

    int p = stack[stack[0]];
    stack[stack[0]] = 0;
    stack[0] = stack[0] - 1;
    return p;

}

//Minimo tra due interi
int min(int k, int j){

    if(k<j)
        return k;
    return j;

}

//True se x appartiene ad array
bool is_in_array_0_len(int x, int *array){
    
    int i;

    for(i = 1; i<=array[0];i++)
        if(array[i]==x)
            return true;

    return false;
}

//Rovescia l'array di lunghezza len
void reverse_array(int *arr, int len){
    
    int i, temp;
    for (i=0; i<len/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[len-i-1];
        arr[len-i-1] = temp;
    }
} 

//Stampa le compenenti fortemente connesse
void print_scc(int **scc_s){
    for(int i = 1; i<=scc_s[0][0]; i++){
        for(int j = 1 ; j<=scc_s[i][0]; j++){
            printf("[%d] ",scc_s[i][j]);
        }
        printf("\n");
    }
}

//Algoritmo di Tarjan per il calcolo delle componenti fortemente connesse, dove la connessione è indicata con uno 0 (dettagli su http://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm)
void strongconnect(int v, int *stack, int **scc, int *index, int *lowlink, int index_n, int **grafo, int n_nodi){

    int w,o;

    index[v] = index_n;
    lowlink[v] = index_n;
    index_n = index_n + 1;
    push(v, stack);

    for(w=0;w<n_nodi;w++){
        
        if(grafo[v][w]==0){
            if(index[w]==-1){
                strongconnect(w,stack,scc,index,lowlink,index_n,grafo,n_nodi);
                lowlink[v] = min(lowlink[v],lowlink[w]);
                
            }
            else if(is_in_array_0_len(w,stack)){
            lowlink[v] = min(lowlink[v],index[w]);
            
            }
        }
        
        
    }

    if(lowlink[v] == index[v]){
        scc[0][0] = scc[0][0] + 1;
        scc[scc[0][0]] = I_alloc(n_nodi+1);
        
        do{
            o = pop(stack);
            scc[scc[0][0]][0] = scc[scc[0][0]][0] + 1;
            scc[scc[0][0]][scc[scc[0][0]][0]] = o;
            
        } while ( o != v );
    }

}

//Inizializza le strutture dati ed esegue l'algoritmo di Tarjan per il calcolo delle componenti fortemente connesse
int **scc(int **grafo, int n_nodi){

    int i;

	int *stack = I_alloc(n_nodi+1);

	int **scc = PI_alloc(n_nodi+1);
    scc[0] = I_alloc(1);
	scc[0][0] = 0;

    int *index = I_alloc(n_nodi);
    for(i=0;i<n_nodi;i++)
        index[i]=-1;

    int *lowlink = I_alloc(n_nodi);
    for(i=0;i<n_nodi;i++)
        lowlink[i]=-1;

    int index_n = 0;
    
    for(i=0;i<n_nodi;i++){
        if(index[i]==-1)
            strongconnect(i,stack,scc,index,lowlink,index_n,grafo,n_nodi);
    }

    free(stack);
    free(index);
    free(lowlink);

    return scc;

}




