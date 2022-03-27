


#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__unsigned_int_max_postinc_12_bad()
{
    unsigned int data;
    data = 0;
    if(globalReturnsTrueOrFalse())
    {
        
        data = UINT_MAX;
    }
    else
    {
        
        data = 2;
    }
    if(globalReturnsTrueOrFalse())
    {
        {
            
            data++;
            unsigned int result = data;
            printUnsignedLine(result);
        }
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

#endif 

#ifndef OMITGOOD


static void goodB2G()
{
    unsigned int data;
    data = 0;
    if(globalReturnsTrueOrFalse())
    {
        
        data = UINT_MAX;
    }
    else
    {
        
        data = UINT_MAX;
    }
    if(globalReturnsTrueOrFalse())
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


static void goodG2B()
{
    unsigned int data;
    data = 0;
    if(globalReturnsTrueOrFalse())
    {
        
        data = 2;
    }
    else
    {
        
        data = 2;
    }
    if(globalReturnsTrueOrFalse())
    {
        {
            
            data++;
            unsigned int result = data;
            printUnsignedLine(result);
        }
    }
    else
    {
        {
            
            data++;
            unsigned int result = data;
            printUnsignedLine(result);
        }
    }
}

void CWE190_Integer_Overflow__unsigned_int_max_postinc_12_good()
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
    CWE190_Integer_Overflow__unsigned_int_max_postinc_12_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__unsigned_int_max_postinc_12_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
