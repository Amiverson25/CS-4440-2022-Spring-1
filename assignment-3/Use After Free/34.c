


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE416_Use_After_Free__malloc_free_int64_t_16_bad()
{
    int64_t * data;
    
    data = NULL;
    while(1)
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
        break;
    }
    while(1)
    {
        
        printLongLongLine(data[0]);
        
        break;
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G()
{
    int64_t * data;
    
    data = NULL;
    while(1)
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
        break;
    }
    while(1)
    {
        
        
        
        ; 
        break;
    }
}


static void goodG2B()
{
    int64_t * data;
    
    data = NULL;
    while(1)
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
        
        break;
    }
    while(1)
    {
        
        printLongLongLine(data[0]);
        
        break;
    }
}

void CWE416_Use_After_Free__malloc_free_int64_t_16_good()
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
    CWE416_Use_After_Free__malloc_free_int64_t_16_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_int64_t_16_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
