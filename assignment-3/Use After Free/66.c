


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE416_Use_After_Free__malloc_free_long_12_bad()
{
    long * data;
    
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
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
    }
    else
    {
        data = (long *)malloc(100*sizeof(long));
        if (data == NULL) {exit(-1);}
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5L;
            }
        }
        
    }
    if(globalReturnsTrueOrFalse())
    {
        
        printLongLine(data[0]);
        
    }
    else
    {
        
        
        
        ; 
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G()
{
    long * data;
    
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
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
    }
    else
    {
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
    }
    if(globalReturnsTrueOrFalse())
    {
        
        
        
        ; 
    }
    else
    {
        
        
        
        ; 
    }
}


static void goodG2B()
{
    long * data;
    
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        data = (long *)malloc(100*sizeof(long));
        if (data == NULL) {exit(-1);}
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5L;
            }
        }
        
    }
    else
    {
        data = (long *)malloc(100*sizeof(long));
        if (data == NULL) {exit(-1);}
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5L;
            }
        }
        
    }
    if(globalReturnsTrueOrFalse())
    {
        
        printLongLine(data[0]);
        
    }
    else
    {
        
        printLongLine(data[0]);
        
    }
}

void CWE416_Use_After_Free__malloc_free_long_12_good()
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
    CWE416_Use_After_Free__malloc_free_long_12_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_long_12_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
