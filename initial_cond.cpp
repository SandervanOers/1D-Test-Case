# include "initial_cond.hpp"
/*--------------------------------------------------------------------------*/
// Stratified Test Problem
/*--------------------------------------------------------------------------*/
extern double calculate_sigma(const double &N2, const unsigned int &k)
{
    return sqrt(1/4.0*N2*N2+2.0*PETSC_PI*2.0*PETSC_PI*k*k)/2.0/PETSC_PI;
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_m(const double &x, const double &t, const double &N2, const double &sigma, const unsigned int &k)
{
    return exp(-0.5*N2*x)*sin(2.0*PETSC_PI*k*x)*sin(2.0*PETSC_PI*sigma*(t+0.1));
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_p(const double &x, const double &t, const double &N2, const double &sigma, const unsigned int &k)
{
    return exp(-0.5*N2*x)*(N2/4.0/sigma/PETSC_PI*sin(2.0*PETSC_PI*k*x)+k/sigma*cos(2.0*PETSC_PI*k*x))*cos(2.0*PETSC_PI*sigma*(t+0.1));
}
/*--------------------------------------------------------------------------*/
extern double rho_0(const double &x, const double &N2)
{
    return exp(-N2*x);
}
/*--------------------------------------------------------------------------*/
extern double rho_0_deriv(const double &x, const double &N2)
{
    return -N2*exp(-N2*x);
}
/*--------------------------------------------------------------------------*/
extern double N_2(const double &x, const double &N2)
{
    // Can generalize to nonconst N2;
    return N2;//
}
/*--------------------------------------------------------------------------*/
// Viscous Homogeneous Test Problem
/*--------------------------------------------------------------------------*/
extern double viscous_calculate_sigma(const double &nu, const unsigned int &k)
{
    return k*sqrt(1.0-PETSC_PI*PETSC_PI*k*k*nu*nu);
}
/*--------------------------------------------------------------------------*/
extern double viscous_Exact_Solution_m(const double &x, const double &t, const double &nu, const double &sigma, const unsigned int &k)
{
    return sin(2.0*PETSC_PI*k*x)*exp(-2.0*k*k*PETSC_PI*PETSC_PI*nu*t)*sin(2*PETSC_PI*sigma*t);
}
/*--------------------------------------------------------------------------*/
extern double viscous_Exact_Solution_p(const double &x, const double &t, const double &nu, const double &sigma, const unsigned int &k)
{
    return cos(2.0*PETSC_PI*k*x)*exp(-2.0*k*k*PETSC_PI*PETSC_PI*nu*t)*(k*nu*PETSC_PI*sin(2*PETSC_PI*sigma*t)+sigma/((double)k)*cos(2.0*PETSC_PI*sigma*t));
}
/*--------------------------------------------------------------------------*/
extern double viscous_rho_0(const double &x, const double &N2)
{
    return 1.0;
}
/*--------------------------------------------------------------------------*/
extern double viscous_rho_0_deriv(const double &x, const double &N2)
{
    return 0.0;
}
/*--------------------------------------------------------------------------*/
// System 1 Test Case
/*--------------------------------------------------------------------------*/
extern double calculate_sigma_system1(const double &N2, const unsigned int &k)
{
    return sqrt((N2+1.0)/N2*(0.25*N2*N2-N2+1.0+4.0*PETSC_PI*PETSC_PI*k*k))/2.0/PETSC_PI;
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_m_system1(const double &x, const double &t, const double &N2, const double &sigma, const unsigned int &k)
{
    return exp(-0.5*N2*x)*sin(2.0*PETSC_PI*k*x)*sin(2.0*PETSC_PI*sigma*(t+0.1));
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_p_system1(const double &x, const double &t, const double &N2, const double &sigma, const unsigned int &k)
{
    return exp(-0.5*N2*x)*((N2/2.0-1.0)/2.0/sigma/PETSC_PI*sin(2.0*PETSC_PI*k*x)+k/sigma*cos(2.0*PETSC_PI*k*x))*cos(2.0*PETSC_PI*sigma*(t+0.1));
}
/*--------------------------------------------------------------------------*/
// System 3 Test Case
/*--------------------------------------------------------------------------*/
extern double calculate_sigma_system3(const double &beta, const unsigned int &k)
{
    double N2 = beta-1.0;
    return sqrt((N2+1.0)/N2*(0.25*N2*N2-0.5*N2+0.25+4.0*PETSC_PI*PETSC_PI*k*k))/2.0/PETSC_PI;
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_m_system3(const double &x, const double &t, const double &beta, const double &sigma, const unsigned int &k)
{
    double N2 = beta-1.0;
    return exp(-0.5*beta*x)*sin(2.0*PETSC_PI*k*x)*sin(2.0*PETSC_PI*sigma*(t+0.1));
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_p_system3(const double &x, const double &t, const double &beta, const double &sigma, const unsigned int &k)
{
    double N2 = beta-1.0;
    return exp(-0.5*beta*x)*((N2-1.0)/4.0/sigma/PETSC_PI*sin(2.0*PETSC_PI*k*x)+k/sigma*cos(2.0*PETSC_PI*k*x))*cos(2.0*PETSC_PI*sigma*(t+0.1));
}
/*--------------------------------------------------------------------------*/
extern double rho_0_compressible(const double &x, const double &beta)
{
    return exp(-beta*x);
}
/*--------------------------------------------------------------------------*/
extern double rho_0_deriv_compressible(const double &x, const double &beta)
{
    return -beta*exp(-beta*x);
}
/*--------------------------------------------------------------------------*/
extern double N_2_compressible(const double &x, const double &beta)
{
    return beta-1.0;
}
/*--------------------------------------------------------------------------*/
// System 4 Test Case
/*--------------------------------------------------------------------------*/
extern double calculate_sigma_system4(const double &beta, const unsigned int &k)
{
    double N2 = beta-1.0;
    return sqrt(4.0*PETSC_PI*PETSC_PI*k*k*(1.0+2.0/N2)+0.25*N2*N2+0.25*(1.0+2.0/N2))/2.0/PETSC_PI;
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_m_system4(const double &x, const double &t, const double &beta, const double &sigma, const unsigned int &k)
{
    double N2 = beta-1.0;
    return exp(-0.5*beta*x)*sin(2.0*PETSC_PI*k*x)*sin(2.0*PETSC_PI*sigma*(t+0.1));
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_r_system4(const double &x, const double &t, const double &beta, const double &sigma, const unsigned int &k)
{
    double N2 = beta-1.0;
    return exp(-0.5*beta*x)*((N2+1.0)/4.0/sigma/PETSC_PI*sin(2.0*PETSC_PI*k*x)+k/sigma*cos(2.0*PETSC_PI*k*x))*cos(2.0*PETSC_PI*sigma*(t+0.1));
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_p_system4(const double &x, const double &t, const double &beta, const double &sigma, const unsigned int &k)
{
    double N2 = beta-1.0;
    return exp(-0.5*beta*x)*((N2-1.0)/4.0/sigma/PETSC_PI*sin(2.0*PETSC_PI*k*x)+k/sigma*cos(2.0*PETSC_PI*k*x))*cos(2.0*PETSC_PI*sigma*(t+0.1));
}
/*--------------------------------------------------------------------------*/
// System 5 Test Case
/*--------------------------------------------------------------------------*/
extern double calculate_sigma_system5(const double &beta, const unsigned int &k)
{
    double N2 = beta-1.0;
    return sqrt(4.0*PETSC_PI*PETSC_PI*k*k*(1.0+2.0/N2)+0.25*N2*N2+0.25*(1.0+2.0/N2))/2.0/PETSC_PI;
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_m_system5(const double &x, const double &t, const double &beta, const double &sigma, const unsigned int &k)
{
    double N2 = beta-1.0;
    return exp(-0.5*beta*x)*sin(2.0*PETSC_PI*k*x)*sin(2.0*PETSC_PI*sigma*(t+0.1));
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_r_system5(const double &x, const double &t, const double &beta, const double &sigma, const unsigned int &k)
{
    double N2 = beta-1.0;
    return exp(-0.5*beta*x)*(-(N2+1.0)/4.0/sigma/PETSC_PI*sin(2.0*PETSC_PI*k*x)+k/sigma*cos(2.0*PETSC_PI*k*x))*cos(2.0*PETSC_PI*sigma*(t+0.1));
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_p_system5(const double &x, const double &t, const double &beta, const double &sigma, const unsigned int &k)
{
    double N2 = beta-1.0;
    return exp(-0.5*beta*x)*((N2-1.0)/4.0/sigma/PETSC_PI*sin(2.0*PETSC_PI*k*x)+k/sigma*cos(2.0*PETSC_PI*k*x))*cos(2.0*PETSC_PI*sigma*(t+0.1));
}
/*--------------------------------------------------------------------------*/
// System 6: Verification: 1D Compressible Nonviscous Test Case
/*--------------------------------------------------------------------------*/
extern double calculate_sigma_system1dcom(const double &beta, const unsigned int &k)
{
    double N2 = beta-1.0;
    return sqrt(4.0*PETSC_PI*PETSC_PI*k*k+0.25*N2*N2+0.5*N2+0.25)/2.0/PETSC_PI;
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_m_system1dcom(const double &x, const double &t, const double &beta, const double &sigma, const unsigned int &k)
{
    double N2 = beta-1.0;
    return exp(-0.5*beta*x)*sin(2.0*PETSC_PI*k*x)*sin(2.0*PETSC_PI*sigma*(t+0.1));
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_r_system1dcom(const double &x, const double &t, const double &beta, const double &sigma, const unsigned int &k)
{
    double N2 = beta-1.0;
    return exp(-0.5*beta*x)*(-(N2+1.0)/4.0/sigma/PETSC_PI*sin(2.0*PETSC_PI*k*x)+k/sigma*cos(2.0*PETSC_PI*k*x))*cos(2.0*PETSC_PI*sigma*(t+0.1));
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_p_system1dcom(const double &x, const double &t, const double &beta, const double &sigma, const unsigned int &k)
{
    double N2 = beta-1.0;
    return exp(-0.5*beta*x)*((N2-1.0)/4.0/sigma/PETSC_PI*sin(2.0*PETSC_PI*k*x)+k/sigma*cos(2.0*PETSC_PI*k*x))*cos(2.0*PETSC_PI*sigma*(t+0.1));
}
/*--------------------------------------------------------------------------*/
// 2D
/*--------------------------------------------------------------------------*/
// System 1 Test Case
/*--------------------------------------------------------------------------*/
extern double calculate_sigma_2D_system1(const double &beta, const unsigned int &kx, const unsigned int &kz)
{
    return sqrt(beta*beta/16.0/PETSC_PI/PETSC_PI+kx*kx+kz*kz);
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_mx_2D_system1(const double &x, const double &z, const double &t, const double &beta, const double &sigma, const unsigned int &kx, const unsigned int &kz)
{
    //return exp(-0.5*beta*z)*kx/(pow(sigma,2.0)-pow(kx,2.0))*(beta/4.0/PETSC_PI*sin(2.0*PETSC_PI*kz*z)+kz*cos(2.0*PETSC_PI*kz*z))*sin(2.0*PETSC_PI*kx*x)*sin(2*PETSC_PI*sigma*t);
    return 2.0*PETSC_PI*kx*cos(2.0*PETSC_PI*kz*z)*sin(2.0*PETSC_PI*kx*x)*sin(2*PETSC_PI*sigma*t);
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_mz_2D_system1(const double &x, const double &z, const double &t, const double &beta, const double &sigma, const unsigned int &kx, const unsigned int &kz)
{
    //return sin(2.0*PETSC_PI*kz*z)*cos(2.0*PETSC_PI*kx*x)*sin(2*PETSC_PI*sigma*t);
    return 2.0*PETSC_PI*kz*sin(2.0*PETSC_PI*kz*z)*cos(2.0*PETSC_PI*kx*x)*sin(2*PETSC_PI*sigma*t);
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_r_2D_system1(const double &x, const double &z, const double &t, const double &beta, const double &sigma, const unsigned int &kx, const unsigned int &kz)
{
    return 0;
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_p_2D_system1(const double &x, const double &z, const double &t, const double &beta, const double &sigma, const unsigned int &kx, const unsigned int &kz)
{
    //return exp(-0.5*beta*z)*sigma/(pow(sigma,2.0)-pow(kx,2.0))*(beta/4.0/PETSC_PI*sin(2.0*PETSC_PI*kz*z)+kz*cos(2.0*PETSC_PI*kz*z))*cos(2.0*PETSC_PI*kx*x)*cos(2*PETSC_PI*sigma*t);
    return cos(2.0*PETSC_PI*kz*z)*cos(2.0*PETSC_PI*kx*x)*cos(2*PETSC_PI*sigma*t);
}
/*--------------------------------------------------------------------------*/
extern double rho_0_2D_system1(const double &z, const double &beta)
{
    return exp(-beta*z);
}
/*--------------------------------------------------------------------------*/
extern std::vector<double> rho_0_2D_system1(const std::vector<double> &z, const double &beta)
{
    std::vector<double> returnvector;
    for (const double& i : z)
    {
        returnvector.push_back(exp(-beta*(i)));
        //returnvector.push_back(1.0+i+i*i);
    }
    return returnvector;
}
/*--------------------------------------------------------------------------*/
extern double rho_0_deriv_2D_system1(const double &z, const double &beta)
{
    return -beta*exp(-beta*z);
}
/*--------------------------------------------------------------------------*/
extern std::vector<double> rho_0_deriv_2D_system1(const std::vector<double> &z, const double &beta)
{
    std::vector<double> returnvector;
    for (const double& i : z)
    {
        returnvector.push_back(-beta*exp(-beta*(i)));
        //returnvector.push_back(1.0+2.0*i);
    }
    return returnvector;
}
/*--------------------------------------------------------------------------*/
extern double N_2_2D_system1(const double &z, const double &beta)
{
    return beta-1.0;
}
/*--------------------------------------------------------------------------*/
extern std::vector<double> N_2_2D_system1(const std::vector<double> &z, const double &beta)
{
    std::vector<double> returnvector;
    for (const double& i : z)
    {
        returnvector.push_back(beta-1.0);
    }
    return returnvector;
}
/*--------------------------------------------------------------------------*/
// System 2 Test Case
/*--------------------------------------------------------------------------*/
extern double calculate_sigma_2D_system2(const double &beta, const unsigned int &kx, const unsigned int &kz)
{
    //return sqrt(beta*beta/16.0/PETSC_PI/PETSC_PI+kx*kx+kz*kz);
    double N2 = beta - 1;
    double kxd = (double)kx;
    double kzd = (double)kz;
    //return sqrt(beta*beta*beta/N2/16.0/PETSC_PI/PETSC_PI+beta/N2*(kx*kx+kz*kz));
    //return sqrt((beta-2.0)*(beta-2.0)/16.0/PETSC_PI/PETSC_PI + kx*kx + kz * kz);
    //return sqrt((N2+1.0)/N2*(kx*kx+kz*kz+(N2-1.0)*(N2-1.0)/16.0/PETSC_PI/PETSC_PI));
    double b = -kxd*kxd-kzd*kzd-(N2+1.0)*(N2+1.0)/16.0/PETSC_PI/PETSC_PI;
    double c = kxd*kxd*N2/4.0/PETSC_PI/PETSC_PI;
    return sqrt(-b/2.0+0.5*sqrt(b*b-4.0*c));
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_mx_2D_system2(const double &x, const double &z, const double &t, const double &beta, const double &sigma, const unsigned int &kx, const unsigned int &kz)
{
    //return exp(-0.5*beta*z)*kx/(pow(sigma,2.0)-pow(kx,2.0))*(beta/4.0/PETSC_PI*sin(2.0*PETSC_PI*kz*z)+kz*cos(2.0*PETSC_PI*kz*z))*sin(2.0*PETSC_PI*kx*x)*sin(2*PETSC_PI*sigma*t);
    //return exp(-0.5*beta*z)*(4.0*PETSC_PI*kx)/(16.0*PETSC_PI*PETSC_PI*kz*kz+beta*beta)*(beta*sin(2.0*PETSC_PI*kz*z)+4.0*PETSC_PI*kz*cos(2.0*PETSC_PI*kz*z))*sin(2.0*PETSC_PI*kx*x)*sin(2*PETSC_PI*sigma*t);
    //return exp(-0.5*beta*z)*(4.0*PETSC_PI*kx)/(16.0*PETSC_PI*PETSC_PI*kz*kz+(beta-2.0)*(beta-2.0))*((beta-2.0)*sin(2.0*PETSC_PI*kz*z)+4.0*PETSC_PI*kz*cos(2.0*PETSC_PI*kz*z))*sin(2.0*PETSC_PI*kx*x)*sin(2*PETSC_PI*sigma*t);
    return 0.0;
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_mz_2D_system2(const double &x, const double &z, const double &t, const double &beta, const double &sigma, const unsigned int &kx, const unsigned int &kz)
{
    return exp(-0.5*beta*z)*sin(2.0*PETSC_PI*kz*z)*cos(2.0*PETSC_PI*kx*x)*sin(2*PETSC_PI*sigma*t);
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_r_2D_system2(const double &x, const double &z, const double &t, const double &beta, const double &sigma, const unsigned int &kx, const unsigned int &kz)
{
    double N2 = beta - 1;
    //return 0;
    return exp(-0.5*beta*z)*sigma/(kx*kx-sigma*sigma)*(((N2+1.0)/4.0/PETSC_PI-kx*kx*N2/2.0/PETSC_PI/sigma/sigma)*sin(2.0*PETSC_PI*kz*z)-kz*cos(2.0*PETSC_PI*kz*z))*cos(2.0*PETSC_PI*kx*x)*cos(2.0*PETSC_PI*sigma*t);
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_p_2D_system2(const double &x, const double &z, const double &t, const double &beta, const double &sigma, const unsigned int &kx, const unsigned int &kz)
{
    double N2 = beta - 1;
    //return exp(-0.5*beta*z)*sigma/(pow(sigma,2.0)-pow(kx,2.0))*(beta/4.0/PETSC_PI*sin(2.0*PETSC_PI*kz*z)+kz*cos(2.0*PETSC_PI*kz*z))*cos(2.0*PETSC_PI*kx*x)*cos(2*PETSC_PI*sigma*t);
    //return exp(-0.5*beta*z)*(4.0*PETSC_PI*sigma*N2)/(beta*(16.0*PETSC_PI*PETSC_PI*kz*kz+beta*beta))*(beta*sin(2.0*PETSC_PI*kz*z)+4.0*PETSC_PI*kz*cos(2.0*PETSC_PI*kz*z))*cos(2.0*PETSC_PI*kx*x)*cos(2*PETSC_PI*sigma*t);
    //return exp(-0.5*beta*z)*(1.0)/(beta*(16.0*PETSC_PI*PETSC_PI*kz*kz+(beta-2.0)*(beta-2.0)))*(4.0*PETSC_PI*sigma*(beta-2.0)*sin(2.0*PETSC_PI*kz*z)+16.0*PETSC_PI*PETSC_PI*sigma*kz*cos(2.0*PETSC_PI*kz*z))*cos(2.0*PETSC_PI*kx*x)*cos(2*PETSC_PI*sigma*t);

    ///return exp(-0.5*beta*z)*(4.0*PETSC_PI*sigma*sqrt(beta))/(16.0*PETSC_PI*PETSC_PI*kz*kz+(beta-2.0)*(beta-2.0))*N2/sqrt(N2+1.0)*((beta-2.0)*sin(2.0*PETSC_PI*kz*z)+4.0*PETSC_PI*kz*cos(2.0*PETSC_PI*kz*z))*cos(2.0*PETSC_PI*kx*x)*cos(2*PETSC_PI*sigma*t);
    //return exp(-0.5*beta*z)*1.0/(4.0*sigma*PETSC_PI*(16.0*PETSC_PI*PETSC_PI*kz*kz+(beta-2.0)*(beta-2.0))) *((16.0*PETSC_PI*PETSC_PI*(kx*kx+kz*kz)+(beta-2.0)*(beta-2.0))*(beta-2.0)*sin(2.0*PETSC_PI*kz*z)+(16.0*PETSC_PI*PETSC_PI*(kx*kx+kz*kz)+(beta-2.0)*(beta-2.0))* 4.0*PETSC_PI*kz*cos(2.0*PETSC_PI*kz*z))*cos(2.0*PETSC_PI*kx*x)*cos(2*PETSC_PI*sigma*t);
    return exp(-0.5*beta*z)*sigma/(kx*kx-sigma*sigma)*(-(N2-1.0)/4.0/PETSC_PI*sin(2.0*PETSC_PI*kz*z)-kz*cos(2.0*PETSC_PI*kz*z))*cos(2.0*PETSC_PI*kx*x)*cos(2.0*PETSC_PI*sigma*t);

}
/*--------------------------------------------------------------------------*/
extern double rho_0_2D_system2(const double &z, const double &beta)
{
    return exp(-beta*z);
}
/*--------------------------------------------------------------------------*/
extern std::vector<double> rho_0_2D_system2(const std::vector<double> &z, const double &beta)
{
    std::vector<double> returnvector;
    for (const double& i : z)
    {
        returnvector.push_back(exp(-beta*(i)));
    }
    return returnvector;
}
/*--------------------------------------------------------------------------*/
extern double rho_0_deriv_2D_system2(const double &z, const double &beta)
{
    return -beta*exp(-beta*z);
}
/*--------------------------------------------------------------------------*/
extern std::vector<double> rho_0_deriv_2D_system2(const std::vector<double> &z, const double &beta)
{
    std::vector<double> returnvector;
    for (const double& i : z)
    {
        returnvector.push_back(-beta*exp(-beta*(i)));
    }
    return returnvector;
}
/*--------------------------------------------------------------------------*/
extern double N_2_2D_system2(const double &z, const double &beta)
{
    return beta-1.0;
}
/*--------------------------------------------------------------------------*/
extern std::vector<double> N_2_2D_system2(const std::vector<double> &z, const double &beta)
{
    std::vector<double> returnvector;
    for (const double& i : z)
    {
        returnvector.push_back(beta-1.0);
    }
    return returnvector;
}
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
//  Incompresisble Test Case
/*--------------------------------------------------------------------------*/
extern double calculate_sigma_2DIC(const double &beta, const unsigned int &kx, const unsigned int &kz)
{
    double N2 = beta;
    double kxd = (double)kx;
    double kzd = (double)kz;
    double b = 16.0*PETSC_PI*PETSC_PI*(kxd*kxd+kzd*kzd)+N2*N2;
    double c = 4.0*N2*kxd*kxd;
    return sqrt(c/b);
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_mx_2DIC(const double &x, const double &z, const double &t, const double &beta, const double &sigma, const unsigned int &kx, const unsigned int &kz)
{
    double N2 = beta;
    double kxd = (double)kx;
    double kzd = (double)kz;
    return exp(-0.5*beta*z)*(-N2/(2.0*2.0*PETSC_PI*kxd)*sin(2.0*PETSC_PI*kzd*z)-kzd/kxd*cos(2.0*PETSC_PI*kzd*z))*sin(2.0*PETSC_PI*kxd*x)*sin(sigma*t+0.1);
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_mz_2DIC(const double &x, const double &z, const double &t, const double &beta, const double &sigma, const unsigned int &kx, const unsigned int &kz)
{
    double kxd = (double)kx;
    double kzd = (double)kz;
    return exp(-0.5*beta*z)*sin(2.0*PETSC_PI*kzd*z)*cos(2.0*PETSC_PI*kxd*x)*sin(2*PETSC_PI*sigma*t+0.1);
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_r_2DIC(const double &x, const double &z, const double &t, const double &beta, const double &sigma, const unsigned int &kx, const unsigned int &kz)
{
    double N2 = beta;
    double kxd = (double)kx;
    double kzd = (double)kz;
    return -N2/(2.0*PETSC_PI*sigma)*exp(-0.5*beta*z)*sin(2.0*PETSC_PI*kzd*z)*cos(2.0*PETSC_PI*kxd*x)*cos(2*PETSC_PI*sigma*t+0.1);
}
/*--------------------------------------------------------------------------*/
extern double Exact_Solution_p_2DIC(const double &x, const double &z, const double &t, const double &beta, const double &sigma, const unsigned int &kx, const unsigned int &kz)
{
    double N2 = beta;
    double kxd = (double)kx;
    double kzd = (double)kz;
    return exp(-0.5*beta*z)*(-N2*sigma/(2.0*2.0*PETSC_PI*kxd*kxd)*sin(2.0*PETSC_PI*kzd*z)-kz*sigma/kxd/kxd*cos(2.0*PETSC_PI*kzd*z))*cos(2.0*PETSC_PI*kxd*x)*cos(2*PETSC_PI*sigma*t+0.1);
}
/*--------------------------------------------------------------------------*/
extern double rho_0_2DIC(const double &z, const double &beta)
{
    return exp(-beta*z);
}
/*--------------------------------------------------------------------------*/
/*extern std::vector<double> rho_0_2DIC(const std::vector<double> &z, const double &beta)
{
    std::vector<double> returnvector;
    for (const double& i : z)
    {
        returnvector.push_back(exp(-beta*(i)));
    }
    return returnvector;
}*/
/*--------------------------------------------------------------------------*/
extern double rho_0_deriv_2DIC(const double &z, const double &beta)
{
    return -beta*exp(-beta*z);
}
/*--------------------------------------------------------------------------*/
/*extern std::vector<double> rho_0_deriv_2DIC(const std::vector<double> &z, const double &beta)
{
    std::vector<double> returnvector;
    for (const double& i : z)
    {
        returnvector.push_back(-beta*exp(-beta*(i)));
    }
    return returnvector;
}*/
/*--------------------------------------------------------------------------*/
extern double N_2_2DIC(const double &z, const double &beta)
{
    return beta;
}
/*--------------------------------------------------------------------------*/
/*extern std::vector<double> N_2_2DIC(const std::vector<double> &z, const double &beta)
{
    std::vector<double> returnvector;
    for (const double& i : z)
    {
        returnvector.push_back(beta);
    }
    return returnvector;
}*/
/*--------------------------------------------------------------------------*/
