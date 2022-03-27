


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE416_Use_After_Free__malloc_free_char_17_bad()
{
    int i,j;
    char * data;
    
    data = NULL;
    for(i = 0; i < 1; i++)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        
        free(data);
    }
    for(j = 0; j < 1; j++)
    {
        
        printLine(data);
        
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G()
{
    int i,k;
    char * data;
    
    data = NULL;
    for(i = 0; i < 1; i++)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        
        free(data);
    }
    for(k = 0; k < 1; k++)
    {
        
        
        
        ; 
    }
}


static void goodG2B()
{
    int h,j;
    char * data;
    
    data = NULL;
    for(h = 0; h < 1; h++)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        
    }
    for(j = 0; j < 1; j++)
    {
        
        printLine(data);
        
    }
}

void CWE416_Use_After_Free__malloc_free_char_17_good()
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
    CWE416_Use_After_Free__malloc_free_char_17_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_char_17_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
