


#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define SNPRINTF _snwprintf
#else
#define SNPRINTF swprintf
#endif

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_snprintf_01_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    
    wmemset(data, L'A', 100-1); 
    data[100-1] = L'\0'; 
    {
        wchar_t dest[50] = L"";
        
        SNPRINTF(dest, wcslen(data), L"%s", data);
        printWLine(data);
    }
}

#endif 

#ifndef OMITGOOD


static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    
    wmemset(data, L'A', 50-1); 
    data[50-1] = L'\0'; 
    {
        wchar_t dest[50] = L"";
        
        SNPRINTF(dest, wcslen(data), L"%s", data);
        printWLine(data);
    }
}

void CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_snprintf_01_good()
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
    CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_snprintf_01_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_snprintf_01_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
