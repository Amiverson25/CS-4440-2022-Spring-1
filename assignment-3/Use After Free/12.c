


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE416_Use_After_Free__malloc_free_char_12_bad()
{
    char * data;
    
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        
        free(data);
    }
    else
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        
    }
    if(globalReturnsTrueOrFalse())
    {
        
        printLine(data);
        
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
    char * data;
    
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        
        free(data);
    }
    else
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        
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
    char * data;
    
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        
    }
    else
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        
    }
    if(globalReturnsTrueOrFalse())
    {
        
        printLine(data);
        
    }
    else
    {
        
        printLine(data);
        
    }
}

void CWE416_Use_After_Free__malloc_free_char_12_good()
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
    CWE416_Use_After_Free__malloc_free_char_12_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_char_12_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
