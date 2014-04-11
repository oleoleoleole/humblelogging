#ifndef HUMBLE_MUTEX_WINDOWS_HEADER
#define HUMBLE_MUTEX_WINDOWS_HEADER

#include <Windows.h>

#include "humblelogging/defines.h"

namespace std {

class HUMBLE_EXPORT_API mutex
{
public:
  mutex();
  ~mutex();
  void lock();
  void unlock();

private:
  CRITICAL_SECTION _criticalSection;
};

template<typename TLockable>
class lock_guard
{
public:
  lock_guard(TLockable &lockable)
    : _lockable(lockable)
  {
    _lockable.lock();
  }
  
  ~lock_guard()
  {
    _lockable.unlock();
  }
  
private:
  TLockable &_lockable;
};

}  // End of namespaces.
#endif