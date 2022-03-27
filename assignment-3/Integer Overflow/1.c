


#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__int64_t_max_preinc_01_bad()
{
    int64_t data;
    data = 0LL;
    
    data = LLONG_MAX;
    {
        
        ++data;
        int64_t result = data;
        printLongLongLine(result);
    }
}

#endif 

#ifndef OMITGOOD


static void goodG2B()
{
    int64_t data;
    data = 0LL;
    
    data = 2;
    {
        
        ++data;
        int64_t result = data;
        printLongLongLine(result);
    }
}


static void goodB2G()
{
    int64_t data;
    data = 0LL;
    
    data = LLONG_MAX;
    
    if (data < LLONG_MAX)
    {
        ++data;
        int64_t result = data;
        printLongLongLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}

void CWE190_Integer_Overflow__int64_t_max_preinc_01_good()
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
    CWE190_Integer_Overflow__int64_t_max_preinc_01_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int64_t_max_preinc_01_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
