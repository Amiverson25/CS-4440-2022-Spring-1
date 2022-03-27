


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE416_Use_After_Free__malloc_free_char_18_bad()
{
    char * data;
    
    data = NULL;
    goto source;
source:
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    
    free(data);
    goto sink;
sink:
    
    printLine(data);
    
}

#endif 

#ifndef OMITGOOD


static void goodB2G()
{
    char * data;
    
    data = NULL;
    goto source;
source:
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    
    free(data);
    goto sink;
sink:
    
    
    
    ; 
}


static void goodG2B()
{
    char * data;
    
    data = NULL;
    goto source;
source:
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    
    goto sink;
sink:
    
    printLine(data);
    
}

void CWE416_Use_After_Free__malloc_free_char_18_good()
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
    CWE416_Use_After_Free__malloc_free_char_18_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_char_18_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
