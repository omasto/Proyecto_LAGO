
//
#include "LXeStackingAction.hh"
#include "LXeEventAction.hh"
#include "LXeSteppingAction.hh"

#include "G4ios.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleTypes.hh"
#include "G4Track.hh"
#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4EventManager.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXeStackingAction::LXeStackingAction(LXeEventAction* ea)
 : fEventAction(ea)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXeStackingAction::~LXeStackingAction() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4ClassificationOfNewTrack
LXeStackingAction::ClassifyNewTrack(const G4Track * aTrack){
 
  //Count what process generated the optical photons
  if(aTrack->GetDefinition()==G4OpticalPhoton::OpticalPhotonDefinition()){
    // particle is optical photon
    if(aTrack->GetParentID()>0){
      // particle is secondary
      if(aTrack->GetCreatorProcess()->GetProcessName()=="Scintillation")
        fEventAction->IncPhotonCount_Scint();
      else if(aTrack->GetCreatorProcess()->GetProcessName()=="Cerenkov")
        fEventAction->IncPhotonCount_Ceren();
    }
  }
  else{
  }
  return fUrgent;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeStackingAction::NewStage() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeStackingAction::PrepareNewEvent() {}
