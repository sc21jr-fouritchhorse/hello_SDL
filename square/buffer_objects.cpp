#include "buffer_objects.h"

void buffer_object::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void buffer_object::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, vbo_ID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_ID);
}

void buffer_object::destroy()
{
    delete this;
}

void buffer_object::readFile()
{
    verts = std::vector<GLfloat*>();
    indices = std::vector<GLuint*>();

    GLfloat temp_vert[3];
    GLuint temp_face[3];
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
                    fscanf(buffer_object_file, "%f %f %f", &temp_vert[0], &temp_vert[1], &temp_vert[2]);
                    verts.push_back((GLfloat*) malloc(3 * sizeof(GLfloat)));
                    for(int i = 0; i < 3; i++)
                        verts.back()[i] = temp_vert[i];
                    break;

                case 'f':
                    fscanf(buffer_object_file, "%u %u %u", &temp_face[0], &temp_face[1], &temp_face[2]);
                    indices.push_back((GLuint*) malloc(3 * sizeof(GLuint)));
                    for(int i = 0; i < 3; i++)
                        indices.back()[i] = temp_face[i];
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

        unbind();
    }

        
}

buffer_object::buffer_object(const char *filename)
{
    destroyed = false;
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


buffer_object::~buffer_object() {
    destroyed = true;
    printf("I'm deleting my buffers\n");
    if (destroyed) {
        for (GLfloat *v: verts) {
            delete (v);
            v = nullptr;
        }
    for (GLuint *i: indices) {
        if (i != nullptr) {
            i = nullptr;
        }
    }
    }
}


