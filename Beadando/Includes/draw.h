#ifndef DRAW_H
#define DRAW_H

#include "model.h"


/**
 * Draws the triangles of the model.
 */
void draw_triangles(const struct Model* model);

/**
 * Draws the quads of the model.
 */
void draw_quads(const struct Model* model);

/**
 * Draws the given model.
 */
void draw_model(const struct Model* model);

#endif /* DRAW_H */
