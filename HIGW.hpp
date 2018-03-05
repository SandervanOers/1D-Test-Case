#ifndef HIGW
#define HIGW

#include <petscksp.h>
#include <iostream>
/*--------------------------------------------------------------------------*/
extern Mat MassMatrix_local(const Mat &V);
/*--------------------------------------------------------------------------*/
extern Mat MassMatrix_inverse_local(const Mat &V);
/*--------------------------------------------------------------------------*/
extern double calculate_Hamiltonian(const Mat &M1, const Vec &Solution, const unsigned int &Number_Of_Elements, const unsigned int &Np);
/*--------------------------------------------------------------------------*/
extern double calculate_Hamiltonian_pres(const Mat &M1, const Mat &M2, const Vec &Solution, const unsigned int &Number_Of_Elements, const unsigned int &Np);
/*--------------------------------------------------------------------------*/
extern double calculate_Hamiltonian_comp(const Mat &M1, const Mat &M2, const Vec &Solution, const unsigned int &Number_Of_Elements, const unsigned int &Np);
/*--------------------------------------------------------------------------*/
extern double calculate_Error(const Vec &Exact, const Vec &Solution, const unsigned int &Number_Of_Elements, const unsigned int &Np, const double &DeltaX);
/*--------------------------------------------------------------------------*/
#endif
