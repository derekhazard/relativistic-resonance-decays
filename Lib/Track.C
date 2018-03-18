// Implementation of our track class for ROOT now we have to include our header file.

#include "track.h"

#include <iostream>  

ClassImp(track)

using namespace std;

// Default constructor
track::track():TLorentzVector() {
    
    //  Set the particle name
    SetParticle("undefined");
}

// User defined constructor
track::track(std::string part, double restMass, double phi, double theta, double magP):TLorentzVector() {

    //  Set the particle name
    SetParticle(part);
    
    //  Check the azimuthal angle
    if (TMath::Abs(phi) > TMath::Pi()) cout << "\n" << phi << " is an nvalid entry for azimuthal angle.  Must be from -Pi to Pi.  Default to value zero.\n";
    
    //  Check the polar angle
    if (theta > TMath::Pi() && theta < 0.0) cout << "\n" << theta << " is an invalid entry for polar angle.  Must be from 0 to Pi.  Default to value zero.\n";
    
    //  Check the rest mass
    if (restMass < 0.0) cout << "\n" << restMass << " is an invalid entry for rest mass.  Must be greater than or equal to zero.  Default to value zero.\n";
    
    //  Check the momentum magnitude
    if (magP < 0.0) cout << "\n" << magP << " is an invalid entry for momentum magnitude.  Must be greater than or equal to zero.  Default to value zero.\n";
    
    //  If all inputs are valid, convert to px, py, pz, and E.  Then create a lorentz vector.
    else if (TMath::Abs(phi) <= TMath::Pi() && theta <= TMath::Pi() && theta >= 0.0 && restMass >= 0.0) {
        
        SetPxPyPzE(magP * TMath::Sin(theta) * TMath::Cos(phi),      //  px
                   magP * TMath::Sin(theta) * TMath::Sin(phi),      //  py
                   magP * TMath::Cos(theta),                        //  pz
                   TMath::Sqrt(magP * magP + restMass * restMass)); //  E
    }
}
 
//  Default destructor
track::~track() {}

// Print function
void track::Print()
{
    cout << GetParticle() << " with " << "E = "<< E() << ", px = "<< Px() << ", py = " << Py() << ", pz = " << Pz() << endl;
}

//  Set the particle name
void track::SetParticle(std::string part) {
    particle = part;
    return;
}

//  Get the name of the particle in the track.
std::string track::GetParticle() {
    return particle;
}

