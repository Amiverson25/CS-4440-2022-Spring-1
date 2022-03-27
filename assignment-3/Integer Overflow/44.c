


#include "std_testcase.h"

static int CWE190_Integer_Overflow__int_max_add_45_badData;
static int CWE190_Integer_Overflow__int_max_add_45_goodG2BData;
static int CWE190_Integer_Overflow__int_max_add_45_goodB2GData;

#ifndef OMITBAD

static void badSink()
{
    int data = CWE190_Integer_Overflow__int_max_add_45_badData;
    {
        
        int result = data + 1;
        printIntLine(result);
    }
}

void CWE190_Integer_Overflow__int_max_add_45_bad()
{
    int data;
    
    data = 0;
    
    data = INT_MAX;
    CWE190_Integer_Overflow__int_max_add_45_badData = data;
    badSink();
}

#endif 

#ifndef OMITGOOD


static void goodG2BSink()
{
    int data = CWE190_Integer_Overflow__int_max_add_45_goodG2BData;
    {
        
        int result = data + 1;
        printIntLine(result);
    }
}

static void goodG2B()
{
    int data;
    
    data = 0;
    
    data = 2;
    CWE190_Integer_Overflow__int_max_add_45_goodG2BData = data;
    goodG2BSink();
}


static void goodB2GSink()
{
    int data = CWE190_Integer_Overflow__int_max_add_45_goodB2GData;
    
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
    
    data = 0;
    
    data = INT_MAX;
    CWE190_Integer_Overflow__int_max_add_45_goodB2GData = data;
    goodB2GSink();
}

void CWE190_Integer_Overflow__int_max_add_45_good()
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
    CWE190_Integer_Overflow__int_max_add_45_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_max_add_45_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
