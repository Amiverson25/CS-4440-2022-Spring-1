


#include "std_testcase.h"

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_01_bad()
{
    int64_t * data;
    data = NULL;
    
    data = (int64_t *)malloc(50*sizeof(int64_t));
    if (data == NULL) {exit(-1);}
    {
        int64_t source[100] = {0}; 
        
        memcpy(data, source, 100*sizeof(int64_t));
        printLongLongLine(data[0]);
        free(data);
    }
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
        int64_t source[100] = {0}; 
        
        memcpy(data, source, 100*sizeof(int64_t));
        printLongLongLine(data[0]);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_01_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_01_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_01_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
