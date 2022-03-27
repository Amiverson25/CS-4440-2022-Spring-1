


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__struct_12_bad()
{
    twoIntsStruct data;
    if(globalReturnsTrueOrFalse())
    {
        
        ; 
    }
    else
    {
        
        data.intOne = 1;
        data.intTwo = 2;
    }
    if(globalReturnsTrueOrFalse())
    {
        
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
    }
    else
    {
        
        data.intOne = 1;
        data.intTwo = 2;
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G()
{
    twoIntsStruct data;
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
        
        data.intOne = 1;
        data.intTwo = 2;
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
    }
    else
    {
        
        data.intOne = 1;
        data.intTwo = 2;
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
    }
}


static void goodG2B()
{
    twoIntsStruct data;
    if(globalReturnsTrueOrFalse())
    {
        
        data.intOne = 1;
        data.intTwo = 2;
    }
    else
    {
        
        data.intOne = 1;
        data.intTwo = 2;
    }
    if(globalReturnsTrueOrFalse())
    {
        
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
    }
    else
    {
        
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
    }
}

void CWE457_Use_of_Uninitialized_Variable__struct_12_good()
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
    CWE457_Use_of_Uninitialized_Variable__struct_12_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__struct_12_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
