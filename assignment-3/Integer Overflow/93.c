


#include "std_testcase.h"

#ifndef OMITBAD


static int badStatic = 0;

static void badSink(unsigned int data)
{
    if(badStatic)
    {
        {
            
            data++;
            unsigned int result = data;
            printUnsignedLine(result);
        }
    }
}

void CWE190_Integer_Overflow__unsigned_int_max_postinc_21_bad()
{
    unsigned int data;
    data = 0;
    
    data = UINT_MAX;
    badStatic = 1; 
    badSink(data);
}

#endif 

#ifndef OMITGOOD


static int goodB2G1Static = 0;
static int goodB2G2Static = 0;
static int goodG2BStatic = 0;


static void goodB2G1Sink(unsigned int data)
{
    if(goodB2G1Static)
    {
        
        printLine("Benign, fixed string");
    }
    else
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
}

static void goodB2G1()
{
    unsigned int data;
    data = 0;
    
    data = UINT_MAX;
    goodB2G1Static = 0; 
    goodB2G1Sink(data);
}


static void goodB2G2Sink(unsigned int data)
{
    if(goodB2G2Static)
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
}

static void goodB2G2()
{
    unsigned int data;
    data = 0;
    
    data = UINT_MAX;
    goodB2G2Static = 1; 
    goodB2G2Sink(data);
}


static void goodG2BSink(unsigned int data)
{
    if(goodG2BStatic)
    {
        {
            
            data++;
            unsigned int result = data;
            printUnsignedLine(result);
        }
    }
}

static void goodG2B()
{
    unsigned int data;
    data = 0;
    
    data = 2;
    goodG2BStatic = 1; 
    goodG2BSink(data);
}

void CWE190_Integer_Overflow__unsigned_int_max_postinc_21_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B();
}

#endif 



#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE190_Integer_Overflow__unsigned_int_max_postinc_21_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__unsigned_int_max_postinc_21_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
