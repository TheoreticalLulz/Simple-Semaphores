class sleepingBarber
{
public:
	sleepingBarber();
	void barber();
	void customer();
	void sleep();
	void loadOne();
	void cut_hair();
	void leaveOne();
private:
	Condition canCut;
	Condition canWait;
	bool waitlock;
	int customers;
	int chairs;
}

sleepingBarber::sleepingBarber()
{
	waitlock  = false;
	customers = 0;
	chairs    = n;
}

void sleepingBarber::barber()
{
	while(m_customers == 0)					//Sleep while there are no customers
	{
		sleep();
	}
	
	//Wait if customers are entering the waiting room
	if(waitLock)			//Wait until hair cutting is allowed
	{
		wait(canCut);
	}
	
	waitlock = true;						//Prevent waiting until finished cutting
	
	loadOne();								//Load the next customer in the queue

	cut_hair();								//Cut the customer's hair
	
	leaveOne();								//Remove the customer.
	customers--;							//Decrement the number of customers
	chairs++;								//Increment available chairs
	
	waitLock == false;
	signal(canWait);						//Allow customers to enter waiting room
}

void sleepingBarber::customer()
{
	//Wait until chairs are available or
	if(waitLock)				//Wait until allowed to enter waiting room.
	{
		wait(canWait);
	}
	
	if(chairs > 0)							//If available chairs, enter waiting room		
	{
		waitlock = true;					//Prevent cutting until entered room
	
		pushOne();							//Add customer to waiting room
		chairs--;							//Decrement the number of chairs
		customers++;						//increment the number of customers
		
		waitlock = false;					//Allow hair cutting
		signal(canCut);
	}
}