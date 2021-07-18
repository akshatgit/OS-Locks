#ifndef __tick_lock_h__
#define __tick_lock_h__

typedef struct lock {  
  int next_ticket;
  int currently_serving;
} ticket_lock;

void ticket_lock_init(ticket_lock *lock);
void ticket_lock_acquire(ticket_lock *lock);
void ticket_lock_release(ticket_lock *lock);
#endif