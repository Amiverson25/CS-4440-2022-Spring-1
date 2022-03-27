


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__struct_16_bad()
{
    twoIntsStruct data;
    while(1)
    {
        
        ; 
        break;
    }
    while(1)
    {
        
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
        break;
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G()
{
    twoIntsStruct data;
    while(1)
    {
        
        ; 
        break;
    }
    while(1)
    {
        
        data.intOne = 1;
        data.intTwo = 2;
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
        break;
    }
}


static void goodG2B()
{
    twoIntsStruct data;
    while(1)
    {
        
        data.intOne = 1;
        data.intTwo = 2;
        break;
    }
    while(1)
    {
        
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
        break;
    }
}

void CWE457_Use_of_Uninitialized_Variable__struct_16_good()
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
    CWE457_Use_of_Uninitialized_Variable__struct_16_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__struct_16_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
