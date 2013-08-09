/*
 * Copyright 2013 TennenColl
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef BACKTRACE_OBJECT_PLANE_H
#define BACKTRACE_OBJECT_PLANE_H

#include "../geometricobject.hpp"

namespace backtrace {

class Plane : public GeometricObject
{
public:
    Plane()
        : m_normal(0.0, 1.0, 0.0)
    {
    }

    Plane(const Point3d& point, const Normald& normal)
        : m_point(point),
        m_normal(normal)
    {
        m_normal.normalize();
    }
    
    virtual ~Plane() {}
    
    virtual bool hit(const Ray& ray, double& tmin, ShadeRecord& result) const;

protected:
    Point3d m_point;
    Normald m_normal;
};

bool Plane::hit(const Ray& ray, double& tmin, ShadeRecord& result) const
{
    double t = (m_point - ray.origin) * m_normal / (ray.direction * m_normal);

    if(t > kEpsilon)
    {
        tmin = t;
        result.normal = m_normal;
        result.localHitPoint = ray.origin + t * ray.direction;
        return true;
    }
    else
    {
        return false;
    }
}

}

#endif
