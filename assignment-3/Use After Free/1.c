


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE416_Use_After_Free__malloc_free_char_01_bad()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    
    free(data);
    
    printLine(data);
    
}

#endif 

#ifndef OMITGOOD


static void goodG2B()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    
    
    printLine(data);
    
}


static void goodB2G()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    
    free(data);
    
    
    
    ; 
}

void CWE416_Use_After_Free__malloc_free_char_01_good()
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
    CWE416_Use_After_Free__malloc_free_char_01_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_char_01_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
