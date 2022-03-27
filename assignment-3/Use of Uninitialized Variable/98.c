


#include "std_testcase.h"

#include <wchar.h>


static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__wchar_t_pointer_08_bad()
{
    wchar_t * data;
    if(staticReturnsTrue())
    {
        
        ; 
    }
    if(staticReturnsTrue())
    {
        
        printWLine(data);
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G1()
{
    wchar_t * data;
    if(staticReturnsTrue())
    {
        
        ; 
    }
    if(staticReturnsFalse())
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
    if(staticReturnsTrue())
    {
        
        ; 
    }
    if(staticReturnsTrue())
    {
        
        data = L"string";
        printWLine(data);
    }
}


static void goodG2B1()
{
    wchar_t * data;
    if(staticReturnsFalse())
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = L"string";
    }
    if(staticReturnsTrue())
    {
        
        printWLine(data);
    }
}


static void goodG2B2()
{
    wchar_t * data;
    if(staticReturnsTrue())
    {
        
        data = L"string";
    }
    if(staticReturnsTrue())
    {
        
        printWLine(data);
    }
}

void CWE457_Use_of_Uninitialized_Variable__wchar_t_pointer_08_good()
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
    CWE457_Use_of_Uninitialized_Variable__wchar_t_pointer_08_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__wchar_t_pointer_08_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
