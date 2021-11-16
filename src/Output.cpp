#include "Output.h"


Output::Output(Parameters _param) {
	// not thought of anything so far
	cout << "constructed output structure" << endl;
}

// write the data to a new file filename
void Output::writeText(vector <Particle> & particles, string filename) {
	
	// generate and open new file with the correct name
	ofstream outfile(filename);
	// First line is header
	outfile << "index \t  x \t y  \t theta \t  vx \t vy \t omega \t R " << endl;
	for (int i = 0; i< particles.size(); i++) {
		particles[i].printFile(outfile);
	}
	outfile.close();
}
	
	
void Output::writeVTP(vector <Particle> & particles, string filename) {
	// generate polydata structure containing positions, velocities active forces and radii
	vtkSmartPointer<vtkPolyData> polydata =  vtkSmartPointer<vtkPolyData>::New();
	vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
	
	vtkSmartPointer<vtkIntArray> ids = vtkSmartPointer<vtkIntArray>::New();
    ids->SetNumberOfComponents(1);
    ids->SetName("Index");

    vtkSmartPointer<vtkDoubleArray> force = vtkSmartPointer<vtkDoubleArray>::New();
    force->SetNumberOfComponents(3);
    force->SetName("Force");
	
	vtkSmartPointer<vtkDoubleArray> director = vtkSmartPointer<vtkDoubleArray>::New();
    director->SetNumberOfComponents(3);
    director->SetName("Director");
	
	vtkSmartPointer<vtkDoubleArray> radius = vtkSmartPointer<vtkDoubleArray>::New();
    radius->SetNumberOfComponents(1);
    radius->SetName("Radius");
	
	for (int i = 0; i< particles.size(); i++) {
		// position
		points->InsertNextPoint(particles[i].x, particles[i].y, 0.0);
		// id
		ids->InsertNextValue(particles[i].index);
		// velocity / force
		double vel[3] = {particles[i].fx, particles[i].fy,0};
        force->InsertNextTuple(vel);
		// director
		double dir[3] = {cos(particles[i].theta), sin(particles[i].theta),0};
        director->InsertNextTuple(dir);
		// radius
		double rad[1] = {particles[i].R};
        radius->InsertNextTuple(rad);
	}
	
	polydata->SetPoints(points);
    polydata->GetPointData()->AddArray(ids);
    polydata->GetPointData()->AddArray(force);
	polydata->GetPointData()->AddArray(director);
	polydata->GetPointData()->AddArray(radius);
	
	// Write the file
    vtkSmartPointer<vtkXMLPolyDataWriter> writer =  vtkSmartPointer<vtkXMLPolyDataWriter>::New();
    writer->SetFileName(filename.c_str()); 
	writer->SetInputData(polydata);
	writer->SetDataModeToAscii();
    writer->Write();
}
	
	
