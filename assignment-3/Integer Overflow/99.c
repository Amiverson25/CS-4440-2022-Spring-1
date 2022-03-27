


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

void CWE190_Integer_Overflow__unsigned_int_max_postinc_44_bad()
{
    unsigned int data;
    
    void (*funcPtr) (unsigned int) = badSink;
    data = 0;
    
    data = UINT_MAX;
    
    funcPtr(data);
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
    void (*funcPtr) (unsigned int) = goodG2BSink;
    data = 0;
    
    data = 2;
    funcPtr(data);
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
    void (*funcPtr) (unsigned int) = goodB2GSink;
    data = 0;
    
    data = UINT_MAX;
    funcPtr(data);
}

void CWE190_Integer_Overflow__unsigned_int_max_postinc_44_good()
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
    CWE190_Integer_Overflow__unsigned_int_max_postinc_44_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__unsigned_int_max_postinc_44_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
