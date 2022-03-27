


#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__int_max_preinc_18_bad()
{
    int data;
    
    data = 0;
    goto source;
source:
    
    data = INT_MAX;
    goto sink;
sink:
    {
        
        ++data;
        int result = data;
        printIntLine(result);
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G()
{
    int data;
    
    data = 0;
    goto source;
source:
    
    data = INT_MAX;
    goto sink;
sink:
    
    if (data < INT_MAX)
    {
        ++data;
        int result = data;
        printIntLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}


static void goodG2B()
{
    int data;
    
    data = 0;
    goto source;
source:
    
    data = 2;
    goto sink;
sink:
    {
        
        ++data;
        int result = data;
        printIntLine(result);
    }
}

void CWE190_Integer_Overflow__int_max_preinc_18_good()
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
    CWE190_Integer_Overflow__int_max_preinc_18_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_max_preinc_18_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
