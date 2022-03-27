


#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define SNPRINTF _snprintf
#else
#define SNPRINTF snprintf
#endif

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_snprintf_10_bad()
{
    char * data;
    data = NULL;
    if(globalTrue)
    {
        
        data = (char *)malloc(50*sizeof(char));
        if (data == NULL) {exit(-1);}
        data[0] = '\0'; 
    }
    {
        char source[100];
        memset(source, 'C', 100-1); 
        source[100-1] = '\0'; 
        
        SNPRINTF(data, 100, "%s", source);
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
        
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        data[0] = '\0'; 
    }
    {
        char source[100];
        memset(source, 'C', 100-1); 
        source[100-1] = '\0'; 
        
        SNPRINTF(data, 100, "%s", source);
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
        
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        data[0] = '\0'; 
    }
    {
        char source[100];
        memset(source, 'C', 100-1); 
        source[100-1] = '\0'; 
        
        SNPRINTF(data, 100, "%s", source);
        printLine(data);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_snprintf_10_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_snprintf_10_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_snprintf_10_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
