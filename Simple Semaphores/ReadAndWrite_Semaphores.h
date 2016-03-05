int readers = 0;
Semaphore s_readers = new Semaphore(1);
Semaphore s_writers = new Semaphore(1);

void Read()
{
	P(s_readers);			//Continue if (s_readers>0), else place at end of queue
	readers++;				//Increment the number of readers
	if(readers == 1)
	{
		P(s_writers);		//Continue if (s_writers>0), else place at end of queue
	}
	
	//Read data
	
	V(s_readers);			//End if queue is empty, else load next process
	readers--;				//Decrement the number of readers
	
	if(readers == 0)		//Readers are depleted, initiate write processes;
	{
		signal(canWrite);
	}
}

void Write()
{
	P(s_writers);			//Continue if (s_writers>0), else place at end of queue
	
	//Write data
	
	V(s_writers);			//End if queue is empty, else load next process
	
	if(readers > 0)			//If there are waiting readers, initiate read process
	{
		signal(canRead);
	}	
}