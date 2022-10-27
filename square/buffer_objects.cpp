#include "buffer_objects.h"

void buffer_object::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, *vbo_ID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo_ID);
}


void buffer_object::readFile()
{
    std::vector<GLfloat*> temp_verts;
    std::vector<GLuint*> temp_indices;
    const int buffer_object_line_length = 50;
    char current_line[buffer_object_line_length];
    char current_first_char = ' ';
    FILE *buffer_object_file = fopen(buffer_object_filename, "r");
    if(!buffer_object_file)
        return;
    else 
    {
        while(fgets(current_line, sizeof(current_line), buffer_object_file) != NULL)
        {
            current_first_char = current_line[0];
            switch(current_first_char)
            {
                case 'v':
                    GLfloat vert[3];
                    fscanf(buffer_object_file, "%f %f %f\n", &vert[0], &vert[1], &vert[2]);
                    temp_verts.push_back(vert);
                break;

                case 'f':
                    GLuint face[3];
                    fscanf(buffer_object_file, "%u %u %u\n", &face[0], &face[1], &face[2]);
                    temp_indices.push_back(face);
                break;

                case '#':
                    continue;
                break;
            }
        }
        

        glGenBuffers(1, vbo_ID);
        glGenBuffers(1, ebo_ID);

        bind();

        glBufferData(GL_ARRAY_BUFFER, verts.size() * (sizeof(GLfloat) * 3), verts.data(), GL_STATIC_DRAW);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * (sizeof(GLuint) * 3), indices.data(), GL_STATIC_DRAW);
    }

        
}

buffer_object::buffer_object(const char *filename)
{
    createNull();
    buffer_object_filename = filename;
    if(!filename)
    {
        return;
    }
    else 
    {
        readFile();
    }
}


buffer_object::~buffer_object()
{
    for(GLfloat *v : verts)
        delete v;
    for(GLuint *i : indices)
        delete i;
}

