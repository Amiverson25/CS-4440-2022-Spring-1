


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__struct_15_bad()
{
    twoIntsStruct data;
    switch(6)
    {
    case 6:
        
        ; 
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    switch(7)
    {
    case 7:
        
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G1()
{
    twoIntsStruct data;
    switch(6)
    {
    case 6:
        
        ; 
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    switch(8)
    {
    case 7:
        
        printLine("Benign, fixed string");
        break;
    default:
        
        data.intOne = 1;
        data.intTwo = 2;
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
        break;
    }
}


static void goodB2G2()
{
    twoIntsStruct data;
    switch(6)
    {
    case 6:
        
        ; 
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    switch(7)
    {
    case 7:
        
        data.intOne = 1;
        data.intTwo = 2;
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}


static void goodG2B1()
{
    twoIntsStruct data;
    switch(5)
    {
    case 6:
        
        printLine("Benign, fixed string");
        break;
    default:
        
        data.intOne = 1;
        data.intTwo = 2;
        break;
    }
    switch(7)
    {
    case 7:
        
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}


static void goodG2B2()
{
    twoIntsStruct data;
    switch(6)
    {
    case 6:
        
        data.intOne = 1;
        data.intTwo = 2;
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    switch(7)
    {
    case 7:
        
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}

void CWE457_Use_of_Uninitialized_Variable__struct_15_good()
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
    CWE457_Use_of_Uninitialized_Variable__struct_15_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__struct_15_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
