// This is the header file of our event class for ROOT

#ifndef ROOT_event
#define ROOT_event

#include "track.h"
#include "TBuffer.h"
#include "TObjArray.h"
#include "TObject.h"
#include "TROOT.h"
#include <string>

//definition of our event class
class event : public TObject
{
    // Class members
    protected:

    int eventNumber;        //  Number of events
    TObjArray *trackArray;  //  Our track object array

    public:

    // Constructors
    event();        //  Default
    event(int nEv); //  User defined

    //  Destructor
    virtual ~event();

    //  Setter Functions
    void SetEventNumber(int nEv) {eventNumber=nEv;}
    void Addtrack(track *mv) {trackArray->AddLast(mv);}
    void Addtrack(std::string part, double restMass, double phi, double theta, double magP);

    // Getter functions
    int GetEventNumber() {return eventNumber;}
    int GetNumberOfTracks() {return (int) trackArray->GetEntries();}
    track* GetTrack(int nT) {return (track*) trackArray->At(nT);}

    //our member functions
    void Print();
    void PrintTracks();

    ClassDef(event,1);
};
 
#endif //ROOT_track
