//Create a Boolean occupied value
boolean occupied = false;
int semaphore = 0;
queue waiting;

//Initialize the threads
startThreads();

//Thread T_x

void main()
{
	while(!done)
	{
//Generate our P(s)
		boolean pxMustWait = true;
		while(pxMustWait)
		{
			testAndSet(pxMustWait, occupied);
		}
		
		if(semaphore == 0)
		{
			//Place the thread at the end of the queue
			//Force the thread to sleep
		}
		else
		{
			semaphore--;
			occupied = true;
		}
		
		//Critical Section Code
		
		pxMustWait = true;
		occupied   = false;

//Generate our V(s)
		while(pxMustWait)
		{
			testAndSet(pxMusWait, occupied);
		}

		if(waiting == 0)
		{
			semaphore++;
		}
		else
		{
			//Remove the next process from the queue
			//Force the process to wait
		}
	}
}