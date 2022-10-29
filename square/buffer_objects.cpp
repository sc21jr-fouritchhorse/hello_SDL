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

void buffer_object::render(array_object *vao)
{
    glUseProgram(my_shader->getID());
    glDrawElements(GL_TRIANGLES, getIndCount(), GL_UNSIGNED_INT, indices.data());
}

void buffer_object::destroy()
{
    delete this;
}

void buffer_object::readFile()
{
    verts = std::vector<GLfloat*>();
    indices = std::vector<GLuint>();

    GLfloat temp_vert[3];
    const int buffer_object_line_length = 50;
    char current_line[buffer_object_line_length];
    FILE *buffer_object_file = fopen(buffer_object_filename, "r");
    if(!buffer_object_file)
        return;
    else 
    {
        while(fscanf(buffer_object_file, "%s", current_line) > 0)
        {
            char current_first_char = current_line[0];

            switch(current_first_char)
            {
                case 'v':
                    fscanf(buffer_object_file, "%f %f %f", &temp_vert[0], &temp_vert[1], &temp_vert[2]);
                    verts.push_back((GLfloat*) malloc(3 * sizeof(GLfloat)));
                    for(int i = 0; i < 3; i++)
                        verts.back()[i] = temp_vert[i];
                    break;

                case 'f':
                    GLuint index;
                    while( fscanf(buffer_object_file, "%d ", &index) == 1) {
                       indices.push_back(index);
                    }
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

        glBindBuffer(GL_ARRAY_BUFFER, vbo_ID);
        glBufferData(GL_ARRAY_BUFFER, verts.size() * (sizeof(GLfloat) * 3), verts.data(), GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_ID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);


        glVertexAttribPointer(0, getVertCount(), GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void*) 0);
        glEnableVertexAttribArray(0);


        glVertexAttribPointer(1, getVertCount(), GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void*) 0);
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

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
    printf("I'm deleting my buffers\n");
        if (!destroyed) {
            for (GLfloat *v: verts) {
                delete (v);
            }
        }
    printf("My indices: ");
    for(GLuint i : indices)
    {
        printf("%d", i);
    }
    printf("\n");
    destroyed = true;

}


