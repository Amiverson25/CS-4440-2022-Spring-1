


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_cpy_01_bad()
{
    char * data;
    char dataBadBuffer[50];
    char dataGoodBuffer[100];
    
    data = dataBadBuffer;
    data[0] = '\0'; 
    {
        char source[100];
        memset(source, 'C', 100-1); 
        source[100-1] = '\0'; 
        
        strcpy(data, source);
        printLine(data);
    }
}

#endif 

#ifndef OMITGOOD


static void goodG2B()
{
    char * data;
    char dataBadBuffer[50];
    char dataGoodBuffer[100];
    
    data = dataGoodBuffer;
    data[0] = '\0'; 
    {
        char source[100];
        memset(source, 'C', 100-1); 
        source[100-1] = '\0'; 
        
        strcpy(data, source);
        printLine(data);
    }
}

void CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_cpy_01_good()
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
    CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_cpy_01_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_cpy_01_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
