//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "LearnMooseTestApp.h"
#include "LearnMooseApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<LearnMooseTestApp>()
{
  InputParameters params = validParams<LearnMooseApp>();
  return params;
}

LearnMooseTestApp::LearnMooseTestApp(InputParameters parameters) : MooseApp(parameters)
{
  LearnMooseTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

LearnMooseTestApp::~LearnMooseTestApp() {}

void
LearnMooseTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  LearnMooseApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"LearnMooseTestApp"});
    Registry::registerActionsTo(af, {"LearnMooseTestApp"});
  }
}

void
LearnMooseTestApp::registerApps()
{
  registerApp(LearnMooseApp);
  registerApp(LearnMooseTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
LearnMooseTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  LearnMooseTestApp::registerAll(f, af, s);
}
extern "C" void
LearnMooseTestApp__registerApps()
{
  LearnMooseTestApp::registerApps();
}
