from . import PgalDerivative
from .fog_kernels import get_fog_derivative

class dPgal_dsigma_c(PgalDerivative):
    """
    The partial derivative of `Pgal` with respect to `sigma_c`
    """
    param = 'sigma_c'
    
    @staticmethod
    def eval(m, pars, k, mu):
        
        G = m.evaluate_fog(k, mu, m.sigma_c)
        Gprime = k*mu * get_fog_derivative(m.fog_model, k*mu*m.sigma_c)

        with m.preserve():
            m.sigma_c = 0
            
            if not m.use_so_correction:
                term1 = 2*G*Gprime * m.Pgal_cc(k, mu)
            else:
                # turn off SO correction
                m.use_so_correction = False
                Pcc = m.Pgal_cc(k, mu)

                # derivative of the SO correction terms
                G2    = m.evaluate_fog(k, mu, m.sigma_so)                
                term1_a = 2*G* (1-m.f_so)**2 * Pcc
                term1_b = 2*m.f_so*(1-m.f_so) * G2 * Pcc
                term1_c = 2*G2*m.f_so*m.fcB*m.NcBs
                term1 = (term1_a + term1_b + term1_c) * Gprime
                
            term2 = Gprime * m.Pgal_cs(k, mu)
            
        return (1-m.fs)**2 * term1 + 2*m.fs*(1-m.fs) * term2
            