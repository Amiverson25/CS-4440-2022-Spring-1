


#include "std_testcase.h"

#ifndef OMITBAD

static void badSink(int data)
{
    {
        
        ++data;
        int result = data;
        printIntLine(result);
    }
}

void CWE190_Integer_Overflow__int_max_preinc_41_bad()
{
    int data;
    
    data = 0;
    
    data = INT_MAX;
    badSink(data);
}

#endif 

#ifndef OMITGOOD


static void goodG2BSink(int data)
{
    {
        
        ++data;
        int result = data;
        printIntLine(result);
    }
}

static void goodG2B()
{
    int data;
    
    data = 0;
    
    data = 2;
    goodG2BSink(data);
}


static void goodB2GSink(int data)
{
    
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

static void goodB2G()
{
    int data;
    
    data = 0;
    
    data = INT_MAX;
    goodB2GSink(data);
}

void CWE190_Integer_Overflow__int_max_preinc_41_good()
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
    CWE190_Integer_Overflow__int_max_preinc_41_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_max_preinc_41_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
