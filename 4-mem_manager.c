#include "shell.h"

/*
 * step 1: allocate a temp memory with initial bufSize
 * step 2: copy from  buff to temp
 * step 3: free buff
 * step 4: reallocate the new buff
 * step 5: copy from tmp to buff
 * step 6: free tmp
 * step 6: return the new buff
 */

void * _realloc(void *ptr, int old, int new)
{
    void *tmp;
    int i, min;
    if (!ptr)
        return (malloc(new));
    else if (new == old)
        return (ptr);
    else if (new == 0 && ptr)
    {
        free(ptr);
        return (NULL);
    }
    else
    {
        min = (new < old) ? new : old;
        tmp = malloc(new);
        if (tmp)
        {
            for (i = 0; i < min; i++)
            *((char *)tmp + i) = * ((char *)ptr + i);
            free(ptr);
            return (tmp);
        }
        else 
            return (NULL);
    }
    
}