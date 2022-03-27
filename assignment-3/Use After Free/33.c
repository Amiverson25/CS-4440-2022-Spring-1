


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE416_Use_After_Free__malloc_free_int64_t_15_bad()
{
    int64_t * data;
    
    data = NULL;
    switch(6)
    {
    case 6:
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
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    switch(7)
    {
    case 7:
        
        printLongLongLine(data[0]);
        
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G1()
{
    int64_t * data;
    
    data = NULL;
    switch(6)
    {
    case 6:
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
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    switch(8)
    {
    case 7:
        
        printLine("Benign, fixed string");
        break;
    default:
        
        
        
        ; 
        break;
    }
}


static void goodB2G2()
{
    int64_t * data;
    
    data = NULL;
    switch(6)
    {
    case 6:
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
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    switch(7)
    {
    case 7:
        
        
        
        ; 
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}


static void goodG2B1()
{
    int64_t * data;
    
    data = NULL;
    switch(5)
    {
    case 6:
        
        printLine("Benign, fixed string");
        break;
    default:
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
    switch(7)
    {
    case 7:
        
        printLongLongLine(data[0]);
        
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}


static void goodG2B2()
{
    int64_t * data;
    
    data = NULL;
    switch(6)
    {
    case 6:
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
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    switch(7)
    {
    case 7:
        
        printLongLongLine(data[0]);
        
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}

void CWE416_Use_After_Free__malloc_free_int64_t_15_good()
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
    CWE416_Use_After_Free__malloc_free_int64_t_15_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_int64_t_15_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
