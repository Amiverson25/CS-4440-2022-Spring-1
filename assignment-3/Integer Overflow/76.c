


#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__unsigned_int_max_postinc_02_bad()
{
    unsigned int data;
    data = 0;
    if(1)
    {
        
        data = UINT_MAX;
    }
    if(1)
    {
        {
            
            data++;
            unsigned int result = data;
            printUnsignedLine(result);
        }
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G1()
{
    unsigned int data;
    data = 0;
    if(1)
    {
        
        data = UINT_MAX;
    }
    if(0)
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


static void goodB2G2()
{
    unsigned int data;
    data = 0;
    if(1)
    {
        
        data = UINT_MAX;
    }
    if(1)
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


static void goodG2B1()
{
    unsigned int data;
    data = 0;
    if(0)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = 2;
    }
    if(1)
    {
        {
            
            data++;
            unsigned int result = data;
            printUnsignedLine(result);
        }
    }
}


static void goodG2B2()
{
    unsigned int data;
    data = 0;
    if(1)
    {
        
        data = 2;
    }
    if(1)
    {
        {
            
            data++;
            unsigned int result = data;
            printUnsignedLine(result);
        }
    }
}

void CWE190_Integer_Overflow__unsigned_int_max_postinc_02_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}

#endif 



#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE190_Integer_Overflow__unsigned_int_max_postinc_02_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__unsigned_int_max_postinc_02_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
