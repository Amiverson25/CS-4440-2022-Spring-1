


#include "std_testcase.h"

typedef union
{
    int unionFirst;
    int unionSecond;
} CWE190_Integer_Overflow__int_max_preinc_34_unionType;

#ifndef OMITBAD

void CWE190_Integer_Overflow__int_max_preinc_34_bad()
{
    int data;
    CWE190_Integer_Overflow__int_max_preinc_34_unionType myUnion;
    
    data = 0;
    
    data = INT_MAX;
    myUnion.unionFirst = data;
    {
        int data = myUnion.unionSecond;
        {
            
            ++data;
            int result = data;
            printIntLine(result);
        }
    }
}

#endif 

#ifndef OMITGOOD


static void goodG2B()
{
    int data;
    CWE190_Integer_Overflow__int_max_preinc_34_unionType myUnion;
    
    data = 0;
    
    data = 2;
    myUnion.unionFirst = data;
    {
        int data = myUnion.unionSecond;
        {
            
            ++data;
            int result = data;
            printIntLine(result);
        }
    }
}


static void goodB2G()
{
    int data;
    CWE190_Integer_Overflow__int_max_preinc_34_unionType myUnion;
    
    data = 0;
    
    data = INT_MAX;
    myUnion.unionFirst = data;
    {
        int data = myUnion.unionSecond;
        
        if (data < INT_MAX)
        {
            ++data;
            int result = data;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}

void CWE190_Integer_Overflow__int_max_preinc_34_good()
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
    CWE190_Integer_Overflow__int_max_preinc_34_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_max_preinc_34_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
