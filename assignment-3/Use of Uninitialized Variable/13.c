


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__char_pointer_13_bad()
{
    char * data;
    if(GLOBAL_CONST_FIVE==5)
    {
        
        ; 
    }
    if(GLOBAL_CONST_FIVE==5)
    {
        
        printLine(data);
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G1()
{
    char * data;
    if(GLOBAL_CONST_FIVE==5)
    {
        
        ; 
    }
    if(GLOBAL_CONST_FIVE!=5)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = "string";
        printLine(data);
    }
}


static void goodB2G2()
{
    char * data;
    if(GLOBAL_CONST_FIVE==5)
    {
        
        ; 
    }
    if(GLOBAL_CONST_FIVE==5)
    {
        
        data = "string";
        printLine(data);
    }
}


static void goodG2B1()
{
    char * data;
    if(GLOBAL_CONST_FIVE!=5)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = "string";
    }
    if(GLOBAL_CONST_FIVE==5)
    {
        
        printLine(data);
    }
}


static void goodG2B2()
{
    char * data;
    if(GLOBAL_CONST_FIVE==5)
    {
        
        data = "string";
    }
    if(GLOBAL_CONST_FIVE==5)
    {
        
        printLine(data);
    }
}

void CWE457_Use_of_Uninitialized_Variable__char_pointer_13_good()
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
    CWE457_Use_of_Uninitialized_Variable__char_pointer_13_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__char_pointer_13_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
