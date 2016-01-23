%{
#include "ClassCosmology.h"
%}


class ClassCosmology : public Engine {

public:

    ClassCosmology();
    ClassCosmology(const ClassParams& pars, const std::string& precision_file = "");
    ClassCosmology(const std::string& param_file, const std::string& precision_file = "");
    ~ClassCosmology();

    void Initialize(const ClassParams& pars, const std::string& precision_file);
    int GetCls(const vector<unsigned>& lVec, parray& cltt, parray& clte, parray& clee, parray& clbb);
    int GetLensing(const vector<unsigned>& lVec, parray& clphiphi, parray& cltphi, parray& clephi);
    double GetPklin(double z, double k);
    double GetPknl(double z, double k);
    int GetTk(double z, const parray& k, parray& Tk);
    int l_max_scalars() const;
    
    double H0() const;
    double h() const;
    double Tcmb() const;
    double Omega0_b() const;
    double Omega0_cdm() const;
    double Omega0_ur() const;
    double Omega0_m() const;
    double Omega0_r() const;
    double Omega0_g() const;
    double Omega0_lambda() const;
    double Omega0_k() const;
    double w0_fld() const;
    double wa_fld() const;
    double n_s() const;
    double k_pivot() const;
    double A_s() const;
    double ln_1e10_A_s() const;
    double sigma8() const;
    double k_max() const;
    double z_drag() const;
    double rs_drag() const;
    double tau_reio() const;
    double z_reio() const;
    
    double f_z(double z) const;
    parray f_z(const parray& z) const;
    
    double H_z(double z) const;
    parray H_z(const parray& z) const;
    
    double Da_z(double z) const;
    parray Da_z(const parray& z) const;

    double Dc_z(double z) const;
    parray Dc_z(const parray& z) const;
    
    double Dm_z(double z) const;
    parray Dm_z(const parray& z) const;
    
    double D_z(double z) const;
    parray D_z(const parray& z) const;
    
    double Sigma8_z(double z) const;
    parray Sigma8_z(const parray& z) const;
    
    double Omega_m_z(double z) const;
    parray Omega_m_z(const parray& z) const;
    
    double rho_bar_z(double z, bool cgs = false) const;
    parray rho_bar_z(const parray& z, bool cgs = false) const;
    
    double rho_crit_z(double z, bool cgs = false) const;
    parray rho_crit_z(const parray& z, bool cgs = false) const;
    
    double dV(double z) const;
    parray dV(const parray& z) const;
    
    double V(double zmin, double zmax, int Nz=1024) const;
    parray V(const parray& zmin, const parray& zmax, int Nz=1024) const;

    void PrintFC();


};
