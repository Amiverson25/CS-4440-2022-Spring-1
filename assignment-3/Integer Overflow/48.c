


#include "std_testcase.h"


static const int STATIC_CONST_TRUE = 1; 
static const int STATIC_CONST_FALSE = 0; 

#ifndef OMITBAD

void CWE190_Integer_Overflow__int_max_multiply_04_bad()
{
    int data;
    
    data = 0;
    if(STATIC_CONST_TRUE)
    {
        
        data = INT_MAX;
    }
    if(STATIC_CONST_TRUE)
    {
        if(data > 0) 
        {
            
            int result = data * 2;
            printIntLine(result);
        }
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G1()
{
    int data;
    
    data = 0;
    if(STATIC_CONST_TRUE)
    {
        
        data = INT_MAX;
    }
    if(STATIC_CONST_FALSE)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        if(data > 0) 
        {
            
            if (data < (INT_MAX/2))
            {
                int result = data * 2;
                printIntLine(result);
            }
            else
            {
                printLine("data value is too large to perform arithmetic safely.");
            }
        }
    }
}


static void goodB2G2()
{
    int data;
    
    data = 0;
    if(STATIC_CONST_TRUE)
    {
        
        data = INT_MAX;
    }
    if(STATIC_CONST_TRUE)
    {
        if(data > 0) 
        {
            
            if (data < (INT_MAX/2))
            {
                int result = data * 2;
                printIntLine(result);
            }
            else
            {
                printLine("data value is too large to perform arithmetic safely.");
            }
        }
    }
}


static void goodG2B1()
{
    int data;
    
    data = 0;
    if(STATIC_CONST_FALSE)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = 2;
    }
    if(STATIC_CONST_TRUE)
    {
        if(data > 0) 
        {
            
            int result = data * 2;
            printIntLine(result);
        }
    }
}


static void goodG2B2()
{
    int data;
    
    data = 0;
    if(STATIC_CONST_TRUE)
    {
        
        data = 2;
    }
    if(STATIC_CONST_TRUE)
    {
        if(data > 0) 
        {
            
            int result = data * 2;
            printIntLine(result);
        }
    }
}

void CWE190_Integer_Overflow__int_max_multiply_04_good()
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
    CWE190_Integer_Overflow__int_max_multiply_04_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_max_multiply_04_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
