


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE416_Use_After_Free__malloc_free_int64_t_01_bad()
{
    int64_t * data;
    
    data = NULL;
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
    
    printLongLongLine(data[0]);
    
}

#endif 

#ifndef OMITGOOD


static void goodG2B()
{
    int64_t * data;
    
    data = NULL;
    data = (int64_t *)malloc(100*sizeof(int64_t));
    if (data == NULL) {exit(-1);}
    {
        size_t i;
        for(i = 0; i < 100; i++)
        {
            data[i] = 5LL;
        }
    }
    
    
    printLongLongLine(data[0]);
    
}


static void goodB2G()
{
    int64_t * data;
    
    data = NULL;
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
    
    
    
    ; 
}

void CWE416_Use_After_Free__malloc_free_int64_t_01_good()
{
    goodG2B();
    goodB2G();
}

#endif 



#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE416_Use_After_Free__malloc_free_int64_t_01_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_int64_t_01_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
