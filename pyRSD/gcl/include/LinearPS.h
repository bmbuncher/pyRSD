#ifndef LINEAR_PS_H
#define LINEAR_PS_H


#include "Common.h"
#include "PowerSpectrum.h"
#include "Cosmology.h"

/**********************************************************************
 * LinearPS
 *
 * Linear power spectrum interpolated from a transfer function, which is
 * presumably calculated from a Boltzmann code.  Uses the analytic
 * $\ln^2(k)/k^3$ formula at high $k$.
 *********************************************************************/
class LinearPS : public PowerSpectrum {
public:
    
    LinearPS(Cosmology& C, double z = 0);

    const Cosmology& GetCosmology() const { return C; }
    double Evaluate(double k) const;
    

private:
    
    Cosmology& C;
    double z;

};

#endif // LINEAR_PS_H
