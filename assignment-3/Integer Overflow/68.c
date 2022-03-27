


#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__int_max_preinc_31_bad()
{
    int data;
    
    data = 0;
    
    data = INT_MAX;
    {
        int dataCopy = data;
        int data = dataCopy;
        {
            
            ++data;
            int result = data;
            printIntLine(result);
        }
    }
}

#endif 

#ifndef OMITGOOD


static void goodG2B()
{
    int data;
    
    data = 0;
    
    data = 2;
    {
        int dataCopy = data;
        int data = dataCopy;
        {
            
            ++data;
            int result = data;
            printIntLine(result);
        }
    }
}


static void goodB2G()
{
    int data;
    
    data = 0;
    
    data = INT_MAX;
    {
        int dataCopy = data;
        int data = dataCopy;
        
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
}

void CWE190_Integer_Overflow__int_max_preinc_31_good()
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
    CWE190_Integer_Overflow__int_max_preinc_31_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_max_preinc_31_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
