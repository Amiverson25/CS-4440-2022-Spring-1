


#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__unsigned_int_max_postinc_18_bad()
{
    unsigned int data;
    data = 0;
    goto source;
source:
    
    data = UINT_MAX;
    goto sink;
sink:
    {
        
        data++;
        unsigned int result = data;
        printUnsignedLine(result);
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G()
{
    unsigned int data;
    data = 0;
    goto source;
source:
    
    data = UINT_MAX;
    goto sink;
sink:
    
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


static void goodG2B()
{
    unsigned int data;
    data = 0;
    goto source;
source:
    
    data = 2;
    goto sink;
sink:
    {
        
        data++;
        unsigned int result = data;
        printUnsignedLine(result);
    }
}

void CWE190_Integer_Overflow__unsigned_int_max_postinc_18_good()
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
    CWE190_Integer_Overflow__unsigned_int_max_postinc_18_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__unsigned_int_max_postinc_18_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
