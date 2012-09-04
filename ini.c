#include <libcorc/core/str.h>
#include "parse.h"

CorcParseNode corcparse_ini_stream(const char *in)
{
    char *copy, *ptr, *s;
    CorcParseNode *head, *n, *p, *section;

    head = n = p = section = NULL;

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
        else if (*s == '[' && *ptr == ']') 
        {
            n = corparse_node_new();
            n->root = true;
            n->name = strdup(s);
            
            if (p)
            {
                p->next = n;
                n->prev = p;
            }

            section = n;

            if (!head)
                head = n;
        }

        else if ((ptr = strchr(s, '='))
        {
            n = corcparse_node_new();
            if (section)
            {
                n->root = false;
                n->parent = section;
            }
            else
                n->root = true;

            if (p)
            {
                if (p == section)
                    section->data = n;
                else
                {
                    p->next = n;
                    n->prev = p;
                }
            }

            *ptr = '\0';

            while (isspace(*s))
                *s++;
            while (isspace(--*ptr));
            (*ptr + 1) = '\0';

            n->name = strdup(s);
    }
}

size_t corcparse_ini(CorcParser *parser)
{

}
