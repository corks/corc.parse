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
    bool fatal;
    enum corcparse_error err;
    enum corcparse_types filetype;
    char **files;
    size_t nfiles;
    CorcParseNode *head;
};

extern CorcParser *corcparse_new(enum corcparse_types type);
extern CorcParseNode *corcparse_node_new();

#endif /* CORC_PARSE_H */
