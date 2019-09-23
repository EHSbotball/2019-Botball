int main()
{
	while(1)
	{
		if(analog10(0) > 900)
		{
			motor(1,50);
			msleep(200);
			
		}
		else
		{
			motor(2,50);
			msleep(200);
			
		}
	}
	
	return(0);
}
