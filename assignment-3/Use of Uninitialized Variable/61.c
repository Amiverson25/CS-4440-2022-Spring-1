


#include "std_testcase.h"


static int staticFive = 5;

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__struct_array_declare_no_init_07_bad()
{
    twoIntsStruct * data;
    twoIntsStruct dataUninitArray[10];
    data = dataUninitArray;
    if(staticFive==5)
    {
        
        ; 
    }
    if(staticFive==5)
    {
        
        {
            int i;
            for(i=0; i<10; i++)
            {
                printIntLine(data[i].intOne);
                printIntLine(data[i].intTwo);
            }
        }
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G1()
{
    twoIntsStruct * data;
    twoIntsStruct dataUninitArray[10];
    data = dataUninitArray;
    if(staticFive==5)
    {
        
        ; 
    }
    if(staticFive!=5)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
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
}


static void goodB2G2()
{
    twoIntsStruct * data;
    twoIntsStruct dataUninitArray[10];
    data = dataUninitArray;
    if(staticFive==5)
    {
        
        ; 
    }
    if(staticFive==5)
    {
        
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
}


static void goodG2B1()
{
    twoIntsStruct * data;
    twoIntsStruct dataUninitArray[10];
    data = dataUninitArray;
    if(staticFive!=5)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        {
            int i;
            for(i=0; i<10; i++)
            {
                data[i].intOne = i;
                data[i].intTwo = i;
            }
        }
    }
    if(staticFive==5)
    {
        
        {
            int i;
            for(i=0; i<10; i++)
            {
                printIntLine(data[i].intOne);
                printIntLine(data[i].intTwo);
            }
        }
    }
}


static void goodG2B2()
{
    twoIntsStruct * data;
    twoIntsStruct dataUninitArray[10];
    data = dataUninitArray;
    if(staticFive==5)
    {
        
        {
            int i;
            for(i=0; i<10; i++)
            {
                data[i].intOne = i;
                data[i].intTwo = i;
            }
        }
    }
    if(staticFive==5)
    {
        
        {
            int i;
            for(i=0; i<10; i++)
            {
                printIntLine(data[i].intOne);
                printIntLine(data[i].intTwo);
            }
        }
    }
}

void CWE457_Use_of_Uninitialized_Variable__struct_array_declare_no_init_07_good()
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
    CWE457_Use_of_Uninitialized_Variable__struct_array_declare_no_init_07_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__struct_array_declare_no_init_07_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
