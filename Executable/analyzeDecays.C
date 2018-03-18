void analyzeDecays() {
    
    //  Load the library
    gSystem->Load("../Lib/libEvent.so");
  
    //  Open file and read in the tree.
    TFile *f=new TFile("resonanceDecay.root","read");
    TTree *t1=(TTree*) f->Get("event");
  
    //  Pointer to current event
    event *ev=0;

    //  Access the branch holding the events.
    t1->SetBranchAddress("event",&ev);
  
    //  Get the number of events stored in the tree.
    Int_t events = (Int_t)t1->GetEntries();

    //  Welcome the user and display the number of entries.
    std::cout << "Welcome to the resonance decay analysis macro.\n\n";
    std::cout << "There are " << events << " decay events on record.\n\n";
    std::cout << "Calculating invariant mass for each event...\n\n";
    
    //  Loop through the events
    for (Int_t i=0; i< events; i++) {
        
        //  Get an event
        t1->GetEntry(i);
        
        //  Get tracks from the event
        track *particle1 = ev->GetTrack(0);
        track *particle2 = ev->GetTrack(1);
        
        //  Print the invariant mass.
        std::cout << "Event #" << i+1 << " has an invariant mass of ";
        std::cout << TMath::Sqrt((*particle1 + *particle2) * (*particle1 + *particle2)) * 1000.0 << " MeV.\n";
    }
}
