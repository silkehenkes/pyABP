# Debugging ABP script
# Where to look for the module:
import sys
sys.path.append("./build") 
import os
import shutil

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
# system
params["N"]=100
params["L"]=10.0

# dynamics
params["dt"]=0.01
params["seed"]=1

# ABPs
params["mu"]=1.0
params["Dr"]=0.1
params["v0"]=0.1
#// Interaction
params["k"]=1.0
params["poly"]=0.01

# C++ internal: debugging output?
params["verbose"]=False

# Python script options only
params["Nsteps"]=10000
params["freq"]=100
params["saveText"]=True
params["saveVTK"]=True

print(params)

# set up system
thisSystem = pyABP.System(params)
# run system
nsave = int(params["Nsteps"]/params["freq"])

# make test output directory. Delete previous version first
shutil.rmtree("test") 
os.mkdir('test')


for k in range(nsave):
	thisSystem.step(params["freq"])
	# basic output (text so far)
	filename = 'test/data'+str(k)+'.dat'
	# void output(string filename, bool _saveText, bool _saveVTP);
	thisSystem.output(filename,params["saveText"],params["saveVTK"])
	print("Ran and saved after " + str(params["freq"]) + " steps, total at " + str((k+1)*params["freq"]))
