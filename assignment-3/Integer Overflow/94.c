


#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__unsigned_int_max_postinc_31_bad()
{
    unsigned int data;
    data = 0;
    
    data = UINT_MAX;
    {
        unsigned int dataCopy = data;
        unsigned int data = dataCopy;
        {
            
            data++;
            unsigned int result = data;
            printUnsignedLine(result);
        }
    }
}

#endif 

#ifndef OMITGOOD


static void goodG2B()
{
    unsigned int data;
    data = 0;
    
    data = 2;
    {
        unsigned int dataCopy = data;
        unsigned int data = dataCopy;
        {
            
            data++;
            unsigned int result = data;
            printUnsignedLine(result);
        }
    }
}


static void goodB2G()
{
    unsigned int data;
    data = 0;
    
    data = UINT_MAX;
    {
        unsigned int dataCopy = data;
        unsigned int data = dataCopy;
        
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

void CWE190_Integer_Overflow__unsigned_int_max_postinc_31_good()
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
    CWE190_Integer_Overflow__unsigned_int_max_postinc_31_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__unsigned_int_max_postinc_31_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
