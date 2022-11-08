#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

struct Vec2 {
    union  {
        struct { float x, y; };
        float raw[2];    
    };
    Vec2() : x(0), y(0) {}
    Vec2(float _x, float _y) : x(_x), y(_y) {}
    inline Vec2 operator+(const Vec2 &V) const { return Vec2(x + V.x, y + V.y); }
    inline Vec2 operator-(const Vec2 &V) const { return Vec2(x - V.x, y - V.y); }
    inline Vec2 operator*(float a)       const { return Vec2(a*x, a*y);  }
    inline Vec3     toVec3()             const { return Vec3(x, y, 1.0); }
};


struct Vec3 {
    union  {
        struct { float x, y, z; };
        float raw[3];    
    };
    Vec3() : x(0), y(0), z(0) {}
    Vec3(float _x, float _y, float _z) : x(_x), y(_y) {}
    inline Vec3  operator+(const Vec3 &V) const { return Vec3(x + V.x, y + V.y, z + V.z); }
    inline Vec3  operator-(const Vec3 &V) const { return Vec3(x - V.x, y - V.y, z - V.z); }
    inline Vec3  operator*(float a)       const { return Vec3(a*x, a*y, a*z); }
    inline float operator*(const Vec3 &v) const { return x*v.x + y*v.y + z*v.z; }
    inline Vec2  toVec2() const { return Vec2(x, y);}
};


#endif //__GEOMETRY_H__