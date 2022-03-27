


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__char_pointer_01_bad()
{
    char * data;
    
    ; 
    
    printLine(data);
}

#endif 

#ifndef OMITGOOD


static void goodG2B()
{
    char * data;
    
    data = "string";
    
    printLine(data);
}


static void goodB2G()
{
    char * data;
    
    ; 
    
    data = "string";
    printLine(data);
}

void CWE457_Use_of_Uninitialized_Variable__char_pointer_01_good()
{
    goodG2B();
    goodB2G();
}

#endif 



#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE457_Use_of_Uninitialized_Variable__char_pointer_01_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__char_pointer_01_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
