


#include "std_testcase.h"

#ifndef OMITBAD


static int badStatic = 0;

static void badSink(int data)
{
    if(badStatic)
    {
        {
            
            ++data;
            int result = data;
            printIntLine(result);
        }
    }
}

void CWE190_Integer_Overflow__int_max_preinc_21_bad()
{
    int data;
    
    data = 0;
    
    data = INT_MAX;
    badStatic = 1; 
    badSink(data);
}

#endif 

#ifndef OMITGOOD


static int goodB2G1Static = 0;
static int goodB2G2Static = 0;
static int goodG2BStatic = 0;


static void goodB2G1Sink(int data)
{
    if(goodB2G1Static)
    {
        
        printLine("Benign, fixed string");
    }
    else
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
}

static void goodB2G1()
{
    int data;
    
    data = 0;
    
    data = INT_MAX;
    goodB2G1Static = 0; 
    goodB2G1Sink(data);
}


static void goodB2G2Sink(int data)
{
    if(goodB2G2Static)
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
}

static void goodB2G2()
{
    int data;
    
    data = 0;
    
    data = INT_MAX;
    goodB2G2Static = 1; 
    goodB2G2Sink(data);
}


static void goodG2BSink(int data)
{
    if(goodG2BStatic)
    {
        {
            
            ++data;
            int result = data;
            printIntLine(result);
        }
    }
}

static void goodG2B()
{
    int data;
    
    data = 0;
    
    data = 2;
    goodG2BStatic = 1; 
    goodG2BSink(data);
}

void CWE190_Integer_Overflow__int_max_preinc_21_good()
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
    CWE190_Integer_Overflow__int_max_preinc_21_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_max_preinc_21_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
