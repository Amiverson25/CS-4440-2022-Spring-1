


#include "std_testcase.h"

#include <wchar.h>


static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}

#ifndef OMITBAD

void CWE416_Use_After_Free__malloc_free_char_08_bad()
{
    char * data;
    
    data = NULL;
    if(staticReturnsTrue())
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        
        free(data);
    }
    if(staticReturnsTrue())
    {
        
        printLine(data);
        
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G1()
{
    char * data;
    
    data = NULL;
    if(staticReturnsTrue())
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        
        free(data);
    }
    if(staticReturnsFalse())
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
    char * data;
    
    data = NULL;
    if(staticReturnsTrue())
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        
        free(data);
    }
    if(staticReturnsTrue())
    {
        
        
        
        ; 
    }
}


static void goodG2B1()
{
    char * data;
    
    data = NULL;
    if(staticReturnsFalse())
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        
    }
    if(staticReturnsTrue())
    {
        
        printLine(data);
        
    }
}


static void goodG2B2()
{
    char * data;
    
    data = NULL;
    if(staticReturnsTrue())
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        
    }
    if(staticReturnsTrue())
    {
        
        printLine(data);
        
    }
}

void CWE416_Use_After_Free__malloc_free_char_08_good()
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
    CWE416_Use_After_Free__malloc_free_char_08_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_char_08_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
