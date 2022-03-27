


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memcpy_10_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    if(globalTrue)
    {
        
        wmemset(data, L'A', 100-1); 
        data[100-1] = L'\0'; 
    }
    {
        wchar_t dest[50] = L"";
        
        memcpy(dest, data, wcslen(data)*sizeof(wchar_t));
        dest[50-1] = L'\0'; 
        printWLine(data);
    }
}

#endif 

#ifndef OMITGOOD


static void goodG2B1()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    if(globalFalse)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        wmemset(data, L'A', 50-1); 
        data[50-1] = L'\0'; 
    }
    {
        wchar_t dest[50] = L"";
        
        memcpy(dest, data, wcslen(data)*sizeof(wchar_t));
        dest[50-1] = L'\0'; 
        printWLine(data);
    }
}


static void goodG2B2()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    if(globalTrue)
    {
        
        wmemset(data, L'A', 50-1); 
        data[50-1] = L'\0'; 
    }
    {
        wchar_t dest[50] = L"";
        
        memcpy(dest, data, wcslen(data)*sizeof(wchar_t));
        dest[50-1] = L'\0'; 
        printWLine(data);
    }
}

void CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memcpy_10_good()
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
    CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memcpy_10_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memcpy_10_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
