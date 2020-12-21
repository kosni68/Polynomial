
#ifndef Polynomial_H_

class Polynomial
{

public:

  Polynomial(byte degree_polynome,byte nombre_points);

  void calcul_coef(double coordonee_X[], double coordonee_Y[]);
  
  double Get_coeficient(byte coeficient);

  double resultat(double valeur);

  byte Get_degree();

  //int Get_degree();

private:

  int i, j, k;

  //no. of data-points
  int N;
  //degree of polynomial
  int n;

  double a[16];

};

#endif
