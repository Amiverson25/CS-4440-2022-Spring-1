


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_memmove_01_bad()
{
    wchar_t * data;
    data = NULL;
    
    data = (wchar_t *)malloc(50*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    data[0] = L'\0'; 
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1); 
        source[100-1] = L'\0'; 
        
        memmove(data, source, 100*sizeof(wchar_t));
        data[100-1] = L'\0'; 
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
    
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    data[0] = L'\0'; 
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1); 
        source[100-1] = L'\0'; 
        
        memmove(data, source, 100*sizeof(wchar_t));
        data[100-1] = L'\0'; 
        printWLine(data);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_memmove_01_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_memmove_01_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_memmove_01_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
