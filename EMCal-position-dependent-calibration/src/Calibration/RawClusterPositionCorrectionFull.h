#ifndef CALORECO_RAWCLUSTERPOSITIONCORRECTIONFULL_H
#define CALORECO_RAWCLUSTERPOSITIONCORRECTIONFULL_H

#include <fun4all/SubsysReco.h>

#include <phparameter/PHParameters.h>

#include <string>
#include <vector>
#include <math.h>

class PHCompositeNode;
class RawClusterContainer;

class RawClusterPositionCorrectionFull : public SubsysReco
{
 public:
  explicit RawClusterPositionCorrectionFull(const std::string &name);

  int InitRun(PHCompositeNode *topNode) override;
  int process_event(PHCompositeNode *topNode) override;
  int End(PHCompositeNode *topNode) override;

  void CreateNodeTree(PHCompositeNode *topNode);

  const PHParameters &Get_eclus_CalibrationParameters() const
  {
    return _eclus_calib_params;
  }
  PHParameters &Get_eclus_CalibrationParameters()
  {
    return _eclus_calib_params;
  }
  const PHParameters &Get_eore_CalibrationParameters() const
  {
    return _ecore_calib_params;
  }
  PHParameters &Get_ecore_CalibrationParameters()
  {
    return _ecore_calib_params;
  }

  void Set_eclus_CalibrationParameters(const PHParameters &calib_params)
  {
    _eclus_calib_params = calib_params;
  }
  void Set_ecore_CalibrationParameters(const PHParameters &calib_params)
  {
    _ecore_calib_params = calib_params;
  }

 private:
  PHParameters _eclus_calib_params;
  PHParameters _ecore_calib_params;
  void SetDefaultParameters(PHParameters &param);
  RawClusterContainer *_recalib_clusters;

  std::string _det_name;

  const double sector_boundary_phi_length = 1.52/25.3; // boundary length in mm divided by tower length in mm
  const double sector_boundary_eta_length = 3.04/25.3; // boundary length in mm divided by tower length in mm
  const double tower_length_rad = 2*M_PI/(256+32*sector_boundary_phi_length);
  const double sector_boundary_phi_length_rad = tower_length_rad*sector_boundary_phi_length;

  int bins_eta, bins_phi;
  std::vector<std::vector<double> > eclus_calib_constants;
  std::vector<std::vector<double> > ecore_calib_constants;
};

#endif
