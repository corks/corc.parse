#include <libcorc/core/str.h>
#include "parse.h"

CorcParseNode corcparse_ini_stream(const char *in)
{
    char *copy, *ptr, *s;
    /*CorcString *cs;*/
    CorcParseNode *n, *p;

    copy = strdup(in);

    while ((ptr = strchr(copy, '\n')))
    {
        *ptr = '\0';
        /*cs = corcstr(copy);*/
        s = strdup(copy);
        *copy = *(ptr + 1);
        while (isspace(*s))
            *s++;
        while (isspace(*ptr--));
        
        if (*s == ';' || *s == '#')
            

        if (*s == '[' && *ptr == ']') 
        {
            /* This is a section... apparently. */
        }
        
    }
    
}

size_t corcparse_ini(CorcParser *parser)
{

}
