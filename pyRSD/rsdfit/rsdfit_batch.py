import logging
from mpi4py import MPI
from pyRSD.rsdfit.util.taskmanager import TaskManager

# setup the logging
rank = MPI.COMM_WORLD.rank
name = MPI.Get_processor_name()
logging.basicConfig(level=logging.DEBUG,
                    format='rank %d on %s: '%(rank,name) + \
                            '%(asctime)s %(name)-15s %(levelname)-8s %(message)s',
                    datefmt='%m-%d %H:%M')
logger = logging.getLogger('rsdfit-batch.py')


def main():

    desc = """iterate (possibly in parallel) over a set of configuration parameters, 
              running `rsdfit` for each"""
    manager = TaskManager.create(MPI.COMM_WORLD, desc=desc)
    manager.run_all()
   
if __name__ == '__main__' :
    main()
    
    
