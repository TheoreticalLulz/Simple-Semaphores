class sleepingBarber
{
public:

	sleepingBarber();
	void barber();							//Barber routine
	void customer();						//Customer routine
	void cutHair();							//Cut the customer's hair
	void wakeOne();							//Wake the next customer
	void loadOne();							//Let the next customer into cutting room
	void leaveOne();						//Remove customer from cutting room
	
private:

	semaphore s_barber;						//Binary semaphore for barber
	semaphore s_chairs;						//Counting semaphore for chairs
	int customers;
	Condition canCut;
}

sleepingBarber::sleepingBarber()
{
	s_barber  = 1;
	s_chairs  = n;
	customers = 0;
}

void sleepingBarber::barber()
{
	while(customers == 0)					//Barber sleeps without customers
	{
		sleep();
	}

	wakeOne();								//Wake the next waiting customer
	loadOne();								//Load the next customer in the queue

	cut_hair();								//Cut the customer's hair
	
	leaveOne();								//Remove the customer.
	
	customers--;
	signal(canCut);							//Allow the next customer into the c_room
}

void sleepingBarber::customers()
{
	if(s_chairs > 0)
	{
		push();								//Adds a customer to the queue
		customer++;							//Increments the number of customers
		s_chairs--;
	}
}