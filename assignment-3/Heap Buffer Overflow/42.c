


#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif


#define SRC_STRING L"AAAAAAAAAA"

static wchar_t * CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_loop_45_badData;
static wchar_t * CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_loop_45_goodG2BData;

#ifndef OMITBAD

static void badSink()
{
    wchar_t * data = CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_loop_45_badData;
    {
        wchar_t source[10+1] = SRC_STRING;
        size_t i, sourceLen;
        sourceLen = wcslen(source);
        
        
        for (i = 0; i < sourceLen + 1; i++)
        {
            data[i] = source[i];
        }
        printWLine(data);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_loop_45_bad()
{
    wchar_t * data;
    data = NULL;
    
    data = (wchar_t *)malloc(10*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_loop_45_badData = data;
    badSink();
}

#endif 

#ifndef OMITGOOD


static void goodG2BSink()
{
    wchar_t * data = CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_loop_45_goodG2BData;
    {
        wchar_t source[10+1] = SRC_STRING;
        size_t i, sourceLen;
        sourceLen = wcslen(source);
        
        
        for (i = 0; i < sourceLen + 1; i++)
        {
            data[i] = source[i];
        }
        printWLine(data);
        free(data);
    }
}

static void goodG2B()
{
    wchar_t * data;
    data = NULL;
    
    data = (wchar_t *)malloc((10+1)*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_loop_45_goodG2BData = data;
    goodG2BSink();
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_loop_45_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_loop_45_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_loop_45_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
