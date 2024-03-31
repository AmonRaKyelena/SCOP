#include "include.hpp"

class Matrix
{
private:

public:
    Matrix(/* args */);
    ~Matrix();
    float *makeScaleMatrix(float *diagonal, float *matrix);
    float *translateMatrix(float *matrix, float *vector3);
    float *multiplyMatrices(float *matrix1, float *matrix2);
    float *createDiagonalMatrix(float diagonal);


};


