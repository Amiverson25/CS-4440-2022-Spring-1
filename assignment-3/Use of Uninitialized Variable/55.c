


#include "std_testcase.h"

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__struct_array_declare_no_init_01_bad()
{
    twoIntsStruct * data;
    twoIntsStruct dataUninitArray[10];
    data = dataUninitArray;
    
    ; 
    
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


static void goodG2B()
{
    twoIntsStruct * data;
    twoIntsStruct dataUninitArray[10];
    data = dataUninitArray;
    
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


static void goodB2G()
{
    twoIntsStruct * data;
    twoIntsStruct dataUninitArray[10];
    data = dataUninitArray;
    
    ; 
    
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

void CWE457_Use_of_Uninitialized_Variable__struct_array_declare_no_init_01_good()
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
    CWE457_Use_of_Uninitialized_Variable__struct_array_declare_no_init_01_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__struct_array_declare_no_init_01_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
