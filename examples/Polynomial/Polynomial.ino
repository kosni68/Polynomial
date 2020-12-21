#include "Polynomial.h"

Polynomial droite1(1, 2); //droite , nombre de points
Polynomial droite2(1, 6); //droite , nombre de points

Polynomial courbe1(2, 3); //Polynome du second degrée , nombre de points
Polynomial courbe2(3, 6); //Polynome du troisieme degrée , nombre de points
Polynomial courbe3(5, 6); //Polynome du cinquieme degrée , nombre de points

double coordonee_X_droite1[] = {707, 1525};
double coordonee_Y_droite1[] = {12, 192};

double coordonee_X_droite2[] = {707, 1525, 2565, 3521, 4057, 5521};
double coordonee_Y_droite2[] = {2, 112, 222, 435, 679, 896};

double coordonee_X_courbe1[] = {123.56, 525.12, 723.02};
double coordonee_Y_courbe1[] = {12.08, 59.45, 115.98};

double coordonee_X_courbe2[] = {1707, 2525, 25, 1488, 7565, 9057};
double coordonee_Y_courbe2[] = {12, 32, 48, 73, 135, 179};

double coordonee_X_courbe3[] = {1707, 2525, 25, 1488, 7565, 9057};
double coordonee_Y_courbe3[] = {12, 32, 48, 73, 135, 179};

// ***********************************************************************
// ***********************     FONCTION SETUP     ************************
// ***********************************************************************

void setup()
{

  Serial.begin(115200);

  droite1.calcul_coef(coordonee_X_droite1, coordonee_Y_droite1);
  droite2.calcul_coef(coordonee_X_droite2, coordonee_Y_droite2);

  courbe1.calcul_coef(coordonee_X_courbe1, coordonee_Y_courbe1);
  courbe2.calcul_coef(coordonee_X_courbe2, coordonee_Y_courbe2);
  courbe3.calcul_coef(coordonee_X_courbe3, coordonee_Y_courbe3);

  // *************************      DROITE 1     **************************

  Serial.print("nombre de degree : ");
  Serial.println(droite1.Get_degree());
  Serial.println("droite f(x) = ax + b :");

  Serial.print("a = ");
  Serial.println(droite1.Get_coeficient(1), 15);
  Serial.print("b = ");
  Serial.println(droite1.Get_coeficient(0), 15);

  Serial.print("f(1200) = ");
  Serial.println(droite1.resultat(1200), 15);

  Serial.println("");

  // *************************      DROITE 2     **************************

  Serial.print("nombre de degree : ");
  Serial.println(droite2.Get_degree());
  Serial.println("droite f(x) = ax + b :");

  Serial.print("a = ");
  Serial.println(droite2.Get_coeficient(1), 15);
  Serial.print("b = ");
  Serial.println(droite2.Get_coeficient(0), 15);

  Serial.print("f(3005.23) = ");
  Serial.println(droite2.resultat(3005.23), 15);

  Serial.println("");

  // *************************      COURBE 1     **************************

  Serial.print("nombre de degree : ");
  Serial.println(courbe1.Get_degree());
  Serial.println("fonction du second degrée f(x) = ax2 + bx + c :");

  Serial.print("a = ");
  Serial.println(courbe1.Get_coeficient(2), 15);
  Serial.print("b = ");
  Serial.println(courbe1.Get_coeficient(1), 15);
  Serial.print("c = ");
  Serial.println(courbe1.Get_coeficient(0), 15);

  Serial.print("f(400) = ");
  Serial.println(courbe1.resultat(400), 15);

  Serial.println("");

  // *************************      COURBE 2     **************************

  Serial.print("nombre de degree : ");
  Serial.println(courbe2.Get_degree());
  Serial.println("fonction du troisième degrée f(x) = ax3 + bx2 + cx + d :");

  Serial.print("a = ");
  Serial.println(courbe2.Get_coeficient(3), 15);
  Serial.print("b = ");
  Serial.println(courbe2.Get_coeficient(2), 15);
  Serial.print("c = ");
  Serial.println(courbe2.Get_coeficient(1), 15);
  Serial.print("d = ");
  Serial.println(courbe2.Get_coeficient(0), 15);

  Serial.print("f(4251) = ");
  Serial.println(courbe2.resultat(4251), 15);

  Serial.println("");

  // *************************      COURBE 3     **************************

  Serial.print("nombre de degree : ");
  Serial.println(courbe3.Get_degree());
  Serial.println("fonction du cinquieme degrée f(x) = ax5 + bx4 + cx3 + dx2 + ex + f :");

  Serial.print("a = ");
  Serial.println(courbe3.Get_coeficient(5), 25);
  Serial.print("b = ");
  Serial.println(courbe3.Get_coeficient(4), 25);
  Serial.print("c = ");
  Serial.println(courbe3.Get_coeficient(3), 25);
  Serial.print("d = ");
  Serial.println(courbe3.Get_coeficient(2), 25);
  Serial.print("e = ");
  Serial.println(courbe3.Get_coeficient(1), 25);
  Serial.print("f = ");
  Serial.println(courbe3.Get_coeficient(0), 25);

  Serial.print("f(5245) = ");
  Serial.println(courbe3.resultat(0), 15);

  Serial.println("");
}

// ***********************************************************************
// ***********************     FONCTION LOOP     *************************
// ***********************************************************************

void loop() {}
