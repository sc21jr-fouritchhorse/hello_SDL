#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "Geometry.h"

class Component 
{
public:
    virtual void Init();
    virtual void Update();
    virtual void GetInput();
    virtual void Draw();
    virtual void Destroy();
};

class Transform_2 : public Component
{
public:
    float scale;
    Vec2 *position;
private:
    virtual void Init();
    virtual void Update();
    virtual void Destroy();
};

class Transform_3 : public Component
{
public:
    float scale;
    Vec3 *position;
private:
    virtual void Init();
    virtual void Update();
    virtual void Destroy();
};

class Model : public Component 
{
public: 
    const char* filename;
    GLuint vbo_id;
    GLuint ebo_id;
private:
    std::vector<GLuint> indices;
    std::vector<GLfloat*> vertices;
    virtual void Init();
    virtual void Render();
    virtual void Destroy();
};

#endif