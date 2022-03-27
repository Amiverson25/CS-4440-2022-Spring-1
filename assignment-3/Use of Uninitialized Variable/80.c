


#include "std_testcase.h"


static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__struct_array_malloc_no_init_08_bad()
{
    twoIntsStruct * data;
    data = (twoIntsStruct *)malloc(10*sizeof(twoIntsStruct));
    if (data == NULL) {exit(-1);}
    if(staticReturnsTrue())
    {
        
        ; 
    }
    if(staticReturnsTrue())
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
    data = (twoIntsStruct *)malloc(10*sizeof(twoIntsStruct));
    if (data == NULL) {exit(-1);}
    if(staticReturnsTrue())
    {
        
        ; 
    }
    if(staticReturnsFalse())
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
    data = (twoIntsStruct *)malloc(10*sizeof(twoIntsStruct));
    if (data == NULL) {exit(-1);}
    if(staticReturnsTrue())
    {
        
        ; 
    }
    if(staticReturnsTrue())
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
    data = (twoIntsStruct *)malloc(10*sizeof(twoIntsStruct));
    if (data == NULL) {exit(-1);}
    if(staticReturnsFalse())
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
    if(staticReturnsTrue())
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
    data = (twoIntsStruct *)malloc(10*sizeof(twoIntsStruct));
    if (data == NULL) {exit(-1);}
    if(staticReturnsTrue())
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
    if(staticReturnsTrue())
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

void CWE457_Use_of_Uninitialized_Variable__struct_array_malloc_no_init_08_good()
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
    CWE457_Use_of_Uninitialized_Variable__struct_array_malloc_no_init_08_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__struct_array_malloc_no_init_08_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
