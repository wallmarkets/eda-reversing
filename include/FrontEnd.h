// FrontEnd.h -- Apr 15, 2009
//    by geohot
//  released under GPLv3, see http://gplv3.fsf.org/

#ifndef EDA_FRONTEND_H_
#define EDA_FRONTEND_H_

#include "threading.h"
#include "Mailbox.h"
#include "macros.h"
#include "Bank.h"
#include "Core.h"

#include <string>

namespace eda
{

class FrontEnd
{
public:
  FrontEnd();
  FrontEnd(Bank *bank);
  virtual ~FrontEnd();
  void attach(Core *);
protected:
  virtual void runLoop();
  Mailbox *mCore;
  Bank *mBank;
private:
  static void entryPoint(void *);
  threadContainer mThread;
};

}

#endif /* EDA_FRONTEND_H_ */