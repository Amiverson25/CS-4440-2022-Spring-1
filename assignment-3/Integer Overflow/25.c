


#include "std_testcase.h"


static int staticFive = 5;

#ifndef OMITBAD

void CWE190_Integer_Overflow__int_max_add_07_bad()
{
    int data;
    
    data = 0;
    if(staticFive==5)
    {
        
        data = INT_MAX;
    }
    if(staticFive==5)
    {
        {
            
            int result = data + 1;
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
    if(staticFive==5)
    {
        
        data = INT_MAX;
    }
    if(staticFive!=5)
    {
        
        printLine("Benign, fixed string");
    }
    else
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
}


static void goodB2G2()
{
    int data;
    
    data = 0;
    if(staticFive==5)
    {
        
        data = INT_MAX;
    }
    if(staticFive==5)
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
}


static void goodG2B1()
{
    int data;
    
    data = 0;
    if(staticFive!=5)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = 2;
    }
    if(staticFive==5)
    {
        {
            
            int result = data + 1;
            printIntLine(result);
        }
    }
}


static void goodG2B2()
{
    int data;
    
    data = 0;
    if(staticFive==5)
    {
        
        data = 2;
    }
    if(staticFive==5)
    {
        {
            
            int result = data + 1;
            printIntLine(result);
        }
    }
}

void CWE190_Integer_Overflow__int_max_add_07_good()
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
    CWE190_Integer_Overflow__int_max_add_07_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_max_add_07_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
