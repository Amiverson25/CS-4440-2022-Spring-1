


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE416_Use_After_Free__malloc_free_struct_01_bad()
{
    twoIntsStruct * data;
    
    data = NULL;
    data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
    if (data == NULL) {exit(-1);}
    {
        size_t i;
        for(i = 0; i < 100; i++)
        {
            data[i].intOne = 1;
            data[i].intTwo = 2;
        }
    }
    
    free(data);
    
    printStructLine(&data[0]);
    
}

#endif 

#ifndef OMITGOOD


static void goodG2B()
{
    twoIntsStruct * data;
    
    data = NULL;
    data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
    if (data == NULL) {exit(-1);}
    {
        size_t i;
        for(i = 0; i < 100; i++)
        {
            data[i].intOne = 1;
            data[i].intTwo = 2;
        }
    }
    
    
    printStructLine(&data[0]);
    
}


static void goodB2G()
{
    twoIntsStruct * data;
    
    data = NULL;
    data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
    if (data == NULL) {exit(-1);}
    {
        size_t i;
        for(i = 0; i < 100; i++)
        {
            data[i].intOne = 1;
            data[i].intTwo = 2;
        }
    }
    
    free(data);
    
    
    
    ; 
}

void CWE416_Use_After_Free__malloc_free_struct_01_good()
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
    CWE416_Use_After_Free__malloc_free_struct_01_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_struct_01_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
