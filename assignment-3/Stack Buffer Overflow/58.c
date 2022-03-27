


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_ncat_10_bad()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    if(globalTrue)
    {
        
        memset(data, 'A', 100-1); 
        data[100-1] = '\0'; 
    }
    {
        char dest[50] = "";
        
        strncat(dest, data, strlen(data));
        dest[50-1] = '\0'; 
        printLine(data);
    }
}

#endif 

#ifndef OMITGOOD


static void goodG2B1()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    if(globalFalse)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        memset(data, 'A', 50-1); 
        data[50-1] = '\0'; 
    }
    {
        char dest[50] = "";
        
        strncat(dest, data, strlen(data));
        dest[50-1] = '\0'; 
        printLine(data);
    }
}


static void goodG2B2()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    if(globalTrue)
    {
        
        memset(data, 'A', 50-1); 
        data[50-1] = '\0'; 
    }
    {
        char dest[50] = "";
        
        strncat(dest, data, strlen(data));
        dest[50-1] = '\0'; 
        printLine(data);
    }
}

void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_ncat_10_good()
{
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
    CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_ncat_10_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_ncat_10_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
