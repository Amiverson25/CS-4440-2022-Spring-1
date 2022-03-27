


#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif


#define SRC_STRING "AAAAAAAAAA"

static char * CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_45_badData;
static char * CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_45_goodG2BData;

#ifndef OMITBAD

static void badSink()
{
    char * data = CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_45_badData;
    {
        char source[10+1] = SRC_STRING;
        
        
        memmove(data, source, (strlen(source) + 1) * sizeof(char));
        printLine(data);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_45_bad()
{
    char * data;
    data = NULL;
    
    data = (char *)malloc(10*sizeof(char));
    if (data == NULL) {exit(-1);}
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_45_badData = data;
    badSink();
}

#endif 

#ifndef OMITGOOD


static void goodG2BSink()
{
    char * data = CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_45_goodG2BData;
    {
        char source[10+1] = SRC_STRING;
        
        
        memmove(data, source, (strlen(source) + 1) * sizeof(char));
        printLine(data);
        free(data);
    }
}

static void goodG2B()
{
    char * data;
    data = NULL;
    
    data = (char *)malloc((10+1)*sizeof(char));
    if (data == NULL) {exit(-1);}
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_45_goodG2BData = data;
    goodG2BSink();
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_45_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_45_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_45_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
