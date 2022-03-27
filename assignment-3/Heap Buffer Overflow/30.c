


#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif


#define SRC_STRING "AAAAAAAAAA"

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_ncpy_10_bad()
{
    char * data;
    data = NULL;
    if(globalTrue)
    {
        
        data = (char *)malloc(10*sizeof(char));
        if (data == NULL) {exit(-1);}
    }
    {
        char source[10+1] = SRC_STRING;
        
        
        strncpy(data, source, strlen(source) + 1);
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
    if(globalFalse)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = (char *)malloc((10+1)*sizeof(char));
        if (data == NULL) {exit(-1);}
    }
    {
        char source[10+1] = SRC_STRING;
        
        
        strncpy(data, source, strlen(source) + 1);
        printLine(data);
        free(data);
    }
}


static void goodG2B2()
{
    char * data;
    data = NULL;
    if(globalTrue)
    {
        
        data = (char *)malloc((10+1)*sizeof(char));
        if (data == NULL) {exit(-1);}
    }
    {
        char source[10+1] = SRC_STRING;
        
        
        strncpy(data, source, strlen(source) + 1);
        printLine(data);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_ncpy_10_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_ncpy_10_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_ncpy_10_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
