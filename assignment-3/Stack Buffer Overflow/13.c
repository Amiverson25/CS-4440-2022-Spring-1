


#include "std_testcase.h"

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_memmove_01_bad()
{
    twoIntsStruct * data;
    twoIntsStruct dataBadBuffer[50];
    twoIntsStruct dataGoodBuffer[100];
    
    data = dataBadBuffer;
    {
        twoIntsStruct source[100];
        {
            size_t i;
            
            for (i = 0; i < 100; i++)
            {
                source[i].intOne = 0;
                source[i].intTwo = 0;
            }
        }
        
        memmove(data, source, 100*sizeof(twoIntsStruct));
        printStructLine(&data[0]);
    }
}

#endif 

#ifndef OMITGOOD


static void goodG2B()
{
    twoIntsStruct * data;
    twoIntsStruct dataBadBuffer[50];
    twoIntsStruct dataGoodBuffer[100];
    
    data = dataGoodBuffer;
    {
        twoIntsStruct source[100];
        {
            size_t i;
            
            for (i = 0; i < 100; i++)
            {
                source[i].intOne = 0;
                source[i].intTwo = 0;
            }
        }
        
        memmove(data, source, 100*sizeof(twoIntsStruct));
        printStructLine(&data[0]);
    }
}

void CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_memmove_01_good()
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
    CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_memmove_01_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_memmove_01_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
