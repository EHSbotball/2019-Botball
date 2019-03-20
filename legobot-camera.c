#include <kipr/botball.h>

int a = 0;
int b = 0;
int x = 0;
int y = 0;
int n =0;
int card = 0;
int botguy = 0;
int mayor = 0;
int main()

{ 
    camera_open_black();
    enable_servos();
    set_servo_position(2,1286);
    set_servo_position(1, 650);
    while (y == 0)
    {
    	msleep(100);
    	camera_update();
    	x++;
    	if(x > 20)
    		{
    		motor(0,25);
    		motor(2,25); 
    		if(get_object_count(2) > 1)
    			{
        			y = 1;
                card = 1;
            }
    		}
    	}
    ao();
        while(get_object_center_x(2,0) < 80)
    {
        camera_update();
        motor(0,25);
       motor(2,25);
       msleep(10);
    }
    ao();
    /*
    motor(0,50);
    motor(2,50);
    msleep(3000);
    ao();
    y = 0;
    x = 0;
    camera_close();
    camera_open_black();
    while (y == 0)
    {
    	msleep(100);
    	camera_update();
    	x++;
    	if(x > 20)
    		{
    		motor(0,25);
    		motor(2,25); 
    		if(get_object_count(2) > 1)
    			{
        			y = 1;
                    card = 1;
    			}
            if(get_object_count(3) > 1)
    			{
        			y = 1;
                    mayor = 1;
    			}    
    		}
    	}
    ao();
   */ /*
    motor(0,-25);
    motor(2,25);
    msleep(2400);
    ao();
    while(analog(0) < 1500)
    {
        motor(0,25);
        motor(2,25);
        msleep(100);
    }
    ao();
    set_servo_position(1, 1259);
    set_servo_position(2, 900);
    msleep(1000);
    set_servo_position(2,1286);
    set_servo_position(1, 650);
    msleep(1000);
   */
 
 if(card > 0)
 {
   printf("Card detected\n");
    
 }
 if( botguy > 0)
 {
    printf("botguy detected\n");
     
 }
 if ( mayor > 0)
 {
     printf("mayor detected\n");
     
 }
    disable_servos();
    camera_close();  
    return 0;
}