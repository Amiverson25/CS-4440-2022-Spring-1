


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__char_pointer_12_bad()
{
    char * data;
    if(globalReturnsTrueOrFalse())
    {
        
        ; 
    }
    else
    {
        
        data = "string";
    }
    if(globalReturnsTrueOrFalse())
    {
        
        printLine(data);
    }
    else
    {
        
        data = "string";
        printLine(data);
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G()
{
    char * data;
    if(globalReturnsTrueOrFalse())
    {
        
        ; 
    }
    else
    {
        
        ; 
    }
    if(globalReturnsTrueOrFalse())
    {
        
        data = "string";
        printLine(data);
    }
    else
    {
        
        data = "string";
        printLine(data);
    }
}


static void goodG2B()
{
    char * data;
    if(globalReturnsTrueOrFalse())
    {
        
        data = "string";
    }
    else
    {
        
        data = "string";
    }
    if(globalReturnsTrueOrFalse())
    {
        
        printLine(data);
    }
    else
    {
        
        printLine(data);
    }
}

void CWE457_Use_of_Uninitialized_Variable__char_pointer_12_good()
{
    goodB2G();
    goodG2B();
}

#endif 



#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE457_Use_of_Uninitialized_Variable__char_pointer_12_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__char_pointer_12_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
