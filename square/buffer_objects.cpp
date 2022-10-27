#include "buffer_objects.h"

void buffer_object::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, vbo_ID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_ID);
}


void buffer_object::readFile()
{
    verts = std::vector<GLfloat*>();
    indices = std::vector<GLuint*>();

    const int buffer_object_line_length = 50;
    char current_line[buffer_object_line_length];
    char current_first_char = ' ';
    FILE *buffer_object_file = fopen(buffer_object_filename, "r");
    if(!buffer_object_file)
        return;
    else 
    {
        while(fscanf(buffer_object_file, "%s", current_line) > 0)
        {
            current_first_char = current_line[0];

            switch(current_first_char)
            {
                case 'v':
                    GLfloat vert[3];
                    fscanf(buffer_object_file, "%f %f %f", &vert[0], &vert[1], &vert[2]);
                    verts.push_back(vert);
                break;

                case 'f':
                    GLuint face[3];
                    fscanf(buffer_object_file, "%u %u %u", &face[0], &face[1], &face[2]);
                    indices.push_back(face);
                break;

                case '#':
                    continue;
                default:
                    break;
            }
        }
        
        printf("I've read my buffers!\n");
        glGenBuffers(1, &vbo_ID);
        glGenBuffers(1, &ebo_ID);

        bind();

        glBufferData(GL_ARRAY_BUFFER, verts.size() * (sizeof(GLfloat) * 3), verts.data(), GL_STATIC_DRAW);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * (sizeof(GLuint) * 3), indices.data(), GL_STATIC_DRAW);
    }

        
}

buffer_object::buffer_object(const char *filename)
{
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
    for (GLfloat *v: verts) {
        for(int i = 0; i < 3; i++)
            printf("\n%f\n", v[i]);
        delete [] v;
    }
    for (GLuint *i: indices) {
        for(int j = 0; j < 3; j++)
            printf("\n%d\n", i[j]);

        delete [] i;
    }
}


