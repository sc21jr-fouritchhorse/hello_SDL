#ifndef __OBJ_MODEL__
#define __OBJ_MODEL__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct objModel 
{
    unsigned int    vertCount;
    unsigned int     indCount;
    unsigned int commentCount;
    float        **vertData;
    unsigned int   *indices;
    char           **comments;

} ObjModel;


ObjModel objRead(const char  *filename);
void     objWrite(const char *filename);
void     destroy(ObjModel *the_obj);

#endif //__OBJ_MODEL__