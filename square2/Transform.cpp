#include "Transform.h"

Transform_2::Transform_2(float __x, float __y)
{
    scale = 1.0;
    position = new Vec2(__x, __y);
}

void Transform_2::Translate(Vec2 *factor)
{
    *position + *factor;
}

void Transform_2::Scale(float factor)
{
    scale * factor;
}

Transform_3::Transform_3(float __x, float __y, float __z)
{
    scale = 1.0;
    position = new Vec3(__x, __y, __z);
}

void Transform_3::Translate(Vec3 *factor)
{
    *position + *factor;
}

void Transform_3::Scale(float factor)
{
    scale * factor;
}

