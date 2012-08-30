#ifndef CORC_PARSE_H
#define CORC_PARSE_H

enum corcparse_types
{
    CORCPARSE_TYPE_JSON,
    CORCPARSE_TYPE_INI
};

typedef struct corcparse_node CorcParseNode;
typedef struct corcparse_parser CorcParser;

struct corcparse_node
{
    CorcParseNode *parent, *next, *prev;
    const char *name;
    bool root;
    void *data;
};

struct corcparse_parser
{
    size_t count;
    enum corcparse_types filetype;
    CorcParseNode *head;
};

#endif /* CORC_PARSE_H */
