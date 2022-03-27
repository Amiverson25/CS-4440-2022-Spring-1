


#include "std_testcase.h"

#ifndef OMITBAD

static void badSink(unsigned int data)
{
    {
        
        data++;
        unsigned int result = data;
        printUnsignedLine(result);
    }
}

void CWE190_Integer_Overflow__unsigned_int_max_postinc_41_bad()
{
    unsigned int data;
    data = 0;
    
    data = UINT_MAX;
    badSink(data);
}

#endif 

#ifndef OMITGOOD


static void goodG2BSink(unsigned int data)
{
    {
        
        data++;
        unsigned int result = data;
        printUnsignedLine(result);
    }
}

static void goodG2B()
{
    unsigned int data;
    data = 0;
    
    data = 2;
    goodG2BSink(data);
}


static void goodB2GSink(unsigned int data)
{
    
    if (data < UINT_MAX)
    {
        data++;
        unsigned int result = data;
        printUnsignedLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}

static void goodB2G()
{
    unsigned int data;
    data = 0;
    
    data = UINT_MAX;
    goodB2GSink(data);
}

void CWE190_Integer_Overflow__unsigned_int_max_postinc_41_good()
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
    CWE190_Integer_Overflow__unsigned_int_max_postinc_41_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__unsigned_int_max_postinc_41_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
