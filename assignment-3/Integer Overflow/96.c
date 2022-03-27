


#include "std_testcase.h"

typedef union
{
    unsigned int unionFirst;
    unsigned int unionSecond;
} CWE190_Integer_Overflow__unsigned_int_max_postinc_34_unionType;

#ifndef OMITBAD

void CWE190_Integer_Overflow__unsigned_int_max_postinc_34_bad()
{
    unsigned int data;
    CWE190_Integer_Overflow__unsigned_int_max_postinc_34_unionType myUnion;
    data = 0;
    
    data = UINT_MAX;
    myUnion.unionFirst = data;
    {
        unsigned int data = myUnion.unionSecond;
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
    CWE190_Integer_Overflow__unsigned_int_max_postinc_34_unionType myUnion;
    data = 0;
    
    data = 2;
    myUnion.unionFirst = data;
    {
        unsigned int data = myUnion.unionSecond;
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
    CWE190_Integer_Overflow__unsigned_int_max_postinc_34_unionType myUnion;
    data = 0;
    
    data = UINT_MAX;
    myUnion.unionFirst = data;
    {
        unsigned int data = myUnion.unionSecond;
        
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

void CWE190_Integer_Overflow__unsigned_int_max_postinc_34_good()
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
    CWE190_Integer_Overflow__unsigned_int_max_postinc_34_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__unsigned_int_max_postinc_34_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
