


#include "std_testcase.h"

#include <wchar.h>


static int staticTrue = 1; 
static int staticFalse = 0; 

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__char_pointer_05_bad()
{
    char * data;
    if(staticTrue)
    {
        
        ; 
    }
    if(staticTrue)
    {
        
        printLine(data);
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G1()
{
    char * data;
    if(staticTrue)
    {
        
        ; 
    }
    if(staticFalse)
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
    if(staticTrue)
    {
        
        ; 
    }
    if(staticTrue)
    {
        
        data = "string";
        printLine(data);
    }
}


static void goodG2B1()
{
    char * data;
    if(staticFalse)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = "string";
    }
    if(staticTrue)
    {
        
        printLine(data);
    }
}


static void goodG2B2()
{
    char * data;
    if(staticTrue)
    {
        
        data = "string";
    }
    if(staticTrue)
    {
        
        printLine(data);
    }
}

void CWE457_Use_of_Uninitialized_Variable__char_pointer_05_good()
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
    CWE457_Use_of_Uninitialized_Variable__char_pointer_05_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__char_pointer_05_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
