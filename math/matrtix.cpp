#include "matrix.hpp"

float *addition4(float *matrix1, float *matrix2)
{

}

float *Matrix::createDiagonalMatrix(float diagonal)
{
    float *matrix = new float[16]();
    for(int i = 0; i < 16; i++)
    {
        if(i == 15)
            matrix[i] = 1.0f;
        else if(i % 5 == 0)
            matrix[i] = diagonal;
        else
            matrix[i] = 0;
    }
}

float *Matrix::makeScaleMatrix(float *diagonal, float *matrix)
{
    for(int i = 0, j = 0; i < 11; i += 5, j++)
    {
        matrix[i] = matrix[i] * diagonal[j];
    }

    return matrix;
}

float *Matrix::translateMatrix(float *matrix, float *vector3)
{
    for(int i = 12, j = 0; i < 15; i ++, j++)
         matrix[i] += vector3[j];

    return matrix;
}

float *Matrix::multiplyMatrices(float *matrix1, float *matrix2)
{
    float *matrixResult = new float[4]();
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            for(int k = 0; k < 4; k++)
                matrixResult[i] += matrix1[k * 4 + i] * matrix2[j * 4 + k];
        }
    }

    return matrixResult;
}

Matrix::Matrix(){}
Matrix::~Matrix(){}