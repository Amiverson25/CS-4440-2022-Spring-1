


#include "std_testcase.h"


static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}

#ifndef OMITBAD

void CWE190_Integer_Overflow__int64_t_max_preinc_08_bad()
{
    int64_t data;
    data = 0LL;
    if(staticReturnsTrue())
    {
        
        data = LLONG_MAX;
    }
    if(staticReturnsTrue())
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
    if(staticReturnsTrue())
    {
        
        data = LLONG_MAX;
    }
    if(staticReturnsFalse())
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
    if(staticReturnsTrue())
    {
        
        data = LLONG_MAX;
    }
    if(staticReturnsTrue())
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
    if(staticReturnsFalse())
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = 2;
    }
    if(staticReturnsTrue())
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
    if(staticReturnsTrue())
    {
        
        data = 2;
    }
    if(staticReturnsTrue())
    {
        {
            
            ++data;
            int64_t result = data;
            printLongLongLine(result);
        }
    }
}

void CWE190_Integer_Overflow__int64_t_max_preinc_08_good()
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
    CWE190_Integer_Overflow__int64_t_max_preinc_08_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int64_t_max_preinc_08_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif