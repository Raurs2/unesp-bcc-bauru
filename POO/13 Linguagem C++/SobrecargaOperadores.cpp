#include <iostream>
using namespace std;

//Raul Alexandre Gonzalez Augusto
//RA: 211023698

class Vetor3D {
  public:
  float x, y, z;

  public:
  friend istream & operator>>(istream &c, Vetor3D &v);

  Vetor3D(float x = 0, float y = 0, float z = 0) {
    this->x = x;
    this->y = y;
    this->z = z;
  }

  Vetor3D operator+(const Vetor3D &v) {
    Vetor3D aux;
    aux.x = x + v.x;
    aux.y = y + v.y;
    aux.z = z + v.z;
    return aux;
  }

  Vetor3D &operator+=(const float f) {
    x += f;
    y += f;
    z += f;
    return *this;
  }

  Vetor3D &operator+=(const Vetor3D &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
  }

  Vetor3D &operator-=(const Vetor3D &v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
  }
};

Vetor3D operator*=(const Vetor3D &v, int e)
{
  Vetor3D aux;
  aux.x = v.x * e;
  aux.y = v.y * e;
  aux.z = v.z * e;
  return aux;
}

Vetor3D operator/=(const Vetor3D &v, int e)
{
  Vetor3D aux;
  aux.x = v.x / e;
  aux.y = v.y / e;
  aux.z = v.z / e;
  return aux;
}

ostream & operator<<(ostream &c, Vetor3D &v) {
  c << '(' << v.x << ", " << v.y << ", " << v.z << ')';
  return c;
}

istream & operator>>(istream &c, Vetor3D &v) {
  c >> v.x >> v.y >>  v.z;
  return c;
}

int main() {

  Vetor3D vet1(1.2, 2.3, 3.4);
  Vetor3D vet2;

  cout << "Digite um valor tridimensional (três valores): ";
  cin >> vet2;

  cout << "Valor1 = " << vet1 << endl;

  cout << "Valor2 = " << vet2 << endl;
  vet2 += 2.0F;
  cout << "Valor2 = " << vet2 << endl;

  Vetor3D v(0.01, 0.01, 0.01);
  Vetor3D vet3 = (vet2 += vet1) + Vetor3D(0.01, 0.01, 0.01);
  cout << "Valor2 = " << vet2 << endl;
  cout << "Valor3 = " << vet3 << endl;
  
  Vetor3D vet4 = vet2 *= 3;
  cout << "Valor4 = " << vet2 << endl;

  Vetor3D vet5 = vet2 /= 3;
  cout << "Valor5 = " << vet2 << endl;

  Vetor3D vet6 = vet4 -= vet5;
  cout << "Valor6 = " << vet6 << endl;
}
