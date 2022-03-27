


#include "std_testcase.h"

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__struct_array_alloca_no_init_18_bad()
{
    twoIntsStruct * data;
    data = (twoIntsStruct *)ALLOCA(10*sizeof(twoIntsStruct));
    goto source;
source:
    
    ; 
    goto sink;
sink:
    
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i].intOne);
            printIntLine(data[i].intTwo);
        }
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G()
{
    twoIntsStruct * data;
    data = (twoIntsStruct *)ALLOCA(10*sizeof(twoIntsStruct));
    goto source;
source:
    
    ; 
    goto sink;
sink:
    
    {
        int i;
        for(i=0; i<10; i++)
        {
            data[i].intOne = i;
            data[i].intTwo = i;
        }
    }
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i].intOne);
            printIntLine(data[i].intTwo);
        }
    }
}


static void goodG2B()
{
    twoIntsStruct * data;
    data = (twoIntsStruct *)ALLOCA(10*sizeof(twoIntsStruct));
    goto source;
source:
    
    {
        int i;
        for(i=0; i<10; i++)
        {
            data[i].intOne = i;
            data[i].intTwo = i;
        }
    }
    goto sink;
sink:
    
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i].intOne);
            printIntLine(data[i].intTwo);
        }
    }
}

void CWE457_Use_of_Uninitialized_Variable__struct_array_alloca_no_init_18_good()
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
    CWE457_Use_of_Uninitialized_Variable__struct_array_alloca_no_init_18_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__struct_array_alloca_no_init_18_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
