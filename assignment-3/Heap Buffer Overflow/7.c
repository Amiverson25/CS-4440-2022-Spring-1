


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memmove_01_bad()
{
    char * data;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    memset(data, 'A', 100-1); 
    data[100-1] = '\0'; 
    {
        char dest[50] = "";
        
        memmove(dest, data, strlen(data)*sizeof(char));
        dest[50-1] = '\0'; 
        printLine(data);
        free(data);
    }
}

#endif 

#ifndef OMITGOOD


static void goodG2B()
{
    char * data;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    memset(data, 'A', 50-1); 
    data[50-1] = '\0'; 
    {
        char dest[50] = "";
        
        memmove(dest, data, strlen(data)*sizeof(char));
        dest[50-1] = '\0'; 
        printLine(data);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memmove_01_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memmove_01_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memmove_01_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
