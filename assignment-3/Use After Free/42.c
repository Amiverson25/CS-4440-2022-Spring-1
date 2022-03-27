


#include "std_testcase.h"

#include <wchar.h>


static const int STATIC_CONST_FIVE = 5;

#ifndef OMITBAD

void CWE416_Use_After_Free__malloc_free_int_06_bad()
{
    int * data;
    
    data = NULL;
    if(STATIC_CONST_FIVE==5)
    {
        data = (int *)malloc(100*sizeof(int));
        if (data == NULL) {exit(-1);}
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5;
            }
        }
        
        free(data);
    }
    if(STATIC_CONST_FIVE==5)
    {
        
        printIntLine(data[0]);
        
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G1()
{
    int * data;
    
    data = NULL;
    if(STATIC_CONST_FIVE==5)
    {
        data = (int *)malloc(100*sizeof(int));
        if (data == NULL) {exit(-1);}
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5;
            }
        }
        
        free(data);
    }
    if(STATIC_CONST_FIVE!=5)
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
    int * data;
    
    data = NULL;
    if(STATIC_CONST_FIVE==5)
    {
        data = (int *)malloc(100*sizeof(int));
        if (data == NULL) {exit(-1);}
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5;
            }
        }
        
        free(data);
    }
    if(STATIC_CONST_FIVE==5)
    {
        
        
        
        ; 
    }
}


static void goodG2B1()
{
    int * data;
    
    data = NULL;
    if(STATIC_CONST_FIVE!=5)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        data = (int *)malloc(100*sizeof(int));
        if (data == NULL) {exit(-1);}
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5;
            }
        }
        
    }
    if(STATIC_CONST_FIVE==5)
    {
        
        printIntLine(data[0]);
        
    }
}


static void goodG2B2()
{
    int * data;
    
    data = NULL;
    if(STATIC_CONST_FIVE==5)
    {
        data = (int *)malloc(100*sizeof(int));
        if (data == NULL) {exit(-1);}
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5;
            }
        }
        
    }
    if(STATIC_CONST_FIVE==5)
    {
        
        printIntLine(data[0]);
        
    }
}

void CWE416_Use_After_Free__malloc_free_int_06_good()
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
    CWE416_Use_After_Free__malloc_free_int_06_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_int_06_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
