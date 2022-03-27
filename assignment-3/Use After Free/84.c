


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE416_Use_After_Free__malloc_free_struct_12_bad()
{
    twoIntsStruct * data;
    
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
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
    }
    else
    {
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
        
    }
    if(globalReturnsTrueOrFalse())
    {
        
        printStructLine(&data[0]);
        
    }
    else
    {
        
        
        
        ; 
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G()
{
    twoIntsStruct * data;
    
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
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
    }
    else
    {
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
    }
    if(globalReturnsTrueOrFalse())
    {
        
        
        
        ; 
    }
    else
    {
        
        
        
        ; 
    }
}


static void goodG2B()
{
    twoIntsStruct * data;
    
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
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
        
    }
    else
    {
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
        
    }
    if(globalReturnsTrueOrFalse())
    {
        
        printStructLine(&data[0]);
        
    }
    else
    {
        
        printStructLine(&data[0]);
        
    }
}

void CWE416_Use_After_Free__malloc_free_struct_12_good()
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
    CWE416_Use_After_Free__malloc_free_struct_12_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_struct_12_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
