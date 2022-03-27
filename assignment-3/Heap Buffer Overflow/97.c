


#include "std_testcase.h"

static int64_t * CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_45_badData;
static int64_t * CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_45_goodG2BData;

#ifndef OMITBAD

static void badSink()
{
    int64_t * data = CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_45_badData;
    {
        int64_t source[100] = {0}; 
        
        memcpy(data, source, 100*sizeof(int64_t));
        printLongLongLine(data[0]);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_45_bad()
{
    int64_t * data;
    data = NULL;
    
    data = (int64_t *)malloc(50*sizeof(int64_t));
    if (data == NULL) {exit(-1);}
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_45_badData = data;
    badSink();
}

#endif 

#ifndef OMITGOOD


static void goodG2BSink()
{
    int64_t * data = CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_45_goodG2BData;
    {
        int64_t source[100] = {0}; 
        
        memcpy(data, source, 100*sizeof(int64_t));
        printLongLongLine(data[0]);
        free(data);
    }
}

static void goodG2B()
{
    int64_t * data;
    data = NULL;
    
    data = (int64_t *)malloc(100*sizeof(int64_t));
    if (data == NULL) {exit(-1);}
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_45_goodG2BData = data;
    goodG2BSink();
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_45_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_45_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_45_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
