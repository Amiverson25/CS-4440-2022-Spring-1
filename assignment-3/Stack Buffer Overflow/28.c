


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_loop_10_bad()
{
    wchar_t * data;
    wchar_t dataBadBuffer[50];
    wchar_t dataGoodBuffer[100];
    if(globalTrue)
    {
        
        data = dataBadBuffer;
        data[0] = L'\0'; 
    }
    {
        size_t i;
        wchar_t source[100];
        wmemset(source, L'C', 100-1); 
        source[100-1] = L'\0'; 
        
        for (i = 0; i < 100; i++)
        {
            data[i] = source[i];
        }
        data[100-1] = L'\0'; 
        printWLine(data);
    }
}

#endif 

#ifndef OMITGOOD


static void goodG2B1()
{
    wchar_t * data;
    wchar_t dataBadBuffer[50];
    wchar_t dataGoodBuffer[100];
    if(globalFalse)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = dataGoodBuffer;
        data[0] = L'\0'; 
    }
    {
        size_t i;
        wchar_t source[100];
        wmemset(source, L'C', 100-1); 
        source[100-1] = L'\0'; 
        
        for (i = 0; i < 100; i++)
        {
            data[i] = source[i];
        }
        data[100-1] = L'\0'; 
        printWLine(data);
    }
}


static void goodG2B2()
{
    wchar_t * data;
    wchar_t dataBadBuffer[50];
    wchar_t dataGoodBuffer[100];
    if(globalTrue)
    {
        
        data = dataGoodBuffer;
        data[0] = L'\0'; 
    }
    {
        size_t i;
        wchar_t source[100];
        wmemset(source, L'C', 100-1); 
        source[100-1] = L'\0'; 
        
        for (i = 0; i < 100; i++)
        {
            data[i] = source[i];
        }
        data[100-1] = L'\0'; 
        printWLine(data);
    }
}

void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_loop_10_good()
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
    CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_loop_10_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_loop_10_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
