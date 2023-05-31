#ifndef CAMERA_H
#define CAMERA_H

typedef struct Camera {
    float x;
    float y;
    float z;
    float rotationX;
    float rotationY;
    float rotationZ;
    float speedX;
    float speedY;
    float speedZ;
} Camera;

Camera camera;

void init_camera();

void update_camera();

void rotate_camera();

#endif /* CAMERA_H */
