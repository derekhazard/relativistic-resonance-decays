// Implementation of our event class for ROOT
// now we have to include our header
// file !!!

#include "event.h"
#include <iostream>  

ClassImp(event)

using namespace std;

//  Default constructor
event::event() {
    
    eventNumber=-1;
    trackArray=new TObjArray();

    //  Set explicityly that the array is the owner!
    //  This is important to properly delete memory !!!!
    //  This is a caveat/inconsitency in ROOT, so the
    //  best way is to play around and try to create
    //  a memory leak/error to truly undertsand this aspect!!!
    trackArray->SetOwner(kTRUE);
}

//  User defined constructor
event::event(int nEv) {
  
    eventNumber=nEv;
    trackArray=new TObjArray(50);
    trackArray->SetOwner(kTRUE);
}

//  Destructor
event::~event() {

    trackArray->Delete();
    delete trackArray;
}; 

// Addtrack function
void event::Addtrack(std::string part, double restMass, double phi, double theta, double magP) {
    
    track *v = new track(part, restMass, phi, theta, magP);
    trackArray->AddLast(v);
}

// Print function
void event::Print() {
   
    cout << "Event Class:" << endl;
    cout << "Event # = " << eventNumber << endl;
    cout << "# track = " << trackArray->GetEntries() << endl << endl;
}

// Track printing function
void event::PrintTracks() {
    
    cout << "Event Class:" << endl;
    cout << "Event # = " << eventNumber << endl;
    cout << "# track = " << trackArray->GetEntries() << endl;

    for (int i = 0; i < (int) trackArray->GetEntries(); i++) {
        cout << "Track " << i << ":";
        GetTrack(i)->Print();
    }

  cout<<endl;
}
