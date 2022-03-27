


#include "std_testcase.h"

#include <wchar.h>


static int staticFive = 5;

#ifndef OMITBAD

void CWE416_Use_After_Free__malloc_free_char_07_bad()
{
    char * data;
    
    data = NULL;
    if(staticFive==5)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        
        free(data);
    }
    if(staticFive==5)
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
    if(staticFive==5)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        
        free(data);
    }
    if(staticFive!=5)
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
    if(staticFive==5)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        
        free(data);
    }
    if(staticFive==5)
    {
        
        
        
        ; 
    }
}


static void goodG2B1()
{
    char * data;
    
    data = NULL;
    if(staticFive!=5)
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
    if(staticFive==5)
    {
        
        printLine(data);
        
    }
}


static void goodG2B2()
{
    char * data;
    
    data = NULL;
    if(staticFive==5)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        
    }
    if(staticFive==5)
    {
        
        printLine(data);
        
    }
}

void CWE416_Use_After_Free__malloc_free_char_07_good()
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
    CWE416_Use_After_Free__malloc_free_char_07_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_char_07_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
