// This is the header file of our track class for ROOT

#ifndef ROOT_track
#define ROOT_track

#include "TLorentzVector.h"
#include "TMath.h"
#include "TROOT.h"

#include <string>

//  Definition of our track class, which inherits from th TLorentzVector class
class track : public TLorentzVector {
    
    private:
    
    //  Class members
    std::string particle;               //  Particle name

    public:

    //  Constructors
    track();                                                                            //  Default
    track(std::string part, double restMass, double phi, double theta, double magP);    //  User defined
    
    //  Destructor
    virtual ~track();
  
    //  Our member functions
    void Print();                       //  Print the track information.
    void SetParticle(std::string part); //  Set the particle using its name.
    std::string GetParticle();          //  Get the name of the particle in the track.


  ClassDef(track,1);
};
 
#endif //ROOT_track
