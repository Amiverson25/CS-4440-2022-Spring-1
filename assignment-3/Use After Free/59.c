


#include "std_testcase.h"

#include <wchar.h>


static int staticTrue = 1; 
static int staticFalse = 0; 

#ifndef OMITBAD

void CWE416_Use_After_Free__malloc_free_long_05_bad()
{
    long * data;
    
    data = NULL;
    if(staticTrue)
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
    if(staticTrue)
    {
        
        printLongLine(data[0]);
        
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G1()
{
    long * data;
    
    data = NULL;
    if(staticTrue)
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
    if(staticFalse)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        
        
        ; 
    }
}


static void goodB2G2()
{
    long * data;
    
    data = NULL;
    if(staticTrue)
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
    if(staticTrue)
    {
        
        
        
        ; 
    }
}


static void goodG2B1()
{
    long * data;
    
    data = NULL;
    if(staticFalse)
    {
        
        printLine("Benign, fixed string");
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
    if(staticTrue)
    {
        
        printLongLine(data[0]);
        
    }
}


static void goodG2B2()
{
    long * data;
    
    data = NULL;
    if(staticTrue)
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
    if(staticTrue)
    {
        
        printLongLine(data[0]);
        
    }
}

void CWE416_Use_After_Free__malloc_free_long_05_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}

#endif 



#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE416_Use_After_Free__malloc_free_long_05_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_long_05_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
