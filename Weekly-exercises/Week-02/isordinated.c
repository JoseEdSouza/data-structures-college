#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_ordinated(int* array, size_t size);


int main() {
    int n =0;
    scanf("%d",&n);
    int*array = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;++i){
        scanf("%d",&array[i]);
    }
    printf("%i\n",is_ordinated(array,n));

}

bool is_ordinated(int* array, size_t size) {
    if (size < 0) exit(1);
    if (size == 0)
        return true;
    for (int i = 0;i < size - 1;++i) {
        if (array[i] > array[i + 1])
            return false;
    }
    return true;
}