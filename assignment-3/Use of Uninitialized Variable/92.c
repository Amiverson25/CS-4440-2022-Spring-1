


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__wchar_t_pointer_02_bad()
{
    wchar_t * data;
    if(1)
    {
        
        ; 
    }
    if(1)
    {
        
        printWLine(data);
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G1()
{
    wchar_t * data;
    if(1)
    {
        
        ; 
    }
    if(0)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = L"string";
        printWLine(data);
    }
}


static void goodB2G2()
{
    wchar_t * data;
    if(1)
    {
        
        ; 
    }
    if(1)
    {
        
        data = L"string";
        printWLine(data);
    }
}


static void goodG2B1()
{
    wchar_t * data;
    if(0)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = L"string";
    }
    if(1)
    {
        
        printWLine(data);
    }
}


static void goodG2B2()
{
    wchar_t * data;
    if(1)
    {
        
        data = L"string";
    }
    if(1)
    {
        
        printWLine(data);
    }
}

void CWE457_Use_of_Uninitialized_Variable__wchar_t_pointer_02_good()
{
    goodB2G1();
    goodB2G2();
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
    CWE457_Use_of_Uninitialized_Variable__wchar_t_pointer_02_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__wchar_t_pointer_02_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
