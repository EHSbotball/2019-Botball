int main()
{
	while(1)
	{
		if(analog(0) > 900)
		{
			motor(1,50);
			motor(2,25);
			msleep(200);
			
		}
		else
		{
			motor(1,25);
			motor(2,50);
			msleep(200);
			
		}
	}
	
	return(0);
}
