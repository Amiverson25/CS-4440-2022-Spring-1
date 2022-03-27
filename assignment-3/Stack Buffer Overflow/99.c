


#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define SNPRINTF _snprintf
#else
#define SNPRINTF snprintf
#endif

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__CWE805_char_declare_snprintf_11_bad()
{
    char * data;
    char dataBadBuffer[50];
    char dataGoodBuffer[100];
    if(globalReturnsTrue())
    {
        
        data = dataBadBuffer;
        data[0] = '\0'; 
    }
    {
        char source[100];
        memset(source, 'C', 100-1); 
        source[100-1] = '\0'; 
        
        SNPRINTF(data, 100, "%s", source);
        printLine(data);
    }
}

#endif 

#ifndef OMITGOOD


static void goodG2B1()
{
    char * data;
    char dataBadBuffer[50];
    char dataGoodBuffer[100];
    if(globalReturnsFalse())
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = dataGoodBuffer;
        data[0] = '\0'; 
    }
    {
        char source[100];
        memset(source, 'C', 100-1); 
        source[100-1] = '\0'; 
        
        SNPRINTF(data, 100, "%s", source);
        printLine(data);
    }
}


static void goodG2B2()
{
    char * data;
    char dataBadBuffer[50];
    char dataGoodBuffer[100];
    if(globalReturnsTrue())
    {
        
        data = dataGoodBuffer;
        data[0] = '\0'; 
    }
    {
        char source[100];
        memset(source, 'C', 100-1); 
        source[100-1] = '\0'; 
        
        SNPRINTF(data, 100, "%s", source);
        printLine(data);
    }
}

void CWE121_Stack_Based_Buffer_Overflow__CWE805_char_declare_snprintf_11_good()
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
    CWE121_Stack_Based_Buffer_Overflow__CWE805_char_declare_snprintf_11_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE805_char_declare_snprintf_11_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
