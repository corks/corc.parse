#include <libcorc/core/str.h>
#include "parse.h"

CorcParseNode corcparse_ini_stream(const char *in)
{
    char *copy, *ptr, *s;
    /*CorcString *cs;*/
    CorcParseNode *n, *p, *section;

    n = p = section = NULL;

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
        
        /* If this line is a comment */
        if (*s == ';' || *s == '#')
            continue;
        
        /* If this line is a section */
        if (*s == '[' && *ptr == ']') 
        {
            n = corparse_node_new();
            n->root = true;
            n->name = strdup(s);
            
            if (p)
            {
                p->next = n;
                n->prev = p;
                if (p->parent)
                    n->parent = p->parent;
            }
        }
        
    }
    
}

size_t corcparse_ini(CorcParser *parser)
{

}
