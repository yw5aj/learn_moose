#include "LearnMooseApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<LearnMooseApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

LearnMooseApp::LearnMooseApp(InputParameters parameters) : MooseApp(parameters)
{
  LearnMooseApp::registerAll(_factory, _action_factory, _syntax);
}

LearnMooseApp::~LearnMooseApp() {}

void
LearnMooseApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"LearnMooseApp"});
  Registry::registerActionsTo(af, {"LearnMooseApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
LearnMooseApp::registerApps()
{
  registerApp(LearnMooseApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
LearnMooseApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  LearnMooseApp::registerAll(f, af, s);
}
extern "C" void
LearnMooseApp__registerApps()
{
  LearnMooseApp::registerApps();
}
