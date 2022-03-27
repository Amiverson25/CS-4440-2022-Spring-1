


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE416_Use_After_Free__malloc_free_int64_t_17_bad()
{
    int i,j;
    int64_t * data;
    
    data = NULL;
    for(i = 0; i < 1; i++)
    {
        data = (int64_t *)malloc(100*sizeof(int64_t));
        if (data == NULL) {exit(-1);}
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5LL;
            }
        }
        
        free(data);
    }
    for(j = 0; j < 1; j++)
    {
        
        printLongLongLine(data[0]);
        
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G()
{
    int i,k;
    int64_t * data;
    
    data = NULL;
    for(i = 0; i < 1; i++)
    {
        data = (int64_t *)malloc(100*sizeof(int64_t));
        if (data == NULL) {exit(-1);}
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5LL;
            }
        }
        
        free(data);
    }
    for(k = 0; k < 1; k++)
    {
        
        
        
        ; 
    }
}


static void goodG2B()
{
    int h,j;
    int64_t * data;
    
    data = NULL;
    for(h = 0; h < 1; h++)
    {
        data = (int64_t *)malloc(100*sizeof(int64_t));
        if (data == NULL) {exit(-1);}
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5LL;
            }
        }
        
    }
    for(j = 0; j < 1; j++)
    {
        
        printLongLongLine(data[0]);
        
    }
}

void CWE416_Use_After_Free__malloc_free_int64_t_17_good()
{
    goodB2G();
    goodG2B();
}

#endif 



#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE416_Use_After_Free__malloc_free_int64_t_17_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_int64_t_17_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
