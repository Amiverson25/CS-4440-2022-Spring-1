


#include "std_testcase.h"

#include <wchar.h>


static const int STATIC_CONST_TRUE = 1; 
static const int STATIC_CONST_FALSE = 0; 

#ifndef OMITBAD

void CWE416_Use_After_Free__malloc_free_struct_04_bad()
{
    twoIntsStruct * data;
    
    data = NULL;
    if(STATIC_CONST_TRUE)
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
    if(STATIC_CONST_TRUE)
    {
        
        printStructLine(&data[0]);
        
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G1()
{
    twoIntsStruct * data;
    
    data = NULL;
    if(STATIC_CONST_TRUE)
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
    if(STATIC_CONST_FALSE)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        
        
        ; 
    }
}


static void goodB2G2()
{
    twoIntsStruct * data;
    
    data = NULL;
    if(STATIC_CONST_TRUE)
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
    if(STATIC_CONST_TRUE)
    {
        
        
        
        ; 
    }
}


static void goodG2B1()
{
    twoIntsStruct * data;
    
    data = NULL;
    if(STATIC_CONST_FALSE)
    {
        
        printLine("Benign, fixed string");
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
    if(STATIC_CONST_TRUE)
    {
        
        printStructLine(&data[0]);
        
    }
}


static void goodG2B2()
{
    twoIntsStruct * data;
    
    data = NULL;
    if(STATIC_CONST_TRUE)
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
    if(STATIC_CONST_TRUE)
    {
        
        printStructLine(&data[0]);
        
    }
}

void CWE416_Use_After_Free__malloc_free_struct_04_good()
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
    CWE416_Use_After_Free__malloc_free_struct_04_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_struct_04_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
