#ifndef __DISKinematics_H__
#define __DISKinematics_H__

#include <fun4all/SubsysReco.h>
#include <math.h>

class TNtuple;
class TFile;
class TH1D;

class PHCompositeNode;
namespace HepMC
{
  class GenEvent;
}

class DISKinematics : public SubsysReco
{

public:

  DISKinematics(std::string filename);

  int
  Init(PHCompositeNode*);
  int
  process_event(PHCompositeNode*);
  int
  End(PHCompositeNode*);

  void
  set_beam_energies( float beam_electron , float beam_proton )
  {
    _e_ebeam = fabs( beam_electron );
    _e_pbeam = fabs( beam_proton );
  }

private:

  bool _verbose;

  int _ievent;
  int _total_pass;

  std::string _foutname;
  TFile *_fout_root;

  /* output tree and variables */
  TNtuple* _tree_dis;

  /* beam energies electron and proton */
  float _e_ebeam;
  float _e_pbeam;
};

#endif // __DISKinematics_H__
