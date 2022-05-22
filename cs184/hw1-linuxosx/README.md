# Homework 1: Transformations

- Implement [Angle-axis formula](./Transform.cpp#L9) for a rotation of angle $\theta$ around the axis $v$

$$R(\theta, v) = \cos(\theta)\begin{pmatrix} 1 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1 \end{pmatrix} 
   + (1 - \cos(\theta))\begin{pmatrix} x^2 & xy & xz \\ xy & y^2 & yz \\ xz & yz & z^2 \end{pmatrix}
   + \sin(\theta)\begin{pmatrix} 0 & -z & y \\ z & 0 & -x \\ -y & x & 0 \end{pmatrix}$$
- Implement [lookAt](./Transform.cpp#L42) for a camera looking at $(0, 0, 0)$ with `eye` and `up`. This is a two-step procedure.
    1. Create a new coordinate frame: $w=\frac{eye}{||eye||}$, $u=\frac{up\times w}{||up\times w||}$, $v=w\times u$
    2. Construct the transformation matrix
    $$\begin{pmatrix} u_0 & u_1 & u_2 & -u\cdot eye \\
                      v_0 & v_1 & v_2 & -u\cdot eye \\
                      w_0 & w_1 & w_2 & -u\cdot eye \\
                      0 & 0 & 0 & 1\end{pmatrix}$$


### Chages in original files
- Add `#include <unistd.h>` in [grader.pp](./UCB/grader.cpp#L8) to prevent errors from `usleep`.