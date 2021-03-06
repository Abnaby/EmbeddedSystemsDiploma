#include "queueConfig.h"
#include "queueAPIs.h"
#include "queuePrivate.h"
STACK_STATE queue_create(queue_t *ptq)
{
    ptq->_rear = 0 ;
    ptq->_front = 0 ;
    ptq->_counter = 0 ;
    return QUEUE_NO_ERROR ;
}
STACK_STATE queue_add(queueEntery dataEnqueue ,queue_t *ptq)
{
    /* Check if it full */
    if(ptq->_counter >= queueSize)
        return QUEUE_FULL ;
    ptq->_rear = (ptq->_rear) % queueSize ;
    ptq->_queueArr[ptq->_rear++] = dataEnqueue ;
    ptq->_counter++;
    return QUEUE_NO_ERROR ;
}
STACK_STATE queue_get(queueEntery *dataEnqueue ,queue_t *ptq)
{
    /* Check if it empty */
    if(ptq->_counter == 0)
        return QUEUE_EMPTY ;
    ptq->_front = (ptq->_front) % queueSize ;

    *dataEnqueue = ptq->_queueArr[ptq->_front++]  ;
    ptq->_counter--;
    return QUEUE_NO_ERROR ;
}
int queue_size(queue_t *ptq)
{
    return ptq->_counter ;
}
void queue_print(queue_t *ptq)
{
    for(int i = ptq->_front ; i< ptq->_counter ; i = (i+1)%queueSize)
        printf("%d ",ptq->_queueArr[i]);
}
