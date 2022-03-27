


#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__unsigned_int_max_postinc_16_bad()
{
    unsigned int data;
    data = 0;
    while(1)
    {
        
        data = UINT_MAX;
        break;
    }
    while(1)
    {
        {
            
            data++;
            unsigned int result = data;
            printUnsignedLine(result);
        }
        break;
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G()
{
    unsigned int data;
    data = 0;
    while(1)
    {
        
        data = UINT_MAX;
        break;
    }
    while(1)
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
        break;
    }
}


static void goodG2B()
{
    unsigned int data;
    data = 0;
    while(1)
    {
        
        data = 2;
        break;
    }
    while(1)
    {
        {
            
            data++;
            unsigned int result = data;
            printUnsignedLine(result);
        }
        break;
    }
}

void CWE190_Integer_Overflow__unsigned_int_max_postinc_16_good()
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
    CWE190_Integer_Overflow__unsigned_int_max_postinc_16_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__unsigned_int_max_postinc_16_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
