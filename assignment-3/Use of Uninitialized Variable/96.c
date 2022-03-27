


#include "std_testcase.h"

#include <wchar.h>


static const int STATIC_CONST_FIVE = 5;

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__wchar_t_pointer_06_bad()
{
    wchar_t * data;
    if(STATIC_CONST_FIVE==5)
    {
        
        ; 
    }
    if(STATIC_CONST_FIVE==5)
    {
        
        printWLine(data);
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G1()
{
    wchar_t * data;
    if(STATIC_CONST_FIVE==5)
    {
        
        ; 
    }
    if(STATIC_CONST_FIVE!=5)
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
    if(STATIC_CONST_FIVE==5)
    {
        
        ; 
    }
    if(STATIC_CONST_FIVE==5)
    {
        
        data = L"string";
        printWLine(data);
    }
}


static void goodG2B1()
{
    wchar_t * data;
    if(STATIC_CONST_FIVE!=5)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = L"string";
    }
    if(STATIC_CONST_FIVE==5)
    {
        
        printWLine(data);
    }
}


static void goodG2B2()
{
    wchar_t * data;
    if(STATIC_CONST_FIVE==5)
    {
        
        data = L"string";
    }
    if(STATIC_CONST_FIVE==5)
    {
        
        printWLine(data);
    }
}

void CWE457_Use_of_Uninitialized_Variable__wchar_t_pointer_06_good()
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
    CWE457_Use_of_Uninitialized_Variable__wchar_t_pointer_06_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__wchar_t_pointer_06_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
