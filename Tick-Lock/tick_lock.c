#include "tick_lock.h"

void ticket_lock_init(ticket_lock *lock)
{
  lock->next_ticket = 0;
  lock->currently_serving = 0;
}

void ticket_lock_acquire(ticket_lock *lock) 
{
  // Obtain my ticket.
  int my_ticket = __atomic_fetch_add(&lock->next_ticket,
			1, __ATOMIC_ACQ_REL);
  int expected = my_ticket;
  // Loop until it is my turn to acquire the lock.
  while (!__atomic_compare_exchange_n(&lock->currently_serving, &my_ticket, expected, 1,__ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)){
    my_ticket = expected;
  };
}

void ticket_lock_release(ticket_lock *lock)
{
  // Move the current ticket by 1.
  __atomic_add_fetch(&lock->currently_serving, 1,
	__ATOMIC_SEQ_CST);
}