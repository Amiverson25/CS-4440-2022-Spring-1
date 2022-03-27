


#include "std_testcase.h"

static unsigned int CWE190_Integer_Overflow__unsigned_int_max_postinc_45_badData;
static unsigned int CWE190_Integer_Overflow__unsigned_int_max_postinc_45_goodG2BData;
static unsigned int CWE190_Integer_Overflow__unsigned_int_max_postinc_45_goodB2GData;

#ifndef OMITBAD

static void badSink()
{
    unsigned int data = CWE190_Integer_Overflow__unsigned_int_max_postinc_45_badData;
    {
        
        data++;
        unsigned int result = data;
        printUnsignedLine(result);
    }
}

void CWE190_Integer_Overflow__unsigned_int_max_postinc_45_bad()
{
    unsigned int data;
    data = 0;
    
    data = UINT_MAX;
    CWE190_Integer_Overflow__unsigned_int_max_postinc_45_badData = data;
    badSink();
}

#endif 

#ifndef OMITGOOD


static void goodG2BSink()
{
    unsigned int data = CWE190_Integer_Overflow__unsigned_int_max_postinc_45_goodG2BData;
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
    CWE190_Integer_Overflow__unsigned_int_max_postinc_45_goodG2BData = data;
    goodG2BSink();
}


static void goodB2GSink()
{
    unsigned int data = CWE190_Integer_Overflow__unsigned_int_max_postinc_45_goodB2GData;
    
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
    CWE190_Integer_Overflow__unsigned_int_max_postinc_45_goodB2GData = data;
    goodB2GSink();
}

void CWE190_Integer_Overflow__unsigned_int_max_postinc_45_good()
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
    CWE190_Integer_Overflow__unsigned_int_max_postinc_45_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__unsigned_int_max_postinc_45_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
