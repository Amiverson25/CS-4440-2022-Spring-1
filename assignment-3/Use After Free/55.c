


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE416_Use_After_Free__malloc_free_long_01_bad()
{
    long * data;
    
    data = NULL;
    data = (long *)malloc(100*sizeof(long));
    if (data == NULL) {exit(-1);}
    {
        size_t i;
        for(i = 0; i < 100; i++)
        {
            data[i] = 5L;
        }
    }
    
    free(data);
    
    printLongLine(data[0]);
    
}

#endif 

#ifndef OMITGOOD


static void goodG2B()
{
    long * data;
    
    data = NULL;
    data = (long *)malloc(100*sizeof(long));
    if (data == NULL) {exit(-1);}
    {
        size_t i;
        for(i = 0; i < 100; i++)
        {
            data[i] = 5L;
        }
    }
    
    
    printLongLine(data[0]);
    
}


static void goodB2G()
{
    long * data;
    
    data = NULL;
    data = (long *)malloc(100*sizeof(long));
    if (data == NULL) {exit(-1);}
    {
        size_t i;
        for(i = 0; i < 100; i++)
        {
            data[i] = 5L;
        }
    }
    
    free(data);
    
    
    
    ; 
}

void CWE416_Use_After_Free__malloc_free_long_01_good()
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
    CWE416_Use_After_Free__malloc_free_long_01_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_long_01_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
