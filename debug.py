# Debugging ABP script
# Where to look for the module:
import sys
sys.path.append("./build") 

import pyABP

#// geometry and size
#int N; // Number of particles
#double L; // system size

#// dynamics
#double dt; // time step
#int Nsteps; // number of time steps
#int freq; // saving frequency
#int seed; // RNG seed

#// ABPs
#double mu; // mobility
#double Dr; // rotational diffusion constant
#double v0; // self-propulsion velocity
#// Interaction
#double k; // interaction stiffness
#double poly; // polydispersity

#// options
#bool saveText; // save as text file
#bool saveVTK; // save as vtk file
	
params={}
params["N"]=10
params["L"]=10.0
params["dt"]=0.01
params["Nsteps"]=10
params["freq"]=10
params["seed"]=1
params["mu"]=1.0
params["Dr"]=0.1
params["v0"]=0.1
params["k"]=1.0
params["poly"]=0.01
params["saveText"]=True
params["saveVTK"]=True

# set up system
#sys = pyABP.system(params)
thisSystem = pyABP.System()
# run system
nsave = int(params["Nsteps"]/params["freq"])
print(params)
for k in range(1):
	print("starting!")
	pyABP.notmain()
	print("Trying the class now!")
	thisSystem.step(params["freq"],True)
	#sys.output(params["saveText"],params["saveVTK"])
	print("Ran and saved after " + str(params["freq"]) + " steps, total at " + str(k*params["freq"]))
