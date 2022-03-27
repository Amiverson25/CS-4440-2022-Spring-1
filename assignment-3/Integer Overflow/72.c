


#include "std_testcase.h"

#ifndef OMITBAD

static int badSource(int data)
{
    
    data = INT_MAX;
    return data;
}

void CWE190_Integer_Overflow__int_max_preinc_42_bad()
{
    int data;
    
    data = 0;
    data = badSource(data);
    {
        
        ++data;
        int result = data;
        printIntLine(result);
    }
}

#endif 

#ifndef OMITGOOD


static int goodG2BSource(int data)
{
    
    data = 2;
    return data;
}

static void goodG2B()
{
    int data;
    
    data = 0;
    data = goodG2BSource(data);
    {
        
        ++data;
        int result = data;
        printIntLine(result);
    }
}


static int goodB2GSource(int data)
{
    
    data = INT_MAX;
    return data;
}

static void goodB2G()
{
    int data;
    
    data = 0;
    data = goodB2GSource(data);
    
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

void CWE190_Integer_Overflow__int_max_preinc_42_good()
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
    CWE190_Integer_Overflow__int_max_preinc_42_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_max_preinc_42_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
