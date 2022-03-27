


#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif


#define SRC_STR L"0123456789abcdef0123456789abcde"

typedef struct _charVoid
{
    wchar_t charFirst[16];
    void * voidSecond;
    void * voidThird;
} charVoid;

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__wchar_t_type_overrun_memcpy_01_bad()
{
    {
        charVoid structCharVoid;
        structCharVoid.voidSecond = (void *)SRC_STR;
        
        printWLine((wchar_t *)structCharVoid.voidSecond);
        
        memcpy(structCharVoid.charFirst, SRC_STR, sizeof(structCharVoid));
        structCharVoid.charFirst[(sizeof(structCharVoid.charFirst)/sizeof(wchar_t))-1] = L'\0'; 
        printWLine((wchar_t *)structCharVoid.charFirst);
        printWLine((wchar_t *)structCharVoid.voidSecond);
    }
}

#endif 

#ifndef OMITGOOD

static void good1()
{
    {
        charVoid structCharVoid;
        structCharVoid.voidSecond = (void *)SRC_STR;
        
        printWLine((wchar_t *)structCharVoid.voidSecond);
        
        memcpy(structCharVoid.charFirst, SRC_STR, sizeof(structCharVoid.charFirst));
        structCharVoid.charFirst[(sizeof(structCharVoid.charFirst)/sizeof(wchar_t))-1] = L'\0'; 
        printWLine((wchar_t *)structCharVoid.charFirst);
        printWLine((wchar_t *)structCharVoid.voidSecond);
    }
}

void CWE121_Stack_Based_Buffer_Overflow__wchar_t_type_overrun_memcpy_01_good()
{
    good1();
}

#endif 



#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE121_Stack_Based_Buffer_Overflow__wchar_t_type_overrun_memcpy_01_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__wchar_t_type_overrun_memcpy_01_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
