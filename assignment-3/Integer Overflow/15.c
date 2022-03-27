


#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__int64_t_max_preinc_15_bad()
{
    int64_t data;
    data = 0LL;
    switch(6)
    {
    case 6:
        
        data = LLONG_MAX;
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    switch(7)
    {
    case 7:
    {
        
        ++data;
        int64_t result = data;
        printLongLongLine(result);
    }
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
    int64_t data;
    data = 0LL;
    switch(6)
    {
    case 6:
        
        data = LLONG_MAX;
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
        break;
    }
}


static void goodB2G2()
{
    int64_t data;
    data = 0LL;
    switch(6)
    {
    case 6:
        
        data = LLONG_MAX;
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    switch(7)
    {
    case 7:
        
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
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}


static void goodG2B1()
{
    int64_t data;
    data = 0LL;
    switch(5)
    {
    case 6:
        
        printLine("Benign, fixed string");
        break;
    default:
        
        data = 2;
        break;
    }
    switch(7)
    {
    case 7:
    {
        
        ++data;
        int64_t result = data;
        printLongLongLine(result);
    }
    break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}


static void goodG2B2()
{
    int64_t data;
    data = 0LL;
    switch(6)
    {
    case 6:
        
        data = 2;
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    switch(7)
    {
    case 7:
    {
        
        ++data;
        int64_t result = data;
        printLongLongLine(result);
    }
    break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}

void CWE190_Integer_Overflow__int64_t_max_preinc_15_good()
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
    CWE190_Integer_Overflow__int64_t_max_preinc_15_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int64_t_max_preinc_15_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
