


#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__int_max_add_16_bad()
{
    int data;
    
    data = 0;
    while(1)
    {
        
        data = INT_MAX;
        break;
    }
    while(1)
    {
        {
            
            int result = data + 1;
            printIntLine(result);
        }
        break;
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G()
{
    int data;
    
    data = 0;
    while(1)
    {
        
        data = INT_MAX;
        break;
    }
    while(1)
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
        break;
    }
}


static void goodG2B()
{
    int data;
    
    data = 0;
    while(1)
    {
        
        data = 2;
        break;
    }
    while(1)
    {
        {
            
            int result = data + 1;
            printIntLine(result);
        }
        break;
    }
}

void CWE190_Integer_Overflow__int_max_add_16_good()
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
    CWE190_Integer_Overflow__int_max_add_16_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_max_add_16_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
