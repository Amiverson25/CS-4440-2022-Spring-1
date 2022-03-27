


#include "std_testcase.h"

static char * helperBad(char * aString)
{
    size_t i = 0;
    size_t j;
    char * reversedString = NULL;
    if (aString != NULL)
    {
        i = strlen(aString);
        reversedString = (char *) malloc(i+1);
        if (reversedString == NULL) {exit(-1);}
        for (j = 0; j < i; j++)
        {
            reversedString[j] = aString[i-j-1];
        }
        reversedString[i] = '\0';
        
        free(reversedString);
        return reversedString;
    }
    else
    {
        return NULL;
    }
}

static char * helperGood(char * aString)
{
    size_t i = 0;
    size_t j;
    char * reversedString = NULL;
    if (aString != NULL)
    {
        i = strlen(aString);
        reversedString = (char *) malloc(i+1);
        if (reversedString == NULL) {exit(-1);}
        for (j = 0; j < i; j++)
        {
            reversedString[j] = aString[i-j-1];
        }
        reversedString[i] = '\0';
        
        return reversedString;
    }
    else
    {
        return NULL;
    }
}

#ifndef OMITBAD

void CWE416_Use_After_Free__return_freed_ptr_02_bad()
{
    if(1)
    {
        {
            
            char * reversedString = helperBad("BadSink");
            printLine(reversedString);
            
        }
    }
}

#endif 

#ifndef OMITGOOD


static void good1()
{
    if(0)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        {
            
            char * reversedString = helperGood("GoodSink");
            printLine(reversedString);
            
        }
    }
}


static void good2()
{
    if(1)
    {
        {
            
            char * reversedString = helperGood("GoodSink");
            printLine(reversedString);
            
        }
    }
}

void CWE416_Use_After_Free__return_freed_ptr_02_good()
{
    good1();
    good2();
}

#endif 



#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE416_Use_After_Free__return_freed_ptr_02_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__return_freed_ptr_02_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
