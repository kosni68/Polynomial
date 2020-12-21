#include "Arduino.h"
#include "Polynomial.h"
//version 0.01

Polynomial::Polynomial(byte degree_polynome, byte nombre_points)
    : n(degree_polynome),
      N(nombre_points)
{
}

void Polynomial::calcul_coef(double coordonee_X[], double coordonee_Y[])
{
  if (n > 1)
  {

    //Array that will store the values of sigma(xi), sigma(xi ^ 2), sigma(xi ^ 3)....sigma(xi ^ 2n)

    double X[2 * n + 1];
    for (i = 0; i < 2 * n + 1; i++)
    {
      X[i] = 0;
      for (j = 0; j < N; j++)
      {
        X[i] = X[i] + pow(coordonee_X[j], i); //consecutive positions of the array will store N, sigma(xi), sigma(xi ^ 2), sigma(xi ^ 3)....sigma(xi ^ 2n)
      }
    }

    double B[n + 1][n + 2]; //B is the Normal matrix(augmented) that will store the equations, 'a' is for value of the final coefficients
    for (i = 0; i <= n; i++)
      for (j = 0; j <= n; j++)
        B[i][j] = X[i + j]; //Build the Normal matrix by storing the corresponding coefficients at the right positions except the last column of the matrix

    //Array to store the values of sigma(yi), sigma(xi * yi), sigma(xi ^ 2 * yi)... sigma(xi ^ n * yi)

    double Y[n + 1];
    for (i = 0; i < n + 1; i++)
    {
      Y[i] = 0;
      for (j = 0; j < N; j++)
      {
        Y[i] = Y[i] + pow(coordonee_X[j], i) * coordonee_Y[j]; //consecutive positions will store sigma(yi), sigma(xi * yi), sigma(xi ^ 2 * yi)... sigma(xi ^ n * yi)
      }
    }

    for (i = 0; i <= n; i++)
      B[i][n + 1] = Y[i]; //load the values of Y as the lastcolumn of B(Normal Matrix but augmented)
    n = n + 1;            //n is made n+1 because the Gaussian Elimination part below was for n equations, but here n is the degree of polynomial and for n degree we get n + 1 equations

    for (i = 0; i < n; i++) //From now Gaussian Elimination starts(can be ignored) to solve the set of linear equations(Pivotisation)
      for (k = i + 1; k < n; k++)
        if (B[i][i] < B[k][i])
          for (j = 0; j <= n; j++)
          {
            double temp = B[i][j];
            B[i][j] = B[k][j];
            B[k][j] = temp;
          }

    for (i = 0; i < n - 1; i++) //loop to perform the gauss elimination
      for (k = i + 1; k < n; k++)
      {
        double t = B[k][i] / B[i][i];
        for (j = 0; j <= n; j++)
          B[k][j] = B[k][j] - t * B[i][j]; //make the elements below the pivot elements equal to zero or elimnate the variables
      }

    for (i = n - 1; i >= 0; i--) //back-substitution
    {                            //x is an array whose values correspond to the values of x, y, z..

      a[i] = B[i][n]; //make the variable to be calculated equal to the rhs of the last equation

      for (j = 0; j < n; j++)
        if (j != i)
        { //then subtract all the lhs values except the coefficient of the variable whose valueis being calculated
          a[i] = a[i] - B[i][j] * a[j];
        }

      a[i] = a[i] / B[i][i]; //now finally divide the rhs by the coefficient of the variable to be calculated
    }
    n--;
  }
  else
  {

    double xsum = 0, x2sum = 0, ysum = 0, xysum = 0; //variables for sums/sigma of xi,yi,xi^2,xiyi etc
    for (i = 0; i < N; i++)
    {
      xsum = xsum + coordonee_X[i];                    //calculate sigma(xi)
      ysum = ysum + coordonee_Y[i];                    //calculate sigma(yi)
      x2sum = x2sum + pow(coordonee_X[i], 2);          //calculate sigma(x^2i)
      xysum = xysum + coordonee_X[i] * coordonee_Y[i]; //calculate sigma(xi*yi)
    }
    a[1] = (N * xysum - xsum * ysum) / (N * x2sum - xsum * xsum);     //calculate slope
    a[0] = (x2sum * ysum - xsum * xysum) / (x2sum * N - xsum * xsum); //calculate intercept
    double y_fit[N];                                                  //an array to store the new fitted values of y
    for (i = 0; i < N; i++)
      y_fit[i] = a[1] * coordonee_X[i] + a[0]; //to calculate y(fitted) at given x points
  }
}

double Polynomial::resultat(double valeur)
{
  if (n == 1)
  {
    return valeur * a[1] + a[0];
  } 
   if (n == 2)
  {
    return a[2] * pow(valeur, 2) + a[1]*valeur + a[0];
  }
  else
  {
    return a[15] * pow(valeur, 15) +a[14] * pow(valeur, 14) +a[13] * pow(valeur, 13) +a[12] * pow(valeur, 12) +a[11] * pow(valeur, 11) +a[10] * pow(valeur, 10) +a[9] * pow(valeur, 9) +a[8] * pow(valeur, 8) + a[7] * pow(valeur, 7) + a[6] * pow(valeur, 6) + a[5] * pow(valeur, 5) + a[4] * pow(valeur, 4) + a[3] * pow(valeur, 3) + a[2] * pow(valeur, 2) + a[1]*valeur + a[0];
  }
}

double Polynomial::Get_coeficient(byte coeficient)
{
  return a[coeficient];
}

byte Polynomial::Get_degree()
{
  return n;
}