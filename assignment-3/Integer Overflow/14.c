


#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__int64_t_max_preinc_14_bad()
{
    int64_t data;
    data = 0LL;
    if(globalFive==5)
    {
        
        data = LLONG_MAX;
    }
    if(globalFive==5)
    {
        {
            
            ++data;
            int64_t result = data;
            printLongLongLine(result);
        }
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G1()
{
    int64_t data;
    data = 0LL;
    if(globalFive==5)
    {
        
        data = LLONG_MAX;
    }
    if(globalFive!=5)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
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
}


static void goodB2G2()
{
    int64_t data;
    data = 0LL;
    if(globalFive==5)
    {
        
        data = LLONG_MAX;
    }
    if(globalFive==5)
    {
        
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
}


static void goodG2B1()
{
    int64_t data;
    data = 0LL;
    if(globalFive!=5)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = 2;
    }
    if(globalFive==5)
    {
        {
            
            ++data;
            int64_t result = data;
            printLongLongLine(result);
        }
    }
}


static void goodG2B2()
{
    int64_t data;
    data = 0LL;
    if(globalFive==5)
    {
        
        data = 2;
    }
    if(globalFive==5)
    {
        {
            
            ++data;
            int64_t result = data;
            printLongLongLine(result);
        }
    }
}

void CWE190_Integer_Overflow__int64_t_max_preinc_14_good()
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
    CWE190_Integer_Overflow__int64_t_max_preinc_14_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int64_t_max_preinc_14_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
