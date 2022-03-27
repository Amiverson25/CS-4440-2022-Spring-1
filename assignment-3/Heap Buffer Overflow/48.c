


#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif


#define SRC_STRING L"AAAAAAAAAA"

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_memmove_01_bad()
{
    wchar_t * data;
    data = NULL;
    
    data = (wchar_t *)malloc(10*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    {
        wchar_t source[10+1] = SRC_STRING;
        
        
        memmove(data, source, (wcslen(source) + 1) * sizeof(wchar_t));
        printWLine(data);
        free(data);
    }
}

#endif 

#ifndef OMITGOOD


static void goodG2B()
{
    wchar_t * data;
    data = NULL;
    
    data = (wchar_t *)malloc((10+1)*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    {
        wchar_t source[10+1] = SRC_STRING;
        
        
        memmove(data, source, (wcslen(source) + 1) * sizeof(wchar_t));
        printWLine(data);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_memmove_01_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_memmove_01_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_memmove_01_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
