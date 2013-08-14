#include "StdAfx.h"
#include "Factory.h"
#include "GlobalSettings.h"



#define BOOST_NO_WCHAR

SettingsFactory::SettingsFactory(PATH libraries_path,PATH config_path,PATH modelicasystem_path)
:SolverSettingsPolicy(libraries_path,modelicasystem_path,config_path)
{


}

SettingsFactory::~SettingsFactory(void)
{

 
}
 boost::shared_ptr<IGlobalSettings> SettingsFactory::createSolverGlobalSettings()
 
 {
   _global_settings =  boost::shared_ptr<IGlobalSettings>(new GlobalSettings());
     loadGlobalSettings(_global_settings);
     return _global_settings;

 }
  
boost::shared_ptr<ISolverSettings>  SettingsFactory::createSelectedSolverSettings()
{
  
  string solver_name = _global_settings->getSelectedSolver();
 _solver_settings = createSolverSettings(solver_name,_global_settings);
  return _solver_settings;

}

