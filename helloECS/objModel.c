#include "objModel.h"


ObjModel objRead(const char  *filename) 
{
    ObjModel the_obj;
    char lineBuffer[512];
    FILE *file = fopen(filename, "r");
    if(file == NULL)
        printf("Couldn't open .obj file!\n");
    else {
        while(fscanf(file, "%s", lineBuffer) > 0) {
            switch(lineBuffer[0])
            {
                case 'v':
                    the_obj.vertCount++;
                break;
                case 'f':
                    the_obj.indCount++;
                break;
            }
        }
    }


    the_obj.vertData = (float**) malloc(the_obj.vertCount * sizeof(float*));
    the_obj.indices = (unsigned int**) malloc(the_obj.indCount * sizeof(unsigned int *));
    
}

void objWrite(const char *filename) 
{

}

void destroy(ObjModel *the_obj) 
{

}