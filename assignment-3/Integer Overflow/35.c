


#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__int_max_add_17_bad()
{
    int i,j;
    int data;
    
    data = 0;
    for(i = 0; i < 1; i++)
    {
        
        data = INT_MAX;
    }
    for(j = 0; j < 1; j++)
    {
        {
            
            int result = data + 1;
            printIntLine(result);
        }
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G()
{
    int i,k;
    int data;
    
    data = 0;
    for(i = 0; i < 1; i++)
    {
        
        data = INT_MAX;
    }
    for(k = 0; k < 1; k++)
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


static void goodG2B()
{
    int h,j;
    int data;
    
    data = 0;
    for(h = 0; h < 1; h++)
    {
        
        data = 2;
    }
    for(j = 0; j < 1; j++)
    {
        {
            
            int result = data + 1;
            printIntLine(result);
        }
    }
}

void CWE190_Integer_Overflow__int_max_add_17_good()
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
    CWE190_Integer_Overflow__int_max_add_17_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_max_add_17_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
