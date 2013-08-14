
#pragma once
#include "stdafx.h"
#if defined(__vxworks)


#elif defined(OMC_BUILD)

#include "Newton.h"
#include "NewtonSettings.h"

    /* OMC factory */
    using boost::extensions::factory;

BOOST_EXTENSION_TYPE_MAP_FUNCTION {
  types.get<std::map<std::string, factory<IAlgLoopSolver,IAlgLoop*, INonLinSolverSettings*> > >()
    ["Newton"].set<Newton>();
  types.get<std::map<std::string, factory<INonLinSolverSettings> > >()
    ["NewtonSettings"].set<NewtonSettings>();
 }

#else
error "operating system not supported"
#endif



   