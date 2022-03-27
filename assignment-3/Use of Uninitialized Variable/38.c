


#include "std_testcase.h"

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__struct_array_alloca_no_init_02_bad()
{
    twoIntsStruct * data;
    data = (twoIntsStruct *)ALLOCA(10*sizeof(twoIntsStruct));
    if(1)
    {
        
        ; 
    }
    if(1)
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
    data = (twoIntsStruct *)ALLOCA(10*sizeof(twoIntsStruct));
    if(1)
    {
        
        ; 
    }
    if(0)
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
    data = (twoIntsStruct *)ALLOCA(10*sizeof(twoIntsStruct));
    if(1)
    {
        
        ; 
    }
    if(1)
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
    data = (twoIntsStruct *)ALLOCA(10*sizeof(twoIntsStruct));
    if(0)
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
    if(1)
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
    data = (twoIntsStruct *)ALLOCA(10*sizeof(twoIntsStruct));
    if(1)
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
    if(1)
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

void CWE457_Use_of_Uninitialized_Variable__struct_array_alloca_no_init_02_good()
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
    CWE457_Use_of_Uninitialized_Variable__struct_array_alloca_no_init_02_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__struct_array_alloca_no_init_02_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
