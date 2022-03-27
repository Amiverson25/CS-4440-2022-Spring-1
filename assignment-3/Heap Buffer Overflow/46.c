


#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif


#define SRC_STRING L"AAAAAAAAAA"

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_memcpy_15_bad()
{
    wchar_t * data;
    data = NULL;
    switch(6)
    {
    case 6:
        
        data = (wchar_t *)malloc(10*sizeof(wchar_t));
        if (data == NULL) {exit(-1);}
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    {
        wchar_t source[10+1] = SRC_STRING;
        
        
        memcpy(data, source, (wcslen(source) + 1) * sizeof(wchar_t));
        printWLine(data);
        free(data);
    }
}

#endif 

#ifndef OMITGOOD


static void goodG2B1()
{
    wchar_t * data;
    data = NULL;
    switch(5)
    {
    case 6:
        
        printLine("Benign, fixed string");
        break;
    default:
        
        data = (wchar_t *)malloc((10+1)*sizeof(wchar_t));
        if (data == NULL) {exit(-1);}
        break;
    }
    {
        wchar_t source[10+1] = SRC_STRING;
        
        
        memcpy(data, source, (wcslen(source) + 1) * sizeof(wchar_t));
        printWLine(data);
        free(data);
    }
}


static void goodG2B2()
{
    wchar_t * data;
    data = NULL;
    switch(6)
    {
    case 6:
        
        data = (wchar_t *)malloc((10+1)*sizeof(wchar_t));
        if (data == NULL) {exit(-1);}
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    {
        wchar_t source[10+1] = SRC_STRING;
        
        
        memcpy(data, source, (wcslen(source) + 1) * sizeof(wchar_t));
        printWLine(data);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_memcpy_15_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_memcpy_15_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_memcpy_15_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
