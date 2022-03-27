


#include "std_testcase.h"

static int * CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_45_badData;
static int * CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_45_goodG2BData;

#ifndef OMITBAD

static void badSink()
{
    int * data = CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_45_badData;
    {
        int source[10] = {0};
        
        memcpy(data, source, 10*sizeof(int));
        printIntLine(data[0]);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_45_bad()
{
    int * data;
    data = NULL;
    
    data = (int *)malloc(10);
    if (data == NULL) {exit(-1);}
    CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_45_badData = data;
    badSink();
}

#endif 

#ifndef OMITGOOD


static void goodG2BSink()
{
    int * data = CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_45_goodG2BData;
    {
        int source[10] = {0};
        
        memcpy(data, source, 10*sizeof(int));
        printIntLine(data[0]);
        free(data);
    }
}

static void goodG2B()
{
    int * data;
    data = NULL;
    
    data = (int *)malloc(10*sizeof(int));
    if (data == NULL) {exit(-1);}
    CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_45_goodG2BData = data;
    goodG2BSink();
}

void CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_45_good()
{
    goodG2B();
}

#endif 


#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_45_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_45_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
