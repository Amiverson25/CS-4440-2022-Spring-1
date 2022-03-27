


#include "std_testcase.h"

static int * CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_memmove_45_badData;
static int * CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_memmove_45_goodG2BData;

#ifndef OMITBAD

static void badSink()
{
    int * data = CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_memmove_45_badData;
    {
        int source[100] = {0}; 
        
        memmove(data, source, 100*sizeof(int));
        printIntLine(data[0]);
    }
}

void CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_memmove_45_bad()
{
    int * data;
    int * dataBadBuffer = (int *)ALLOCA(50*sizeof(int));
    int * dataGoodBuffer = (int *)ALLOCA(100*sizeof(int));
    
    data = dataBadBuffer;
    CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_memmove_45_badData = data;
    badSink();
}

#endif 

#ifndef OMITGOOD


static void goodG2BSink()
{
    int * data = CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_memmove_45_goodG2BData;
    {
        int source[100] = {0}; 
        
        memmove(data, source, 100*sizeof(int));
        printIntLine(data[0]);
    }
}

static void goodG2B()
{
    int * data;
    int * dataBadBuffer = (int *)ALLOCA(50*sizeof(int));
    int * dataGoodBuffer = (int *)ALLOCA(100*sizeof(int));
    
    data = dataGoodBuffer;
    CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_memmove_45_goodG2BData = data;
    goodG2BSink();
}

void CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_memmove_45_good()
{
    goodG2B();
}

#endif 


#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_memmove_45_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_memmove_45_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
