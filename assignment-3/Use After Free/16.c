


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE416_Use_After_Free__malloc_free_char_16_bad()
{
    char * data;
    
    data = NULL;
    while(1)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        
        free(data);
        break;
    }
    while(1)
    {
        
        printLine(data);
        
        break;
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G()
{
    char * data;
    
    data = NULL;
    while(1)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        
        free(data);
        break;
    }
    while(1)
    {
        
        
        
        ; 
        break;
    }
}


static void goodG2B()
{
    char * data;
    
    data = NULL;
    while(1)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        
        break;
    }
    while(1)
    {
        
        printLine(data);
        
        break;
    }
}

void CWE416_Use_After_Free__malloc_free_char_16_good()
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
    CWE416_Use_After_Free__malloc_free_char_16_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_char_16_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
