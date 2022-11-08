#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include "Geometry.h"

//TODO, make all this inherit from a component class
class Transform_2
{
public:
    Transform_2(float, float);
    void Translate(Vec2*);
    void Scale(float);
    inline float GetX() const { return position->x; }
    inline float GetY() const { return position->y; }
    inline void RestScale() { scale = 1.0; }
private:
    float scale;
    Vec2 *position;
};

class Transform_3
{
public:
    Transform_3(float, float, float);
    void Translate(Vec3*);
    void Scale(float);
    inline float GetX() const { return position->x; }
    inline float GetY() const { return position->y; }
    inline float GetZ() const { return position->z; }
    inline void RestScale() { scale = 1.0; }
private:
    float scale;
    Vec3 *position;
};

#endif //__TRANSFORM_H__