


#include "std_testcase.h"

#include <wchar.h>


static int staticFive = 5;

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__struct_07_bad()
{
    twoIntsStruct data;
    if(staticFive==5)
    {
        
        ; 
    }
    if(staticFive==5)
    {
        
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G1()
{
    twoIntsStruct data;
    if(staticFive==5)
    {
        
        ; 
    }
    if(staticFive!=5)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data.intOne = 1;
        data.intTwo = 2;
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
    }
}


static void goodB2G2()
{
    twoIntsStruct data;
    if(staticFive==5)
    {
        
        ; 
    }
    if(staticFive==5)
    {
        
        data.intOne = 1;
        data.intTwo = 2;
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
    }
}


static void goodG2B1()
{
    twoIntsStruct data;
    if(staticFive!=5)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data.intOne = 1;
        data.intTwo = 2;
    }
    if(staticFive==5)
    {
        
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
    }
}


static void goodG2B2()
{
    twoIntsStruct data;
    if(staticFive==5)
    {
        
        data.intOne = 1;
        data.intTwo = 2;
    }
    if(staticFive==5)
    {
        
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
    }
}

void CWE457_Use_of_Uninitialized_Variable__struct_07_good()
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
    CWE457_Use_of_Uninitialized_Variable__struct_07_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__struct_07_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
