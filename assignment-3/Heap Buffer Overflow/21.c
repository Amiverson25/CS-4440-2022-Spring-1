


#include "std_testcase.h"

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_15_bad()
{
    int * data;
    data = NULL;
    switch(6)
    {
    case 6:
        
        data = (int *)malloc(10);
        if (data == NULL) {exit(-1);}
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    {
        int source[10] = {0};
        
        memcpy(data, source, 10*sizeof(int));
        printIntLine(data[0]);
        free(data);
    }
}

#endif 

#ifndef OMITGOOD


static void goodG2B1()
{
    int * data;
    data = NULL;
    switch(5)
    {
    case 6:
        
        printLine("Benign, fixed string");
        break;
    default:
        
        data = (int *)malloc(10*sizeof(int));
        if (data == NULL) {exit(-1);}
        break;
    }
    {
        int source[10] = {0};
        
        memcpy(data, source, 10*sizeof(int));
        printIntLine(data[0]);
        free(data);
    }
}


static void goodG2B2()
{
    int * data;
    data = NULL;
    switch(6)
    {
    case 6:
        
        data = (int *)malloc(10*sizeof(int));
        if (data == NULL) {exit(-1);}
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    {
        int source[10] = {0};
        
        memcpy(data, source, 10*sizeof(int));
        printIntLine(data[0]);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_15_good()
{
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
    CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_15_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_15_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
