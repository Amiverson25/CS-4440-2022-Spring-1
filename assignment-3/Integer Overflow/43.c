


#include "std_testcase.h"

#ifndef OMITBAD

static void badSink(int data)
{
    {
        
        int result = data + 1;
        printIntLine(result);
    }
}

void CWE190_Integer_Overflow__int_max_add_44_bad()
{
    int data;
    
    void (*funcPtr) (int) = badSink;
    
    data = 0;
    
    data = INT_MAX;
    
    funcPtr(data);
}

#endif 

#ifndef OMITGOOD


static void goodG2BSink(int data)
{
    {
        
        int result = data + 1;
        printIntLine(result);
    }
}

static void goodG2B()
{
    int data;
    void (*funcPtr) (int) = goodG2BSink;
    
    data = 0;
    
    data = 2;
    funcPtr(data);
}


static void goodB2GSink(int data)
{
    
    if (data < INT_MAX)
    {
        int result = data + 1;
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
    void (*funcPtr) (int) = goodB2GSink;
    
    data = 0;
    
    data = INT_MAX;
    funcPtr(data);
}

void CWE190_Integer_Overflow__int_max_add_44_good()
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
    CWE190_Integer_Overflow__int_max_add_44_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_max_add_44_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
