#include "ActionAbs.h"

using namespace NAMESPACE_LIBRARY_ACTONS;

ActionAbs::ActionAbs ( QString title , QWidget *parent ) : QAction ( ( QObject * ) parent ) {

  this->setText ( "&" + title );
  this->setToolTip ( title );
  this->setPriority ( QAction::LowPriority );
  this->myParent = parent;
  connect ( this, SIGNAL ( triggered () ), this, SLOT ( execAct () ) );
}
