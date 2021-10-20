# Debugging ABP script
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
params["Nsteps"]=100
params["freq"]=1
params["seed"]=1
params["mu"]=1.0
params["Dr"]=0.1
params["v0"]=0.1
params["k"]=1.0
params["poly"]=0.3
params["saveText"]=True
params["saveVTK"]=True

# set up system
sys = pyABP.system(params)
# run system
nsave = int(param["Nsteps"]/param["freq"]
for k in range(nsave):
	sys.step(params["freq"])
	sys.output(params["saveText"],params["saveVTK"])
	print("Ran and saved after " + params["freq"] + " steps, total at " + str(k*params["freq"]))
