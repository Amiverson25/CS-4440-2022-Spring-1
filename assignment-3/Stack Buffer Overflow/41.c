


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_memcpy_01_bad()
{
    char * data;
    char * dataBuffer = (char *)ALLOCA(100*sizeof(char));
    data = dataBuffer;
    
    memset(data, 'A', 100-1); 
    data[100-1] = '\0'; 
    {
        char dest[50] = "";
        
        memcpy(dest, data, strlen(data)*sizeof(char));
        dest[50-1] = '\0'; 
        printLine(data);
    }
}

#endif 

#ifndef OMITGOOD


static void goodG2B()
{
    char * data;
    char * dataBuffer = (char *)ALLOCA(100*sizeof(char));
    data = dataBuffer;
    
    memset(data, 'A', 50-1); 
    data[50-1] = '\0'; 
    {
        char dest[50] = "";
        
        memcpy(dest, data, strlen(data)*sizeof(char));
        dest[50-1] = '\0'; 
        printLine(data);
    }
}

void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_memcpy_01_good()
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
    CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_memcpy_01_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_memcpy_01_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
