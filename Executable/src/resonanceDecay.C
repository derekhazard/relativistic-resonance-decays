#include <iostream>
#include <string>
#include "TROOT.h"
#include "TTree.h"
#include "TFile.h"
#include "TRandom.h"
#include "TMath.h"


#include "../../Lib/track.h"
#include "../../Lib/event.h"

//  Function that simulates the resonance decay of rho(770) to two pions.

//  Decay Parameters
Double_t bPz = 2.0;                 //  Boost momentum in the z (GeV)
Double_t M = 0.775;                 //  Decay particle mass (GeV)
Double_t m1 = 0.139;                //  First decay product mass (GeV)
Double_t m2 = 0.139;                //  Second decay product mass (GeV)
std::string particleA = "pion";     //  First decay product name
std::string particleB = "pion";     //  Second decay particle name

void resonanceDecay(Int_t events = 1000) {
    
    //  File and tree for data storage.
    TFile *f=new TFile("resonanceDecay.root","recreate");
    TTree *t1=new TTree("event","a simple Tree with our event class");
    
    //  Pointer to current event
    event *ev=0;
    
    //  Branch to hold events generated.
    t1->Branch("event",&ev);

    //  Seed the random number generator
    gRandom->SetSeed(0);
    
    //  Loop to fill the tree with events
    for (Int_t i=0; i< events; i++) {
        
        //  New event
        ev=new event(i);
        
        //  Generate random values for the azimuthal and polar angles.
        Double_t phi1 = gRandom->Uniform(2*TMath::Pi()) - TMath::Pi();
        Double_t theta1 = gRandom->Uniform(TMath::Pi());
        
        Double_t phi2 = 0;
        if (phi1 > 0.0) phi2 = phi1 - TMath::Pi();
        else phi2 = phi1 + TMath::Pi();
        
        Double_t theta2 = TMath::Pi() - theta1;
        
        
        //  Calculate the momentum magnitude and energy based on the decay
        //  and product masses.
        Double_t E = M/2.0;
        
        Double_t p1 = 0;
        if (TMath::Power(E,2) < TMath::Power(m1,2))
            std::cout << "ERROR: Decay impossible E^2 < m1^2 !!!!";
        else p1 = TMath::Sqrt(TMath::Power(E,2) - TMath::Power(m1,2));
        
        Double_t p2 = 0;
        if (TMath::Power(E,2) < TMath::Power(m2,2))
            std::cout << "ERROR: Decay impossible E^2 < m2^2 !!!!";
        else p2 = TMath::Sqrt(TMath::Power(E,2) - TMath::Power(m2,2));
        
        //  Create new tracks
        track *particle1 = new track(particleA, m1, phi1, theta1, p1);
        track *particle2 = new track(particleB, m2, phi2, theta2, p2);
        
        //  Boost the tracks along the z-axis
        particle1->Boost(0.0, 0.0, bPz/TMath::Sqrt(bPz * bPz + M * M));
        particle2->Boost(0.0, 0.0, bPz/TMath::Sqrt(bPz * bPz + M * M));
        
        //  Add tracks to the event
        ev->Addtrack(particle1);
        ev->Addtrack(particle2);
        
        //  Add event to the tree
        t1->Fill();

        //  Print the boosted tracks.
        ev->PrintTracks();

        //  Free the memory
        delete ev;
    }

    // Save data to disk
    t1->Write();
    f->Write();
    f->Close();
}

int main()
{
    resonanceDecay();
}

