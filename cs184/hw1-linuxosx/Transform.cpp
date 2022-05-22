// Transform.cpp: implementation of the Transform class.


#include "Transform.h"

//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
  // YOUR CODE FOR HW1 HERE
  // Please implement this. 
  const float radians=glm::radians(degrees); 
  const float x=axis[0];
  const float y=axis[1];
  const float z=axis[2];
  const mat3 skew{0, -z, y, z, 0, -x, -y, x, 0};
  const mat3 aaT{x*x, x*y, x*z, x*y, y*y, y*z, x*z, y*z, z*z};
  const mat3 Id{1.0};
  return glm::cos(radians) * Id + (1 - glm::cos(radians)) * aaT + glm::sin(radians) * skew;
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE
  const mat3 rotation=rotate(degrees, up);
  eye = eye * rotation;
  up = up * rotation;
  return;
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE
  const vec3 horizontal=glm::normalize(glm::cross(up, eye));
  const mat3 rotation=rotate(degrees, horizontal);
  eye = eye * rotation;
  up = up * rotation;
  return;
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  // YOUR CODE FOR HW1 HERE
  const vec3 w=glm::normalize(eye);
  const vec3 u=glm::normalize(glm::cross(up, w));
  const vec3 v=glm::cross(w, u);

  const mat4 mv{u[0], u[1], u[2], -glm::dot(u, eye), 
             v[0], v[1], v[2], -glm::dot(v, eye), 
             w[0], w[1], w[2], -glm::dot(w, eye), 
             0, 0, 0, 1};
  return mv;
}

Transform::Transform()
{

}

Transform::~Transform()
{

}