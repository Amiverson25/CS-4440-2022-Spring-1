


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_01_bad()
{
    char * data;
    data = NULL;
    
    data = (char *)malloc(50*sizeof(char));
    if (data == NULL) {exit(-1);}
    data[0] = '\0'; 
    {
        char source[100];
        memset(source, 'C', 100-1); 
        source[100-1] = '\0'; 
        
        strncat(data, source, 100);
        printLine(data);
        free(data);
    }
}

#endif 

#ifndef OMITGOOD


static void goodG2B()
{
    char * data;
    data = NULL;
    
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    data[0] = '\0'; 
    {
        char source[100];
        memset(source, 'C', 100-1); 
        source[100-1] = '\0'; 
        
        strncat(data, source, 100);
        printLine(data);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_01_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_01_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_01_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
