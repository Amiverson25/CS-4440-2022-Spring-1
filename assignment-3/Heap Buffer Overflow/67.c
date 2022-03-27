


#include "std_testcase.h"

#include <wchar.h>

static char * CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memcpy_45_badData;
static char * CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memcpy_45_goodG2BData;

#ifndef OMITBAD

static void badSink()
{
    char * data = CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memcpy_45_badData;
    {
        char source[100];
        memset(source, 'C', 100-1); 
        source[100-1] = '\0'; 
        
        memcpy(data, source, 100*sizeof(char));
        data[100-1] = '\0'; 
        printLine(data);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memcpy_45_bad()
{
    char * data;
    data = NULL;
    
    data = (char *)malloc(50*sizeof(char));
    if (data == NULL) {exit(-1);}
    data[0] = '\0'; 
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memcpy_45_badData = data;
    badSink();
}

#endif 

#ifndef OMITGOOD


static void goodG2BSink()
{
    char * data = CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memcpy_45_goodG2BData;
    {
        char source[100];
        memset(source, 'C', 100-1); 
        source[100-1] = '\0'; 
        
        memcpy(data, source, 100*sizeof(char));
        data[100-1] = '\0'; 
        printLine(data);
        free(data);
    }
}

static void goodG2B()
{
    char * data;
    data = NULL;
    
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    data[0] = '\0'; 
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memcpy_45_goodG2BData = data;
    goodG2BSink();
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memcpy_45_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memcpy_45_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memcpy_45_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
