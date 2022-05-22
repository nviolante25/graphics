# Homework 1: Transformations

- Implement [angle-axis formula](./Transform.cpp#L9) for a rotation of angle $\theta$ around the axis $v$.

$$R(\theta, v) = \cos(\theta)\begin{pmatrix} 1 & 0 & 0 \\
                                             0 & 1 & 0 \\ 
                                             0 & 0 & 1 
                             \end{pmatrix} 
                 + (1 - \cos(\theta))\begin{pmatrix} x^2 & xy & xz \\ 
                                                     xy & y^2 & yz \\
                                                     xz & yz & z^2 \\
                                                     \end{pmatrix} 
                 + \sin(\theta)\begin{pmatrix} 0 & -z & y \\ 
                                               z & 0 & -x \\ 
                                               -y & x & 0 \\
                                \end{pmatrix}
$$

- Implement [lookAt](./Transform.cpp#L42) to transform 3D world coordiantes to 3D camera coordinates, with the camera placed in `eye` looking at $(0, 0, 0)$ with its head pointing in the `up` direction.

    1. Create an orthonormal camera coordinate system starting from the directions `eye` and `up` using the cross product trick: $w=\frac{eye}{||eye||}$, $u=\frac{up\times w}{||up\times w||}$, $v=w\times u$
    2. Given a point $X$ in world coordinates we first translate it by $-eye$ and then apply the world-to-camera rotation given by the basis $(u, v, w)$.
    3. Combine the translation and the rotation to construct the $4\times 4$ transformation matrix
        $$\begin{pmatrix} u_0 & u_1 & u_2 & -u\cdot eye \\
                          v_0 & v_1 & v_2 & -v\cdot eye \\
                          w_0 & w_1 & w_2 & -w\cdot eye \\
                          0 & 0 & 0 & 1 \\
           \end{pmatrix}
        $$


### Changes in original files
- Add `#include <unistd.h>` in [grader.pp](./UCB/grader.cpp#L8) to prevent errors from `usleep`.