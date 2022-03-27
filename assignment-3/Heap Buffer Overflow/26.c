


#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif


#define SRC_STRING "AAAAAAAAAA"

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_15_bad()
{
    char * data;
    data = NULL;
    switch(6)
    {
    case 6:
        
        data = (char *)malloc(10*sizeof(char));
        if (data == NULL) {exit(-1);}
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    {
        char source[10+1] = SRC_STRING;
        
        
        memmove(data, source, (strlen(source) + 1) * sizeof(char));
        printLine(data);
        free(data);
    }
}

#endif 

#ifndef OMITGOOD


static void goodG2B1()
{
    char * data;
    data = NULL;
    switch(5)
    {
    case 6:
        
        printLine("Benign, fixed string");
        break;
    default:
        
        data = (char *)malloc((10+1)*sizeof(char));
        if (data == NULL) {exit(-1);}
        break;
    }
    {
        char source[10+1] = SRC_STRING;
        
        
        memmove(data, source, (strlen(source) + 1) * sizeof(char));
        printLine(data);
        free(data);
    }
}


static void goodG2B2()
{
    char * data;
    data = NULL;
    switch(6)
    {
    case 6:
        
        data = (char *)malloc((10+1)*sizeof(char));
        if (data == NULL) {exit(-1);}
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    {
        char source[10+1] = SRC_STRING;
        
        
        memmove(data, source, (strlen(source) + 1) * sizeof(char));
        printLine(data);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_15_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_15_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_15_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
