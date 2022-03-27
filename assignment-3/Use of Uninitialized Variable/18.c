


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__char_pointer_18_bad()
{
    char * data;
    goto source;
source:
    
    ; 
    goto sink;
sink:
    
    printLine(data);
}

#endif 

#ifndef OMITGOOD


static void goodB2G()
{
    char * data;
    goto source;
source:
    
    ; 
    goto sink;
sink:
    
    data = "string";
    printLine(data);
}


static void goodG2B()
{
    char * data;
    goto source;
source:
    
    data = "string";
    goto sink;
sink:
    
    printLine(data);
}

void CWE457_Use_of_Uninitialized_Variable__char_pointer_18_good()
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
    CWE457_Use_of_Uninitialized_Variable__char_pointer_18_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__char_pointer_18_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
