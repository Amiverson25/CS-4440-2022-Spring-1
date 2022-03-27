


#include "std_testcase.h"

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_01_bad()
{
    int * data;
    data = NULL;
    
    data = (int *)malloc(10);
    if (data == NULL) {exit(-1);}
    {
        int source[10] = {0};
        size_t i;
        
        for (i = 0; i < 10; i++)
        {
            data[i] = source[i];
        }
        printIntLine(data[0]);
        free(data);
    }
}

#endif 

#ifndef OMITGOOD


static void goodG2B()
{
    int * data;
    data = NULL;
    
    data = (int *)malloc(10*sizeof(int));
    if (data == NULL) {exit(-1);}
    {
        int source[10] = {0};
        size_t i;
        
        for (i = 0; i < 10; i++)
        {
            data[i] = source[i];
        }
        printIntLine(data[0]);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_01_good()
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
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_01_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_01_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
