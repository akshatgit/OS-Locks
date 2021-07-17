#ifndef __lock_h__
#define __lock_h__

typedef volatile int my_spinlock_t;

extern int my_spin_init(my_spinlock_t *lock);
extern int my_spin_lock(my_spinlock_t *lock);
extern int my_spin_unlock(my_spinlock_t *lock);

#endif