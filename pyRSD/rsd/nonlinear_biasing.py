"""
Module to implement nonlinear biases as a function of 
linear bias
"""
from ._cache import parameter, cached_property
from .. import numpy as np, data as sim_data
from .simulation import NonlinearBiasFits

def _get_nonlinear_biasing_function(self, kind, tag, coeffs):
    """
    Internal function to return the nonlinear biasing function
    """
    name = kind + '_' + tag
    t = self.nonlinear_bias_types.get(name, None)
    
    # default is the GP fit
    if t is None:
        return lambda b1: self.nonlinear_bias_fitter(b1=b1, select=name)
    # use one b2_00 and one b2_01
    elif t == 'vlah':
        return lambda b1: self.nonlinear_bias_fitter(b1=b1, select=kind+'_a')
    # polynomials
    elif t == 'poly':
        return np.poly1d(coeffs)
    # map to other term
    elif t in self.nonlinear_biases:
        return lambda b1: self.nonlinear_bias_fitter(b1=b1, select=t)
    else:
        raise ValueError("do not understand '%s' biasing type for '%s'" %(t, name))

class NonlinearBiasingMixin(object):
    """
    A mix-in class to implement the relevant nonlinear biasing 
    functions, which uses a polynomial as a function of linear bias
    
    This class will have "parameter" objects (added dynamically, via
    the metaclass) for each of the names in `nonlinear_biases`
    
    The nonlinear biasing parameters should be set to their polynomial
    coefficients, and when accessed, the parameters will return
    `numpy.poly1d` instances, which can be called with the appropriate
    linear bias parameter
    """
    nonlinear_biases = ['b2_00_a', 'b2_00_b', 'b2_00_c', 'b2_00_d', 'b2_01_a', 'b2_01_b']
    
    def __init__(self):
        
        # nonlinear biasing types (initialized to None)
        self.nonlinear_bias_types = {k:None for k in self.nonlinear_biases}
        
        # loop over each nonlinear bias and set the defaults
        for name in self.nonlinear_biases:
            
            names = [name+'__'+str(i) for i in reversed(range(5))]
            if 'b2_00' in name:
                defaults = sim_data.nonlinear_bias_data('b2_00', name)
            elif 'b2_01' in name:
                defaults = sim_data.nonlinear_bias_data('b2_01', name)
            else:
                raise ValueError("only nonlinear biases are 'b2_00' or 'b2_01'")
                
            # dictionary for storing defaults
            self.nonlinear_bias_defaults = {}
            
            # set the defaults
            for i, d in enumerate(defaults):
                if hasattr(self.__class__, names[i]):
                    setattr(self, names[i], d)
                    self.nonlinear_bias_defaults[names[i]] = d

    
    @cached_property()
    def nonlinear_bias_fitter(self):
        """
        Interpolator from simulation data for nonlinear biases
        """
        return NonlinearBiasFits()
    
    @parameter
    def nonlinear_bias_types(self, val):
        """
        The type of nonlinear biasing to use
        """
        return val
        
    @parameter
    def use_vlah_biasing(self, val):
        """
        Whether to use the nonlinear biasing scheme from Vlah et al. 2013
        """ 
        if val:
            kws = {k:'vlah' for k in self.nonlinear_biases}
        else:
            kws = {k:None for k in self.nonlinear_biases}
        self.update_nonlinear_biasing(**kws)
        return val
        
    def update_nonlinear_biasing(self, **kws):
        """
        Update the nonlinear biasing types
        """
        d = self.nonlinear_bias_types.copy()
        d.update(**kws)
        self.nonlinear_bias_types = d
    
    #--------------------------------------------------------------------------
    # b2_00_a
    #--------------------------------------------------------------------------
    @parameter
    def b2_00_a__0(self, val):
        return val
        
    @parameter
    def b2_00_a__2(self, val):
        return val
    
    @parameter
    def b2_00_a__4(self, val):
        return val
        
    @cached_property("b2_00_a__0", "b2_00_a__2", "b2_00_a__4", "nonlinear_bias_types")
    def b2_00_a(self):
        """
        The nonlinear bias term that enters into Phm
        """
        coeffs = [self.b2_00_a__4, 0., self.b2_00_a__2, 0., self.b2_00_a__0]
        return _get_nonlinear_biasing_function(self, 'b2_00', 'a', coeffs)
            
    #--------------------------------------------------------------------------
    # b2_00_b
    #--------------------------------------------------------------------------
    @parameter
    def b2_00_b__0(self, val):
        return val
        
    @parameter
    def b2_00_b__2(self, val):
        return val
    
    @parameter
    def b2_00_b__4(self, val):
        return val
        
    @cached_property("b2_00_b__0", "b2_00_b__2", "b2_00_b__4", "nonlinear_bias_types")
    def b2_00_b(self):
        """
        The nonlinear bias term that enters into (P11+P02)[mu2]
        """
        coeffs = [self.b2_00_b__4, 0., self.b2_00_b__2, 0., self.b2_00_b__0]
        return _get_nonlinear_biasing_function(self, 'b2_00', 'b', coeffs)
    
    #--------------------------------------------------------------------------
    # b2_00_c
    #--------------------------------------------------------------------------
    @parameter
    def b2_00_c__0(self, val):
        return val
        
    @parameter
    def b2_00_c__2(self, val):
        return val
    
    @parameter
    def b2_00_c__4(self, val):
        return val
        
    @cached_property("b2_00_c__0", "b2_00_c__2", "b2_00_c__4", "nonlinear_bias_types")
    def b2_00_c(self):
        """
        The nonlinear bias term that enters into P02[mu4]
        """
        coeffs = [self.b2_00_c__4, 0., self.b2_00_c__2, 0., self.b2_00_c__0]
        return _get_nonlinear_biasing_function(self, 'b2_00', 'c', coeffs)
    
    #--------------------------------------------------------------------------
    # b2_00_d
    #--------------------------------------------------------------------------
    @parameter
    def b2_00_d__0(self, val):
        return val
        
    @parameter
    def b2_00_d__2(self, val):
        return val
    
    @parameter
    def b2_00_d__4(self, val):
        return val
        
    @cached_property("b2_00_d__0", "b2_00_d__2", "b2_00_d__4", "nonlinear_bias_types")
    def b2_00_d(self):
        """
        The nonlinear bias term that enters into (P13+P22+P04)[mu4]
        """
        coeffs = [self.b2_00_d__4, 0., self.b2_00_d__2, 0., self.b2_00_d__0]
        return _get_nonlinear_biasing_function(self, 'b2_00', 'd', coeffs)
        
    #--------------------------------------------------------------------------
    # b2_01_a
    #--------------------------------------------------------------------------
    @parameter
    def b2_01_a__0(self, val):
        return val
        
    @parameter
    def b2_01_a__1(self, val):
        return val
    
    @parameter
    def b2_01_a__2(self, val):
        return val
        
    @cached_property("b2_01_a__0", "b2_01_a__1", "b2_01_a__2", "nonlinear_bias_types")
    def b2_01_a(self):
        """
        The nonlinear bias term that enters into P01[mu2]
        """
        coeffs = [0., 0., self.b2_01_a__2, self.b2_01_a__1, self.b2_01_a__0]
        return _get_nonlinear_biasing_function(self, 'b2_01', 'a', coeffs)
        
    #--------------------------------------------------------------------------
    # b2_01_b
    #--------------------------------------------------------------------------
    @parameter
    def b2_01_b__0(self, val):
        return val
        
    @parameter
    def b2_01_b__1(self, val):
        return val
    
    @parameter
    def b2_01_b__2(self, val):
        return val
        
    @cached_property("b2_01_b__0", "b2_01_b__1", "b2_01_b__2", "nonlinear_bias_types")
    def b2_01_b(self):
        """
        The nonlinear bias term that enters into (P12+P03)[mu4]
        """
        coeffs = [0., 0., self.b2_01_b__2, self.b2_01_b__1, self.b2_01_b__0]
        return _get_nonlinear_biasing_function(self, 'b2_01', 'b', coeffs)
    