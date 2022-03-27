


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__char_pointer_16_bad()
{
    char * data;
    while(1)
    {
        
        ; 
        break;
    }
    while(1)
    {
        
        printLine(data);
        break;
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G()
{
    char * data;
    while(1)
    {
        
        ; 
        break;
    }
    while(1)
    {
        
        data = "string";
        printLine(data);
        break;
    }
}


static void goodG2B()
{
    char * data;
    while(1)
    {
        
        data = "string";
        break;
    }
    while(1)
    {
        
        printLine(data);
        break;
    }
}

void CWE457_Use_of_Uninitialized_Variable__char_pointer_16_good()
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
    CWE457_Use_of_Uninitialized_Variable__char_pointer_16_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__char_pointer_16_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
