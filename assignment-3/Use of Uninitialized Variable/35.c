


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__struct_17_bad()
{
    int i,j;
    twoIntsStruct data;
    for(i = 0; i < 1; i++)
    {
        
        ; 
    }
    for(j = 0; j < 1; j++)
    {
        
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G()
{
    int i,k;
    twoIntsStruct data;
    for(i = 0; i < 1; i++)
    {
        
        ; 
    }
    for(k = 0; k < 1; k++)
    {
        
        data.intOne = 1;
        data.intTwo = 2;
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
    }
}


static void goodG2B()
{
    int h,j;
    twoIntsStruct data;
    for(h = 0; h < 1; h++)
    {
        
        data.intOne = 1;
        data.intTwo = 2;
    }
    for(j = 0; j < 1; j++)
    {
        
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
    }
}

void CWE457_Use_of_Uninitialized_Variable__struct_17_good()
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
    CWE457_Use_of_Uninitialized_Variable__struct_17_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__struct_17_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
